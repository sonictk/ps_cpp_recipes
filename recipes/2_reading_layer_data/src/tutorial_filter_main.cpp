#include <PIDefines.h>
#include <PIAbout.h>
#include <PIFilter.h>
#include <SPBasic.h>

#define OS_PATH_SEP '\\'

SPBasicSuite *sSPBasic = NULL;


void findRGBChannelsForLayer(const ReadLayerDesc *layerDesc, ReadChannelDesc **rChn, ReadChannelDesc **gChn, ReadChannelDesc **bChn)
{
	ReadChannelDesc *curChn = layerDesc->compositeChannelsList;
	while (curChn != NULL) {
		int32_t tileHeight = curChn->tileSize.v;
		int32_t tileWidth = curChn->tileSize.h;
		if (tileHeight == 0 || tileWidth == 0) {
			curChn = curChn->next;
			continue;
		}

		switch (curChn->channelType) {
		case PS_CHANNEL_ID_RED:
			*rChn = curChn;
			break;
		case PS_CHANNEL_ID_GREEN:
			*gChn = curChn;
			break;
		case PS_CHANNEL_ID_BLUE:
			*bChn = curChn;
			break;
		default:
			break;
		}
		curChn = curChn->next;
	}

	return;
}


void writeRGBChannelsToJPG(const ReadChannelDesc* rChn,
						   const ReadChannelDesc *gChn,
						   const ReadChannelDesc *bChn,
						   const char *jpgPath,
						   const int width,
						   const int height)
{
	int tileHeight = rChn->tileSize.v;
	int tileWidth = rChn->tileSize.h;

	assert(tileHeight != 0);
	assert(tileWidth != 0);

	int chnHeight = rChn->bounds.bottom - rChn->bounds.top;
	int chnWidth = rChn->bounds.right - rChn->bounds.left;
	int numTilesVert = (tileHeight - 1 + chnHeight) / tileHeight;
	int numTilesHoriz = (tileWidth - 1 + chnWidth) / tileWidth;
	int chnSize = tileWidth * tileHeight * rChn->depth / 8;

	int numTiles = numTilesVert * numTilesHoriz;
	int counter = 0;

	int rgbBufSize = chnSize * numTiles * 3 * sizeof(uint8_t);
	uint8_t *rgbPxDataPlanar = (uint8_t *)malloc(rgbBufSize);

	assert(rgbPxDataPlanar != NULL);

	int bytesRead = 0;
	readPSChannelDataIntoBuffer(rChn, rgbPxDataPlanar, chnWidth, &bytesRead);

	int totalBytesRead = bytesRead;
	readPSChannelDataIntoBuffer(gChn, rgbPxDataPlanar + totalBytesRead, chnWidth, &bytesRead);

	totalBytesRead += bytesRead;
	readPSChannelDataIntoBuffer(bChn, rgbPxDataPlanar + totalBytesRead, chnWidth, &bytesRead);

	uint8_t *rgbPxDataPixel = (uint8_t *)malloc(rgbBufSize);
	convertPlanarToPixelRGB(rgbPxDataPixel, rgbPxDataPlanar, chnWidth, chnHeight, rChn->depth / 8);
	saveResizedImageDataRGB(rgbPxDataPixel, jpgPath, chnWidth, chnHeight, rChn->depth / 8, PSImgFormat_JPG, width, height, keepAspect, ImgDataResize_Bilinear);

	free(rgbPxDataPlanar);
	free(rgbPxDataPixel);

	return;
}


void executeFilter(const FilterRecordPtr &filterRecord)
{
	ReadImageDocumentDesc *docInfo = filterRecord->documentInfo;
	assert(docInfo != NULL);
	if (docInfo->layerCount == 0) {
		return;
	}

	ReadLayerDesc *layerDesc = docInfo->layersDescriptor;
	if (layerDesc == NULL) {
		return;
	}

	// NOTE: (sonictk) Create a temporary directory to store the output images.
	char *tempDirPath = (char *)malloc(MAX_PATH * sizeof(char));
	DWORD lenTempDirPath = GetTempPathA((DWORD)MAX_PATH, (LPSTR)tempDirPath);
	DWORD fileAttrs = GetFileAttributes((LPCTSTR)tempDirPath);
	if (!(fileAttrs & FILE_ATTRIBUTE_DIRECTORY)) {
		CreateDirectory((LPCSTR)tempDirPath, NULL);
	}

	int layersLeftToProcess = docInfo->layerCount;
	int validLayers = 0;
	int progressTotal = layersLeftToProcess;
	int progressCounter = 0;
	do {
		++progressCounter;
		--layersLeftToProcess;

		const char *layerName = layerDesc->name;
		// NOTE: (sonictk) We don't save out layers which have empty names
		if (layerName == NULL || layerName[0] == '\0') {
			layerDesc = layerDesc->next;
			continue;
		}

		// NOTE: (sonictk) Format the final output path for this layer.
		char outPath[MAX_PATH];
		int lenPath = snprintf(outPath, 0, "%s%c%s.jpg", tempDirPath, OS_PATH_SEP, layerName);
		snprintf(outPath, lenPath + 1, "%s%c%s.jpg", tempDirPath, OS_PATH_SEP, layerName);

		// NOTE: (sonictk) Read image pixels and write the output jpg.
		ReadChannelDesc *rChn = NULL;
		ReadChannelDesc *gChn = NULL;
		ReadChannelDesc *bChn = NULL;
		findRGBChannelsForLayer(layerDesc, &rChn, &gChn, &bChn);
		assert(rChn != NULL);
		assert(gChn != NULL);
		assert(bChn != NULL);

		int chnWidth = rChn->bounds.right - rChn->bounds.left;
		int chnHeight = rChn->bounds.bottom - rChn->bounds.top;

		writeRGBChannelsToJPG(rChn, gChn, bChn, outPath, 100, chnWidth, chnHeight, true);

		gFilterRecord->progressProc(progressCounter, progressTotal);
		// NOTE: (sonictk) If the user requested an interrupt, exit early and stop processing.
		if (gFilterRecord->abortProc()) {
			break;
		}

		++validLayers;

		if (layerDesc->next != NULL) {
			layerDesc = layerDesc->next;
		}
	} while (layersLeftToProcess > 0 && layerDesc != NULL);

	free(tempDirPath);

	return;
}


/**
 * By convention, this is the entry point for Photoshop Filter plug-ins.
 *
 * @param selector			Host provides selector indicating what command to do.

 * @param filterRecord		Host provides a pointer to parameter block containing
 * 						pertinent data and callbacks. See ``PIFilter.h``.

 * @param data				Use this to store a pointer to our global data structure,
 * 						which is maintained by the host between calls to the plug-in.

 * @param result			Returns error result. Some errors are handled by the host,
 * 						some are silent, and some you must handle. See ``PIGeneral.h``.
 */
DLLExport MACPASCAL void PluginMain(const int16_t selector,
									FilterRecordPtr filterRecord,
									long long *data,
									int16_t *result)
{
	switch (selector) {
	case filterSelectorAbout:
		sSPBasic = ((AboutRecord *)filterRecord)->sSPBasic;

	case filterSelectorStart:
	{
		sSPBasic = filterRecord->sSPBasic;
		if (filterRecord->bigDocumentData != NULL) {
			filterRecord->bigDocumentData->PluginUsing32BitCoordinates = true;
		}

		executeFilter(filterRecord);

		break;
	}
	default:
		break;
	}

	return;
}

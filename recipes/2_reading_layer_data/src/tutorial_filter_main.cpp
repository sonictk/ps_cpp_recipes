#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <Windows.h>
#include <stdio.h>

#include <PIDefines.h>
#include <PIAbout.h>
#include <PIFilter.h>
#include <SPBasic.h>

#include <PIUSuites.cpp>

#include "libps_globals.h"
#include "libps_math.cpp"
#include "libps_pixel.cpp"

#define STB_IMAGE_IMPLEMENTATION
#define STBI_MSC_SECURE_CRT
#define STB_IMAGE_WRITE_IMPLEMENTATION
#define STB_JPG_WRITE_QUALITY_LEVEL 100

#include <stb/stb_image_write.h>


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


void readPSChannelDataIntoBuffer(const ReadChannelDesc *chn, uint8_t *buf, const int bufWidth, int *bytesRead)
{
	int tileHeight = chn->tileSize.v;
	int tileWidth = chn->tileSize.h;

	int chnHeight = chn->bounds.bottom - chn->bounds.top;
	int chnWidth = chn->bounds.right - chn->bounds.left;
	int numTilesVert = (tileHeight - 1 + chnHeight) / tileHeight;
	int numTilesHoriz = (tileWidth - 1 + chnWidth) / tileWidth;
	int chnSize = tileWidth * tileHeight * chn->depth / 8;
	int numTiles = numTilesVert * numTilesHoriz;

	// NOTE: (sonictk) Iterate over each "tile" in the channel data and store it in the
	// buffer that we've allocated, in a bottom-up, left-right fashion.
	int totalBytesRead = 0;
	VRect curRect;

	int curX = 0;
	int curY = 0;
	for (int vertTile = 0; vertTile < numTilesVert; ++vertTile) {
		for (int horizTile = 0; horizTile < numTilesHoriz; ++horizTile) {
			curY = tileHeight * vertTile;

			PixelMemoryDesc pxMemDesc;
			// NOTE: (sonictk) We use the Photoshop API for getting a buffer, since all the
			// convenience functionality for reading from the buffer is built around it.
			pxMemDesc.data = sPSBuffer->New(NULL, chnSize);
			pxMemDesc.colBits = chn->depth;
			pxMemDesc.bitOffset = 0;
			pxMemDesc.depth = chn->depth;

			curRect.top = vertTile * tileHeight;
			curRect.left = horizTile * tileWidth;
			curRect.bottom = curRect.top + tileHeight;
			curRect.right = curRect.left + tileWidth;

			// NOTE: (sonictk) Clamp to the document boundaries, since the document
			// size may not be a multiple of the tile sizes.
			if (curRect.bottom > chnHeight) {
				curRect.bottom = chnHeight;
			}
			if (curRect.right > chnWidth) {
				curRect.right = chnWidth;
			}

			pxMemDesc.rowBits = (curRect.right - curRect.left) * chn->depth;
			int stride = pxMemDesc.rowBits / PS_NUM_OF_BITS_IN_ONE_BYTE;
			// NOTE: (sonictk) I wish there was a way to avoid having to use their buffer for this.
			// Would reduce the amount of allocations required and copying memory around.
			sPSChannelProcs->ReadPixelsFromLevel(chn->port, 0, &curRect, &pxMemDesc);

			// NOTE: (sonictk) Check how many bytes were _actually_ read, since the tile
			// size can vary.
			int curRectWidth = curRect.right - curRect.left;
			// NOTE: (sonictk) All horizontal tiles in the same row will have the same height.
			int curRectHeight = curRect.bottom - curRect.top;

			int numBytesRead = curRectWidth * curRectHeight * (chn->depth / PS_NUM_OF_BITS_IN_ONE_BYTE);

			// NOTE: (sonictk) For the current tile, copy its pixel data to the appropriate location
			// in the larger "combined" pixel buffer of all the tiles.
			for (int h=0; h < curRectHeight; ++h) {
				memcpy(&buf[(curY * bufWidth) + curX],
					   &((uint8_t *)(pxMemDesc.data))[curRectWidth * h],
					   curRectWidth * sizeof(uint8_t));
				curY++;
			}

			totalBytesRead += numBytesRead;

			sPSBuffer->Dispose((Ptr *)&pxMemDesc.data);

			curX = (curX + curRectWidth) % bufWidth;
		}
	}

	*bytesRead = totalBytesRead;

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

	int chnHeight = rChn->bounds.bottom - rChn->bounds.top;
	int chnWidth = rChn->bounds.right - rChn->bounds.left;
	int numTilesVert = (tileHeight - 1 + chnHeight) / tileHeight;
	int numTilesHoriz = (tileWidth - 1 + chnWidth) / tileWidth;
	int chnSize = tileWidth * tileHeight * rChn->depth / 8;

	int numTiles = numTilesVert * numTilesHoriz;
	int counter = 0;

	int rgbBufSize = chnSize * numTiles * 3 * sizeof(uint8_t);
	uint8_t *rgbPxDataPlanar = (uint8_t *)malloc(rgbBufSize);

	int bytesRead = 0;
	readPSChannelDataIntoBuffer(rChn, rgbPxDataPlanar, chnWidth, &bytesRead);

	int totalBytesRead = bytesRead;
	readPSChannelDataIntoBuffer(gChn, rgbPxDataPlanar + totalBytesRead, chnWidth, &bytesRead);

	totalBytesRead += bytesRead;
	readPSChannelDataIntoBuffer(bChn, rgbPxDataPlanar + totalBytesRead, chnWidth, &bytesRead);

	uint8_t *rgbPxDataPixel = (uint8_t *)malloc(rgbBufSize);
	convertPlanarToPixelRGB(rgbPxDataPixel, rgbPxDataPlanar, chnWidth, chnHeight, rChn->depth / 8);

	stbi_write_jpg(jpgPath,
				   chnWidth,
				   chnHeight,
				   3,
				   rgbPxDataPixel,
				   100);

	free(rgbPxDataPlanar);
	free(rgbPxDataPixel);

	return;
}


void executeFilter(const FilterRecordPtr &filterRecord)
{
	ReadImageDocumentDesc *docInfo = filterRecord->documentInfo;
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
		int lenPath = snprintf(NULL, 0, "%s%c%s.jpg", tempDirPath, OS_PATH_SEP, layerName);
		snprintf(outPath, lenPath + 1, "%s%c%s.jpg", tempDirPath, OS_PATH_SEP, layerName);

		// NOTE: (sonictk) Read image pixels and write the output jpg.
		ReadChannelDesc *rChn = NULL;
		ReadChannelDesc *gChn = NULL;
		ReadChannelDesc *bChn = NULL;
		findRGBChannelsForLayer(layerDesc, &rChn, &gChn, &bChn);

		int chnWidth = rChn->bounds.right - rChn->bounds.left;
		int chnHeight = rChn->bounds.bottom - rChn->bounds.top;

		writeRGBChannelsToJPG(rChn, gChn, bChn, outPath, chnWidth, chnHeight);

		filterRecord->progressProc(progressCounter, progressTotal);
		// NOTE: (sonictk) If the user requested an interrupt, exit early and stop processing.
		if (filterRecord->abortProc()) {
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

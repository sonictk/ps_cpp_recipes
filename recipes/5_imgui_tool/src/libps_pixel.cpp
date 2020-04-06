#include "libps_pixel.h"


void convertPlanarToPixelRGB(uint8_t *dest, const uint8_t *const src, const int width, const int height, const int bytesPerChannel)
{
	int numPixels = width * height;
	int curPixelIdx = 0;
	int i = 0;
	for (; i < (numPixels * 3); i+=3) {
		for (int chn=0; chn < 3; ++chn) {
			// NOTE: (sonictk) Since we're writing out 8bits-per-channel for thumbnails,
			// need to remap any 16-bit values down to size.
			switch (bytesPerChannel) {
			case 1:
				dest[i + chn] = src[(curPixelIdx * bytesPerChannel) + (numPixels * chn * bytesPerChannel)];
				break;
			case 2:
			{
				uint16_t *buffer16 = (uint16_t *)src;
				uint16_t curVal = buffer16[curPixelIdx + (numPixels * chn)];
				uint8_t remappedVal = remapValue(curVal);
				dest[i + chn] = remappedVal;
				break;
			}
			case 4:
			{
				uint32_t *buffer32 = (uint32_t *)src;
				uint32_t curVal = buffer32[curPixelIdx + (numPixels * chn)];
				uint8_t remappedVal = remapValue(curVal);
				dest[i + chn] = remappedVal;
				break;
			}
			default:
				return;
			}
		}
		++curPixelIdx;
	}

	return;
}

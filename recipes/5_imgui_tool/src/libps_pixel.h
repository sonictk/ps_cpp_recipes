#ifndef LIBPS_PIXEL_H
#define LIBPS_PIXEL_H


/**
 * Converts image data in planar form (RRR ... GGG ... BBB ...) to pixel form (RGB ...), along with remapping
 * it down to 8 bits per component. The difference between this and ``convertPlanarToPixel`` is that any additional
 * channels other than the first 3, which are assumed to be RGB, will be dropped in the final output buffer.
 *
 *
 * @param dest					The target buffer to write the converted data to.
 * @param src					The source buffer to read the planar data from.
 * @param width				The width of the image data in pixels.
 * @param height				The height of the image data in pixels.
 * @param bytesPerChannel		The number of bytes per channel component in the image data.
 *
 * @return 					A status code.
 */
void convertPlanarToPixelRGB(uint8_t *dest, const uint8_t *const src, const int width, const int height, const int bytesPerChannel);


#endif /* LIBPS_PIXEL_H */

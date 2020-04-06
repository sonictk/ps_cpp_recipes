#include "libps_math.h"
#include <float.h>

bool isEqual(float a, float b, float epsilon)
{
	if (fabs(a - b) < epsilon) {
		return true;
	} else {
		return false;
	}
}

bool isEqual(float a, float b)
{
	return isEqual(a, b, FLT_EPSILON);
}

bool isEqual(double a, double b, float epsilon)
{
	if (fabs(a - b) < epsilon) {
		return true;
	} else {
		return false;
	}
}

bool isEqual(double a, double b)
{
	return isEqual(a, b, FLT_EPSILON);
}


float lerp(float a, float b, float t)
{
	float result = ((1.0f - t) * a) + (t * b);

	return result;
}

double lerp(double a, double b, double t)
{
	double result = ((1.0 - t) * a) + (t * b);

	return result;
}

float lerp(int a, int b, float t)
{
	float result = ((1.0f - t) * (float)a) + (t * (float)b);

	return result;
}

float lerp(unsigned int a, unsigned int b, float t)
{
	float result = ((1.0f - t) * (float)a) + (t * (float)b);

	return result;
}


int clamp(int val, int min, int max)
{
	int result = val;

	if (val < min) {
		result = min;
	} else if (val > max) {
		result = max;
	}

	return result;
}

unsigned int clamp(unsigned int val, unsigned int min, unsigned int max)
{
	unsigned int result = val;

	if (val < min) {
		result = min;
	} else if (val > max) {
		result = max;
	}

	return result;
}

float clamp(float val, float min, float max)
{
	float result = val;

	if (val < min) {
		result = min;
	} else if (val > max) {
		result = max;
	}

	return result;
}

double clamp(double val, double min, double max)
{
	double result = val;

	if (val < min) {
		result = min;
	} else if (val > max) {
		result = max;
	}

	return result;
}


float unlerp(float val, float min, float max)
{
	return (val - min) / (max - min);
}

double unlerp(double val, double min, double max)
{
	return (val - min) / (max - min);
}


uint8_t remapValue(const uint16_t &val)
{
	uint32_t valTypeRange = (uint32_t)(powf(2.0f, (float)(sizeof(uint16_t) * PS_NUM_OF_BITS_IN_ONE_BYTE) - 1));
	uint32_t destTypeRange = (uint32_t)(powf(2.0f, (float)(sizeof(uint8_t) * PS_NUM_OF_BITS_IN_ONE_BYTE) - 1));
	float factor = (float)destTypeRange / (float)valTypeRange;
	uint8_t result = (uint8_t)(factor * (float)val);

	return result;
}


uint8_t remapValue(const uint32_t &val)
{
	uint64_t valTypeRange = (uint64_t)(pow(2.0f, (float)(sizeof(uint32_t) * PS_NUM_OF_BITS_IN_ONE_BYTE) - 1));
	uint64_t destTypeRange = (uint64_t)(pow(2.0f, (float)(sizeof(uint8_t) * PS_NUM_OF_BITS_IN_ONE_BYTE) - 1));
	double factor = (double)destTypeRange / (double)valTypeRange;
	uint8_t result = (uint8_t)(factor * (double)val);

	return result;
}

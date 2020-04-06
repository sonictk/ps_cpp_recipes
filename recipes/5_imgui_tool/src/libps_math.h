#ifndef LIBPS_MATH_H
#define LIBPS_MATH_H


#include <math.h>

#define PI 3.14159265359f
#define DEG_TO_RAD 0.01745329251994f
#define RAD_TO_DEG 57.2957795130f
#define TAU 6.28318530717958647692f


/**
 * This function checks if the two given floating-point numbers are equal within a
 * given tolerance.
 *
 * @param a			The first number.
 * @param b			The second number.
 * @param epsilon	The tolerance.
 *
 * @return			``true`` if the numbers are equal, ``false`` otherwise.
 */
bool isEqual(float a, float b, float epsilon);

/// @overload
bool isEqual(float a, float b);

/// @overload
bool isEqual(double a, double b, float epsilon);

/// @overload
bool isEqual(double a, double b);


/**
 * Linearly interpolate between ``a`` and ``b`` by factor ``t``.
 *
 * @param a 	The first value.
 * @param b 	The second value.
 * @param t 	The interpolation factor.
 *
 * @return 	The interpolated value.
 */
float lerp(float a, float b, float t);

/// @overload
double lerp(double a, double b, double t);

/// @overload
float lerp(int a, int b, float t);

/// @overload
float lerp(unsigned int a, unsigned int b, float t);


/**
 * Clamps the given ``val`` to between the given ``min`` and ``max`` limits.
 *
 * @param val 	The value to clamp.
 * @param min 	The lower bound.
 * @param max 	The upper bound.
 *
 * @return 	The clamped value.
 */
int clamp(int val, int min, int max);

/// @overload
unsigned int clamp(unsigned int val, unsigned int min, unsigned int max);

/// @overload
float clamp(float val, float min, float max);

/// @overload
double clamp(double val, double min, double max);


/**
 * Calculates the linear parameter that produces the interpolant ``val`` within the
 * range ``[min, max]``.
 *
 * @param val		The interpolant.
 * @param min		The minimum value of the range.
 * @param max		The maximum value of the range.
 *
 * @return			The linear parameter.
 */
float unlerp(float val, float min, float max);

double unlerp(double val, double min, double max);


/**
 * Linearly interpolate between ``a`` and ``b`` by factor ``t``. The type provided
 * must support the ``*`` and assignment operands.
 * NOTE: This is precise (guarantees result is ``v1`` when t = 1).
 *
 * @param a 	The first value.
 * @param b 	The second value.
 * @param t 	The interpolation factor.
 *
 * @return 	The interpolated value.
 */
template<typename T>
inline T lerp(T a, T b, float factor)
{
	T result = static_cast<T>(((1.0f - factor) * a) + (factor * b));

	return result;
}


/**
 * Linearly interpolate between ``a`` and ``b`` by factor ``t``. The type provided
 * must support the ``*`` and assignment operands.
 * NOTE: ``qlerp`` stands for quicklerp; this is imprecise and does not guarantee
 * result is ``v1`` when ``t`` is ``1``,
 * due to floating-point error.
 * May be used when the hardware has a FMA instruction.
 *
 * @param a 	The first value.
 * @param b 	The second value.
 * @param t 	The interpolation factor.
 *
 * @return 	The interpolated value.
 */
template<typename T>
inline T qlerp(T a, T b, float factor)
{
	T result = a + (factor * (b - a));

	return result;
}


/**
 * Clamps the given ``val`` to between the given ``min`` and ``max`` limits.
 * The type provided must support the ``<``, ``>`` and assignment operands.
 *
 * @param val 	The value to clamp.
 * @param min 	The lower bound.
 * @param max 	The upper bound.
 *
 * @return 	The clamped value.
 */
template<typename T>
inline T clamp(T val, T min, T max)
{
	T result = val;

	if (val < min) {
		result = min;
	} else if (val > max) {
		result = max;
	}

	return result;
}


uint8_t remapValue(const uint16_t &val);

uint8_t remapValue(const uint32_t &val);

template <typename To, typename From>
inline To remapValue(const From &val)
{
	uint64_t valTypeRange = pow(2, sizeof(From) * LIBPSD_NUM_OF_BITS_IN_ONE_BYTE) - 1;
	uint64_t destTypeRange = pow(2, sizeof(To) * LIBPSD_NUM_OF_BITS_IN_ONE_BYTE) - 1;
	double factor = static_cast<double>(destTypeRange) / static_cast<double>(valTypeRange);
	To result = static_cast<To>(factor * (double)val);

	return result;
}


#endif /* LIBPS_MATH_H */

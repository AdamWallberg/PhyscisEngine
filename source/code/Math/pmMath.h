#pragma once

#include <math.h>



// Returns the square root of the specified value.
inline float pmSqrt( const float& value )
{
	return static_cast<float>( sqrt( value ) );
}



// Returns pow of the specified base
inline float pmPow( const float& base, const float& exponent )
{
	return static_cast<float>( pow( base, exponent ) );
}



// Calculates and returns the absolute 
// value of the specified float.
inline float pmAbs( const float& value )
{
	if( value < 0.f )
		return -value;
	else
		return value;
}



// Clamps the specified value between the specified 
// min and max values, and returns the result.
inline float pmClamp( const float& value, const float& min, const float& max )
{
	if( value <= min )
		return min;
	else if( value >= max )
		return max;

	return value;
}



// Clamps the specified value between 0 and 1 
// and returns the result.
inline float pmSaturate( float value )
{
	if( value <= 0.f )
		return 0.f;
	else if( value >= 1.f )
		return 1.f;

	return value;
}



// Converts degrees to radians.
// Uses only multiplication with const value to optimize performance.
inline float pmToRadians( const float& degrees )
{
	return degrees * 0.0174532925f;
}



// Converts radians to degrees.
// Uses only multiplication with const value to optimize performance.
inline float pmToDegrees( const float& radians )
{
	return radians * 57.2957795f;
}



// Returns sine from degrees.
inline float pmSin( const float& degrees )
{
	return static_cast<float>( sin( pmToRadians( degrees ) ) );
}



// Returns asin
inline float pmASin( const float& sin )
{
	return pmToDegrees( static_cast<float>( asin( sin ) ) );
}



// Returns cosine from degrees.
inline float pmCos( const float& degrees )
{
	return static_cast<float>( cos( pmToRadians( degrees ) ) );
}



// Returns acos
inline float pmACos( const float& cos )
{
	return pmToDegrees( static_cast<float>( acos( cos ) ) );
}



// Returns tangent from degrees.
inline float pmTan( const float& degrees )
{
	return static_cast<float>( tan( pmToRadians( degrees ) ) );
}


// Returns atan
inline float pmATan( const float& tan )
{
	return pmToDegrees( static_cast<float>( atan( tan ) ) );
}



// Interpolates between two values using a factor.
// factor 0 is no interpolation and factor 1 is full.
// The interpolation can go outside range, both positive and negative.
inline float pmLerp( const float& start, const float& end, const float& factor )
{
	return start + ( end - start ) * factor;
}



// Cosine interpolates between the two given values using the factor.
inline float pmInterpolateCos( const float& start, const float& end, const float& factor )
{
	return start + ( end - start ) * ( ( -pmCos( factor * 180.0f ) + 1.0f ) * 0.5f );
}
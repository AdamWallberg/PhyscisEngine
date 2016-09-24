#pragma once


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
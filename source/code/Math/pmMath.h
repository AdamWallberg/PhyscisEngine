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
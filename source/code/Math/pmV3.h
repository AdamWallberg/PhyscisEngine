#pragma once

#include <string>

#include "pmMath.h"
#include "pmV2.h"


class pmV3
{
public:

	// Constructors / Destructor
	pmV3( const float& x = 0.0f, const float& y = 0.0f, const float& z = 0.0f );
	pmV3( const pmV3& rOther );

	~pmV3();

	// Static instances
	static const pmV3 zero;

	static const pmV3 posx;
	static const pmV3 negx;

	static const pmV3 posy;
	static const pmV3 negy;

	static const pmV3 posz;
	static const pmV3 negz;

	// Member variables
	union
	{
		struct
		{
			float x;
			float y;
			float z;
		};

		pmV2 xy;
	};

////////////////////////////////////////////////////////////////

	// Methods

	// Performance heavy, use lengthSquared() when possible.
	inline const float length() const
	{
		return pmSqrt( lengthSquared() );

	} // length

	const float lengthSquared() const
	{
		return x * x + y * y + z * z;

	} // lengthSquared

	// Returns a normalized version of this vector. 
	// normalize() automatically calculates the length
	// of the vector, which can be stored in a float pointer.
	inline const pmV3 normalize( float* pOutLength = nullptr ) const
	{
		pmV3 out;
		const float length = this->length();

		// return length if pointer is given
		if (pOutLength)
			*pOutLength = length;

		// Don't divide by zero
		if (length != 0.0f)
		{
			out.x = x / length;
			out.y = y / length;
			out.z = z / length;
		}

		return out;

	} // normalize

	// Dot product methods
	inline const float dot( const pmV3& rOther ) const
	{
		return x * rOther.x + y * rOther.y + z * rOther.z;

	} // dot

	// Cross product methods
	inline const pmV3 cross( const pmV3& in ) const
	{
		return pmV3( y * in.z - in.y * z, z * in.x - in.z * x, x * in.y - in.x * y );

	} // cross

	// String conversion
	inline const std::string toString()
	{
		return "x: " + std::to_string( x ) + " y: " + std::to_string( y ) + " z: " + std::to_string( z );

	} // toString

////////////////////////////////////////////////////////////////

	// Addition operators
	const pmV3 operator + ( const pmV3& in ) const;
	const pmV3 operator + ( const float in ) const;
	void operator += ( const pmV3& in );
	void operator += ( const float in );

	// Subtraction operators
	const pmV3 operator - ( const pmV3& in ) const;
	const pmV3 operator - ( const float in ) const;
	void operator -= ( const pmV3& in );
	void operator -= ( const float in );

	// Multiplication
	const pmV3 operator * ( const pmV3& in ) const;
	const pmV3 operator * ( const float in ) const;
	void operator *= ( const pmV3& in );
	void operator *= ( const float in );

	// Division operators
	const pmV3 operator / ( const pmV3& in ) const;
	const pmV3 operator / ( const float in ) const;
	void operator /= ( const pmV3& in );
	void operator /= ( const float in );

	// Comparison operators
	bool operator == ( const pmV3& in ) const;
	bool operator != ( const pmV3& in ) const;

};
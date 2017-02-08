#pragma once

#include <string>

#include "pmMath.h"
#include "pmV2.h"
#include "pmV3.h"

class pmV4
{
public:

	// Constructors / Destructor
	pmV4( const float& x = 0.0f, const float& y = 0.0f, const float& z = 0.0f, const float& w = 0.0f );
	pmV4( const pmV4& rOther );

	~pmV4();

	// Static instances
	static const pmV4 zero;

	static const pmV4 posx;
	static const pmV4 negx;

	static const pmV4 posy;
	static const pmV4 negy;

	static const pmV4 posz;
	static const pmV4 negz;

	static const pmV4 posw;
	static const pmV4 negw;

	// Color constants
	static const pmV4 white;
	static const pmV4 black;
	static const pmV4 gray;
	static const pmV4 red;
	static const pmV4 green;
	static const pmV4 blue;
	static const pmV4 magenta;
	static const pmV4 yellow;
	static const pmV4 turquoise;

	// Member variables
	union
	{
		struct
		{
			float x;
			float y;
			float z;
			float w;
		};
		pmV2 xy;
		pmV3 xyz;
		struct
		{
			float r;
			float g;
			float b;
			float a;
		};
		pmV2 rg;
		pmV3 rgb;
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
		return x * x + y * y + z * z + w * w;

	} // lengthSquared

	// Returns a normalized version of this vector. 
	// normalize() automatically calculates the length
	// of the vector, which can be stored in a float pointer.
	inline const pmV4 normalize( float* pOutLength = nullptr ) const
	{
		pmV4 out;
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
			out.w = w / length;
		}

		return out;

	} // normalize

	// Dot product methods
	inline const float& dot( const pmV4& rOther ) const
	{
		return x * rOther.x + y * rOther.y + z * rOther.z + w * rOther.w;

	} // dot

	// String conversion
	inline const std::string toString()
	{
		return "x: " + std::to_string( x ) + " y: " + std::to_string( y ) + " z: " + std::to_string( z )+ " w: " + std::to_string( w );

	} // toString

////////////////////////////////////////////////////////////////

	// Addition operators
	const pmV4 operator + ( const pmV4& in ) const;
	const pmV4 operator + ( const float in ) const;
	void operator += ( const pmV4& in );
	void operator += ( const float in );

	// Subtraction operators
	const pmV4 operator - ( const pmV4& in ) const;
	const pmV4 operator - ( const float in ) const;
	void operator -= ( const pmV4& in );
	void operator -= ( const float in );

	// Multiplication
	const pmV4 operator * ( const pmV4& in ) const;
	const pmV4 operator * ( const float in ) const;
	void operator *= ( const pmV4& in );
	void operator *= ( const float in );

	// Division operators
	const pmV4 operator / ( const pmV4& in ) const;
	const pmV4 operator / ( const float in ) const;
	void operator /= ( const pmV4& in );
	void operator /= ( const float in );

	// Comparison operators
	bool operator == ( const pmV4& in ) const ;
	bool operator != ( const pmV4& in ) const;

};
#pragma once

#include <string>

#include "pmMath.h"


class pmV2
{
public:

	// Constructors / Destructor
	pmV2( const float& x = 0.0f, const float& y = 0.0f );
	pmV2( const pmV2& rOther );

	~pmV2();

	// Static instances
	static const pmV2 zero;
					
	static const pmV2 posx;
	static const pmV2 negx;
					
	static const pmV2 posy;
	static const pmV2 negy;

	// Member variables
	union
	{
		struct
		{
			float x;
			float y;
		};
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
		return x * x + y * y;

	} // lengthSquared

	// Returns a normalized version of this vector. 
	// normalize() automatically calculates the length
	// of the vector, which can be stored in a float pointer.
	inline const pmV2 normalize( float* pOutLength = nullptr ) const
	{
		pmV2 out;
		const float length = this->length();

		// return length if pointer is given
		if (pOutLength)
			*pOutLength = length;

		// Don't divide by zero
		if (length != 0.0f)
		{
			out.x = x / length;
			out.y = y / length;
		}

		return out;

	} // normalize

	// Dot product methods
	inline const float& dot( const pmV2& rOther ) const
	{
		return x * rOther.x + y * rOther.y;

	} // dot

	// String conversion
	inline const std::string toString()
	{
		return "x: " + std::to_string( x ) + " y: " + std::to_string( y );

	} // toString

////////////////////////////////////////////////////////////////

	// Addition operators
	const pmV2 operator + ( const pmV2& in ) const;
	const pmV2 operator + ( const float in ) const;
	void operator += ( const pmV2& in );
	void operator += ( const float in );

	// Subtraction operators
	const pmV2 operator - ( const pmV2& in ) const;
	const pmV2 operator - ( const float in ) const;
	void operator -= ( const pmV2& in );
	void operator -= ( const float in );

	// Multiplication
	const pmV2 operator * ( const pmV2& in ) const;
	const pmV2 operator * ( const float in ) const;
	void operator *= ( const pmV2& in );
	void operator *= ( const float in );

	// Division operators
	const pmV2 operator / ( const pmV2& in ) const;
	const pmV2 operator / ( const float in ) const;
	void operator /= ( const pmV2& in );
	void operator /= ( const float in );

	// Comparison operators
	bool operator == ( const pmV2& in ) const ;
	bool operator != ( const pmV2& in ) const;

};
#include "phSystem.h"

#include "pmMat4.h"

pmMat4::pmMat4()
{
	// Set all elements to 0
	memset( elements, 0, 16 * sizeof(float) );
}



pmMat4::pmMat4( const pmMat4& other )
{
	for( uint8 i = 0; i < 16; i++ )
	{
		elements[i] = other.elements[i];
	}
}



pmMat4::pmMat4( const float diagonal )
{
	// Set all elements to 0
	memset( elements, 0, 16 * sizeof(float) );

	// Set the diagonal
	for( unsigned char i = 0; i < 4; ++i )
	{
		elements[ i + i * 4 ] = diagonal;
	}
}



pmMat4::~pmMat4()
{
}



void pmMat4::Translate( const pmV3& translation )
{
	this->translation = translation;
}



void pmMat4::Rotate( float angle, const pmV3& axis )
{
	float r = pmToRadians( angle );
	float c = pmCos( r );
	float s = pmSin( r );
	float omc = 1.0f - c;

	float x = axis.x;
	float y = axis.y;
	float z = axis.z;

	elements[ 0 + 0 * 4 ] = x * omc + c;
	elements[ 0 + 1 * 4 ] = y * x * omc + z * s;
	elements[ 0 + 2 * 4 ] = x * z * omc - y * s;

	elements[ 1 + 0 * 4 ] = x * y * omc - z * s;
	elements[ 1 + 1 * 4 ] = y * omc + c;
	elements[ 1 + 2 * 4 ] = y * z * omc + x * s;

	elements[ 2 + 0 * 4 ] = x * z * omc + y * s;
	elements[ 2 + 1 * 4 ] = y * z * omc - x * s;
	elements[ 2 + 2 * 4 ] = z * omc + c;
}



void pmMat4::Scale( const pmV3& scale )
{
	elements[ 0 + 0 * 4 ] = scale.x;
	elements[ 1 + 1 * 4 ] = scale.y;
	elements[ 2 + 2 * 4 ] = scale.z;
}



const pmMat4& pmMat4::operator*( const pmMat4& other )
{
	pmMat4 result;
	float sum;
	for( uint8 row = 0; row < 4; ++row )
	{
		for( uint8 col = 0; col < 4; ++col )
		{
			sum = 0.0f;
			for( uint8 i = 0; i < 4; ++i )
			{
				sum += elements[ i + row * 4 ] * other.elements[ col + i * 4 ];
			}
			result.elements[ col + row * 4 ] = sum;
		}
	}

	return result;
}


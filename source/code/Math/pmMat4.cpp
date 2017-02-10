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
	this->translation += translation;
}


void pmMat4::Rotate( const pmV3& axis )
{
	pmMat4 rot(1);

	float cx = pmCos( axis.x );
	float sx = pmSin( axis.x );
	float cy = pmCos( axis.y );
	float sy = pmSin( axis.y );
	float cz = pmCos( axis.z );
	float sz = pmSin( axis.z );

	rot.left.x = cy * cz;
	rot.left.y = sx * sy * cz + cx * sz;
	rot.left.z = -cx * sy * cz + sx * sz;

	rot.up.x = -cy * sz;
	rot.up.y = -sx * sy + cx * cz;
	rot.up.z = cx * sy * sz + sx * cz;

	rot.forward.x = sy;
	rot.forward.y = -sx * cy;
	rot.forward.z = cx * cy;

	*this = rot * *this;
}



void pmMat4::Scale( const pmV3& scale )
{
	elements[ 0 + 0 * 4 ] = scale.x;
	elements[ 1 + 1 * 4 ] = scale.y;
	elements[ 2 + 2 * 4 ] = scale.z;
}



pmMat4 pmMat4::GetInverse() const
{
	float temp[ 16 ];

	temp[ 0 ] = elements[ 5 ] * elements[ 10 ] * elements[ 15 ] -
		elements[ 5 ] * elements[ 11 ] * elements[ 14 ] -
		elements[ 9 ] * elements[ 6 ] * elements[ 15 ] +
		elements[ 9 ] * elements[ 7 ] * elements[ 14 ] +
		elements[ 13 ] * elements[ 6 ] * elements[ 11 ] -
		elements[ 13 ] * elements[ 7 ] * elements[ 10 ];

	temp[ 4 ] = -elements[ 4 ] * elements[ 10 ] * elements[ 15 ] +
		elements[ 4 ] * elements[ 11 ] * elements[ 14 ] +
		elements[ 8 ] * elements[ 6 ] * elements[ 15 ] -
		elements[ 8 ] * elements[ 7 ] * elements[ 14 ] -
		elements[ 12 ] * elements[ 6 ] * elements[ 11 ] +
		elements[ 12 ] * elements[ 7 ] * elements[ 10 ];

	temp[ 8 ] = elements[ 4 ] * elements[ 9 ] * elements[ 15 ] -
		elements[ 4 ] * elements[ 11 ] * elements[ 13 ] -
		elements[ 8 ] * elements[ 5 ] * elements[ 15 ] +
		elements[ 8 ] * elements[ 7 ] * elements[ 13 ] +
		elements[ 12 ] * elements[ 5 ] * elements[ 11 ] -
		elements[ 12 ] * elements[ 7 ] * elements[ 9 ];

	temp[ 12 ] = -elements[ 4 ] * elements[ 9 ] * elements[ 14 ] +
		elements[ 4 ] * elements[ 10 ] * elements[ 13 ] +
		elements[ 8 ] * elements[ 5 ] * elements[ 14 ] -
		elements[ 8 ] * elements[ 6 ] * elements[ 13 ] -
		elements[ 12 ] * elements[ 5 ] * elements[ 10 ] +
		elements[ 12 ] * elements[ 6 ] * elements[ 9 ];

	temp[ 1 ] = -elements[ 1 ] * elements[ 10 ] * elements[ 15 ] +
		elements[ 1 ] * elements[ 11 ] * elements[ 14 ] +
		elements[ 9 ] * elements[ 2 ] * elements[ 15 ] -
		elements[ 9 ] * elements[ 3 ] * elements[ 14 ] -
		elements[ 13 ] * elements[ 2 ] * elements[ 11 ] +
		elements[ 13 ] * elements[ 3 ] * elements[ 10 ];

	temp[ 5 ] = elements[ 0 ] * elements[ 10 ] * elements[ 15 ] -
		elements[ 0 ] * elements[ 11 ] * elements[ 14 ] -
		elements[ 8 ] * elements[ 2 ] * elements[ 15 ] +
		elements[ 8 ] * elements[ 3 ] * elements[ 14 ] +
		elements[ 12 ] * elements[ 2 ] * elements[ 11 ] -
		elements[ 12 ] * elements[ 3 ] * elements[ 10 ];

	temp[ 9 ] = -elements[ 0 ] * elements[ 9 ] * elements[ 15 ] +
		elements[ 0 ] * elements[ 11 ] * elements[ 13 ] +
		elements[ 8 ] * elements[ 1 ] * elements[ 15 ] -
		elements[ 8 ] * elements[ 3 ] * elements[ 13 ] -
		elements[ 12 ] * elements[ 1 ] * elements[ 11 ] +
		elements[ 12 ] * elements[ 3 ] * elements[ 9 ];

	temp[ 13 ] = elements[ 0 ] * elements[ 9 ] * elements[ 14 ] -
		elements[ 0 ] * elements[ 10 ] * elements[ 13 ] -
		elements[ 8 ] * elements[ 1 ] * elements[ 14 ] +
		elements[ 8 ] * elements[ 2 ] * elements[ 13 ] +
		elements[ 12 ] * elements[ 1 ] * elements[ 10 ] -
		elements[ 12 ] * elements[ 2 ] * elements[ 9 ];

	temp[ 2 ] = elements[ 1 ] * elements[ 6 ] * elements[ 15 ] -
		elements[ 1 ] * elements[ 7 ] * elements[ 14 ] -
		elements[ 5 ] * elements[ 2 ] * elements[ 15 ] +
		elements[ 5 ] * elements[ 3 ] * elements[ 14 ] +
		elements[ 13 ] * elements[ 2 ] * elements[ 7 ] -
		elements[ 13 ] * elements[ 3 ] * elements[ 6 ];

	temp[ 6 ] = -elements[ 0 ] * elements[ 6 ] * elements[ 15 ] +
		elements[ 0 ] * elements[ 7 ] * elements[ 14 ] +
		elements[ 4 ] * elements[ 2 ] * elements[ 15 ] -
		elements[ 4 ] * elements[ 3 ] * elements[ 14 ] -
		elements[ 12 ] * elements[ 2 ] * elements[ 7 ] +
		elements[ 12 ] * elements[ 3 ] * elements[ 6 ];

	temp[ 10 ] = elements[ 0 ] * elements[ 5 ] * elements[ 15 ] -
		elements[ 0 ] * elements[ 7 ] * elements[ 13 ] -
		elements[ 4 ] * elements[ 1 ] * elements[ 15 ] +
		elements[ 4 ] * elements[ 3 ] * elements[ 13 ] +
		elements[ 12 ] * elements[ 1 ] * elements[ 7 ] -
		elements[ 12 ] * elements[ 3 ] * elements[ 5 ];

	temp[ 14 ] = -elements[ 0 ] * elements[ 5 ] * elements[ 14 ] +
		elements[ 0 ] * elements[ 6 ] * elements[ 13 ] +
		elements[ 4 ] * elements[ 1 ] * elements[ 14 ] -
		elements[ 4 ] * elements[ 2 ] * elements[ 13 ] -
		elements[ 12 ] * elements[ 1 ] * elements[ 6 ] +
		elements[ 12 ] * elements[ 2 ] * elements[ 5 ];

	temp[ 3 ] = -elements[ 1 ] * elements[ 6 ] * elements[ 11 ] +
		elements[ 1 ] * elements[ 7 ] * elements[ 10 ] +
		elements[ 5 ] * elements[ 2 ] * elements[ 11 ] -
		elements[ 5 ] * elements[ 3 ] * elements[ 10 ] -
		elements[ 9 ] * elements[ 2 ] * elements[ 7 ] +
		elements[ 9 ] * elements[ 3 ] * elements[ 6 ];

	temp[ 7 ] = elements[ 0 ] * elements[ 6 ] * elements[ 11 ] -
		elements[ 0 ] * elements[ 7 ] * elements[ 10 ] -
		elements[ 4 ] * elements[ 2 ] * elements[ 11 ] +
		elements[ 4 ] * elements[ 3 ] * elements[ 10 ] +
		elements[ 8 ] * elements[ 2 ] * elements[ 7 ] -
		elements[ 8 ] * elements[ 3 ] * elements[ 6 ];

	temp[ 11 ] = -elements[ 0 ] * elements[ 5 ] * elements[ 11 ] +
		elements[ 0 ] * elements[ 7 ] * elements[ 9 ] +
		elements[ 4 ] * elements[ 1 ] * elements[ 11 ] -
		elements[ 4 ] * elements[ 3 ] * elements[ 9 ] -
		elements[ 8 ] * elements[ 1 ] * elements[ 7 ] +
		elements[ 8 ] * elements[ 3 ] * elements[ 5 ];

	temp[ 15 ] = elements[ 0 ] * elements[ 5 ] * elements[ 10 ] -
		elements[ 0 ] * elements[ 6 ] * elements[ 9 ] -
		elements[ 4 ] * elements[ 1 ] * elements[ 10 ] +
		elements[ 4 ] * elements[ 2 ] * elements[ 9 ] +
		elements[ 8 ] * elements[ 1 ] * elements[ 6 ] -
		elements[ 8 ] * elements[ 2 ] * elements[ 5 ];

	float determinant = elements[ 0 ] * temp[ 0 ] + elements[ 1 ] * temp[ 4 ] + elements[ 2 ] * temp[ 8 ] + elements[ 3 ] * temp[ 12 ];
	determinant = 1.0f / determinant;

	pmMat4 result(0.0f);

	for( uint8 i = 0; i < 4 * 4; i++ )
		result.elements[ i ] = temp[ i ] * determinant;

	return result;
}



pmMat4 pmMat4::Orthographic( float left, float right, float bottom, float top, float near, float far )
{
	pmMat4 result(1.0f);

	result.elements[0 + 0 * 4] = 2.0f / (right - left);
	result.elements[1 + 1 * 4] = 2.0f / (top - bottom);
	result.elements[2 + 2 * 4] = 2.0f / (near - far);

	result.elements[3 + 0 * 4] = (left + right) / (left - right);
	result.elements[3 + 1 * 4] = (bottom + top) / (bottom - top);
	result.elements[3 + 2 * 4] = (far + near) / (far - near);

	return result;
}



pmMat4 pmMat4::Perspective( float fov, float aspectRatio, float near, float far )
{
	pmMat4 result(0.0f);

	result.left.x = (1.0f / pmTan(fov * 0.5f)) / aspectRatio;
	result.up.y = 1.0f / pmTan(fov * 0.5f);
	result.forward.z = (near + far) / (near - far);
	result.translation.z = (2.0f * near * far) / (near - far);
	result.elements[11] = -1.0f;

	return result;
}



pmMat4 pmMat4::LookAt( const pmV3& position, const pmV3& target, const pmV3& up )
{
	pmMat4 result(1.0f);

	pmV3 f = (target - position).normalize();
	pmV3 s = f.cross(up.normalize());
	pmV3 u = s.cross(f);

	result.elements[0 + 0 * 4] = s.x;
	result.elements[0 + 1 * 4] = s.y;
	result.elements[0 + 2 * 4] = s.z;

	result.elements[1 + 0 * 4] = u.x;
	result.elements[1 + 1 * 4] = u.y;
	result.elements[1 + 2 * 4] = u.z;

	result.elements[2 + 0 * 4] = -f.x;
	result.elements[2 + 1 * 4] = -f.y;
	result.elements[2 + 2 * 4] = -f.z;

	result.Translate(pmV3::zero - position);

	return result;
}



pmMat4 pmMat4::operator*( const pmMat4& other )
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


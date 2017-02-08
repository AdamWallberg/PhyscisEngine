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
	// TODO: Do all of this in one matrix instead of 3
	float cx = pmCos(axis.x);
	float sx = pmSin(axis.x);
	float cy = pmCos(axis.y);
	float sy = pmSin(axis.y);
	float cz = pmCos(axis.z);
	float sz = pmSin(axis.z);
	
	pmMat4 rotx(1);
	rotx.up.y = cx;
	rotx.up.z = sx;
	rotx.forward.y = -sx;
	rotx.forward.z = cx;

	pmMat4 roty(1);
	roty.left.x = cy;
	roty.left.z = -sy;
	roty.forward.x = sy;
	roty.forward.z = cy;

	pmMat4 rotz(1);
	rotz.left.x = cz;
	rotz.left.y = sz;
	rotz.up.x = -sz;
	rotz.up.y = cz;

	*this = rotx * roty * rotz;
}



void pmMat4::Scale( const pmV3& scale )
{
	elements[ 0 + 0 * 4 ] = scale.x;
	elements[ 1 + 1 * 4 ] = scale.y;
	elements[ 2 + 2 * 4 ] = scale.z;
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
	pmMat4 result(1.0f);

	result.up.y = 1.0f / pmTan(fov * 0.5f);
	result.left.x = result.up.y / aspectRatio;
	result.elements[11] = -1.0f;
	result.forward.z = -(far + near) / (far - near);
	result.translation.z = -(2.0f * far * near) / (far - near);

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


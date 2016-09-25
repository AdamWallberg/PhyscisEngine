#include "Engine/phSystem.h"

#include "pmV3.h"



// Static const vectors
const pmV3 pmV3::zero = pmV3();
const pmV3 pmV3::posx = pmV3( 1.0f, 0.0f, 0.0f );
const pmV3 pmV3::negx = pmV3( -1.0f, 0.0f, 0.0f );
const pmV3 pmV3::posy = pmV3( 0.0f, 1.0f, 0.0f );
const pmV3 pmV3::negy = pmV3( 0.0f, -1.0f, 0.0f );
const pmV3 pmV3::posz = pmV3( 0.0f, 0.0f, 1.0f );
const pmV3 pmV3::negz = pmV3( 0.0f, 0.0f, -1.0f );



pmV3::pmV3( const float& x /*= 0.0f*/, const float& y /*= 0.0f*/, const float& z /*= 0.0f*/ )
{
	this->x = x;
	this->y = y;
	this->z = z;
} // pmV3



pmV3::pmV3( const pmV3& rOther )
{
	this->x = rOther.x;
	this->y = rOther.y;
	this->z = rOther.z;
} // pmV3



pmV3::~pmV3()
{
} // ~pmV3



const pmV3 pmV3::operator + ( const pmV3& in ) const
{
	return pmV3( x + in.x, y + in.y, z + in.z );

} // operator +

const pmV3 pmV3::operator + ( const float in ) const
{
	return pmV3( x + in, y + in, z + in );

} // operator +



void pmV3::operator += ( const pmV3& in )
{
	x += in.x;
	y += in.y;
	z += in.z;

} // operator +=

void pmV3::operator += ( const float in )
{
	x += in;
	y += in;
	z += in;

} // operator +=



const pmV3 pmV3::operator - ( const pmV3& in ) const
{
	return pmV3( x - in.x, y - in.y, z - in.z );

} // operator -

const pmV3 pmV3::operator - ( const float in ) const
{
	return pmV3( x - in, y - in, z - in );

} // operator -



void pmV3::operator -= ( const pmV3& in )
{
	x -= in.x;
	y -= in.y;
	z -= in.z;

} // operator -=

void pmV3::operator -= ( const float in )
{
	x -= in;
	y -= in;
	z -= in;

} // operator -=



const pmV3 pmV3::operator * ( const pmV3& in ) const
{
	return pmV3( x * in.x, y * in.y, z * in.z );

} // operator *

const pmV3 pmV3::operator * ( const float in ) const
{
	return pmV3( x * in, y * in, z * in );

} // operator *



void pmV3::operator *= ( const pmV3& in )
{
	x *= in.x;
	y *= in.y;
	z *= in.z;

} // operator *=

void pmV3::operator *= ( const float in )
{
	x *= in;
	y *= in;
	z *= in;

} // operator *=




const pmV3 pmV3::operator / ( const pmV3& in ) const
{
	return pmV3( x / in.x, y / in.y, z / in.z );

} // operator /

const pmV3 pmV3::operator / ( const float in ) const
{
	return pmV3( x / in, y / in, z / in );

} // operator /



void pmV3::operator /= ( const pmV3& in )
{
	x /= in.x;
	y /= in.y;
	z /= in.z;

} // operator /=

void pmV3::operator /= ( const float in )
{
	x /= in;
	y /= in;
	z /= in;

} // operator /=



bool pmV3::operator == ( const pmV3& in ) const
{
	return x == in.x && y == in.y && z == in.z;

} // operator ==



bool pmV3::operator != ( const pmV3& in ) const
{
	return x != in.x || y != in.y || z != in.z;

} // operator !=



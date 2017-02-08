#include "Engine/phSystem.h"

#include "pmV4.h"


// Static const vectors
const pmV4 pmV4::zero = pmV4();
const pmV4 pmV4::posx = pmV4(  1.0f,  0.0f,  0.0f,  0.0f );
const pmV4 pmV4::negx = pmV4( -1.0f,  0.0f,  0.0f,  0.0f );
const pmV4 pmV4::posy = pmV4(  0.0f,  1.0f,  0.0f,  0.0f );
const pmV4 pmV4::negy = pmV4(  0.0f, -1.0f,  0.0f,  0.0f );
const pmV4 pmV4::posz = pmV4(  0.0f,  0.0f,  1.0f,  0.0f );
const pmV4 pmV4::negz = pmV4(  0.0f,  0.0f, -1.0f,  0.0f );
const pmV4 pmV4::posw = pmV4(  0.0f,  0.0f,  0.0f,  1.0f );
const pmV4 pmV4::negw = pmV4(  0.0f,  0.0f,  0.0f, -1.0f );

// Color constants
const pmV4 pmV4::white		= pmV4( 1.0f, 1.0f, 1.0f, 1.0f );
const pmV4 pmV4::black		= pmV4( 0.0f, 0.0f, 0.0f, 1.0f );
const pmV4 pmV4::gray		= pmV4( 0.5f, 0.5f, 0.5f, 1.0f );
const pmV4 pmV4::red		= pmV4( 1.0f, 0.0f, 0.0f, 1.0f );
const pmV4 pmV4::green		= pmV4( 0.0f, 1.0f, 0.0f, 1.0f );
const pmV4 pmV4::blue		= pmV4( 0.0f, 0.0f, 1.0f, 1.0f );
const pmV4 pmV4::magenta	= pmV4( 1.0f, 0.0f, 1.0f, 1.0f );
const pmV4 pmV4::yellow		= pmV4( 1.0f, 1.0f, 0.0f, 1.0f );
const pmV4 pmV4::turquoise	= pmV4( 0.0f, 1.0f, 1.0f, 1.0f );


pmV4::pmV4( const float& x /*= 0.0f*/, const float& y /*= 0.0f*/, const float& z /*= 0.0f*/, const float& w/*= 0.0f*/ )
{
	this->x = x;
	this->y = y;
	this->z = z;
	this->w = w;
} // pmV4



pmV4::pmV4( const pmV4& rOther )
{
	this->x = rOther.x;
	this->y = rOther.y;
	this->z = rOther.z;
	this->w = rOther.w;
} // pmV4



pmV4::~pmV4()
{
} // ~pmV4



const pmV4 pmV4::operator + ( const pmV4& in ) const
{
	return pmV4( x + in.x, y + in.y, z + in.z, w + in.w );

} // operator +

const pmV4 pmV4::operator + ( const float in ) const
{
	return pmV4( x + in, y + in, z + in, w + in );

} // operator +



void pmV4::operator += ( const pmV4& in )
{
	x += in.x;
	y += in.y;
	z += in.z;
	w += in.w;

} // operator +=

void pmV4::operator += ( const float in )
{
	x += in;
	y += in;
	z += in;
	w += in;

} // operator +=



const pmV4 pmV4::operator - ( const pmV4& in ) const
{
	return pmV4( x - in.x, y - in.y, z - in.z, w - in.w );

} // operator -

const pmV4 pmV4::operator - ( const float in ) const
{
	return pmV4( x - in, y - in, z - in, w - in );

} // operator -



void pmV4::operator -= ( const pmV4& in )
{
	x -= in.x;
	y -= in.y;
	z -= in.z;
	w -= in.w;

} // operator -=

void pmV4::operator -= ( const float in )
{
	x -= in;
	y -= in;
	z -= in;
	w -= in;

} // operator -=



const pmV4 pmV4::operator * ( const pmV4& in ) const
{
	return pmV4( x * in.x, y * in.y, z * in.z, w * in.w );

} // operator *

const pmV4 pmV4::operator * ( const float in ) const
{
	return pmV4( x * in, y * in, z * in, w * in );

} // operator *



void pmV4::operator *= ( const pmV4& in )
{
	x *= in.x;
	y *= in.y;
	z *= in.z;
	w *= in.w;

} // operator *=

void pmV4::operator *= ( const float in )
{
	x *= in;
	y *= in;
	z *= in;
	w *= in;

} // operator *=




const pmV4 pmV4::operator / ( const pmV4& in ) const
{
	return pmV4( x / in.x, y / in.y, z / in.z, w / in.w );

} // operator /

const pmV4 pmV4::operator / ( const float in ) const
{
	return pmV4( x / in, y / in, z / in, w / in );

} // operator /



void pmV4::operator /= ( const pmV4& in )
{
	x /= in.x;
	y /= in.y;
	z /= in.z;
	w /= in.w;

} // operator /=

void pmV4::operator /= ( const float in )
{
	x /= in;
	y /= in;
	z /= in;
	w /= in;

} // operator /=



bool pmV4::operator == ( const pmV4& in ) const
{
	return x == in.x && y == in.y && z == in.z && w == in.w;

} // operator ==



bool pmV4::operator != ( const pmV4& in ) const
{
	return x != in.x || y != in.y || z != in.z || w != in.w;

} // operator !=



#include "Engine/phSystem.h"

#include "pmV2.h"



// Static const vectors
const pmV2 pmV2::zero = pmV2();
const pmV2 pmV2::posx = pmV2( 1.0f, 0.0f );
const pmV2 pmV2::negx = pmV2( -1.0f, 0.0f );
const pmV2 pmV2::posy = pmV2( 0.0f, 1.0f );
const pmV2 pmV2::negy = pmV2( 0.0f, -1.0f );



pmV2::pmV2( const float& x /*= 0.0f*/, const float& y /*= 0.0f*/ )
{
	this->x = x;
	this->y = y;
} // pmV2



pmV2::pmV2( const pmV2& rOther )
{
	this->x = rOther.x;
	this->y = rOther.y;
} // pmV2



pmV2::~pmV2()
{
} // ~pmV2



const pmV2 pmV2::operator + ( const pmV2& in ) const
{
	return pmV2( x + in.x, y + in.y );

} // operator +

const pmV2 pmV2::operator + ( const float in ) const
{
	return pmV2( x + in, y + in );

} // operator +



void pmV2::operator += ( const pmV2& in )
{
	x += in.x;
	y += in.y;

} // operator +=

void pmV2::operator += ( const float in )
{
	x += in;
	y += in;

} // operator +=



const pmV2 pmV2::operator - ( const pmV2& in ) const
{
	return pmV2( x - in.x, y - in.y );

} // operator -

const pmV2 pmV2::operator - ( const float in ) const
{
	return pmV2( x - in, y - in );

} // operator -



void pmV2::operator -= ( const pmV2& in )
{
	x -= in.x;
	y -= in.y;

} // operator -=

void pmV2::operator -= ( const float in )
{
	x -= in;
	y -= in;

} // operator -=



const pmV2 pmV2::operator * ( const pmV2& in ) const
{
	return pmV2( x * in.x, y * in.y );

} // operator *

const pmV2 pmV2::operator * ( const float in ) const
{
	return pmV2( x * in, y * in );

} // operator *



void pmV2::operator *= ( const pmV2& in )
{
	x *= in.x;
	y *= in.y;

} // operator *=

void pmV2::operator *= ( const float in )
{
	x *= in;
	y *= in;

} // operator *=




const pmV2 pmV2::operator / ( const pmV2& in ) const
{
	return pmV2( x / in.x, y / in.y );

} // operator /

const pmV2 pmV2::operator / ( const float in ) const
{
	return pmV2( x / in, y / in );

} // operator /



void pmV2::operator /= ( const pmV2& in )
{
	x /= in.x;
	y /= in.y;

} // operator /=

void pmV2::operator /= ( const float in )
{
	x /= in;
	y /= in;

} // operator /=



bool pmV2::operator == ( const pmV2& in ) const
{
	return x == in.x && y == in.y;

} // operator ==



bool pmV2::operator != ( const pmV2& in ) const
{
	return x != in.x || y != in.y;

} // operator !=



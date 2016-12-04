#pragma once

#include "pmV3.h"

// Represents a triangle in 3D space
class pmTriangle
{
public:

	pmTriangle()
	{
	}

	pmTriangle( const pmV3& p1, const pmV3& p2, const pmV3& p3 )
	{
		this->p1 = p1;
		this->p2 = p2;
		this->p3 = p3;
	}

	// TODO: Methods for line intersection, normals, area, etc..

	pmV3 p1;
	pmV3 p2;
	pmV3 p3;
};
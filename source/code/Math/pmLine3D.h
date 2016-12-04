#pragma once

#include "pmV3.h"

// Uses two 3D vectors to represent a line in 3D space
class pmLine3D
{
public:

	pmLine3D()
	{

	}

	pmLine3D( const pmV3& startPos, const pmV3& endPos )
	{
		this->startPos = startPos;
		this->endPos = endPos;
	}

	inline const float GetLength( pmV3* lengthVectorOut = nullptr )
	{
		pmV3 lengthVector = endPos - startPos;
		if( lengthVectorOut )
			*lengthVectorOut = lengthVector;

		return lengthVector.length();
	}

	inline const pmV3 GetPositionAtFraction( const float& fraction )
	{
		return startPos + ( endPos - startPos ) * fraction;
	}

	pmV3 startPos;
	pmV3 endPos;

};
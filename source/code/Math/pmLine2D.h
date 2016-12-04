#pragma once

#include "pmV2.h"

// Uses two 2D vectors to represent a line in 2D space
class pmLine2D
{
public:

	pmLine2D()
	{

	}

	pmLine2D( const pmV2& startPos, const pmV2& endPos )
	{
		this->startPos = startPos;
		this->endPos = endPos;
	}

	inline const float GetLength( pmV2* lengthVectorOut = nullptr )
	{
		pmV2 lengthVector = endPos - startPos;
		if( lengthVectorOut )
			*lengthVectorOut = lengthVector;

		return lengthVector.length();
	}

	inline const pmV2 GetPositionAtFraction( const float& fraction )
	{
		return startPos + ( endPos - startPos ) * fraction;
	}

	pmV2 startPos;
	pmV2 endPos;

};
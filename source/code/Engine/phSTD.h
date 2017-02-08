#pragma once

#include <vector>

// Contains helper functions and macros for the std library


// Removes an element from a vector
template<class T> void phStdRemoveFromVector(const T& rItem, std::vector<T>& rVector)
{
	auto it = std::find( rVector.begin(), rVector.end(), rItem );
	if( it != rVector.end() )
	{
		rVector.erase(it);
	}
}
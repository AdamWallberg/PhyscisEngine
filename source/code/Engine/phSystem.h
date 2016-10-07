#pragma once

// Track memory leaks using newp
// No special reason for the 'p' other than
// it's easy to write..
#ifdef DEBUG
	#define _CRTDBG_MAP_ALLOC
	#include <stdlib.h>
	#include <crtdbg.h>
	#define newp new( _NORMAL_BLOCK, __FILE__, __LINE__)
#else
	#define newp new
#endif

// Include typedefs
#include "Utils/phTypes.h"
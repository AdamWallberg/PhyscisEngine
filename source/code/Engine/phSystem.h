#pragma once

// Track memory leaks
#ifdef DEBUG
	#define _CRTDBG_MAP_ALLOC
	#include <stdlib.h>
	#include <crtdbg.h>
#endif

// Enable detailed memory leak dump information
#include "memenable.h"
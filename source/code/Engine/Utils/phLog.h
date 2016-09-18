#pragma once

#include <stdio.h>

// TODO: Replace printf with own logging methods
// that can save data to files, and exit the program. 

// Regular log message
#define _log( MESSAGE, ... ) printf( MESSAGE, __VA_ARGS__ )

// Debug log message
#ifdef DEBUG
#define _logDebug( MESSAGE, ... ) printf( "%s\n", MESSAGE, __VA_ARGS__ )
#else
#define _logDebug( MESSAGE, ... )
#endif
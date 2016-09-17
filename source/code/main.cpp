// Program written by: Adam Wallberg


// Track memory leaks
#ifdef DEBUG
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#endif


// Framework
#include "Application.h"


int main()
{
	// Create the application
	Application app;

	// Run the application
	app.Run();

#ifdef DEBUG
	// Dump memory leaks
	_CrtDumpMemoryLeaks();
#endif

	return 0;
}
// Track memory leaks
#ifdef DEBUG
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#endif


#include "Application.h"

// Program written by: Adam Wallberg

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
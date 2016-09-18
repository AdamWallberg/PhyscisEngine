// Program written by: Adam Wallberg


// Track memory leaks
#ifdef DEBUG
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#endif


// framework
#include "Application.h"


int main()
{
	// Create the application
	Application* app = new Application;

	// Run the application
	app->Run();

	// Delete the application
	delete app;

#ifdef DEBUG
	// Dump memory leaks
	_CrtDumpMemoryLeaks();
#endif

	return 0;
}
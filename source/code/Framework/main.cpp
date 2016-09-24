// Program written by: Adam Wallberg

// Track memory leaks
#ifdef DEBUG
#define _CRTDBG_MAP_ALLOC
//#include <stdlib.h>
#include <crtdbg.h>
#endif


// framework
#include "Application.h"


int main()
{
	// Create the application
	Application* pApp = new Application;
	
	// Run the application
	pApp->Run();
	
	// Delete the application
	delete pApp;

#ifdef DEBUG
	// Dump memory leaks
	_CrtDumpMemoryLeaks();
#endif

	return 0;
}
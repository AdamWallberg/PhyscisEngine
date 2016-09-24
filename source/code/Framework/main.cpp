// Program written by: Adam Wallberg

// engine
#include "Engine/phSystem.h"
// framework
#include "Application.h"

int main()
{
	new int(6);

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
// Program written by: Adam Wallberg

// engine
#include "Engine/phSystem.h"
// framework
#include "CApplication.h"

int main()
{
	// Create the application
	CApplication* pApp = new CApplication;
	
	// Run the application
	pApp->Run();

	// Delete the application
	delete pApp;

#ifdef DEBUG
	// Dump memory leaks
	_CrtDumpMemoryLeaks();
#endif

	return 0;
} // main
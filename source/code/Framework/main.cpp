// Program written by: Adam Wallberg

// engine
#include "Engine/phSystem.h"
// framework
#include "CApplication.h"

int main()
{

#ifdef DEBUG
	_CrtSetDbgFlag( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF );
#endif

	// Create the application
	CApplication* pApp = new CApplication;
	
	// Run the application
	pApp->Run();

	// Delete the application
	delete pApp;

	return 0;

} // main
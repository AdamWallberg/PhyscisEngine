#pragma once

class phCWindow;
class phCInputSystem;

// Contains the game loop, and updates the rest of
// the application. 
class CApplication
{
public:

	CApplication();
	~CApplication();
	
	// Mathod that runs the game loop
	void Run();

private:

	void Update();
	void Render();

	phCWindow* m_pWindow;

	phCInputSystem* m_pInputSystem;

};
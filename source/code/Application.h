#pragma once

// Contains the game loop, and updates the rest of
// the application. 
class Application
{
public:

	Application();
	~Application();
	
	// Mathod that runs the game loop
	void Run();

private:

	void Update();
	void Render();

	bool m_isRunning;

};
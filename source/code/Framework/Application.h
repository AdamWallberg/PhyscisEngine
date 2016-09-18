#pragma once

class phWindow;
class phInputSystem;

#include "Engine/Input/phIInputListener.h"

// Contains the game loop, and updates the rest of
// the application. 
class Application : phIInputListener
{
public:

	Application();
	~Application();
	
	// Mathod that runs the game loop
	void Run();

	void InputEvent( const phInputSystem::SEvent& event ) override;

private:

	void Update();
	void Render();

	phWindow* m_window;
	phInputSystem* m_inputSystem;

};
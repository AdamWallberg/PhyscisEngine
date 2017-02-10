#pragma once

// graphics
#include "phGL.h"
#include "phSystem.h"
#include "Systems/phServiceLocators.h"

// All interaction with the GLFW window goes through this class. 
class phCWindow
{
public:

	phCWindow();
	~phCWindow();

	// Creates the window
	bool CreateWindow( const char* title, uint16 width, uint16 height, uint8 samples, bool fullscreen, bool unlockFps );

	// Polls glfw events
	void Update();
	void SwapBuffers();

	// Getters
	bool ShouldClose() { return m_shouldClose; }
	GLFWwindow* GetWindow() { return m_pWindow; }
	GLFWwindow* GetThreadContext() { return m_pThreadContext; }

	// Setters
	void SetWindowTitle( const char* title ) { glfwSetWindowTitle( m_pWindow, title ); }

private:

	GLFWwindow* m_pWindow;
	GLFWwindow* m_pThreadContext;
	bool m_shouldClose;

};

class phCWindowLocator : public phIServiceLocator<phCWindow>
{
};

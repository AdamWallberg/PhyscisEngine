#pragma once

// graphics
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "phSystem.h"

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

	// Getters
	bool ShouldClose() { return m_shouldClose; }
	GLFWwindow* GetWindow() { return m_pWindow; }

	// Setters
	void SetWindowTitle( const char* title ) { glfwSetWindowTitle( m_pWindow, title ); }

private:

	GLFWwindow* m_pWindow;
	bool m_shouldClose;

};
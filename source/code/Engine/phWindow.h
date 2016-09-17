#pragma once

// graphics
#include <GL/glew.h>
#include <GLFW/glfw3.h>

// All interaction with the GLFW window goes through this class. 
class phWindow
{
public:

	phWindow();
	~phWindow();

	// Creates the window
	bool CreateWindow( const char* title, int width, int height, int samples, bool fullscreen, bool unlockFps );

	// Polls glfw events
	void Update();

	// Getters
	bool ShouldClose() { return m_shouldClose; }

	// Setters
	void SetWindowTitle( const char* title ) { glfwSetWindowTitle( m_window, title ); }

private:

	GLFWwindow* m_window;
	bool m_shouldClose;

};
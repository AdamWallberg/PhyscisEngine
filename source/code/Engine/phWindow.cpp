#include "phWindow.h"

// engine
#include "Utils/phLog.h"
// std
#include <assert.h>

phWindow::phWindow()
	: m_window( nullptr )
	, m_shouldClose( false )
{
}



phWindow::~phWindow()
{
	glfwTerminate();
}



bool phWindow::CreateWindow( const char* title, int width, int height, int samples, bool fullscreen, bool unlockFps )
{
	// Initialize GLFW
	if( !glfwInit() )
	{
		_log( "Couldn't initialize glfw!" );
		return false;
	}
	_log( "Initialized GLFW.." );

	// Create the window
	glfwWindowHint( GLFW_SAMPLES, samples );
	glfwWindowHint( GLFW_CONTEXT_VERSION_MAJOR, 3 );
	glfwWindowHint( GLFW_CONTEXT_VERSION_MINOR, 3 );
	glfwWindowHint( GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE );
	glfwWindowHint( GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE );

	m_window = glfwCreateWindow( width, height, title, nullptr, nullptr );
	if( !m_window )
	{
		_log( "Couldn't create window!" );
		glfwTerminate();
		return false;
	}
	_log( "Window created.." );

	// Set current context
	glfwMakeContextCurrent( m_window );

	// Unlock fps
	if( unlockFps )
	{
		glfwSwapInterval( 0 );
	}

	// Init GLEW
	glewExperimental = true;
	if( glewInit() != GLEW_OK )
	{
		_log( "Couldn't initialize GLEW!" );
		glfwTerminate();
		return false;
	}
	_log( "Initialzied GLEW.." );

}



void phWindow::Update()
{
	glfwPollEvents();
	m_shouldClose = glfwWindowShouldClose( m_window );
}
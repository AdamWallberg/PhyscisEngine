#include "phCWindow.h"

// engine
#include "Utils/phLog.h"
// std
#include <assert.h>

phCWindow::phCWindow()
	: m_pWindow( nullptr )
	, m_shouldClose( false )
{
} // phCWindow



phCWindow::~phCWindow()
{
	glfwTerminate();
} // ~phCWindow



bool phCWindow::CreateWindow( const char* title, int width, int height, int samples, bool fullscreen, bool unlockFps )
{
	// Initialize GLFW
	if( !glfwInit() )
	{
		_log( "Couldn't initialize glfw!\n" );
		return false;
	}
	_log( "Initialized GLFW..\n" );

	// Create the window
	glfwWindowHint( GLFW_SAMPLES, samples );
	glfwWindowHint( GLFW_CONTEXT_VERSION_MAJOR, 3 );
	glfwWindowHint( GLFW_CONTEXT_VERSION_MINOR, 3 );
	glfwWindowHint( GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE );
	glfwWindowHint( GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE );

	// Setup fullscreen
	GLFWmonitor* pMonitor = nullptr;
	if( fullscreen )
		pMonitor = glfwGetPrimaryMonitor();

	m_pWindow = glfwCreateWindow( width, height, title, pMonitor, nullptr );
	if( !m_pWindow )
	{
		_log( "Couldn't create window!\n" );
		glfwTerminate();
		return false;
	}
	_log( "Window created..\n" );

	// Set current context
	glfwMakeContextCurrent( m_pWindow );

	// Unlock fps
	if( unlockFps )
	{
		glfwSwapInterval( 0 );
	}

	// Init GLEW
	glewExperimental = true;
	if( glewInit() != GLEW_OK )
	{
		_log( "Couldn't initialize GLEW!\n" );
		glfwTerminate();
		return false;
	}
	_log( "Initialzied GLEW..\n" );

	return true;

} // CreateWindow



void phCWindow::Update()
{
	glfwPollEvents();
	m_shouldClose = glfwWindowShouldClose( m_pWindow ) == GL_TRUE ? true : false;
	glfwSwapBuffers( m_pWindow );
} // Update
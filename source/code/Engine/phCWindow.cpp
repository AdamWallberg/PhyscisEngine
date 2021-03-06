#include "phSystem.h"

#include "phCWindow.h"

// engine
#include "Utils/phLog.h"
// std
#include <assert.h>

phCWindow::phCWindow()
	: m_pWindow( nullptr )
	, m_pThreadContext( nullptr )
	, m_shouldClose( false )
{
} // phCWindow



phCWindow::~phCWindow()
{
	glfwTerminate();
} // ~phCWindow



bool phCWindow::CreateWindow( const char* title, uint16 width, uint16 height, uint8 samples, bool fullscreen, bool unlockFps )
{
	// Initialize GLFW
	if( !glfwInit() )
	{
		_logError( "Couldn't initialize glfw!" );
		return false;
	}
	_logDebug( "Initialized GLFW.." );

	// Create the window
	glfwWindowHint( GLFW_SAMPLES, samples );
	glfwWindowHint( GLFW_CONTEXT_VERSION_MAJOR, 3 );
	glfwWindowHint( GLFW_CONTEXT_VERSION_MINOR, 3 );
	glfwWindowHint( GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE );
	glfwWindowHint( GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE );

	// Create thread context
	glfwWindowHint(GLFW_VISIBLE, false);
	m_pThreadContext = glfwCreateWindow(1, 1, "physcis_thread_context", nullptr, nullptr);
	assert(m_pThreadContext);
	glfwWindowHint(GLFW_VISIBLE, true);

	// Setup fullscreen
	GLFWmonitor* pMonitor = nullptr;
	if( fullscreen )
		pMonitor = glfwGetPrimaryMonitor();

	m_pWindow = glfwCreateWindow( width, height, title, pMonitor, m_pThreadContext );
	if( !m_pWindow )
	{
		_logError( "Couldn't create window!" );
		glfwTerminate();
		return false;
	}
	_logDebug( "Window created.." );

	// Set current context
	glfwMakeContextCurrent( m_pWindow );

	// Unlock fps
	glfwSwapInterval( !unlockFps );

	// Init GLEW
	glewExperimental = true;
	if( glewInit() != GLEW_OK )
	{
		_logError( "Couldn't initialize GLEW!" );
		glfwTerminate();
		return false;
	}
	_logDebug( "Initialzied GLEW.." );

	return true;

} // CreateWindow



void phCWindow::Update()
{
	glfwPollEvents();
	m_shouldClose = glfwWindowShouldClose( m_pWindow ) == GL_TRUE;
} // Update


void phCWindow::SwapBuffers()
{
	glfwSwapBuffers( m_pWindow );
}

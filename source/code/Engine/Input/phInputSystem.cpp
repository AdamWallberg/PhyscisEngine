#include "phInputSystem.h"
#include "phInputListenerSystem.h"
#include "Engine/phWindow.h"
#include "phIInputListener.h"

phInputSystem::phInputSystem( phWindow* pWindow )
{

	// Set key event callback
	glfwSetKeyCallback( pWindow->GetWindow(), KeyPressedCB );

} // phInputSystem



phInputSystem::~phInputSystem()
{
	
} // ~phInputSystem



void phInputSystem::KeyPressedCB( GLFWwindow* pWindow, int key, int scancode, int action, int mods )
{
	SEvent event;
	event.key = key;
	
	switch( action )
	{
		case GLFW_PRESS:
			event.type = KEY_PRESSED;
			break;
		case GLFW_RELEASE:
			event.type = KEY_RELEASED;
			break;
		default:
			return;
	}

	for( phIInputListener* listener : phInputListenerSystem::m_listeners )
	{
		if( listener->GetTypeFlags() & event.type )
			listener->InputEvent( event );
	}

} // KeyPressedCB
#include "phSystem.h"

#include "phCKeyboardMapping.h"

// glfw
#include "memdisable.h"
#include <GLFW/glfw3.h>
#include "memenable.h"

phCKeyboardMapping::phCKeyboardMapping( GLFWwindow* pWindow, int key )
	: phIInputMapping()
	, m_pWindow( pWindow )
	, m_key( key )
	, m_pressed( false )
	, m_held( false )
	, m_released( false )
{
	
} // phCKeyboardMapping



void phCKeyboardMapping::Update()
{

	if( m_held )
		m_pressed = false;

	int state = glfwGetKey( m_pWindow, m_key );

	if( state == GLFW_PRESS ) // Key pressed
	{
		m_pressed = true;
		m_released = false;
		m_held = true;
	}
	else if( state == GLFW_RELEASE ) // Key released
	{
		m_released = true;
		m_released = false;
		m_held = false;
	}

} // Update
#include "phSystem.h"

#include "phCKeyboardMapping.h"

#include "phCWindow.h"

phCKeyboardMapping::phCKeyboardMapping( phCWindow* pWindow, int key )
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

	int state = glfwGetKey( m_pWindow->GetWindow(), m_key );

	if( state == GLFW_PRESS ) // Key pressed
	{
		if( !m_held )
		{
			m_pressed = true;
			m_held = true;
			m_released = false;
		}
		else // m_held
		{
			m_pressed = false;	
		}

	}
	else if( state == GLFW_RELEASE ) // Key released
	{
		if( m_held )
		{
			m_held = false;
			m_released = true;
			m_pressed = false;
		}
		else // !m_held
		{
			m_released = false;
		}

	}

} // Update
#include "phSystem.h"

#include "phCPadButtonMapping.h"
#include "phCWindow.h"
#include "Engine/Utils/phLog.h"
//glfw
#include <GLFW/glfw3.h>

phCPadButtonMapping::phCPadButtonMapping( phCWindow* pWindow, const uint8 pad, const uint8 button )
	: m_pWindow( pWindow )
	, m_pad( pad )
	, m_button( button )
	, m_held( false )
	, m_prevHeld( false )
{
		
}



void phCPadButtonMapping::Update()
{

	m_prevHeld = m_held;

	if( glfwJoystickPresent( m_pad ) )
	{
		int numButtons;
		const char value = glfwGetJoystickButtons( m_pad, &numButtons )[ m_button ];
		
		if( value == GLFW_PRESS )
			m_held = true;

		if( value == GLFW_RELEASE )
			m_held = false;
	}

}
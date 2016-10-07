#include "Engine/phSystem.h"
#include "phCPadStickAxisMapping.h"
#include "phCWindow.h"
#include "Engine/Utils/phLog.h"
//glfw
#include <GLFW/glfw3.h>
//math
#include "Math/pmMath.h"



phCPadStickAxisMapping::phCPadStickAxisMapping( phCWindow* pWindow, const uint8 pad, const uint8 axis )
	: phIInputMapping()
	, m_pWindow( pWindow )
	, m_pad( pad )
	, m_axis( axis )
	, m_held( false )
	, m_prevHeld( false )
	, m_magnitude( 0.0f )
{
} // phCPadStickAxisMapping



void phCPadStickAxisMapping::Update()
{
	if( glfwJoystickPresent( m_pad ) )
	{
		int numAxes;
		const float value = glfwGetJoystickAxes( m_pad, &numAxes )[ m_axis ];

		m_magnitude = pmAbs( value ) >= JOYSTICK_DEADZONE ? value : 0.0f;
	}

	m_prevHeld = m_held;
	m_held = m_magnitude != 0.0f ? true : false;

} // Update
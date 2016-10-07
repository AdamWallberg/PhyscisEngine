#include "phSystem.h"
#include "phCInputSystem.h"
#include "phCWindow.h"
#include "Utils/phLog.h"
#include "Mappings/phCKeyboardMapping.h"
#include "Mappings/phCPadStickAxisMapping.h"


phCInputSystem::phCInputSystem( phCWindow* pWindow )
{
	
	m_testAction.AddMapping( newp phCKeyboardMapping( pWindow, 'W' ), 1.0f );
	m_testAction.AddMapping( newp phCKeyboardMapping( pWindow, 'S' ), -1.0f );
	m_testAction.AddMapping( newp phCPadStickAxisMapping( pWindow, 0, 0 ), 1.0f );

} // phCInputSystem



phCInputSystem::~phCInputSystem()
{
	
} // ~phCInputSystem



void phCInputSystem::Update()
{

	m_testAction.Update();
	
} // Update
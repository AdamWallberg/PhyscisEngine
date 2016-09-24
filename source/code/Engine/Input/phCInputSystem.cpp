#include "phSystem.h"
#include "phCInputSystem.h"
#include "phCWindow.h"
#include "Utils/phLog.h"
#include "Mappings/phCKeyboardMapping.h"



phCInputSystem::phCInputSystem( phCWindow* pWindow )
{
	
	m_testAction.AddMapping( new phCKeyboardMapping( pWindow, 'W' ), 1.0f );
	m_testAction.AddMapping( new phCKeyboardMapping( pWindow, 'S' ), -1.0f );

} // phCInputSystem



phCInputSystem::~phCInputSystem()
{
	
} // ~phCInputSystem



void phCInputSystem::Update()
{

	m_testAction.Update();
	
	_log( "%f\n", m_testAction.GetValue() );

} // Update
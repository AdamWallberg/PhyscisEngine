#include "CGameStateMenu.h"
#include "phSystem.h"
#include "Clock/phCClock.h"
#include "CGameStateMachine.h"

CGameStateMenu::CGameStateMenu( CGameStateMachine* pMachine )
	: IGameState( pMachine )
{

}



void CGameStateMenu::OnCreate()
{
	_logDebug( "Game State MENU: ON CREATE" );
}

void CGameStateMenu::OnDestroy()
{
	_logDebug( "Game State MENU: ON DESTROY" );
}

void CGameStateMenu::OnEnter()
{
	_logDebug( "Game State MENU: ON ENTER" );
	phCClock::GetInstance().StartStopwatch("game_state_menu_lifetime");
}

void CGameStateMenu::OnExit()
{
	_logDebug( "Game State MENU: ON EXIT" );
	phCClock::GetInstance().StopStopwatch("game_state_menu_lifetime");
}

void CGameStateMenu::Update()
{
	if(phCClock::GetInstance().GetStopwatchTime("game_state_menu_lifetime") >= 4.0f)
	{
		m_pMachine->ChangeGameState("game");
	}
}
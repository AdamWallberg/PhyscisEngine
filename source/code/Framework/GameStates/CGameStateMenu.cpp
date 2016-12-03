#include "CGameStateMenu.h"
#include "phSystem.h"

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
}

void CGameStateMenu::OnExit()
{
	_logDebug( "Game State MENU: ON EXIT" );
}

void CGameStateMenu::Update()
{

}
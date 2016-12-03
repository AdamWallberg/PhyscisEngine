#include "CGameStateGame.h"
#include "Engine/phSystem.h"

CGameStateGame::CGameStateGame( CGameStateMachine* pMachine )
	: IGameState( pMachine )
{

}



void CGameStateGame::OnCreate()
{
	_logDebug( "Game State GAME: ON CREATE" );
}

void CGameStateGame::OnDestroy()
{
	_logDebug( "Game State GAME: ON DESTROY" );
}

void CGameStateGame::OnEnter()
{
	_logDebug( "Game State GAME: ON ENTER" );
}

void CGameStateGame::OnExit()
{
	_logDebug( "Game State GAME: ON EXIT" );
}

void CGameStateGame::Update()
{

}
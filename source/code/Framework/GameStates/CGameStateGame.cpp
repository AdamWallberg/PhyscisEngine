#include "CGameStateGame.h"
#include "Engine/phSystem.h"
#include "Engine/Events/phCEventBroadcaster.h"

CGameStateGame::CGameStateGame( CGameStateMachine* pMachine )
	: IGameState( pMachine )
{
	phCEventBroadcaster::GetInstance().RegisterListener( "test_key_pressed", this, ListenerCallback );
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



void CGameStateGame::ListenerCallback( const char* eventID, void* pObject, void* pData )
{
}
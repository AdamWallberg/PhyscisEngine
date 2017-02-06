#include "CGameStateGame.h"
#include "Engine/phSystem.h"

CGameStateGame::CGameStateGame( CGameStateMachine* pMachine )
	: IGameState( pMachine )
	, m_pTestModel(nullptr)
{

}



void CGameStateGame::OnCreate()
{
	_logDebug( "Game State GAME: ON CREATE" );
	// WARNING:
	// Opengl can't, for some reason, generate buffers on another thread,
	// look into this!
}

void CGameStateGame::OnDestroy()
{
	_logDebug( "Game State GAME: ON DESTROY" );
}

void CGameStateGame::OnEnter()
{
	_logDebug( "Game State GAME: ON ENTER" );
	m_pTestModel = newp phCModel("data/models/cube/cube.obj");
}

void CGameStateGame::OnExit()
{
	_logDebug( "Game State GAME: ON EXIT" );
	delete m_pTestModel;
}

void CGameStateGame::Update()
{
	m_pTestModel->Update();
}
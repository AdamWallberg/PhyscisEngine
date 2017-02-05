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
	m_pTestModel = new phCModel("data/models/monkey/monkey.obj");
}

void CGameStateGame::OnDestroy()
{
	_logDebug( "Game State GAME: ON DESTROY" );
	delete m_pTestModel;
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
	m_pTestModel->Update();
}
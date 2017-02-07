#include "CGameStateGame.h"
#include "Engine/phSystem.h"
#include "Clock/phCClock.h"
#include "Camera/phCCameraSystem.h"

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
	m_pTestModel = newp phCModel("data/models/monkey/monkey.obj");
	m_pTestModel2 = newp phCModel("data/models/cube/cube.obj");
	
	m_pTestModel->m_matrix.Translate(pmV3(-2.0f, 0.0f, 3.0f));
	m_pTestModel2->m_matrix.Translate(pmV3(2.0f, 0.0f, 3.0f));

	m_pCamera = new CCameraFreeFlight();
	phCCameraSystemLocator::GetService()->SetCurrentCamera(m_pCamera);
}

void CGameStateGame::OnExit()
{
	_logDebug( "Game State GAME: ON EXIT" );
	delete m_pCamera;
	delete m_pTestModel;
	delete m_pTestModel2;
}

void CGameStateGame::Update()
{
	m_pTestModel->m_matrix.Rotate(phCClock::GetInstance().GetLifeTime() * 90.0f, pmV3::posy);
	m_pTestModel->Update();

	m_pTestModel2->m_matrix.translation.y = pmSin(phCClock::GetInstance().GetLifeTime() * 90.0f) * 3.0f;

	m_pCamera->Update();
}
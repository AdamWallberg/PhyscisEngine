#include "CGameStateGame.h"
#include "Engine/phSystem.h"
#include "Clock/phCClock.h"
#include "Camera/phCCameraSystem.h"

CGameStateGame::CGameStateGame( CGameStateMachine* pMachine )
	: IGameState( pMachine )
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
	m_models[0] = newp phCModel("data/models/monkey/monkey.obj");
	m_models[1] = newp phCModel("data/models/test_scene/test_scene.obj");
	m_models[2] = newp phCModel("data/models/fence/fence.obj");
	
	m_models[0]->m_matrix.Translate(pmV3(0.0f, 0.0f, 0.0f));
	m_models[1]->m_matrix.Translate(pmV3(0.0f, -2.0f, 0.0f));
	m_models[2]->m_matrix.Translate(pmV3(0.0f, -2.0f, 0.0f));

	m_pCamera = newp CCameraFreeFlight();
	phCCameraSystemLocator::GetService()->SetCurrentCamera(m_pCamera);
}

void CGameStateGame::OnExit()
{
	_logDebug( "Game State GAME: ON EXIT" );
	delete m_pCamera;
	delete m_models[0];
	delete m_models[1];
	delete m_models[2];
}

void CGameStateGame::Update()
{
	m_models[0]->m_matrix.Rotate(pmV3(1.0f, 1.0f, 1.0f) * phCClock::GetInstance().GetLifeTime() * 90.0f);
	m_models[0]->Update();

	//m_pTestModel2->m_matrix.translation.y = pmSin(phCClock::GetInstance().GetLifeTime() * 90.0f) * 3.0f;

	m_pCamera->Update();
}
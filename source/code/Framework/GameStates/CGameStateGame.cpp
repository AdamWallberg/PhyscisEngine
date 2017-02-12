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

	m_models[ 0 ] = newp phCModel( "data/models/stump/stump.obj" );
	m_models[ 1 ] = newp phCModel( "data/models/test_scene/test_scene.obj" );
	m_models[ 2 ] = newp phCModel( "data/models/monkey/monkey.obj" );

	m_pCamera = newp CCameraFreeFlight();
	phCCameraSystemLocator::GetService()->SetCurrentCamera( m_pCamera );
}

void CGameStateGame::OnDestroy()
{
	_logDebug( "Game State GAME: ON DESTROY" );
	delete m_pCamera;
	delete m_models[0];
	delete m_models[1];
	delete m_models[2];
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
	m_models[0]->m_matrix.RotateXYZ(pm::vec3(0.0f, 1.0f, 0.0f) * phCClock::GetInstance().GetDeltaTime() * 35.0f);
	m_models[0]->m_matrix.Translate(m_models[0]->m_matrix.forward * phCClock::GetInstance().GetDeltaTime());
	m_models[0]->Update();

	//m_pTestModel2->m_matrix.translation.y = pmSin(phCClock::GetInstance().GetLifeTime() * 90.0f) * 3.0f;

	m_pCamera->Update();
}
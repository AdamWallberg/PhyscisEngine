#pragma once

#include "IGameState.h"
#include "Data/Models/phCModel.h"
#include "Framework/Camera/CCameraFreeFlight.h"


class CGameStateGame : public IGameState
{
public:

	CGameStateGame( CGameStateMachine* pMachine );
	
	void OnCreate() override;
	void OnDestroy() override;
	void OnEnter() override;
	void OnExit() override;
	void Update() override;

private:

	phCModel* m_pTestModel;
	phCModel* m_pTestModel2;

	CCameraFreeFlight* m_pCamera;

};

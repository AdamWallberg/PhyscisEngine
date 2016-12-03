#pragma once

#include "IGameState.h"

class CGameStateGame : public IGameState
{
public:

	CGameStateGame( CGameStateMachine* pMachine );
	
	void OnCreate() override;
	void OnDestroy() override;
	void OnEnter() override;
	void OnExit() override;
	void Update() override;

};
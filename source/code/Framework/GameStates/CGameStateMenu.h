#pragma once

#include "IGameState.h"

class CGameStateMenu : public IGameState
{
public:

	CGameStateMenu( CGameStateMachine* pMachine );

	void OnCreate() override;
	void OnDestroy() override;
	void OnEnter() override;
	void OnExit() override;
	void Update() override;

};
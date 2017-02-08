#pragma once

class CGameStateMachine;

class IGameState
{
public:

	IGameState( CGameStateMachine* pMachine )
		: m_pMachine( pMachine )
	{
	}

	// These methods run during the loading screen.
	// It's recommended to allocate/deallocate memory,
	// and load assets in these, and not the enter and exit methods.
	virtual void OnCreate() = 0;
	virtual void OnDestroy() = 0;
	
	// Runs after loading is done, and game state is entered.
	virtual void OnEnter() = 0;
	// Runs before loading screen, when state is exited.
	virtual void OnExit() = 0;
	virtual void Update() = 0;

protected:

	CGameStateMachine* m_pMachine;

};
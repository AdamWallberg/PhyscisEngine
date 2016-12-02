#pragma once

#include <map>

class IGameState;

class CGameStateMachine
{
public:

	CGameStateMachine();
	~CGameStateMachine();

	void Update();

	void ChangeGameState( const char* stateName );

private:

	std::map< const char* /*id*/, IGameState* /*pGameState*/ > m_gameStates;

};
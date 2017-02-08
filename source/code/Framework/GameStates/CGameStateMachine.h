#pragma once

#include <map>
#include <thread>

class IGameState;

class CGameStateMachine
{
public:

	CGameStateMachine();
	~CGameStateMachine();

	void Update();

	void ChangeGameState( const char* stateName );

private:

	IGameState* m_pCurrentGameState;
	IGameState* m_pNextGameState;
	std::map< std::string /*id*/, IGameState* /*pGameState*/ > m_gameStates;
	
	bool m_loading;
	std::thread* m_pLoadingThread;

	// Method pointers for loading thread
	static void UnloadCurrentStateAndLoadNext( CGameStateMachine* pMachine );

};
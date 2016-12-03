#include "CGameStateMachine.h"
#include "Engine/phSystem.h"
#include "IGameState.h"
#include "Clock/phCClock.h"

CGameStateMachine::CGameStateMachine()
	: m_pCurrentGameState( nullptr )
	, m_pNextGameState( nullptr )
	, m_loading( false )
	, m_pLoadingThread( nullptr )
{
	// TODO: Create game states
}

CGameStateMachine::~CGameStateMachine()
{
	// Destroy game states
	for( auto& it : m_gameStates )
	{
		if( it.second )
		{
			delete it.second;
		}
	}
}



void CGameStateMachine::Update()
{
	if( m_pLoadingThread ) // We are currently loading a new state
	{
		if( !m_loading ) // We are done loading
		{
			m_pLoadingThread->join();
			delete m_pLoadingThread;
			m_pLoadingThread = nullptr;
			_logDebug( "Done loading!" );
		}
		else // We are loading
		{

		}
	}
	else // Game is running as usual
	{
		if( m_pCurrentGameState )
		{
			m_pCurrentGameState->Update();
		}
	}
}

void CGameStateMachine::ChangeGameState( const char* stateName )
{
	//m_pNextGameState = m_gameStates[ stateName ];
	//
	//if( !m_pNextGameState )
	//{
	//	_logError( "Couldn't find game state: %s", stateName );
	//	return;
	//}

	// Start unload thread
	m_loading = true;
	m_pLoadingThread = new std::thread( UnloadCurrentStateAndLoadNext, this );
	
	phCClock::GetInstance().StartStopwatch( "gsm_loading_timer" );
}



void CGameStateMachine::UnloadCurrentStateAndLoadNext( CGameStateMachine* pMachine )
{
	_logDebug( "Loading thread started.." );

	pMachine->m_loading = false;
}
#include "CGameStateMachine.h"
#include "Engine/phSystem.h"
#include "IGameState.h"
#include "Clock/phCClock.h"
#include "CGameStateMenu.h"
#include "CGameStateGame.h"

CGameStateMachine::CGameStateMachine()
	: m_pCurrentGameState( nullptr )
	, m_pNextGameState( nullptr )
	, m_loading( false )
	, m_pLoadingThread( nullptr )
{
	// Create game states
	m_gameStates[ "menu" ] = new CGameStateMenu( this );
	m_gameStates[ "game" ] = new CGameStateGame( this );

	m_pCurrentGameState = m_gameStates[ "menu" ];
	m_pCurrentGameState->OnCreate();
	m_pCurrentGameState->OnEnter();
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
	if( m_loading || m_pLoadingThread )
	{
		_logError( "Already switching game states!" );
		return;
	}

	m_pNextGameState = m_gameStates[ stateName ];
	
	if( !m_pNextGameState )
	{
		_logError( "Couldn't find game state: %s", stateName );
		return;
	}

	// Start unload thread
	m_loading = true;
	phCClock::GetInstance().StartStopwatch( "gsm_loading_timer" );
	m_pLoadingThread = new std::thread( UnloadCurrentStateAndLoadNext, this );
}



void CGameStateMachine::UnloadCurrentStateAndLoadNext( CGameStateMachine* pMachine )
{
	_logDebug( "Loading thread started.." );

	while( phCClock::GetInstance().GetStopwatchTime( "gsm_loading_timer" ) < 4.0f )
	{
		_log( "Running on the superthread yeh! %.2f", phCClock::GetInstance().GetStopwatchTime( "gsm_loading_timer" ) );
	}

	pMachine->m_loading = false;
}
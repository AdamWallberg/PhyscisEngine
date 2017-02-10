#include "CGameStateMachine.h"
#include "Engine/phSystem.h"
#include "IGameState.h"
#include "Clock/phCClock.h"
#include "CGameStateMenu.h"
#include "CGameStateGame.h"
#include "Engine/phCWindow.h"

CGameStateMachine::CGameStateMachine()
	: m_pCurrentGameState( nullptr )
	, m_pNextGameState( nullptr )
	, m_loading( false )
	, m_pLoadingThread( nullptr )
{
	// Create game states
	m_gameStates[ "menu" ] = newp CGameStateMenu( this );
	m_gameStates[ "game" ] = newp CGameStateGame( this );

	m_pCurrentGameState = m_gameStates[ "menu" ];
	m_pCurrentGameState->OnCreate();
	m_pCurrentGameState->OnEnter();
}

CGameStateMachine::~CGameStateMachine()
{
	// Properly exit current game state
	m_pCurrentGameState->OnExit();
	m_pCurrentGameState->OnDestroy();

	// Destroy game states
	for( auto& it : m_gameStates )
	{
		IGameState* pGameState = it.second;

		if( pGameState )
		{
			delete pGameState;
		}
	}
}



void CGameStateMachine::Update()
{
	if( m_pLoadingThread ) // We are currently loading a new state
	{
		if( !m_loading ) // We are done loading
		{
			// Destroy thread
			m_pLoadingThread->join();
			delete m_pLoadingThread;
			m_pLoadingThread = nullptr;

			// Call OnEnter for new state
			m_pNextGameState->OnEnter();

			// Set current state to new state
			m_pCurrentGameState = m_pNextGameState;
			m_pNextGameState = nullptr;

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
	if( m_loading || m_pLoadingThread || m_pNextGameState )
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

	// Call on OnExit for current state
	m_pCurrentGameState->OnExit();

	// Start unload thread
	m_loading = true;
	m_pLoadingThread = newp std::thread( UnloadCurrentStateAndLoadNext, this );
}



void CGameStateMachine::UnloadCurrentStateAndLoadNext( CGameStateMachine* pMachine )
{
	_logDebug( "Loading thread started.." );

	// Set GL context
	glfwMakeContextCurrent(phCWindowLocator::GetService()->GetWindow());

	// Unload current game state
	pMachine->m_pCurrentGameState->OnDestroy();

	// Load new game state
	pMachine->m_pNextGameState->OnCreate();

	pMachine->m_loading = false;
}
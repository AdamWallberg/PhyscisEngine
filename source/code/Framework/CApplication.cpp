#include "Engine/phSystem.h"

#include "CApplication.h"
// framework
#include "Settings/CSettingsWindow.h"
#include "GameStates/CGameStateMachine.h"
// engine
#include "Engine/phCWindow.h"
#include "Engine/Utils/phLog.h"
#include "Engine/Input/phCInputSystem.h"
#include "Engine/FileSystem/phCFileSystem.h"
#include "Engine/Clock/phCClock.h"

CApplication::CApplication()
	: m_pWindow( nullptr )
	, m_pInputSystem( nullptr )
{
	// Initialize the file system
	phCFileSystem::Init();

	// Create window
	CSettingsWindow::LoadSettings();
	m_pWindow = newp phCWindow;
	m_pWindow->CreateWindow( CSettingsWindow::title.c_str(), CSettingsWindow::width, CSettingsWindow::height, CSettingsWindow::samples, CSettingsWindow::fullscreen, CSettingsWindow::unlockFps );

	// Initialize the clock
	phCClock::Init();
	phCClock::GetInstance().StartStopwatch( "fps_update_timer" );

	// Create input system
	m_pInputSystem = newp phCInputSystem( m_pWindow );
	_logDebug( "Input system initialized.." );

	// Create the game state machine
	m_pGameStateMachine = new CGameStateMachine();

} // CApplication



CApplication::~CApplication()
{
	delete m_pGameStateMachine;
	delete m_pInputSystem;
	phCClock::Destroy();
	delete m_pWindow;
	phCFileSystem::Destroy();

} // ~CApplication



void CApplication::Run()
{

	// Main loop
	while( !m_pWindow->ShouldClose() )
	{
		Update();
		Render();
	}

} // Run



void CApplication::Update()
{
	// Update clock
	phCClock::GetInstance().Update();

	// Update game state machine
	m_pGameStateMachine->Update();

	// TEMP
	static bool changeState = false;
	if( phCClock::GetInstance().GetLifeTime() > 4.0f && !changeState )
	{
		changeState = true;
		m_pGameStateMachine->ChangeGameState( "testState" );
	}

	// Print fps in window title
	if( phCClock::GetInstance().GetStopwatchTime( "fps_update_timer" ) > 0.25f )
	{
		std::string title = "Physcis Engine    |    " + std::to_string( 1.0 / phCClock::GetInstance().GetDeltaTimeReal() );
		m_pWindow->SetWindowTitle( title.c_str() );
		phCClock::GetInstance().StartStopwatch( "fps_update_timer" );
	}

	// Update input
	m_pInputSystem->Update();

	// Update window
	m_pWindow->Update();

} // Update



void CApplication::Render()
{
	
} // Render
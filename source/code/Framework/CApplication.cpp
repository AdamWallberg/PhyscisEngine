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
#include "Engine/Systems/phCModelSystem.h"
#include "Engine/Data/Textures/phCTextureSystem.h"
#include "Engine/Rendering/phCRenderSystem.h"
#include "Engine/Camera/phCCameraSystem.h"
#include "Engine/Clock/phCClock.h"
#include "Engine/Events/phCEventBroadcaster.h"

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
	// Register window to locator
	phCWindowLocator::SetService(m_pWindow);

	// Initialize the clock
	phCClock::Init();
	phCClock::GetInstance().StartStopwatch( "fps_update_timer" );

	// Initialize the event system
	phCEventBroadcaster::Init();

	// Create input system
	m_pInputSystem = newp phCInputSystem( m_pWindow );
	_logDebug( "Input system initialized.." );
	// Register input system to locator
	phCInputSystemLocator::SetService(m_pInputSystem);

	// Create the renderer
	m_pRenderer = newp phCRenderSystem();
	// Register the renderer to locator
	phCRenderSystemLocator::SetService(m_pRenderer);

	// Create the model system
	m_pModelSystem = newp phCModelSystem();
	// Register system to locator
	phCModelSystemLocator::SetService(m_pModelSystem);

	// Create the texture system
	m_pTextureSystem = newp phCTextureSystem();
	m_pTextureSystem->LoadTexture("data/models/monkey/monkey_diffuse.bmp");
	// Register texture system to locator
	phCTextureSystemLocator::SetService(m_pTextureSystem);

	// Create the camera system
	m_pCameraSystem = newp phCCameraSystem();
	// Register the camera system to locator
	phCCameraSystemLocator::SetService(m_pCameraSystem);

	// Create the game state machine
	m_pGameStateMachine = newp CGameStateMachine();

} // CApplication



CApplication::~CApplication()
{
	delete m_pGameStateMachine;
	delete m_pCameraSystem;
	delete m_pTextureSystem;
	delete m_pModelSystem;
	delete m_pRenderer;
	delete m_pInputSystem;
	phCEventBroadcaster::GetInstance().Destroy();
	phCClock::GetInstance().StopStopwatch( "fps_update_timer" );
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

	// Print fps in window title
	if( phCClock::GetInstance().GetStopwatchTime( "fps_update_timer" ) > 0.25f )
	{
		std::string title = "Physcis Engine    |    " + std::to_string(1.0f / phCClock::GetInstance().GetDeltaTimeReal()) + " FPS";
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
	phCRenderSystemLocator::GetService()->Render();
	m_pWindow->SwapBuffers();
} // Render
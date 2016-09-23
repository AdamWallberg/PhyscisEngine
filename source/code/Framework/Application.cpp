#include "Application.h"
// engine
#include "Engine/phWindow.h"
#include "Engine/Utils/phLog.h"
#include "Engine/Input/phInputSystem.h"


Application::Application()
	: phIInputListener( phInputSystem::KEY_PRESSED | phInputSystem::KEY_RELEASED )
	, m_pWindow( nullptr )
	, m_pInputSystem( nullptr )
{
	
	// Create window
	m_pWindow = new phWindow;
	m_pWindow->CreateWindow( "Physcis Engine", 1280, 720, 0, false, true );

	// Create input system
	m_pInputSystem = new phInputSystem( m_pWindow );

} // Application



Application::~Application()
{

	delete m_pInputSystem;
	delete m_pWindow;

} // ~Application



void Application::Run()
{

	// Main loop
	while( !m_pWindow->ShouldClose() )
	{
		Update();
		Render();
	}

} // Run



void Application::InputEvent( const phInputSystem::SEvent& rEvent )
{

	if( rEvent.type == phInputSystem::EEventType::KEY_PRESSED )
	{
		_log( "%c was pressed..\n", rEvent.key );
	}
	else if( rEvent.type == phInputSystem::EEventType::KEY_RELEASED )
	{
		_log( "%c was released..\n", rEvent.key );
	}

} // InputEvent



void Application::Update()
{

	// Update window
	m_pWindow->Update();

} // Update



void Application::Render()
{
	
} // Render
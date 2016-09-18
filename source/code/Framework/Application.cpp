#include "Application.h"
// engine
#include "Engine/phWindow.h"
#include "Engine/FileSystem/phFileUtils.h"
#include "Engine/Utils/phLog.h"
#include "Engine/Input/phInputSystem.h"


Application::Application()
	: phIInputListener( phInputSystem::KEY_PRESSED | phInputSystem::KEY_RELEASED )
	, m_window( nullptr )
	, m_inputSystem( nullptr )
{
	
	// Create window
	m_window = new phWindow;
	m_window->CreateWindow( "Physcis Engine", 1280, 720, 0, false, true );

	// Create input system
	m_inputSystem = new phInputSystem( m_window );

} // Application



Application::~Application()
{

	delete m_inputSystem;
	delete m_window;

} // ~Application



void Application::Run()
{

	// Main loop
	while( !m_window->ShouldClose() )
	{
		Update();
		Render();
	}

} // Run



void Application::InputEvent( const phInputSystem::SEvent& event )
{

	if( event.type == phInputSystem::EEventType::KEY_PRESSED )
	{
		_log( "%c was pressed..\n", event.key );
	}
	else if( event.type == phInputSystem::EEventType::KEY_RELEASED )
	{
		_log( "%c was released..\n", event.key );
	}

} // InputEvent



void Application::Update()
{

	// Update window
	m_window->Update();

} // Update



void Application::Render()
{
	
} // Render
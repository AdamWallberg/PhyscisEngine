#include "Application.h"
// engine
#include "Engine/phWindow.h"
#include "Engine/Utils/phLog.h"


Application::Application()
	: m_pWindow( nullptr )
{
	
	// Create window
	m_pWindow = new phWindow;
	m_pWindow->CreateWindow( "Physcis Engine", 1280, 720, 0, false, true );

} // Application



Application::~Application()
{
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



void Application::Update()
{

	// Update window
	m_pWindow->Update();

} // Update



void Application::Render()
{
	
} // Render
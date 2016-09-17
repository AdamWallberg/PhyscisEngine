#include "Application.h"

// engine
#include "Engine\phWindow.h"



Application::Application()
	: m_window( nullptr )
{

	m_window = new phWindow;
	m_window->CreateWindow( "Physcis Engine", 1280, 720, 0, false, true );

} // Application



Application::~Application()
{

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



void Application::Update()
{

	// Update window
	m_window->Update();

} // Update



void Application::Render()
{
	
} // Render
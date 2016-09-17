#include "Application.h"



Application::Application()
	: m_isRunning( true )
{
	
} // Application



Application::~Application()
{

} // ~Application



void Application::Run()
{

	// For now we just keep a member that determines if
	// the application should close. 
	// This will be replaced by checking if the "core system"
	// wants to quit later.
	while( m_isRunning )
	{
		Update();
		Render();
	}

} // Run



void Application::Update()
{

	// For now just quit the application
	m_isRunning = false;

} // Update



void Application::Render()
{
	
} // Render
#include "CApplication.h"
// engine
#include "Engine/phCWindow.h"
#include "Engine/Utils/phLog.h"


CApplication::CApplication()
	: m_pWindow( nullptr )
{
	
	// Create window
	m_pWindow = new phCWindow;
	m_pWindow->CreateWindow( "Physcis Engine", 1280, 720, 0, false, true );

} // CApplication



CApplication::~CApplication()
{
	delete m_pWindow;

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

	// Update window
	m_pWindow->Update();

} // Update



void CApplication::Render()
{
	
} // Render
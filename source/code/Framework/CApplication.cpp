#include "CApplication.h"
// engine
#include "Engine/phCWindow.h"
#include "Engine/Utils/phLog.h"
#include "Engine/Input/phCInputSystem.h"

CApplication::CApplication()
	: m_pWindow( nullptr )
	, m_pInputSystem( nullptr )
{
	
	// Create window
	m_pWindow = new phCWindow;
	m_pWindow->CreateWindow( "Physcis Engine", 1280, 720, 0, false, true );

	// Create input system
	m_pInputSystem = new phCInputSystem( m_pWindow );

} // CApplication



CApplication::~CApplication()
{

	delete m_pInputSystem;
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

	// Update input
	m_pInputSystem->Update();

} // Update



void CApplication::Render()
{
	
} // Render
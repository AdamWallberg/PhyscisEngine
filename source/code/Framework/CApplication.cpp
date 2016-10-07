#include "Engine/phSystem.h"

#include "CApplication.h"
// framework
#include "Settings/CSettingsWindow.h"
// engine
#include "Engine/phCWindow.h"
#include "Engine/Utils/phLog.h"
#include "Engine/Input/phCInputSystem.h"
#include "Engine/FileSystem/phCFileUtils.h"

CApplication::CApplication()
	: m_pWindow( nullptr )
	, m_pInputSystem( nullptr )
{
	// Create window
	CSettingsWindow::LoadSettings();
	m_pWindow = newp phCWindow;
	m_pWindow->CreateWindow( CSettingsWindow::title.c_str(), CSettingsWindow::width, CSettingsWindow::height, CSettingsWindow::samples, CSettingsWindow::fullscreen, CSettingsWindow::unlockFps );

	// Create input system
	m_pInputSystem = newp phCInputSystem( m_pWindow );
	_logDebug( "Input system initialized.." );

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
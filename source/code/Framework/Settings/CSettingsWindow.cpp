#include "Engine/phSystem.h"
#include "Engine/FileSystem/phCFileSystem.h"
#include "CSettingsWindow.h"


std::string CSettingsWindow::title = "Default Title";
uint16 CSettingsWindow::width = 1280;
uint16 CSettingsWindow::height = 720;
uint8 CSettingsWindow::samples = 0;
bool CSettingsWindow::fullscreen = false;
bool CSettingsWindow::unlockFps = true;


void CSettingsWindow::LoadSettings()
{

	nlohmann::json j = phCFileSystem::GetInstance().LoadAndParseJSON( "data/settings/window.json" );

	title = j[ "title" ].get<std::string>();
	width = j[ "width" ];
	height = j[ "height" ];
	samples = j[ "samples" ];
	fullscreen = j[ "fullscreen" ];
	unlockFps = j[ "unlock_fps" ];

}

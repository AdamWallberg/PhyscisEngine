#include "Engine/phSystem.h"
#include "Engine/FileSystem/phCFileUtils.h"
#include "CSettingsWindow.h"


std::string CSettingsWindow::title = "Default Title";
int CSettingsWindow::width = 1280;
int CSettingsWindow::height = 720;
int CSettingsWindow::samples = 0;
bool CSettingsWindow::fullscreen = false;
bool CSettingsWindow::unlockFps = true;


void CSettingsWindow::LoadSettings()
{

	nlohmann::json j = phCFileUtils::LoadAndParseJSON( "data/settings/window.json" );

	title = j[ "title" ].get<std::string>();
	width = j[ "width" ];
	height = j[ "height" ];
	samples = j[ "samples" ];
	fullscreen = j[ "fullscreen" ];
	unlockFps = j[ "unlock_fps" ];

}

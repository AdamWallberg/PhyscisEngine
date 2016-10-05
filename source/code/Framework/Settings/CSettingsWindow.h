#pragma once

// std
#include <string>

class CSettingsWindow
{
public:

	static void LoadSettings();

	static std::string title;
	static int width;
	static int height;
	static int samples;
	static bool fullscreen;
	static bool unlockFps;

};
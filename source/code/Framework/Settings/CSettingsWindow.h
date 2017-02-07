#pragma once

#include "phSystem.h"

// std
#include <string>

class CSettingsWindow
{
public:

	static void LoadSettings();

	static std::string title;
	static uint16 width;
	static uint16 height;
	static uint8 samples;
	static bool fullscreen;
	static bool unlockFps;

};
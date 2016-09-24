#pragma once

#include "Mappings/phCKeyboardMapping.h"

// Creates and manages all sub-systems concerning input
class phCInputSystem
{
public:

	phCInputSystem( phCWindow* pWindow );
	~phCInputSystem();

	void Update();

};
#pragma once

#include "Actions/phCAction.h"

class phCWindow;

// Creates and manages all sub-systems concerning input
class phCInputSystem
{
public:

	phCInputSystem( phCWindow* pWindow );
	~phCInputSystem();

	void Update();

private:

	phCAction m_testAction;

};
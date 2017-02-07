#pragma once

#include "Actions/phCAction.h"
#include "Systems/phServiceLocators.h"

class phCWindow;

// Creates and manages all sub-systems concerning input
class phCInputSystem
{
public:

	phCInputSystem( phCWindow* pWindow );
	~phCInputSystem();

	void Update();

};

class phCInputSystemLocator : public phIServiceLocator<phCInputSystem>
{
};
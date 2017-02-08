#pragma once
#include "Camera/phCCamera.h"
#include "Input/Actions/phCAction.h"
#include "Input/Mappings/phCKeyboardMapping.h"

class CCameraFreeFlight : public phCCamera
{
public:

	CCameraFreeFlight();

	void Update();

private:

	phCAction m_verticalMovement;
	phCAction m_horizontalMovement;
	phCAction m_yawMovement;
	phCAction m_pitchMovement;

	phCKeyboardMapping m_mappingW;
	phCKeyboardMapping m_mappingS;
	phCKeyboardMapping m_mappingA;
	phCKeyboardMapping m_mappingD;
	phCKeyboardMapping m_mappingUP;
	phCKeyboardMapping m_mappingDOWN;
	phCKeyboardMapping m_mappingLEFT;
	phCKeyboardMapping m_mappingRIGHT;
};

#pragma once

#include "Systems/phServiceLocators.h"
#include "phCCamera.h"

class phCCameraSystem
{
public:

	phCCameraSystem();

	void SetCurrentCamera(phCCamera* pCamera) { m_pCurrentCamera = pCamera; }
	phCCamera* GetCurrentCamera() { return m_pCurrentCamera; }

private:

	// Eventually these systems will store all the data,
	// but for now... Let's do it this way.
	phCCamera* m_pCurrentCamera;

};

class phCCameraSystemLocator : public phIServiceLocator<phCCameraSystem>
{
};
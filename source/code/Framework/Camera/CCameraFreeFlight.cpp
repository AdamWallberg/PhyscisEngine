#include "CCameraFreeFlight.h"
#include "Framework/Settings/CSettingsWindow.h"
#include "phCWindow.h"
#include "Clock/phCClock.h"

CCameraFreeFlight::CCameraFreeFlight()
	: phCCamera(75.0f, static_cast<float>(CSettingsWindow::width) / static_cast<float>(CSettingsWindow::height), 0.01f, 1000.0f)
	, m_mappingW(phCWindowLocator::GetService(), 'W')
	, m_mappingS(phCWindowLocator::GetService(), 'S')
	, m_mappingA(phCWindowLocator::GetService(), 'A')
	, m_mappingD(phCWindowLocator::GetService(), 'D')
	, m_mappingUP(phCWindowLocator::GetService(), GLFW_KEY_UP)
	, m_mappingDOWN(phCWindowLocator::GetService(), GLFW_KEY_DOWN)
	, m_mappingLEFT(phCWindowLocator::GetService(), GLFW_KEY_LEFT)
	, m_mappingRIGHT(phCWindowLocator::GetService(), GLFW_KEY_RIGHT)
{
	m_horizontalMovement.AddMapping(&m_mappingA, -1.0f);
	m_horizontalMovement.AddMapping(&m_mappingD, 1.0f);
	m_verticalMovement.AddMapping(&m_mappingW, 1.0f);
	m_verticalMovement.AddMapping(&m_mappingS, -1.0f);

	m_yawMovement.AddMapping(&m_mappingLEFT, 1.0f);
	m_yawMovement.AddMapping(&m_mappingRIGHT, -1.0f);
	m_pitchMovement.AddMapping(&m_mappingUP, 1.0f);
	m_pitchMovement.AddMapping(&m_mappingDOWN, -1.0f);

	m_position = pm::vec3(0.0f, 3.0f, 0.0f);
	m_rotation = pm::vec3(0.0f, 0.0f, 0.0f);
}

void CCameraFreeFlight::Update()
{
	m_horizontalMovement.Update();
	m_verticalMovement.Update();
	m_yawMovement.Update();
	m_pitchMovement.Update();

	m_position += m_transformationMatrix.forward * ( m_verticalMovement.GetValue() * phCClock::GetInstance().GetDeltaTime() ) * 3.0f;
	m_position += m_transformationMatrix.left * ( m_horizontalMovement.GetValue() * phCClock::GetInstance().GetDeltaTime() ) * 3.0f;
	
	m_rotation -= pm::vec3(m_pitchMovement.GetValue(), m_yawMovement.GetValue(), 0.0f) * phCClock::GetInstance().GetDeltaTime() * 180.0f;

	phCCamera::Update();
}
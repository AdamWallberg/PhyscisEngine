#pragma once

#include "phIInputMapping.h"

class phCWindow;

class phCPadStickAxisMapping : public phIInputMapping
{
public:

	phCPadStickAxisMapping( phCWindow* pWindow, const uint8 pad, const uint8 axis );

	bool GetPressed() const override { return m_held && !m_prevHeld; }
	bool GetHeld() const override { return m_held; }
	bool GetReleased() const override { return !m_held && m_prevHeld; }
	float GetValue() const override { return m_magnitude; }

	void Update() override;

private:

#define JOYSTICK_DEADZONE 0.12f

	phCWindow* m_pWindow;

	uint8 m_pad;
	uint8 m_axis;

	bool m_held;
	bool m_prevHeld;
	float m_magnitude;

};
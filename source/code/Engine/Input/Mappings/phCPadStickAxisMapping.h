#pragma once

#include "phIInputMapping.h"

class phCWindow;

class phCPadStickAxisMapping : public phIInputMapping
{
public:

	phCPadStickAxisMapping( phCWindow* pWindow, const int pad, const int stick, const int axis );

	bool GetPressed() const override { return m_held && !m_prevHeld; }
	bool GetHeld() const override { return m_held; }
	bool GetReleased() const override { return !m_held && m_prevHeld; }
	float GetValue() const override { return m_magnitude; }

	void Update() override;

private:

#define JOYSTICK_DEADZONE 0.12f

	phCWindow* m_pWindow;

	int m_pad;
	int m_axis;

	bool m_held;
	bool m_prevHeld;
	float m_magnitude;

};
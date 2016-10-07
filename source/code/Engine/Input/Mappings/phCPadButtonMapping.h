#pragma once

#include "phIInputMapping.h"

class phCWindow;

class phCPadButtonMapping : public phIInputMapping
{
public:

	phCPadButtonMapping( phCWindow* pWindow, const uint8 pad, const uint8 button );

	bool GetPressed() const override { return m_held && !m_prevHeld; }
	bool GetHeld() const override { return m_held; }
	bool GetReleased() const override { return !m_held && m_prevHeld; }
	float GetValue() const override { return m_held ? 1.0f : 0.0f; }

	void Update() override;

private:

	phCWindow* m_pWindow;
	uint8 m_pad;
	uint8 m_button;

	bool m_held;
	bool m_prevHeld;

};
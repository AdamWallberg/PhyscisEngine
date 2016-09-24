#pragma once

#include "phIInputMapping.h"

struct phCWindow;

class phCKeyboardMapping : public phIInputMapping
{
public:

	phCKeyboardMapping( phCWindow* pWindow, int key );

	bool GetPressed() const override { return m_pressed; }
	bool GetHeld() const override { return m_held; }
	bool GetReleased() const override { return m_released; }
	float GetValue() const override { return m_held ? 1.f : 0.f; }

	void Update() override;

private:

	phCWindow* m_pWindow;

	int m_key;

	bool m_pressed;
	bool m_held;
	bool m_released;

};
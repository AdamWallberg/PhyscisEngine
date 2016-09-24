#pragma once

#include "phIInputMapping.h"

struct GLFWwindow;

class phCKeyboardMapping : public phIInputMapping
{
public:

	phCKeyboardMapping( GLFWwindow* pWindow, int key );

	bool GetPressed() const override { return m_pressed; }
	bool GetHeld() const override { return m_held; }
	bool GetReleased() const override { return m_released; }
	float GetValue() const override { return m_held ? 1.f : 0.f; }

	void Update() override;

private:

	GLFWwindow* m_pWindow;

	int m_key;

	bool m_pressed;
	bool m_held;
	bool m_released;

};
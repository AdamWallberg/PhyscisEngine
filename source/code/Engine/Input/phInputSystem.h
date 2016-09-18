#pragma once

class phWindow;
struct GLFWwindow;

// Takes care of all interaction with input events from GLFW.
// Sends out all input events to the listeners.
class phInputSystem
{
public:

	phInputSystem( phWindow* window );
	~phInputSystem();

	enum EEventType
	{
		KEY_PRESSED = 1 << 0,
		KEY_RELEASED = 1 << 1
	};

	struct SEvent
	{
		EEventType type;
		int key;
	};

private:

#define NUM_KEYS 350

	static void KeyPressedCB( GLFWwindow* window, int key, int scancode, int action, int mods );

};
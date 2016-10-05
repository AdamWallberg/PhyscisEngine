#pragma once

//std
#include <map>
// input
#include "Input/Mappings/phIInputMapping.h"

// Stores multiple input mappings.
// Has methods for retrieving pressed, released, and held
// for the strongest "signal" ie. mapping. 
class phCAction
{
public:

	phCAction();
	~phCAction();

	// Adds and input mapping to the action.
	// Mapping values are multiplied by their scale before returned.
	void AddMapping( phIInputMapping* pMapping, const float scale );

	bool GetPressed() const { return m_pressed; }
	bool GetHeld() const { return m_held; }
	bool GetReleased() const { return m_released; }
	float GetValue() const { return m_value; }

	// Updates all its input mappings, and calculates
	// the strongest signal.
	void Update();

private:

	std::map< phIInputMapping*, float > m_mappings;

	bool m_pressed;
	bool m_held;
	bool m_released;
	float m_value;

};
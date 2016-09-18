#pragma once

// std
#include <vector>

class phIInputListener;

// System for storing input listeners statically
// so they can be accessed through a static callback.
class phInputListenerSystem
{
public:

	static void AddListener( phIInputListener* listener );

private:

	friend class phInputSystem;

	static std::vector< phIInputListener* > m_listeners;

};
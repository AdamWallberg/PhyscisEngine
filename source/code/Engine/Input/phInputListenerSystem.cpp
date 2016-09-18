#include "phInputListenerSystem.h"

std::vector< phIInputListener* > phInputListenerSystem::m_listeners;



void phInputListenerSystem::AddListener( phIInputListener* listener )
{

	phInputListenerSystem::m_listeners.push_back( listener );

} // AddListener
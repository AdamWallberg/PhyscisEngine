#include "phInputListenerSystem.h"

std::vector< phIInputListener* > phInputListenerSystem::m_listeners;



void phInputListenerSystem::AddListener( phIInputListener* pListener )
{

	phInputListenerSystem::m_listeners.push_back( pListener );

} // AddListener
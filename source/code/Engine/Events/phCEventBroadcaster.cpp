#include "phCEventBroadcaster.h"

phCEventBroadcaster::phCEventBroadcaster()
{

}

phCEventBroadcaster::~phCEventBroadcaster()
{

}



void phCEventBroadcaster::RegisterListener( const char* eventID, void* pListenerObject, void( *ListenerCallback ) ( const char*, void*, void* ) )
{
	m_listenerPackages[ eventID ].push_back( { pListenerObject, ListenerCallback } );
}

void phCEventBroadcaster::BroadcastEvent( const char* eventID, void* pOptionalArguments )
{
	for( SEventListenerPackage& rListener : m_listenerPackages[ eventID ] )
	{
		rListener.ListenerCallback( eventID, rListener.pListenerObject, pOptionalArguments );
	}
}
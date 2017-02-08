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

void phCEventBroadcaster::DeleteListener( void* pListenerObject )
{
	for( auto& it : m_listenerPackages )
	{
		for( auto packageIterator = it.second.begin(); packageIterator != it.second.end(); )
		{
			SEventListenerPackage& rPackage = *packageIterator;
			if( rPackage.pListenerObject == pListenerObject )
			{
				it.second.erase(packageIterator);
			}
			else
			{
				++packageIterator;
			}
		}
	}
}

void phCEventBroadcaster::DeleteEventListener( const char* eventID, void* pListenerObject )
{
	for( auto packageIterator = m_listenerPackages[ eventID ].begin(); packageIterator != m_listenerPackages[ eventID ].end(); )
	{
		SEventListenerPackage& rPackage = *packageIterator;
		if( rPackage.pListenerObject == pListenerObject )
		{
			m_listenerPackages[ eventID ].erase( packageIterator );
		}
		else
		{
			++packageIterator;
		}
	}
}

void phCEventBroadcaster::BroadcastEvent( const char* eventID, void* pOptionalArguments )
{
	for( SEventListenerPackage& rListener : m_listenerPackages[ eventID ] )
	{
		rListener.ListenerCallback( eventID, rListener.pListenerObject, pOptionalArguments );
	}
}
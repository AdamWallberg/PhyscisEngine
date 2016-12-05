#pragma once

#include "Engine/Utils/phCSingleton.h"
#include "Engine/phSystem.h"

#include <map>
#include <vector>

// This is a non-decoupled event system. ie. the events are processed directly 
// when they are sent.
// This might be reworked in case a decoupled system is needed.
// 
// The system is designed the way it is for the following reasons:
// 1. It's a singleton because I want it to be globally accessable.
// 2. I do not want classes to have to inherit from a listener interface.
//		With this design they only have to register a function pointer as callback.

class phCEventBroadcaster : public phCSingleton< phCEventBroadcaster >
{
public:

	phCEventBroadcaster();
	~phCEventBroadcaster();
	
	// Register a function pointer as a event listener.
	// The parameters for the function pointer must be the following:
	//		p1: A pointer to the object itself
	//		p2: A pointer to the custom data that the event sends out.
	void RegisterListener( const char* eventID, void* pListenerObject, void ( *ListenerCallback ) ( const char*, void*, void* ) );
	
	// Broadcasts an event to all listeners that are registered to it.
	void BroadcastEvent( const char* eventID, void* pOptionalArguments );

private:
	
	struct SEventListenerPackage
	{
		void* pListenerObject;
		// Listener callback
		//		Param1: The event ID
		//		Param2: The object itself will be sent via this void pointer.
		//		Param3: The custom data that is sent with the event.
		void( *ListenerCallback ) ( const char*, void*, void* ); 
	};

	std::map< const char* /*event*/, std::vector< SEventListenerPackage > /*listenerPackages*/ > m_listenerPackages;

};

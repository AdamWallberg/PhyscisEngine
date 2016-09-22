#pragma once

#include "phInputListenerSystem.h"
#include "phInputSystem.h"

// Input listener interface
class phIInputListener
{
public:

	phIInputListener( int type )
		: m_typeFlags( type )
	{
		phInputListenerSystem::AddListener( this );
	}

	virtual ~phIInputListener(){}
	
	virtual void InputEvent( const phInputSystem::SEvent& rEvent ) = 0;

	virtual int GetTypeFlags() { return m_typeFlags; }

private:

	int m_typeFlags;

};
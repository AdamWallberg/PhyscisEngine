#include "phCClock.h"
#include "Engine/phSystem.h"

#include <GLFW/glfw3.h>

phCClock::phCClock()
	: m_paused( false )
	, m_deltaTime( 0.0 )
	, m_deltaTimeReal( 0.0 )
	, m_lifeTime( 0.0 )
	, m_lifeTimeReal( 0.0 )
{
	m_lastTime = glfwGetTime();
}

phCClock::~phCClock()
{
	for( auto it : m_clocks )
	{
		_logError( "Found unremoved clock: %s. Please call StopStopwatch() when done using it, for increased performance.", it.first.c_str() );
	}

	m_clocks.clear();
}



void phCClock::Update()
{
	const double newTime = glfwGetTime();
	m_deltaTimeReal = newTime - m_lastTime;
	m_lastTime = newTime;
	m_deltaTime = m_paused ? 0.0 : m_deltaTimeReal;

	m_lifeTimeReal += m_deltaTimeReal;
	m_lifeTime += m_deltaTime;

	for( auto& it : m_clocks )
	{
		it.second.time += it.second.isPaused ? 0.0 : m_deltaTimeReal;
	}
}



void phCClock::StartStopwatch( const char* name )
{
	m_clocks[ name ] = { 0.0, false };
}

const float phCClock::GetStopwatchTime( const char* name )
{
	return static_cast<float>( m_clocks[ name ].time );
}

const float phCClock::PauseStopwatch( const char* name )
{
	m_clocks[ name ].isPaused = true;
	return static_cast<float>( m_clocks[ name ].time );
}

const float phCClock::ResumeStopwatch( const char* name )
{
	m_clocks[ name ].isPaused = false;
	return static_cast<float>( m_clocks[ name ].time );
}

const float phCClock::StopStopwatch( const char* name )
{
	const double value = m_clocks[ name ].time;
	m_clocks.erase( name );
	return static_cast<float>( value );
}

#pragma once

#include "Engine/Utils/phCSingleton.h"

#include <map>

// Keeps track of the total time of the application,
// whether or not the application is paused.
// And can setup and update custom clocks and timers.
class phCClock : public phCSingleton<phCClock>
{
public:
	phCClock();
	~phCClock();

	void Update();

	// All stopwatch methods that return a float value 
	// will return -1.0f if the stopwatch doesn't exist.

	// Starts a custom stopwatch.
	// Remember to call StopStopwatch when done using it.
	void StartStopwatch( const char* name );
	// Recieves the elapsed time since stopwatch was created.
	const float GetStopwatchTime( const char* name );
	// Pauses the stopwatch and returns its current elapsed time.
	const float PauseStopwatch( const char* name );
	// Resumes the stopwatch and returns its current elapsed time.
	const float ResumeStopwatch( const char* name );
	// Removes the stopwatch, and returns the final elapsed time.
	const float StopStopwatch( const char* name );

	// Getters and setters
#pragma warning( push )
#pragma warning( disable : 4172 )
	const float& GetLifeTime() { return static_cast<float>( m_lifeTime ); }
	const float& GetLifeTimeReal() { return static_cast<float>( m_lifeTimeReal ); }
	const float& GetDeltaTime() { return static_cast<float>( m_deltaTime ); }
	const float& GetDeltaTimeReal() { return static_cast<float>( m_deltaTimeReal ); }
	const bool& GetPaused() { return m_paused; }
#pragma warning( pop )
	void SetPaused( bool paused ) { m_paused = paused; }

private:
	struct SStopwatch
	{
		double time;
		bool isPaused;
	};

	bool m_paused;
	double m_lastTime;
	double m_lifeTime;
	double m_lifeTimeReal;
	double m_deltaTime;
	double m_deltaTimeReal;
	std::map<const char* /*name*/, SStopwatch> m_clocks;
};
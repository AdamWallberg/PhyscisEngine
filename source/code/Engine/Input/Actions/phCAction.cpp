#include "phSystem.h"
#include "phCAction.h"
#include "Math/pmMath.h"

phCAction::phCAction()
	: m_pressed( false )
	, m_held( false )
	, m_released( false )
	, m_value( 0.0f )
{
	
} // phCAction



phCAction::~phCAction()
{

	for( auto& it : m_mappings )
	{
		phIInputMapping* pMapping = it.first;
		delete pMapping;
	}

	m_mappings.clear();

} // ~phCAction



void phCAction::AddMapping( phIInputMapping* pMapping, const float scale )
{

	m_mappings[ pMapping ] = scale;

} // AddMapping



void phCAction::Update()
{

	phIInputMapping* pStrongestMapping = nullptr;
	float highestValue = 0.0f;

	// Update mappings, and find strongest signal
	for( auto& it : m_mappings )
	{
		phIInputMapping* pMapping = it.first;
		const float& scale = it.second;
		pMapping->Update();

		const float mappingValue = pMapping->GetValue() * scale;
		if( pmAbs( mappingValue ) >= pmAbs( highestValue ) ) // Use abs since values can be negative
		{
			pStrongestMapping = pMapping;
			highestValue = mappingValue;
		}
	}

	// Set values
	if( pStrongestMapping )
	{
		m_pressed = pStrongestMapping->GetPressed();
		m_held = pStrongestMapping->GetHeld();
		m_released = pStrongestMapping->GetReleased();
		m_value = highestValue;
	}
	else 
	{
		m_pressed = false;
		m_held = false;
		m_released = false;
		m_value = false;
	}

} // Update
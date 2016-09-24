#include "phSystem.h"

#include "phCSingleton.h"

template< typename T > T* phCSingleton<T>::m_pInstance = nullptr;



template< typename T > void phCSingleton<T>::Init()
{

	if( !m_pInstance )
		m_pInstance = new T();

} // Init



template< typename T > void phCSingleton<T>::Destroy()
{
	
	delete m_pInstance;
	m_pInstance = nullptr;

} // Destroy



template< typename T > T& phCSingleton<T>::GetInstance()
{

	return *m_pInstance;

} // GetInstance



template< typename T > T* phCSingleton<T>::GetInstancePtr()
{

	return m_pInstance;

} // GetInstancePtr
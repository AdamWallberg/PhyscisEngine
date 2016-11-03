#pragma once

// Singleton template class.
// Just to offend every c++ programmer out there.

template< class T > class phCSingleton
{
public:

	// Creates and calls the constructor for T
	static void Init();
	// Deletes the instance of T
	static void Destroy();
	static T& GetInstance();
	static T* GetInstancePtr();

protected:

	static T* m_pInstance;

};

template< typename T > T* phCSingleton<T>::m_pInstance = nullptr;



template< typename T > void phCSingleton<T>::Init()
{
	if( !m_pInstance )
		m_pInstance = newp T();

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
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
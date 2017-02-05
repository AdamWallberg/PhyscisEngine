#pragma once

#include "phSystem.h"
#include <cassert>
#include "phCModelSystem.h"

// Simple service locator interface
template <class T> class phIServiceLocator
{
public:

	static void SetService(T* pService)
	{
		if(!pService)
		{
			_logError("You are trying to register a null service!");
			assert(false);
		}

		s_pService = pService;
	}

	static T* GetService() { return s_pService; }

private:

	static T* s_pService;

};

template <typename T> T* phIServiceLocator<T>::s_pService = nullptr;

class phCModelSystemLocator : public phIServiceLocator<phCModelSystem>
{
};
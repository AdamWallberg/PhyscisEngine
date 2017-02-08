#pragma once

#include <vector>
#include "Data/Models/phCModel.h"
#include "phServiceLocators.h"

class phCModelSystem
{
public:

	void AddModel(phCModel* pModel);
	void RemoveModel(phCModel* pModel);

	std::vector<phCModel*>& GetModels(){ return m_models; }
	
private:

	std::vector<phCModel*> m_models;

	// TODO: Later this class should handle allocation and storage of all models and their data

};

class phCModelSystemLocator : public phIServiceLocator<phCModelSystem>
{
};
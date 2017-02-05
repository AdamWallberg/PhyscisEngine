#include "phCModelSystem.h"
#include "phSTD.h"

void phCModelSystem::AddModel(phCModel* pModel)
{
	m_models.push_back(pModel);
}

void phCModelSystem::RemoveModel(phCModel* pModel)
{
	phStdRemoveFromVector(pModel, m_models);
}

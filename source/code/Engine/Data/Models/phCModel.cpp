#include "phCModel.h"

phCModel::phCModel()
	: m_matrix(pmMat4(1))
{
	
}

phCModel::phCModel(const char* filePath)
	: phIAsset(filePath)
	, m_matrix(pmMat4(1))
{
	phCMesh mesh(filePath);
	m_meshes.push_back(mesh);
}

void phCModel::Update()
{
	for(phCMesh& mesh : m_meshes)
	{
		mesh.Update();
	}
}
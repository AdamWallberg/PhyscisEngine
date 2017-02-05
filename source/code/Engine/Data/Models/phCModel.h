#pragma once

//std
#include <vector>
//engine
#include "../phIAsset.h"
#include "phCMesh.h"
//math
#include "Math/pmMat4.h"

class phCModel : public phIAsset 
{
public:

	phCModel();
	phCModel(const char* filePath);
	
	void Update();

	EAssetType GetAssetType() override { return ASSET_TYPE_MODEL; }

private:

	std::vector<phCMesh> m_meshes;
	pmMat4 m_matrix;

};
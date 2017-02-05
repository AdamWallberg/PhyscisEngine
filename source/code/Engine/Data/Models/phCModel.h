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

	~phCModel();
	
	void Update();

	EAssetType GetAssetType() override { return ASSET_TYPE_MODEL; }

private:

	void Init();

	std::vector<phCMesh> m_meshes;
	pmMat4 m_matrix;

};
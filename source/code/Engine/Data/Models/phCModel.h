#pragma once

//std
#include <vector>
//engine
#include "../phIAsset.h"
#include "phCMesh.h"
//math
#include "phMath/mat4.h"

class phCModel : public phIAsset 
{
public:

	phCModel();
	phCModel(const char* filePath);

	~phCModel();
	
	void Update();

	EAssetType GetAssetType() override { return ASSET_TYPE_MODEL; }
	std::vector<phCMesh*>& GetMeshes() { return m_meshes; } 

	pm::mat4 m_matrix;

private:

	void Init();

	std::vector<phCMesh*> m_meshes;

	friend class phCRenderer;
};
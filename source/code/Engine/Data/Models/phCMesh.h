#pragma once

#include "Data/phIAsset.h"
#include "Math/pmMat4.h"


class phCMesh : public phIAsset
{
public:

	phCMesh();

	// TODO: Automatically called from phCModel::Update()
	void Update();

	EAssetType GetAssetType() override { return ASSET_TYPE_MESH; }

private:

	pmMat4 m_matrix;
	// TODO: phCModel* m_pParent;
	// TODO: Vertex Buffer and Index Buffer *
};
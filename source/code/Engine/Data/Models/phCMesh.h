#pragma once

#include "Data/phIAsset.h"
#include "Math/pmV4.h"
#include "Math/pmMat4.h"

class phCMesh : phIAsset
{
public:

	struct SVertex
	{
		pmV3 position;
		pmV3 normal;
		pmV2 uv1;
		// TODO: Add color
	};

	phCMesh();

	virtual ~phCMesh()
	{
	}

	// TODO: Automatically called from phCModel::Update()
	void Update();

	EAssetType GetAssetType() override { return ASSET_TYPE_MESH; }

private:

	pmMat4 m_matrix;
	// TODO: phCModel* m_pParent;

};
#pragma once

#include "Data/phIAsset.h"
#include "Math/pmMat4.h"
#include "phCVertexBuffer.h"
#include "phCIndexBuffer.h"

class phCModel;

class phCMesh : public phIAsset
{
public:

	phCMesh(const char* filePath);
	~phCMesh();

	// Automatically called from phCModel::Update()
	void Update();

	EAssetType GetAssetType() override { return ASSET_TYPE_MESH; }

	// Getters and setters
	bool GetShouldRender() const { return m_shouldRender; }
	void SetShouldRender(bool shouldRender) { m_shouldRender = shouldRender; } 

private:

	pmMat4 m_matrix;
	phCModel* m_pParent;
	
	phCVertexData m_vertexData;
	phCVertexBuffer* m_pVertexBuffer;

	phCIndexData m_indexData;
	phCIndexBuffer* m_pIndexBuffer;

	bool m_shouldRender;

	friend class phCModel;
};
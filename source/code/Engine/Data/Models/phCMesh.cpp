#include "phCMesh.h"

#include "FileSystem/phCFileSystem.h"

phCMesh::phCMesh(const char* filePath)
	: phIAsset(filePath)
	, m_pParent(nullptr)
	, m_shouldRender(true)
	, m_matrix(1.0f)
{
	// TODO: Fix this, this is only temporary.
	// Assuming that we only want to create meshes this way is really silly...
	phCFileSystem::GetInstance().LoadAndParseOBJ(filePath, &m_vertexData, &m_indexData);

	m_pVertexBuffer = newp phCVertexBuffer(&m_vertexData);
	m_pIndexBuffer = newp phCIndexBuffer(&m_indexData);
}

phCMesh::~phCMesh()
{
	delete m_pVertexBuffer;
	delete m_pIndexBuffer;
}

void phCMesh::Update()
{
	// TODO: Multiply matrix by parent model matrix
}
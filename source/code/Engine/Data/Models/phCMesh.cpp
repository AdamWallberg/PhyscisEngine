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
	m_pVertexData = new phCVertexData();
	m_pIndexData = new phCIndexData();
	phCFileSystem::GetInstance().LoadAndParseOBJ(filePath, m_pVertexData, m_pIndexData);

	m_pVertexBuffer = newp phCVertexBuffer(m_pVertexData);
	m_pIndexBuffer = newp phCIndexBuffer(m_pIndexData);
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
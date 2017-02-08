#pragma once

#include <vector>
#include "Math/pmV4.h"
#include "Math/pmMat4.h"
#include "phGL.h"
#include "phSystem.h"

struct SVertex
{
	SVertex()
	{
	}

	pmV3 position;
	pmV3 normal;
	pmV2 uv;
	pmV4 color;

	//bool operator ==( const SVertex& rOther ) const
	//{
	//	return position == rOther.position && normal == rOther.normal && uv == rOther.uv && color == rOther.color;
	//}

	bool operator <( const SVertex other ) const
	{
		return memcmp( ( void* )this, ( void* )&other, sizeof(SVertex) ) > 0;
	}
};

// Stores the raw vertex data
class phCVertexData
{
public:

	phCVertexData()
	{
	}

	phCVertexData( const std::vector< SVertex >& rVertices )
		: m_vertices( rVertices )
	{
	}

	void AddVertex( const SVertex& rVertex ) { m_vertices.push_back( rVertex ); }

	uint32 GetNumVertices() const { return m_vertices.size(); }

private:

	std::vector< SVertex > m_vertices;
	friend class phCFileSystem;
	friend class phCVertexBuffer;
};

// Handles GL vertex buffers
class phCVertexBuffer
{
public:

	phCVertexBuffer( phCVertexData* pVertexData );
	~phCVertexBuffer();

	void Bind() const;

	uint32 GetNumVertices() const { return m_numVertices; }

private:

	phCVertexData* m_pVertexData;
	GLuint m_bufferID;
	uint32 m_numVertices;
};

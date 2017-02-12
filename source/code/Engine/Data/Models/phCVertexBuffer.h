#pragma once

#include <vector>
#include "phMath/vec4.h"
#include "phMath/mat4.h"
#include "phGL.h"
#include "phSystem.h"

struct SVertex
{
	SVertex()
	{
	}

	pm::vec3 position;
	pm::vec3 normal;
	pm::vec2 uv;
	pm::vec4 color;

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

	uint32 GetNumVertices() const { return static_cast<uint32>( m_vertices.size() ); }

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

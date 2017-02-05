#pragma once

#include "phSystem.h"
#include <vector>
#include "phGL.h"

class phCIndexData
{
public:

	phCIndexData()
	{
	}
	phCIndexData(const std::vector<uint32>& rIndicies)
		: m_indices(rIndicies)
	{
	}

	void AddIndex(const uint32& rIndex) { m_indices.push_back(rIndex); }

	uint32 GetNumIndicies() const { return m_indices.size(); }

private:

	std::vector<uint32> m_indices;

	friend class phCFileSystem;
	friend class phCIndexBuffer;
};

class phCIndexBuffer
{
public:

	phCIndexBuffer(phCIndexData* pIndexData);
	~phCIndexBuffer();

	void Bind();

	uint32 GetNumIndicies() const { return m_numIndices; }

private:

	phCIndexData* m_pIndexData;
	GLuint m_bufferID;
	uint32 m_numIndices;

	friend class phCFileSystem;

};
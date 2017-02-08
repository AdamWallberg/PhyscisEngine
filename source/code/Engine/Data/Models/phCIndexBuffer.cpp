#include "phCIndexBuffer.h"

phCIndexBuffer::phCIndexBuffer(phCIndexData * pIndexData)
	: m_pIndexData(pIndexData)
	, m_numIndices(pIndexData->GetNumIndicies())
{
	glGenBuffers(1, &m_bufferID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_bufferID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_numIndices * sizeof(uint32), &pIndexData->m_indices[0], GL_STATIC_DRAW);
}

phCIndexBuffer::~phCIndexBuffer()
{
	glDeleteBuffers(1, &m_bufferID);
}

void phCIndexBuffer::Bind()
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_bufferID);
}

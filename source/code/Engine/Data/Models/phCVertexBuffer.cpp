#include "phCVertexBuffer.h"

phCVertexBuffer::phCVertexBuffer(phCVertexData* pVertexData)
	: m_pVertexData(pVertexData)
	, m_numVertices(pVertexData->GetNumVertices())
{
	glGenBuffers(1, &m_bufferID);
	glBindBuffer(GL_ARRAY_BUFFER, m_bufferID);
	glBufferData(GL_ARRAY_BUFFER, m_numVertices * sizeof(SVertex), &pVertexData->m_vertices[0], GL_STATIC_DRAW);
}

phCVertexBuffer::~phCVertexBuffer()
{
	glDeleteBuffers(1, &m_bufferID);
}

void phCVertexBuffer::Bind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, m_bufferID);
}
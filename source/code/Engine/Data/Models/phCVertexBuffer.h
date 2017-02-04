#pragma once

#include <vector>
#include "Math/pmV4.h"
#include "Math/pmMat4.h"

struct SVertex
{
	pmV3 position;
	pmV3 normal;
	pmV2 uv;
	pmV4 color;
};

class phCVertexBuffer
{
public:

	phCVertexBuffer(){}

private:

	std::vector<SVertex> m_vertices;

	friend class phCFileSystem;

};
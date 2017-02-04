#include "phSystem.h"
#include "phCFileSystem.h"
#include "Data/Models/phCVertexBuffer.h"
#include "Data/Models/phCIndexBuffer.h"
//std
#include <fstream>

phCFileSystem::phCFileSystem()
{
#if defined FBX
	_logDebug( "Initializing FBX manager.." );
	InitFBX();
#endif
}



phCFileSystem::~phCFileSystem()
{
#if defined FBX
	m_pFbxImporter->Destroy();
	m_pFbxIOSettings->Destroy();
	m_pFbxManager->Destroy();
#endif
}



nlohmann::json phCFileSystem::LoadAndParseJSON( const char* filePath )
{
	nlohmann::json j;

	// Read file data
	std::ifstream file( filePath );
	if( file.is_open() )
	{
		std::stringstream buffer;
		buffer << file.rdbuf();
		std::string content = buffer.str();
		file.close();
		
		// Parse json data
		j = nlohmann::json::parse( content.c_str() );
	}

	return j;
}



bool phCFileSystem::LoadAndParseOBJ( const char* filePath, phCVertexBuffer* pVertexBuffer, phCIndexBuffer* pIndexBuffer )
{
	std::vector<uint32> positionIndicies, uvIndicies, normalIndicies;
	std::vector<pmV3> tempPositions;
	std::vector<pmV2> tempUVs;
	std::vector<pmV3> tempNormals;

	FILE* pFile;
	fopen_s(&pFile, filePath, "r");

	// Check if file can be opened
	if(!pFile)
	{
		_logError("Couldn't open OBJ: %s", filePath);
		return false;
	}

	// Read file
	while(true)
	{
		char lineHeader[128]; // Silly assumption, might need some rework later
		int res = fscanf_s(pFile, "%s", lineHeader, _countof(lineHeader));
		if(res == EOF)
			break;

		if(strcmp(lineHeader, "v") == 0) // Read vertex position
		{
			pmV3 position;
			fscanf_s(pFile, "%f %f %f\n", &position.x, &position.y, &position.z);
			tempPositions.push_back(position);
		}
		else if(strcmp(lineHeader, "vt") == 0) // Read uv position
		{
			pmV2 uv;
			fscanf_s(pFile, "%f %f %f\n", &uv.x, &uv.y );
			tempUVs.push_back(uv);
		}
		else if(strcmp(lineHeader, "vn") == 0) // Read normal
		{
			pmV3 normal;
			fscanf_s(pFile, "%f %f %f\n", &normal.x, &normal.y, &normal.z);
			tempNormals.push_back(normal);
		}
		else if(strcmp(lineHeader, "f") == 0) // Read Indicies
		{
			uint32 positionIndex[3], uvIndex[3], normalIndex[3];
			int matches = fscanf_s(	pFile, "%d/%d/%d %d/%d/%d %d/%d/%d\n", 
									&positionIndex[0], &uvIndex[0], &normalIndex[0],
									&positionIndex[1], &uvIndex[1], &normalIndex[1],
									&positionIndex[2], &uvIndex[2], &normalIndex[2] );

			if(matches != 9)
			{
				_logError("Reading OBJ file: %s, something's wrong with the indexing format. Try other exporting options.", filePath);
				return false;
			}

			positionIndicies.push_back(positionIndex[0]);
			positionIndicies.push_back(positionIndex[1]);
			positionIndicies.push_back(positionIndex[2]);
			uvIndicies.push_back(uvIndex[0]);
			uvIndicies.push_back(uvIndex[1]);
			uvIndicies.push_back(uvIndex[2]);
			normalIndicies.push_back(normalIndex[0]);
			normalIndicies.push_back(normalIndex[1]);
			normalIndicies.push_back(normalIndex[2]);
		}
	}

	for(uint32 i = 0; i < positionIndicies.size(); ++i)
	{
		uint32 positionIndex = positionIndicies[i];
		uint32 uvIndex = uvIndicies[i];
		uint32 normalIndex = normalIndicies[i];
		pmV3 position = tempPositions[positionIndex - 1];
		pmV2 uv = tempUVs[uvIndex - 1];
		pmV3 normal = tempNormals[normalIndex - 1];

		SVertex vertex = {position, normal, uv, pmV4::white}; // TODO: Read vertex color

		pVertexBuffer->m_vertices.push_back(vertex);
	}

	return true;
}



#if defined FBX
void phCFileSystem::InitFBX()
{
	// Create the FBX manager
	m_pFbxManager = FbxManager::Create();

	// Create IO settings
	m_pFbxIOSettings = FbxIOSettings::Create( m_pFbxManager, IOSROOT );

	// Init the importer
	m_pFbxImporter = FbxImporter::Create( m_pFbxManager, "fbx_importer" );
}
#endif



#if defined FBX
void phCFileSystem::LoadAndParseFBX( const char* filePath )
{
}
#endif
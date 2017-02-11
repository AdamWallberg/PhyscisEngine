#pragma once

//engine
#include "Engine/Utils/phCSingleton.h"
#include "Dependencies/json.hpp"
#include "phGL.h"
//fbx
#if defined FBX
#include <fbxsdk.h>
#endif

class phCVertexData;
class phCIndexData;

// Used to load and manage files.
class phCFileSystem : public phCSingleton< phCFileSystem >
{
public:

	phCFileSystem();
	~phCFileSystem();

	// JSON parsing
	nlohmann::json LoadAndParseJSON( const char* filePath );

	// OBJ parsing
	bool LoadAndParseOBJ( const char* filePath, phCVertexData* pVertexData, phCIndexData* pIndexData );

#if defined FBX
	// FBX parsing
	// TODO: Change return type after proper model implementation
	void LoadAndParseFBX( const char* filePath );
#endif

private:

#if defined FBX
	// Fbx specific stuff
	void InitFBX();
	FbxManager* m_pFbxManager;
	FbxIOSettings* m_pFbxIOSettings;
	FbxImporter* m_pFbxImporter;
#endif
};
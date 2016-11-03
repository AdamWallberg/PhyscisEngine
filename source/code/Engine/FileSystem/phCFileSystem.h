#pragma once

#include "Engine/Utils/phCSingleton.h"
#include "Dependencies/json.hpp"
#include <fbxsdk.h>

// Used to load and manage files.
class phCFileSystem : public phCSingleton< phCFileSystem >
{
public:

	phCFileSystem();
	~phCFileSystem();

	// JSON parsing
	nlohmann::json LoadAndParseJSON( const char* filePath );

	// FBX parsing
	// TODO: Change return type after proper model implementation
	void LoadAndParseFBX( const char* filePath );

private:

	// Fbx specific stuff
	void InitFBX();
	FbxManager* m_pFbxManager;
	FbxIOSettings* m_pFbxIOSettings;
	FbxImporter* m_pFbxImporter;
};
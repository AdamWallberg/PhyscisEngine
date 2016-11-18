#pragma once

#include "Engine/Utils/phCSingleton.h"
#include "Dependencies/json.hpp"
#if defined FBX
#include <fbxsdk.h>
#endif
// Used to load and manage files.
class phCFileSystem : public phCSingleton< phCFileSystem >
{
public:

	phCFileSystem();
	~phCFileSystem();

	// JSON parsing
	nlohmann::json LoadAndParseJSON( const char* filePath );

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
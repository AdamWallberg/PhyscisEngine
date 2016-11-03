#include "phSystem.h"
#include "phCFileSystem.h"
//std
#include <fstream>

phCFileSystem::phCFileSystem()
{
	_logDebug( "Initializing FBX manager.." );
	InitFBX();
}



phCFileSystem::~phCFileSystem()
{
	m_pFbxImporter->Destroy();
	m_pFbxIOSettings->Destroy();
	m_pFbxManager->Destroy();
}



void phCFileSystem::InitFBX()
{
	// Create the FBX manager
	m_pFbxManager = FbxManager::Create();

	// Create IO settings
	m_pFbxIOSettings = FbxIOSettings::Create( m_pFbxManager, IOSROOT );

	// Init the importer
	m_pFbxImporter = FbxImporter::Create( m_pFbxManager, "fbx_importer" );
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



void phCFileSystem::LoadAndParseFBX( const char* filePath )
{
}
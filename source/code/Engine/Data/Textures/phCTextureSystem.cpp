#include "phCTextureSystem.h"

phCTextureSystem::phCTextureSystem()
{
	
}

phCTextureSystem::~phCTextureSystem()
{
	
}

STexture* phCTextureSystem::LoadTexture( std::string filePath, std::string nameOptional )
{
	STexture* pResult = nullptr;

	// Check which filetype texture is
	uint8 dotPos = filePath.find_last_of(".");
	std::string fileType = filePath.substr(dotPos + 1);

	if(fileType == "bmp")
	{
		uint8* pData = nullptr;
		if(!LoadFromBMP(filePath, pData))
		{
			return nullptr;
		}
	}
	else if(fileType == "dds")
	{
		
	}
	else
	{
		_logError("Incorrect filetype: %s", filePath.c_str());
	}
	
	return pResult;
}

bool phCTextureSystem::LoadFromBMP( std::string filePath, uint8* data )
{
	return false;
}

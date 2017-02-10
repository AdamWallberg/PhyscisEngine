#include "phCTextureSystem.h"

phCTextureSystem::phCTextureSystem()
{
	
}

phCTextureSystem::~phCTextureSystem()
{
	for( auto& it : m_textures )
	{
		STexture* pTexture = it.second;

		if( pTexture )
		{
			_logError("Found undestroyed texture, ID: %d", pTexture->ID);

			// Check if data has been saved
			if( pTexture->pData )
			{
				delete[] pTexture->pData;
			}

			delete pTexture;
		}
	}

	m_textures.clear();
}

STexture* phCTextureSystem::LoadTexture( std::string filePath, std::string nameOptional )
{
	STexture* pTexture = newp STexture;

	// Check which filetype texture is
	uint8 dotPos = (uint8)filePath.find_last_of(".");
	std::string fileType = filePath.substr(dotPos + 1);

	if(fileType == "bmp")
	{
		if(!LoadFromBMP(filePath, pTexture))
		{
			return nullptr;
		}
	}
	else if(fileType == "dds")
	{
		// TODO: Implement dds importing
		_logError("No DDS importer implemented");
		return nullptr;
	}
	else
	{
		_logError("Incorrect filetype: %s", filePath.c_str());
	}

	if( !pTexture->pData )
	{
		_logError("Something went wrong!");
		return nullptr;
	}

	// Create the GL texture
	glGenTextures( 1, &pTexture->ID );

	glBindTexture( GL_TEXTURE_2D, pTexture->ID );

	glTexImage2D( GL_TEXTURE_2D, 0, GL_RGB, pTexture->width, pTexture->height, 0, GL_RGB, GL_UNSIGNED_BYTE, pTexture->pData );

	// TODO: IF want to save data n' stuff
	delete[] pTexture->pData;
	pTexture->pData = nullptr;

	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT );
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT );
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR );
	glGenerateMipmap( GL_TEXTURE_2D );

	// If nameOptional has been defined, use that as ID
	m_textures[nameOptional == "" ? filePath : nameOptional] = pTexture;

	return pTexture;
}

void phCTextureSystem::DestroyTexture( std::string textureName )
{
	STexture* pTexture = m_textures[textureName];
	if( pTexture )
	{
		if( pTexture->pData )
		{
			delete[] pTexture->pData;
		}
		m_textures.erase( textureName );
		delete pTexture;
	}
}

void phCTextureSystem::DestroyTexture( const GLuint textureID )
{
	for( auto& it = m_textures.begin(); it != m_textures.end(); ++it )
	{
		STexture* pTexture = it->second;

		if( pTexture && pTexture->ID == textureID )
		{
			// Check if data has been saved
			if( pTexture->pData )
			{
				delete[] pTexture->pData;
			}

			delete pTexture;
			m_textures.erase( it );
			break;
		}
	}
}

void phCTextureSystem::DestroyTexture( STexture* pTargetTexture )
{
	for( auto& it = m_textures.begin(); it != m_textures.end(); ++it )
	{
		STexture* pTexture = it->second;

		if( pTexture && pTexture == pTargetTexture )
		{
			// Check if data has been saved
			if( pTexture->pData )
			{
				delete[] pTexture->pData;
			}
			delete pTexture;
			m_textures.erase( it );
			break;
		}
	}
}

bool phCTextureSystem::LoadFromBMP( std::string filePath, STexture* pTexture )
{
	_logDebug( "Reading image: %s", filePath.c_str() );

	unsigned char header[ 54 ];
	uint16 dataPos;
	uint16 imageSize;

	// Open file
	FILE* pFile;
	fopen_s( &pFile, filePath.c_str(), "rb" );

	if( !pFile )
	{
		_logError( "Couldn't find file!" );
		return false;
	}

	if( fread( header, 1, 54, pFile ) != 54 )
	{
		_logError( "Not a correct BMP file!" );
		fclose( pFile );
		return false;
	}

	if( header[ 0 ] != 'B' || header[ 1 ] != 'M' )
	{
		_logError( "Not a correct BMP file!" );
		fclose( pFile );
		return false;
	}

	if( *( int* )& ( header[ 0x1E ] ) != 0 )
	{
		_logError( "Not a correct BMP file!" );
		fclose( pFile );
		return false;
	}

	if( *( int* )& ( header[ 0x1C ] ) != 24 ) // TODO: Figure out why this doesn't work
	{
		_logError( "Not a correct BMP file!" );
		fclose( pFile );
		return false;
	}

	// Read image info
	dataPos = *( int* )& ( header[ 0x0A ] );
	imageSize = *( int* )& ( header[ 0x22 ] );
	pTexture->width = *( int* )& ( header[ 0x12 ] );
	pTexture->height = *( int* )& ( header[ 0x16 ] );

	if( imageSize == 0 ) imageSize = pTexture->width * pTexture->height * 3;
	if( dataPos == 0 ) dataPos = 54;

	pTexture->pData = new uint8[ imageSize ];

	fread( pTexture->pData, 1, imageSize, pFile );

	fclose( pFile );

	return true;
}

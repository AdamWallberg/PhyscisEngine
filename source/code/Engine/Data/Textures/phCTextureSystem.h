#pragma once
#include "Systems/phServiceLocators.h"

#include "phSystem.h"
#include "phGL.h"
#include <map>

struct STexture
{
	STexture()
		: ID(0)
		, name("")
		, width(0)
		, height(0)
		, pData(nullptr)
	{
	}

	GLuint ID;
	std::string name;
	uint16 width;
	uint16 height;
	uint8* pData;
};

class phCTextureSystem
{
public:

	phCTextureSystem();
	~phCTextureSystem();

	// Name will default to filePath
	STexture* LoadTexture(std::string filePath, std::string nameOptional = "");
	void DestroyTexture(std::string textureName);
	void DestroyTexture(const GLuint textureID);
	void DestroyTexture(STexture* pTexture);

private:

	bool LoadFromBMP(std::string filePath, STexture* pTexture);

	std::map<std::string, STexture*> m_textures;

};

class phCTextureSystemLocator : public phIServiceLocator<phCTextureSystem>
{
};
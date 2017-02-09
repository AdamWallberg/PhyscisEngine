#pragma once
#include "Systems/phServiceLocators.h"

#include "phSystem.h"
#include "phGL.h"
#include <map>

struct STexture
{
	GLuint ID;

};

class phCTextureSystem
{
public:

	phCTextureSystem();
	~phCTextureSystem();

	// Name will default to filePath
	STexture* LoadTexture(std::string filePath, std::string nameOptional = "");
	void UnloadTexture(std::string textureName);
	void UnloadTexture(const GLuint textureID);
	void UnloadTexture(STexture* pTexture);

private:

	bool LoadFromBMP(std::string filePath, uint8* data);

	std::map<std::string, STexture> m_textures;

};

class phCTextureSystemLocator : public phIServiceLocator<phCTextureSystem>
{
};
#pragma once

#include "Systems/phServiceLocators.h"
#include <map>
#include <vector>
#include "Data/Textures/phCTextureSystem.h"
#include "Rendering/Shaders/phIShaderProgram.h"

struct SMaterial
{
	SMaterial()
		: name("")
		, shaderProgram(nullptr)
	{
	}

	std::string	name;
	std::map<std::string, STexture*> textures;
	phIShaderProgram* shaderProgram;
};

class phCMaterialSystem
{
public:

	phCMaterialSystem();
	~phCMaterialSystem();

	SMaterial* GetMaterial(std::string materialName);

private:

	std::vector<SMaterial*> m_materials;

};

class phCMaterialSystemLocator : public phIServiceLocator<phCMaterialSystem>
{
};
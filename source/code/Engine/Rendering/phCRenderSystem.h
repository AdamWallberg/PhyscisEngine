#pragma once

#include "Systems/phServiceLocators.h"
#include "Shaders/phCShaderDefault.h"

class phCRenderSystem
{
public:

	phCRenderSystem();
	~phCRenderSystem();

	void Render();

	// Shaders
	phCShaderDefault* m_pShaderDefault;

private:

	GLuint m_vertexArrayID;

};

class phCRenderSystemLocator : public phIServiceLocator<phCRenderSystem>
{
};
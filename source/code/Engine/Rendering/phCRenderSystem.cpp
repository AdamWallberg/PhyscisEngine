#include "phCRenderSystem.h"
#include "Utils/phLog.h"
#include "Systems/phCModelSystem.h"
#include "phCRenderer.h"

phCRenderSystem::phCRenderSystem()
{
	//glEnable(GL_DEPTH_TEST);
	//glDepthFunc(GL_LESS);

	m_pShaderDefault = new phCShaderDefault("data/shaders/mesh_default_v.glsl", "data/shaders/mesh_default_p.glsl");
}

phCRenderSystem::~phCRenderSystem()
{
	delete m_pShaderDefault;
}


void phCRenderSystem::Render()
{
	// TODO: Camera setup stuff, like clear.. clear is nice
	glClearColor(0.3f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	for(phCModel* pModel : phCModelSystemLocator::GetService()->GetModels())
	{
		for(phCMesh* pMesh : pModel->GetMeshes())
		{
			phCRenderer::RenderMeshDefault(pMesh);
		}
	}
}
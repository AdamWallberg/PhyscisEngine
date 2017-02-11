#include "phCRenderSystem.h"
#include "Utils/phLog.h"
#include "Systems/phCModelSystem.h"
#include "phCRenderer.h"
#include "Camera/phCCameraSystem.h"

phCRenderSystem::phCRenderSystem()
{
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glGenVertexArrays(1, &m_vertexArrayID);
	glBindVertexArray(m_vertexArrayID);

	m_pShaderDefault = newp phCShaderDefault("data/shaders/mesh_default_v.glsl", "data/shaders/mesh_default_p.glsl");
}

phCRenderSystem::~phCRenderSystem()
{
	delete m_pShaderDefault;
	glDeleteVertexArrays(1, &m_vertexArrayID);
}


void phCRenderSystem::Render()
{
	if(!phCCameraSystemLocator::GetService()->GetCurrentCamera())
		return;

	const pmV4 clearColor = phCCameraSystemLocator::GetService()->GetCurrentCamera()->GetClearColor();
	glClearColor(clearColor.r, clearColor.g, clearColor.b, clearColor.a);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	for(phCModel* pModel : phCModelSystemLocator::GetService()->GetModels())
	{
		for(phCMesh* pMesh : pModel->GetMeshes())
		{
			phCRenderer::RenderMeshDefault(pMesh);
		}
	}
}
#include "phCRenderer.h"
#include "Camera/phCCamera.h"
#include "Camera/phCCameraSystem.h"
#include "phGL.h"
#include "phCRenderSystem.h"
#include "Data/Models/phCModel.h"

void phCRenderer::RenderMeshDefault(phCMesh* pMesh)
{
	phCCamera* pCamera = phCCameraSystemLocator::GetService()->GetCurrentCamera();
	
	GLuint programID = phCRenderSystemLocator::GetService()->m_pShaderDefault->GetProgramID();
	glUseProgram(programID);

	// Get shader uniform handles
	GLint uWorldViewProjMatrixID = glGetUniformLocation(programID, "u_matWorldViewProj");

	// Calc matrices
	pmMat4 matWorld = pMesh->m_matrix * pMesh->m_pParent->m_matrix;
	pmMat4 matViewProj = pCamera->GetProjectionMatrix() * pCamera->GetTransformationMatrix();
	pmMat4 matWorldViewProj = matViewProj * matWorld;

	// Set uniforms
	glUniformMatrix4fv(uWorldViewProjMatrixID, 1, GL_FALSE, &matWorldViewProj.elements[0]);

	// Vertex buffers
	glEnableVertexAttribArray(0);
	pMesh->m_pVertexBuffer->Bind();
	glVertexAttribPointer(
		0,
		sizeof(SVertex) / 4,
		GL_FLOAT,
		GL_FALSE,
		0,
		(void*)0
	);

	// Index buffers
	pMesh->m_pIndexBuffer->Bind();

	// Draw that shit
	glDrawElements(GL_TRIANGLES, pMesh->m_pIndexBuffer->GetNumIndicies(), GL_UNSIGNED_INT, (void*) 0);
	//glDrawArrays(GL_TRIANGLES, 0, pMesh->m_pVertexBuffer->GetNumVertices());
	// Disable attribute buffers
	glDisableVertexAttribArray(0);
}

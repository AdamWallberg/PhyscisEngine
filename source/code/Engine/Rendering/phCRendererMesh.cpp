#include "phCRenderer.h"
#include "Camera/phCCamera.h"
#include "Camera/phCCameraSystem.h"
#include "phGL.h"
#include "phCRenderSystem.h"
#include "Data/Models/phCModel.h"

void phCRenderer::RenderMeshDefault(phCMesh* pMesh)
{
	if(!pMesh->GetShouldRender())
		return;

	phCCamera* pCamera = phCCameraSystemLocator::GetService()->GetCurrentCamera();
	if(!pCamera)
		return;

	GLuint programID = phCRenderSystemLocator::GetService()->m_pShaderDefault->GetProgramID();
	glUseProgram(programID);

	// Get shader uniform handles
	GLint uWorldMatrixID = glGetUniformLocation(programID, "u_matWorld");
	GLint uViewMatrixID = glGetUniformLocation(programID, "u_matView");
	GLint uProjMatrixID = glGetUniformLocation(programID, "u_matProj");
	GLint uWorldViewProjMatrixID = glGetUniformLocation(programID, "u_matWorldViewProj");
	
	pm::mat4 matWorld = pMesh->m_matrix * pMesh->m_pParent->m_matrix;
	pm::mat4 matView = pCamera->GetTransformationMatrix().GetViewMatrix();
	pm::mat4 matProj = pCamera->GetProjectionMatrix();
	pm::mat4 matWorldViewProj = matWorld * matView * matProj;

	// Set uniforms
	glUniformMatrix4fv(uWorldMatrixID, 1, GL_FALSE, &matWorld.elements[0]);
	glUniformMatrix4fv(uViewMatrixID, 1, GL_FALSE, &matView.elements[0]);
	glUniformMatrix4fv(uProjMatrixID, 1, GL_FALSE, &matProj.elements[0]);
	glUniformMatrix4fv(uWorldViewProjMatrixID, 1, GL_FALSE, &matWorldViewProj.elements[0]);

	// Bind textures
	GLuint uTextureID = glGetUniformLocation(programID, "u_textureSampler");
	glActiveTexture(GL_TEXTURE0);
	// TODO: Bind specified texture
	// pMesh->GetMaterial().textureID or whatever
	glBindTexture( GL_TEXTURE_2D, 1 );

	glUniform1i(uTextureID, 0);

	// Vertex buffers
#define BUFFER_OFFSET(i) ((char*) NULL + (i))
	
	pMesh->m_pVertexBuffer->Bind();

	// Positions
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3,	GL_FLOAT, GL_FALSE,	sizeof(SVertex), BUFFER_OFFSET(0));
	// Normals
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3,	GL_FLOAT, GL_FALSE,	sizeof(SVertex), BUFFER_OFFSET(sizeof(pm::vec3)));
	// UV's
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 2,	GL_FLOAT, GL_FALSE,	sizeof(SVertex), BUFFER_OFFSET(sizeof(pm::vec3) + sizeof(pm::vec3)));
	// Colors
	glEnableVertexAttribArray(3);
	glVertexAttribPointer(3, 4,	GL_FLOAT, GL_FALSE,	sizeof(SVertex), BUFFER_OFFSET(sizeof(pm::vec3) + sizeof(pm::vec3) + sizeof(pm::vec2)));

	// Index buffers
	pMesh->m_pIndexBuffer->Bind();
	
	// Draw that shit
	glDrawElements(GL_TRIANGLES, pMesh->m_pIndexBuffer->GetNumIndicies(), GL_UNSIGNED_INT, (void*) 0);
	//glDrawArrays(GL_TRIANGLES, 0, pMesh->m_pVertexBuffer->GetNumVertices());
	// Disable attribute buffers
	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
	glDisableVertexAttribArray(2);
	glDisableVertexAttribArray(3);

}

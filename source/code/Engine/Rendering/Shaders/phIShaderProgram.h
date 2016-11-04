#pragma once

#include <phSystem.h>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

class phIShaderProgram
{
public:

	enum EShaderType
	{
		TYPE_VERTEX_SHADER = GL_VERTEX_SHADER,
		TYPE_FRAGMENT_SHADER = GL_FRAGMENT_SHADER
	};

	virtual ~phIShaderProgram(){}
	
	virtual const GLuint GetProgramID() = 0;

protected:

	GLuint CreateShader( const char* filePath, EShaderType type );
	void LinkProgram( const GLuint& programID );

};

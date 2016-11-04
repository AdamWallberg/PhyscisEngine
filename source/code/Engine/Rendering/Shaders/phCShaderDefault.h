#pragma once

#include "phIShaderProgram.h"

// Default shader program that uses a vertex and fragment shader.
class phCShaderDefault : public phIShaderProgram
{
public:

	phCShaderDefault( const char* vertexShaderPath, const char* fragmentShaderPath );

	~phCShaderDefault();

	GLuint const GetProgramID() override { return m_programID; };

private:

	GLuint m_programID;

};

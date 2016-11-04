#include "phSystem.h"

#include "phCShaderDefault.h"

phCShaderDefault::phCShaderDefault( const char* vertexShaderPath, const char* fragmentShaderPath )
{
	// Create the vertex shader
	GLuint vertexShaderID = CreateShader( vertexShaderPath, EShaderType::TYPE_VERTEX_SHADER );
	
	// Create the fragment shader
	GLuint fragmentShaderID = CreateShader( fragmentShaderPath, EShaderType::TYPE_FRAGMENT_SHADER );

	// Create a new program
	m_programID = glCreateProgram();

	// Attach shaders
	glAttachShader( m_programID, vertexShaderID );
	glAttachShader( m_programID, fragmentShaderID );

	// Link the program
	LinkProgram( m_programID );

	// Detach shaders
	glDetachShader( m_programID, vertexShaderID );
	glDetachShader( m_programID, fragmentShaderID );

	// Delete shaders
	glDeleteShader( vertexShaderID );
	glDeleteShader( fragmentShaderID );
}



phCShaderDefault::~phCShaderDefault()
{
	glDeleteProgram( m_programID );
}

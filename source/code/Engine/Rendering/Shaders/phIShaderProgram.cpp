#include "phIShaderProgram.h"
#include <string>
#include <fstream>
#include <vector>

GLuint phIShaderProgram::CreateShader( const char* filePath, EShaderType type )
{
	GLuint shaderID = glCreateShader( type );

	// Read the shader from file
	std::string shaderData;
	std::ifstream shaderStream( filePath, std::ios::in );
	if( !shaderStream.is_open() )
	{
		_logError( "Couldn't read shader file: %s", filePath );
	}
	else // Opened file successfully
	{
		std::string line = "";

		while( getline( shaderStream, line ) )
			shaderData += "\n" + line;

		shaderStream.close();
	}

	// Compile the shader
	GLint result = GL_FALSE;
	int infoLogLength;

	_logDebug( "Compiling shader: %s", filePath );
	const char* shaderSourcePointer = shaderData.c_str();
	glShaderSource( shaderID, 1, &shaderSourcePointer, nullptr );
	glCompileShader( shaderID );

	// Check shader
	glGetShaderiv( shaderID, GL_COMPILE_STATUS, &result );
	glGetShaderiv( shaderID, GL_INFO_LOG_LENGTH, &infoLogLength );
	if( infoLogLength > 0 )
	{
		std::vector<char> errorMessage( infoLogLength + 1 );
		glGetShaderInfoLog( shaderID, infoLogLength, nullptr, &errorMessage[0] );
		_logError( "%s", &errorMessage[0] );
	}

	return shaderID;
}


void phIShaderProgram::LinkProgram( const GLuint& programID )
{
	_logDebug( "Linking program: %d", programID );
	glLinkProgram( programID );

	// Check the program
	GLint result = GL_FALSE;
	int infoLogLength;

	glGetProgramiv( programID, GL_LINK_STATUS, &result );
	glGetProgramiv( programID, GL_INFO_LOG_LENGTH, &infoLogLength );
	if( infoLogLength > 0 )
	{
		std::vector<char> errorMessage( infoLogLength );
		glGetProgramInfoLog( programID, infoLogLength, nullptr, &errorMessage[0] );
		_logError( "%s", &errorMessage[0] );
	}
}
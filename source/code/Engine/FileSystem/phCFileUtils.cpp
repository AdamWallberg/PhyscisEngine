#include "phSystem.h"
#include "phCFileUtils.h"
//std
#include "memdisable.h"
#include <fstream>
#include <string>
#include "memenable.h"

nlohmann::json phCFileUtils::LoadAndParseJSON( const char* filePath )
{
	nlohmann::json j;

	// Read file data
	std::ifstream file( filePath );
	if( file.is_open() )
	{
		std::stringstream buffer;
		buffer << file.rdbuf();
		std::string content = buffer.str();
		file.close();
		
		// Parse json data
		j = nlohmann::json::parse( content.c_str() );
	}

	return j;

}
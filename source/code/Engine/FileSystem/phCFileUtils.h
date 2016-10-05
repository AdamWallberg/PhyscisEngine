#pragma once

#include "Dependencies/json.hpp"

class phCFileUtils
{
public:

	static nlohmann::json LoadAndParseJSON( const char* filePath );

};
#pragma once

#include "memdisable.h"
#include "Dependencies/json.hpp"
#include "memenable.h"

class phCFileUtils
{
public:

	static nlohmann::json LoadAndParseJSON( const char* filePath );

};
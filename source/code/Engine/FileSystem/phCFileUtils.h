#pragma once

#include "memdisable.h"
#include "json.hpp"
#include "memenable.h"

class phCFileUtils
{
public:

	static nlohmann::json LoadAndParseJSON( const char* filePath );

};
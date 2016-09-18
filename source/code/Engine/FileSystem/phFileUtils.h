#pragma once
#pragma once

// std
#include <map>
#include <fstream>

// Opens and reads data from files
class phFileReader
{
public:

	// Opens a file and returns its id
	static int openFile( const char* filePath );	
	static void closeFile( int fileID );
	static const char* getData( int fileID );

private:

	static std::map< int, std::string > files;

};
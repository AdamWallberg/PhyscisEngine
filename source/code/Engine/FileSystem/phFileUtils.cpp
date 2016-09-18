#include "phFileUtils.h"
// engine 
#include "Engine/Utils/phLog.h"
// std
#include <iostream>
#include <string>



std::map< int, std::string > phFileReader::files;



int phFileReader::openFile( const char* filePath )
{
	int ID = phFileReader::files.size();

	std::ifstream stream( filePath );
	std::string line;

	if( stream.is_open() )
	{
		while( std::getline( stream, line ) )
		{
			phFileReader::files[ID].append( line );
		}

		return ID;

	}
	else
	{
		_log( "Couldn't open file %s!\n", filePath );
	
		return -1;
	}
}



void phFileReader::closeFile( int fileID )
{
	phFileReader::files.erase( fileID );
}



const char* phFileReader::getData( int fileID )
{
	return phFileReader::files[ fileID ].c_str();
}
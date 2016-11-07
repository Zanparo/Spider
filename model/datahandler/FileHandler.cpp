/**
 * Project FileManager DLL
 */

#include "FileHandler.h"
#ifdef __linux__
#include "CUFile.h"
#elif _WIN32
#include "CWFile.h"
#endif

/**
 * FileHandler implementation
 */

/**
 * Add a file to _files. Returns ID of _file on success, otherwise -1
 * @param string
 * @return int
 */

void		FileHandler::add(const std::string path)
{
	IFile	*file;

	#if defined(WIN32)
		file = new CWFile(path);
	#elif(UNIX)
		file = new CUFile(path);
	#endif
		this->files.push_back(file);
}

/**
  *  Returns file handler for given id.
  *
  */


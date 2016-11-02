/**
 * Project FileManager DLL
 */


#include "FileHandler.h"

/**
 * FileHandler implementation
 */


/**
 * Constructor of FileHandler class.
 */
FileHandler::FileHandler() {
	std::cout << "FileHandler constructor" << std::endl;
	_nbfiles = 0;
}

FileHandler::~FileHandler() {
}

/**
 * Add a file to _files. Returns ID of _file on success, otherwise -1
 * @param string
 * @return int
 */

int FileHandler::AddFile(std::string const& path) {
#if defined(WIN32)
	IFile *newitem = new CWFile;
#elif(UNIX)
	IFile *newitem = new CUFile;
#endif
	if (newitem->open(path) == true) {
		this->_files.insert(std::pair<IFile*, int>(newitem, _nbfiles));
		_nbfiles++;
		return (_nbfiles - 1);
	}
	return (-1);
}

/**
  *  Returns file handler for given id.
  *
  */


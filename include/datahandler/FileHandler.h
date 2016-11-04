/**
 * Project FileManager DLL
 */

#ifndef _FILEHANDLER_H
#define _FILEHANDLER_H
#include "IFile.h"
#include "CWFile.h"
#include <iostream>
#include <string>
#include <map>


class FileHandler {
public: 
    
    /**
     * Constructor of FileHandler class.
     */
    FileHandler();
	~FileHandler();
    
    /**
     * Add a file to _files. Return true if succeed.
     * @param string
     */
	int AddFile(std::string const& path);

private: 
    /**
     * List of IFile*. Used to contains pointers on files needed by the DataHandler.
     */
    std::map<IFile*, int> _files;
	int _nbfiles;
};

#endif //_FILEHANDLER_H
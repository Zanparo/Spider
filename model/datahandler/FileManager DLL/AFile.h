/**
 * Project FileManager DLL
 */


#ifndef _AFILE_H
#define _AFILE_H

#include "IFile.h"
#include <string>

class AFile: public IFile {
public: 
    
    /**
     * @param string
     */
	AFile();
	 AFile(std::string const& c);
	 ~AFile();

    std::string _filename;
    int _size;
    std::string _path;
};

#endif //_AFILE_H
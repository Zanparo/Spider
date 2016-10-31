/**
 * Project FileManager DLL
 */


#ifndef _AFILE_H
#define _AFILE_H

#include "IFile.h"


class AFile: public IFile {
public: 
    
    /**
     * @param string
     */
    void AFile(void string);
private: 
    string _filename;
    int _size;
    string _path;
};

#endif //_AFILE_H
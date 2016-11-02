/**
 * Project FileManager DLL
 */


#ifndef _CWFILE_H
#define _CWFILE_H

#include "AFile.h"
#include <string>
#include <Windows.h>
#include <exception>
#include <fstream>
class CWFile : public AFile {
public: 
    
	CWFile() {}
	CWFile(std::string const& filename);
	~CWFile();

    /**
     * Open the Windows file. Returns bool if succeed.
     */
    bool open(std::string const& path);
	bool open();
    
    /**
     * Close the Windows file. Returns true if succeed.
     */
    bool close();
    
    /**
     * Read the n characters in the file, depending on the int parameter. Returns the string read.
     * @param int
     */
    std::string read(int n);
    
    /**
     * Write the string passed in parameter in the file. Returns the number of characters successfully wrote.
     * @param string
     */
    int write(std::string const& towrite);
private: 
     std::fstream _file;
};

#endif //_CWFILE_H
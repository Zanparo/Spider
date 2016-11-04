/**
 * Project FileManager DLL
 */


#ifndef _IFILE_H
#define _IFILE_H

#include <string>

class IFile {
public: 
    
    /**
     * Open the file and return true for sucess
     */
    bool virtual open(std::string const& path) = 0;
    
    /**
     * Close a file. Returns true if suceed.
     */
    bool virtual close() = 0;
    
    /**
     * Read the n characters in the file, depending on the int parameter. Returns the string read.
     * @param int
     */
    std::string virtual read(int n) = 0;
    
    /**
     * Write the string passed in parameter in the file. Returns the number of characters successfully wrote.
     * @param string
     */
    int virtual write(std::string const& towrite) = 0;
};

#endif //_IFILE_H
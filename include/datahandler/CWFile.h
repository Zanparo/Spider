/**
 * Project FileManager DLL
 */


#ifndef _CWFILE_H
# define _CWFILE_H

# include <string>
# include <Windows.h>
# include <exception>
# include <fstream>
# include "FileHandler.h"

class CWFile : public IFile, public AFile {

	std::fstream _file;

public: 
    
	CWFile(std::string const& _path) : AFile(_path) {};

    /**
     * Open the Windows file. Returns bool if succeed.
     */
	bool			open(void);
    
    /**
     * Close the Windows file. Returns true if succeed.
     */
    bool			close(void);
    
    /**
     * Read the n characters in the file, depending on the int parameter. Returns the string read.
     * @param int
     */
    std::string		read(int);
    
    /**
     * Write the string passed in parameter in the file. Returns the number of characters successfully wrote.
     * @param string
     */
    int				write(std::string const&);

};

#endif //_CWFILE_H
/**
 * Project FileManager DLL
 */


#ifndef _FILEHANDLER_H
#define _FILEHANDLER_H

class FileHandler {
public: 
    
    /**
     * Constructor of FileHandler class.
     */
    void FileHandler();
    
    /**
     * Add a file to _files. Return true if succeed.
     * @param string
     */
    bool AddFile(void string);
private: 
    /**
     * List of IFile*. Used to contains pointers on files needed by the DataHandler.
     */
    List<IFile*> _files;
};

#endif //_FILEHANDLER_H
/**
* Project FileManager DLL
*/

#ifndef CW_FILEHANDLER_H
# define CW_FILEHANDLER_H

# include <windows.h>
# include "FileHandler.h"
# include "CWFile.h"

////////////////////////////////////////////////////
// File Handler
////////////////////////////////////////////////////

class CWFileHandler : public IFileHandler {

	int			index;

	bool		writeFromFile(IFile *, std::string &);

public:

	int			initStream(std::string, unsigned int);
	void		closeStream(void);
	void		showStream(void);
	bool		insertDataToStream(std::string);
	std::string	extractDataFromStream(int);
	void		removeLocalData(int);
};

#endif //CW_FILEHANDLER_H
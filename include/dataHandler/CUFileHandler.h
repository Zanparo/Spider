/**
* Project FileManager DLL
*/

#ifndef CU_FILEHANDLER_H
# define CU_FILEHANDLER_H

# include "FileHandler.h"
# include "CUFile.h"

////////////////////////////////////////////////////
// File Handler
////////////////////////////////////////////////////

class CUFileHandler : public IFileHandler {

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

#endif //CU_FILEHANDLER_H
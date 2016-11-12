#ifndef DATA_HANDLER_H__
# define DATA_HANDLER_H__

# include <iostream>
# include <sstream>
# include "DLDictionary.h"
#ifdef __linux__
#include "FileHandler.h"
#elif _WIN32
#include "CWFileHandler.h"
#endif

/////////////////////////////////////////////
/////////////////////////////////////////////

typedef struct			s_Packet {
	unsigned char		_id;
	unsigned short		_status;
	bool				_next;
	size_t				_size;
	char *				_data;
}						Packet;

/////////////////////////////////////////////
/////////////////////////////////////////////

class	IDataHandler {
public:
	IFileHandler			*fileHandler;

};

/////////////////////////////////////////////
/////////////////////////////////////////////

class		DataHandler : public IDataHandler {

	//std::stringstream flux;

public:

	DataHandler() {
	#ifdef __linux__
		this->fileHandler = NULL;
	#elif _WIN32
		this->fileHandler = new CWFileHandler();
	#endif
	}

	//void parser(Packet const& Mess);
};

typedef		IDataHandler* (*_getDataHandler)(void);

#endif /* !DATA_HANDLER_H__ */
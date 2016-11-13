#ifndef DATA_HANDLER_H__
# define DATA_HANDLER_H__

# include <iostream>
# include <sstream>
# include "DLDictionary.h"
# include "XMLSerializer.h"
#ifdef __linux__
#include "FileHandler.h"
#elif _WIN32
#include "CWFileHandler.h"
#endif

/////////////////////////////////////////////
/////////////////////////////////////////////

typedef struct			s_Packet {

	struct s_Packet(unsigned char id, unsigned short status, bool next, size_t size, char *data)
		: _id(id), _status(status), _next(next), _size(size), _data(data) {};

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
	ISerializer				*serializer;

};

/////////////////////////////////////////////
/////////////////////////////////////////////

class		DataHandler : public IDataHandler {

	//std::stringstream flux;

public:

	DataHandler() {
	#ifdef __linux__
		this->fileHandler = new CUFileHandler();
	#elif _WIN32
		this->fileHandler = new CWFileHandler();
	#endif
		this->serializer = new XMLSerializer();
	}

	//void parser(Packet const& Mess);
};

typedef		IDataHandler* (*_getDataHandler)(void);

#endif /* !DATA_HANDLER_H__ */
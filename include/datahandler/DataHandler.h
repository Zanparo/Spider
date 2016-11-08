#ifndef DATA_HANDLER_H__
# define DATA_HANDLER_H__

# include <iostream>
# include <sstream>
# include "DLDictionary.h"
# include "FileHandler.h"

typedef struct			s_Packet {
	unsigned char		_id;
	unsigned short		_status;
	bool				_next;
	size_t				_size;
	char *				_data;
}						Packet;

class		DataHandler {

	//std::stringstream flux;

public:

	FileHandler			fileHandler;

	void	test2(void);

	void	test(void) {
		this->test2();
		std::cout << "Hello test" << std::endl;
	};

	//void parser(Packet const& Mess);
};

//
// SPIDER DYNAMIC LIBRARY STANDARDS
//
// Functions type MUST be defined as the name of the function preceded by "_"
//

typedef		DataHandler* (*_getDataHandler)(void);

#endif /* !DATA_HANDLER_H__ */
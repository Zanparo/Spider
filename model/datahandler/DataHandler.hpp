#pragma once
#pragma once
#include <iostream>
#include <sstream>

typedef struct		s_Message {
	unsigned char	_id;
	unsigned short	_status;
	bool			_next;
	size_t			_size;
	char			*_data;
}					t_Mess;

class				DataHandler {
public:
	DataHandler();
	~DataHandler();
	void	parser(t_Mess const& Mess);

private:
	std::stringstream flux;
};
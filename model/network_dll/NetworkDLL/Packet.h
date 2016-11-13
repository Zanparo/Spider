#pragma once
#include <cstdint>

typedef struct	s_Packet
{
	//Construct
	struct s_Packet(/*unsigned char id, */uint16_t status, char next, uint32_t size, char *data) :
		/*_id(id),*/ _status(status), _next(next), _size(size), _data(data) {};
	//Values
	//unsigned char	_id;
	uint16_t	_status;
	char		_next;
	uint32_t	_size;
	char		*_data;
}				Packet;


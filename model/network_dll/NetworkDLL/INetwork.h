#pragma once
#include						"stdafx.h"

class							INetwork
{
public:
	virtual						~INetwork() {};
	virtual int					init(std::string) = 0;
	virtual void				kill() = 0;
	virtual std::string			get_data_recevied() = 0;
	virtual void				send_data(char *) = 0;
};



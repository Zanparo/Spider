#pragma once
# include						<boost\asio.hpp>
# include						"stdafx.h"
# include						"INetwork.h"
# include						"client.h"

class							clientManager : public INetwork
{
public:
	clientManager();
	~clientManager();
	int							init(std::string);
	void						kill();
	std::string					get_data_recevied();
	void						send_data(char *);

protected:
	client						*services_;
	boost::asio::io_service		io_service;
};


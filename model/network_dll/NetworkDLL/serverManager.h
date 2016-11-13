#pragma once
# include						<boost\asio.hpp>
# include						"stdafx.h"
# include						"INetwork.h"
# include						"server.h"

class							serverManager : public INetwork
{
public:
	serverManager();
	~serverManager();
	int							init(std::string);
	void						kill();
	std::string					get_data_recevied();
	void						send_data(char *);
protected:
	server						*services_;
	boost::asio::io_service		io_service;
};


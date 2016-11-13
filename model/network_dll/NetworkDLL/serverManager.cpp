#pragma once
# include					"stdafx.h"
# include					"serverManager.h"

serverManager::serverManager()
{
}

serverManager::~serverManager()
{
}

int							serverManager::init(std::string port)
{
	try
	{
		server s(io_service, std::atoi(port.c_str()));

		io_service.run();
	}
	catch (std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << "\n";
	}
	return (0);
}

void						serverManager::kill()
{
	delete(this);
}

std::string					serverManager::get_data_recevied()
{
	session &ses = services_->get_session(0);
	std::string datarecevied = ses.get_data_recieved();
	return (datarecevied);
}

void						serverManager::send_data(char *data)
{
	session &ses = services_->get_session(0);
	ses.send_data(data);
}

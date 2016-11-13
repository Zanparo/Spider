#pragma once
# include						"stdafx.h"
# include						"clientManager.h"

clientManager::clientManager()
{
}

clientManager::~clientManager()
{
}

int								clientManager::init(std::string ipport)
{
	try
	{
		std::string				del;
		std::string				ip;
		std::string				port;

		del = "|";
		ip = ipport.substr(0, ipport.find(del));
		ipport.erase(0, ipport.find(del) + del.length());
		port = ipport.substr(0, ipport.find(del));

		boost::asio::ip::tcp::resolver resolver(io_service);
		boost::asio::ip::tcp::resolver::query query(ip.c_str(), port.c_str());
		boost::asio::ip::tcp::resolver::iterator iterator = resolver.resolve(query);

		boost::asio::ssl::context ctx(boost::asio::ssl::context::sslv23);
		ctx.load_verify_file("./cert/server.pem");

		services_ = new client(io_service, ctx, iterator);

		io_service.run();
	}
	catch (std::exception& e)
	{
		std::cerr << "Exception : " << e.what() << "\n";
	}
	return (0);
}

void							clientManager::kill()
{
	delete(this);
	return;
}

std::string						clientManager::get_data_recevied()
{
	return (services_->read());
}

void							clientManager::send_data(char *data)
{
	services_->write(data);
}



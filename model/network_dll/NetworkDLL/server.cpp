#pragma once
# include						"stdafx.h"
# include						"session.h"
# include						"server.h"

server::server(boost::asio::io_service& io_service, unsigned short port) : io_service_(io_service), acceptor_(io_service, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), port)), context_(boost::asio::ssl::context::sslv23)
{
	std::cout << "server::server()" << std::endl;
	context_.set_options(boost::asio::ssl::context::default_workarounds
		| boost::asio::ssl::context::no_tlsv1_2
		| boost::asio::ssl::context::single_dh_use);
	context_.set_password_callback(boost::bind(&server::get_password, this));
	context_.use_certificate_chain_file("./cert/server.pem");
	context_.use_private_key_file("./cert/server.key", boost::asio::ssl::context::pem);
	start_accept();
}

server::~server()
{
}

std::string						server::get_password() const
{
	return "pasword";
}

void							server::start_accept()
{
	session* new_session = new session(io_service_, context_);
	sessions_.push_back(new_session);
	acceptor_.async_accept(new_session->socket(),
		boost::bind(&server::handle_accept, this, new_session,
			boost::asio::placeholders::error));
}

void							server::handle_accept(session* new_session, const bool error)
{
	if (!error)
	{
		new_session->start();
	}
	else
	{
		delete new_session;
	}
	start_accept();
}

session							&server::get_session(int n)
{
	session* sesref = NULL;
	if (sessions_.size() < n)
		sesref = sessions_[n];
	return(std::ref(*sesref));
}

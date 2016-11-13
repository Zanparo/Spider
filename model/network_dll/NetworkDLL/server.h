#pragma once
# include					<cstdlib>
# include					<iostream>
# include					<boost\asio.hpp>
# include					<boost\bind.hpp>
# include					<boost\asio\ssl.hpp>
# include					"session.h"
# include					"IServer.h"

class						server : public IServer
{
public:
	server(boost::asio::io_service&, unsigned short);
	~server();
	std::string				get_password() const;
	void					start_accept();
	void					handle_accept(session *new_session, const bool error);
	session					&get_session(int n);
private:
	boost::asio::io_service&		io_service_;
	boost::asio::ip::tcp::acceptor	acceptor_;
	boost::asio::ssl::context		context_;
	std::vector<session *>			sessions_;
};
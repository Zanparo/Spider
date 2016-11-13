#pragma once
# include							<cstdlib>
# include							<iostream>
# include							<vector>
# include							<boost\asio.hpp>
# include							<boost\bind.hpp>
# include							<boost\asio\ssl.hpp>
# include							"ISession.h"

typedef boost::asio::ssl::stream<boost::asio::ip::tcp::socket> ssl_socket;

class		session : public ISession
{
public:
	session(boost::asio::io_service&, boost::asio::ssl::context&);
	~session();
	ssl_socket::lowest_layer_type&	socket();
	void							start();
	void							handle_handshake(const bool error);
	void							handle_read(const bool error, size_t bytes_transferred);
	void							handle_write(const bool error);
	std::string						get_data_recieved();
	void							send_data(const std::string data);
private:
	ssl_socket						socket_;
	enum { max_length = 4096 };
	char							data_[max_length];
	std::string						buffer_;
	std::vector<std::string>		*recieved_;
};

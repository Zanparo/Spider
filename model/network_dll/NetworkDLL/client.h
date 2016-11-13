#pragma once

#include <cstdlib>
#include <iostream>
#include <vector>
#include <boost\asio.hpp>
#include <boost\bind.hpp>
#include <boost\asio\ssl.hpp>
#include "Iclient.h"

enum { max_length = 1024 };

class client : public Iclient
{
public:
	client(boost::asio::io_service&, boost::asio::ssl::context&, boost::asio::ip::tcp::resolver::iterator);
	~client();
	//bool verify_certificate(bool, boost::asio::ssl::verify_context&);
	void handle_connect(const bool);
	void handle_handshake(const bool);
	void handle_write(const bool, size_t);
	void handle_read(const bool, size_t);
	void handler(const bool, size_t);
	std::string read();
	void write(char *);
private:
	boost::asio::ssl::stream<boost::asio::ip::tcp::socket> socket_;
	char request_[max_length];
	char reply_[max_length];
	std::vector<std::string> *rep_;
	std::vector<std::string>		*recieved_;
};
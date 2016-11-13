#pragma once
# include "stdafx.h"
# include "client.h"

client::client(boost::asio::io_service& io_service, boost::asio::ssl::context& context, boost::asio::ip::tcp::resolver::iterator endpoint_iterator) : socket_(io_service, context)
{
	socket_.set_verify_mode(boost::asio::ssl::verify_peer);
	boost::asio::async_connect(socket_.lowest_layer(), endpoint_iterator, boost::bind(&client::handle_connect, this, boost::asio::placeholders::error));
	rep_ = new std::vector<std::string>();
}

client::~client()
{
}

void						client::handle_connect(bool error)
{
	if (!error)
	{
		socket_.async_handshake(boost::asio::ssl::stream_base::client, boost::bind(&client::handle_handshake, this, boost::asio::placeholders::error));
	}
}

void						client::handle_handshake(const bool error)
{
	if (!error)
	{
		char req[100] = "handshake";
		size_t request_length = strlen(req);

		boost::asio::async_write(socket_, boost::asio::buffer(req, request_length), boost::bind(&client::handler, this, boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));
	}
}

void						client::handler(const bool error, size_t bytes_transferred)
{
}

void						client::handle_write(const bool error, size_t bytes_transferred)
{
	if (!error)
	{
		boost::asio::async_read(socket_,
			boost::asio::buffer(reply_, bytes_transferred),
			boost::bind(&client::handler, this,
				boost::asio::placeholders::error,
				boost::asio::placeholders::bytes_transferred));
	}
}

void						client::handle_read(const bool error, size_t bytes_transferred)
{
	std::string get(reply_);
	recieved_->push_back(get);
}

void						client::write(char *data)
{
	size_t request_length = strlen(data);
	boost::asio::async_write(socket_, boost::asio::buffer(data, request_length), boost::bind(&client::handle_write, this, boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));
}

std::string					client::read()
{
	std::string ret;

	for (auto const& value : *rep_) {
		ret += value;
	}
	rep_ = new std::vector<std::string>();
	return (ret);
}
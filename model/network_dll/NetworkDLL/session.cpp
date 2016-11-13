#pragma once
# include						"stdafx.h"
# include						"session.h"

session::session(boost::asio::io_service& io_service, boost::asio::ssl::context& context) : socket_(io_service, context)
{
	recieved_ = new std::vector<std::string>();
}

session::~session()
{
}

ssl_socket::lowest_layer_type&	session::socket()
{
	return socket_.lowest_layer();
}

void							session::start()
{
	socket_.async_handshake(boost::asio::ssl::stream_base::server, boost::bind(&session::handle_handshake, this, boost::asio::placeholders::error));
}

void							session::handle_handshake(const bool error)
{
	if (!error)
	{
		socket_.async_read_some(boost::asio::buffer(data_, max_length), boost::bind(&session::handle_read, this, boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));
	}
	else
	{
		delete this;
	}
}

void							session::handle_read(const /*boost::system::error_code&*/bool error, size_t bytes_transferred)
{
	if (!error)
	{
		boost::asio::async_write(socket_, boost::asio::buffer(data_, bytes_transferred), boost::bind(&session::handle_write, this, boost::asio::placeholders::error));
		if (bytes_transferred == max_length)
		{
			std::string buf(data_);
			recieved_->push_back(buf);
		}
		else
		{
			std::string buf;
			int n = -1;
			while (++n < bytes_transferred)
				buf += data_[n];
			recieved_->push_back(buf);
		}
	}
	else
	{
		delete this;
	}
}

void							session::handle_write(const /*boost::system::error_code&*/bool error)
{
	if (!error)
	{
		socket_.async_read_some(boost::asio::buffer(data_, max_length), boost::bind(&session::handle_read, this, boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));
	}
	else
	{
		delete this;
	}
}

std::string						session::get_data_recieved()
{
	std::string ret;
	for (auto const& value : *recieved_) {
		ret += value;
	}
	recieved_ = new std::vector<std::string>();
	return(ret);
}

void							session::send_data(const std::string data)
{
	socket_.async_read_some(boost::asio::buffer(data_, max_length), boost::bind(&session::handle_read, this, boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));
	return;
}
#pragma once
# include					<cstdlib>
# include					<iostream>
# include					<boost\asio.hpp>
# include					<boost\bind.hpp>
# include					<boost\asio\ssl.hpp>

class						Iclient
{
public:
	virtual					~Iclient() {};
	virtual void			handle_connect(const bool) = 0;
	virtual void			handle_handshake(const bool) = 0;
	virtual void			handle_write(const bool, size_t) = 0;
	virtual void			handle_read(const bool, size_t) = 0;
};


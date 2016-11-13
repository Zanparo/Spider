#pragma once
# include						<cstdlib>
# include						<iostream>

class							ISession
{
public:
	virtual						~ISession() {};
	virtual void				start() = 0;
	virtual void				handle_handshake(const bool error) = 0;
	virtual void				handle_read(const bool error, size_t bytes_transferred) = 0;
	virtual void				handle_write(const bool error) = 0;
	virtual std::string			get_data_recieved() = 0;
	virtual void				send_data(const std::string data) = 0;
};

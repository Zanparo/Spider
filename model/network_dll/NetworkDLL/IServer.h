#pragma once
# include					<cstdlib>
# include					<iostream>

class						IServer
{
public:
	virtual					~IServer() {};
	virtual std::string		get_password() const = 0;
	virtual void			start_accept() = 0;
	virtual void			handle_accept(session *new_session, const bool error) = 0;
	virtual session			&get_session(int n) = 0;
};


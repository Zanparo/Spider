#pragma once

#include	<iostream>
#include	<vector>
#include	<Windows.h>

class IHook {

public:
	virtual ~IHook() {};
	virtual const bool	setHook() = 0;
	virtual void		notify(int, WPARAM, LPARAM) = 0;
	virtual bool		unsetHook() = 0;
};
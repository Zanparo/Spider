#pragma once			

#include				<iostream>
#include				<Windows.h>

typedef struct			s_Context {
	const std::string&	_windowTitle;
	LPPOINT				_mousePos;
}						t_Context;
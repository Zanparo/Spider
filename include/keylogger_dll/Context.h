#pragma once			

#include				<iostream>
#include				<chrono>
#include				<Windows.h>

typedef struct			s_Context {
	char*			_windowTitle;
	LPPOINT			_mousePos;
	DWORD			_ms;
}						t_Context;
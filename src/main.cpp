/*--------------------------------------------------------------------*
|                                                                     |
|         (c) Copy05 2016-2021 All rights reserved	              |
|	    Creating a Window Using Win32 API (Windows.h)	      |
|	                                                              |
*--------------------------------------------------------------------*/

#include <iostream>
#include "Window.h"


// Additional Functions
namespace as {
	void HideConsole()
	{
		ShowWindow(GetConsoleWindow(), SW_HIDE);
	}
}

int main(int argc, char** argv)
{

	std::cout << "Creating Window\n";
	Window* wind = new Window();

	bool running = true;
	while (running)
	{
		if (!wind->processMessages())
		{
			std::cout << "Closing Window\n";
			running = false;
		}

		// Rendering The Window
		Sleep(10);
	}

	delete wind;
	return 0;
}

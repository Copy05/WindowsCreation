/*--------------------------------------------------------------------*
|                                                                     |
|         (c) Copy05 2016-2021 All rights reserved	                  |
|	    Creating a Window Using Win32 API (Windows.h)				  |
|	                                                                  |
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

	// Creates a new Window using our Window Class
	Window* wind = new Window();
	wind->runWindow();


	return 0;
}
/*--------------------------------------------------------------------*
|                                                                     |
|         (c) Copy05 2016-2021 All rights reserved	              |
|	    Creating a Window Using Win32 API (Windows.h)	      |
|  This is the main Window Class thats used to create the window      |
|	                                                              |
*--------------------------------------------------------------------*/

#pragma once
#include <Windows.h>

LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

class Window
{
public:
	Window();
	~Window();

	bool processMessages();
private:
	HINSTANCE w_hInstance;
	HWND w_hwnd;
};


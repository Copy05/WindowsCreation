/*--------------------------------------------------------------------*
|                                                                     |
|         (c) Copy05 2016-2021 All rights reserved	              |
|	    Creating a Window Using Win32 API (Windows.h)	      |
|    Thats the Code that Creates the Window and Renders it            |
|	                                                              |
*--------------------------------------------------------------------*/

#include <Windows.h>
#include "Window.h"

const wchar_t* class_name = L"Window Class";

LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_CLOSE:
		DestroyWindow(hWnd);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}

	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

Window::Window() : w_hInstance(GetModuleHandle(nullptr))
{
	const wchar_t* windowTitle = L"Window Title";

	WNDCLASS winClass = {};
	winClass.lpszClassName = class_name;
	winClass.hInstance = w_hInstance;
	winClass.hIcon = LoadIcon(NULL, IDI_WINLOGO);
	winClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	winClass.lpfnWndProc = WindowProc;

	RegisterClass(&winClass);

	DWORD style = WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU;

	int rectwidth = 640;
	int rectheight = 480;

	RECT rect;
	rect.left = 250;
	rect.top = 250;
	rect.right = rect.left + rectwidth;
	rect.bottom = rect.top + rectheight;

	AdjustWindowRect(&rect, style, false);

	w_hwnd = CreateWindowEx(0, class_name, windowTitle, style, rect.left, rect.top, rect.right - rect.left, rect.bottom - rect.top, NULL, NULL, w_hInstance, NULL);

	ShowWindow(w_hwnd, SW_SHOW);
}

Window::~Window()
{
	UnregisterClass(class_name, w_hInstance);
}

bool Window::processMessages()
{
	MSG msg = {};
	while (PeekMessage(&msg, nullptr, 0u, 0u, PM_REMOVE))
	{
		if(msg.message == WM_QUIT)
		{
			return false;
		}

		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return true;
}

/*--------------------------------------------------------------------*
|                                                                     |
|         (c) Copy05 2016-2021 All rights reserved	              |
|	    Creating a Window Using Win32 API (Windows.h)	      |
|    Thats the Code that Creates the Window and Renders it            |
|	                                                              |
*--------------------------------------------------------------------*/

#include <Windows.h>
#include "Window.h"

#define Render(int) Sleep(int);
#define W_STATIC_TXT01 1069

const wchar_t* class_name = L"Window Class";

// Will create a static label with the text "Hello World"
void helloWorldControl(HWND hWnd)
{
	CreateWindowW(L"STATIC", L"Hello World",
		WS_CHILD | WS_VISIBLE,
		20, 30, 200, 30,
		hWnd, (HMENU)W_STATIC_TXT01, (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE)  , NULL);
}

LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_CREATE:
		helloWorldControl(hWnd);
		break;
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
	winClass.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);;
	winClass.lpfnWndProc = WindowProc;

	RegisterClass(&winClass);

	DWORD style = WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU | WS_VISIBLE | WS_OVERLAPPEDWINDOW;

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

void Window::runWindow()
{
	bool running = true;
	while (running)
	{
		if (!this->processMessages())
		{
			running = false;
		}

		// Rendering The Window
		Render(10);
	}

	delete this;
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

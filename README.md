# Windows Creation

This Repo Contains basic C++ Code to create a window with **C's Win32 API** for your C++ project

> **NOTICE:**
> 
> I dont recomend using Win32 **ALONE** for making any Desktop apps please use some third party librarys *(like Vulkan, ImGUI)* too

# Getting Started

Clone the source code and include it in your Project

**if you have allready a main.cpp file:**

```cpp
#include "Window.h"

// inside main function
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
```

# Contribution

If you need assistant with Window Creation please go to issues create one and i will look to help
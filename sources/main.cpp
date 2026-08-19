#include "Menu.h"
#include <Windows.h>

int main()
{
	HWND console = GetConsoleWindow();
	ShowWindow(console, SW_MAXIMIZE);

	Menu menu;
	menu.run();

	return 0;
}
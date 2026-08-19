#pragma once
#include "config.h"

class Menu
{
private:
	bool m_running;

	config::MenuPoint m_list[config::menu_points_size];
	int cursor_position;

public:
	Menu();

	void run();



};
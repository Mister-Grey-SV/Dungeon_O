#include "Interface.h"
#include "config.h"
#include <conio.h>
#include <iostream>

config::Command Interface::getCommand()
{
	char input{ static_cast<char>(_getch()) };
	if (input >= 65 && input <= 90) input += 32;
	switch (input)
	{
		case 'w': return config::Command::Up;
		case 's': return config::Command::Down;
		case 'a': return config::Command::Left;
		case 'd': return config::Command::Right;
		case 'f': return config::Command::Attack;
		case 'r': return config::Command::Heal;
		case ' ': return config::Command::EndTurn;
		case 'q': return config::Command::Exit;
		default : return config::Command::None;
	}
}

std::string Interface::getName()
{
	std::string name;
	std::getline(std::cin, name);

	return name;
}
#pragma once
#include "config.h"
#include <array>


class Player;

class World
{
public:
	struct Cell
	{
		char title;
		bool heal_potion;
		bool treasure;
		bool key;
		bool exit;
		uint16_t message;
		Player* actor;
	};

private:
	std::array<std::array<Cell, config::map_width>, config::map_height> m_map{};

public:
	World();

	Cell& getCell(size_t y, size_t x);
	void setLocation(Player* player, const config::Position& position);
	void clearLocation(const config::Position& position);
	bool isWall(int y, int x);
	bool lineOfSight(const config::Position& from, const config::Position& to);

};


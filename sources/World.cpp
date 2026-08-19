#include "World.h"
#include "config.h"
#include "level_data.h"
#include <cmath>

World::World()
{
	for (size_t y = 0; y < m_map.size(); ++y)
	{
		for (size_t x = 0; x < m_map[y].size(); ++x)
		{
			if (level_data::dungeon[y][x])
			{
				m_map[y][x].title = config::wall_sprite;
			}

			else
			{
				m_map[y][x].title = config::empty_sprite;
			}

			m_map[y][x].heal_potion = false;
			m_map[y][x].treasure = false;
			m_map[y][x].key = false;
			m_map[y][x].exit = false;
			m_map[y][x].message = config::none_message;
			m_map[y][x].actor = nullptr;
		}
	}
}

World::Cell& World::getCell(size_t y, size_t x)
{
	return m_map[y][x];
}

void World::setLocation(Player* player, const config::Position& position)
{
	m_map[position.y][position.x].actor = player;
}

void World::clearLocation(const config::Position& position)
{
	m_map[position.y][position.x].actor = nullptr;
}

bool World::isWall(int y, int x)
{
	return m_map[y][x].title == config::wall_sprite;
}

bool World::lineOfSight(const config::Position& from, const config::Position& to)
{
	int step_y = (from.y < to.y) ? 1 : -1;
	int step_x = (from.x < to.x) ? 1 : -1;

	int delta_y = std::abs(from.y - to.y);
	int delta_x = std::abs(from.x - to.x);

	int y = from.y;
	int x = from.x;

	if (delta_x > delta_y)
	{
		int error_y{};

		while (true)
		{
			if (y == to.y && x == to.x)
			{
				return true;
			}

			if (isWall(y, x))
			{
				return false;
			}

			error_y += delta_y;
			x += step_x;

			if (error_y >= delta_x)
			{
				y += step_y;
				error_y -= delta_x;
			}
		}
	}

	else if (delta_y > delta_x)
	{
		int error_x{};

		while (true)
		{
			if (y == to.y && x == to.x)
			{
				return true;
			}

			if (isWall(y, x))
			{
				return false;
			}

			error_x += delta_x;
			y += step_y;

			if (error_x >= delta_y)
			{
				x += step_x;
				error_x -= delta_y;
			}
		}
	}

	else
	{
		while (true)
		{
			if (y == to.y && x == to.x)
			{
				return true;
			}

			if (isWall(y, x))
			{
				return false;
			}

			y += step_y;
			x += step_x;
		}
	}
}
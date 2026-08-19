#pragma once
#include "config.h"

namespace level_data
{
	extern const config::EntityCreation creation[];
	extern const int creation_size;

	extern const config::Position heal_potions[];
	extern const int heal_potions_size;

	extern const config::Position treasures[];
	extern const int treasures_size;

	extern const config::Position keys[];
	extern const int keys_size;

	extern const config::Position exits[];
	extern const int exits_size;

	extern const config::Position ropes[];
	extern const int ropes_size;

	extern const config::Message message_list[];
	extern const int message_list_size;

	extern const bool dungeon[config::map_height][config::map_width];
}

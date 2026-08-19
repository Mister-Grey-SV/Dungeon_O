#include "level_data.h"
#include "config.h"

namespace level_data
{

	// actors list
	const config::EntityCreation creation[]
	{
		{
			config::Entity::Player,
			config::player_sprite,
			{ 26, 28 },
			{ config::Actions::Stay, false, 0, 0 },
			config::player_hp,
			config::player_hp,
			config::player_armor_class,
			config::player_attack_bonus,
			config::player_attack_dice,
			config::player_damage_bonus,
			config::player_damage_dice
		},

		{
			config::Entity::Enemy,
			config::mob_sprite,
			{ 24, 4 },
			{ config::Actions::PatrolHorizontal, false, 0, 11 },
			config::mob_hp,
			config::mob_hp,
			config::mob_armor_class,
			config::mob_attack_bonus,
			config::mob_attack_dice,
			config::mob_damage_bonus,
			config::mob_damage_dice
		},

		{
			config::Entity::Enemy,
			config::mob_sprite,
			{ 12, 17 },
			{ config::Actions::PatrolVertical, false, 0, 12 },
			config::mob_hp,
			config::mob_hp,
			config::mob_armor_class,
			config::mob_attack_bonus,
			config::mob_attack_dice,
			config::mob_damage_bonus,
			config::mob_damage_dice
		},

		{
			config::Entity::Enemy,
			config::mob_sprite,
			{ 24, 19 },
			{ config::Actions::PatrolVertical, true, 0, 12 },
			config::mob_hp,
			config::mob_hp,
			config::mob_armor_class,
			config::mob_attack_bonus,
			config::mob_attack_dice,
			config::mob_damage_bonus,
			config::mob_damage_dice
		},

		{
			config::Entity::Enemy,
			config::mob_sprite,
			{ 11, 46 },
			{ config::Actions::PatrolHorizontal, true, 0, 26 },
			config::mob_hp,
			config::mob_hp,
			config::mob_armor_class,
			config::mob_attack_bonus,
			config::mob_attack_dice,
			config::mob_damage_bonus,
			config::mob_damage_dice
		},

		{
			config::Entity::Enemy,
			config::mob_sprite,
			{ 13, 20 },
			{ config::Actions::PatrolHorizontal, false, 0, 26 },
			config::mob_hp,
			config::mob_hp,
			config::mob_armor_class,
			config::mob_attack_bonus,
			config::mob_attack_dice,
			config::mob_damage_bonus,
			config::mob_damage_dice
		},

		{
			config::Entity::Enemy,
			config::mob_sprite,
			{ 21, 41 },
			{ config::Actions::PatrolHorizontal, false, 0, 18 },
			config::mob_hp,
			config::mob_hp,
			config::mob_armor_class,
			config::mob_attack_bonus,
			config::mob_attack_dice,
			config::mob_damage_bonus,
			config::mob_damage_dice
		},

		{
			config::Entity::Enemy,
			config::mob_sprite,
			{ 23, 59 },
			{ config::Actions::PatrolHorizontal, true, 0, 26 },
			config::mob_hp,
			config::mob_hp,
			config::mob_armor_class,
			config::mob_attack_bonus,
			config::mob_attack_dice,
			config::mob_damage_bonus,
			config::mob_damage_dice
		},

		{
			config::Entity::Enemy,
			config::mob_sprite,
			{ 29, 39 },
			{ config::Actions::PatrolHorizontal, true, 0, 30 },
			config::mob_hp,
			config::mob_hp,
			config::mob_armor_class,
			config::mob_attack_bonus,
			config::mob_attack_dice,
			config::mob_damage_bonus,
			config::mob_damage_dice
		},

		{
			config::Entity::Enemy,
			config::mob_sprite,
			{ 31, 9 },
			{ config::Actions::PatrolHorizontal, false, 0, 30 },
			config::mob_hp,
			config::mob_hp,
			config::mob_armor_class,
			config::mob_attack_bonus,
			config::mob_attack_dice,
			config::mob_damage_bonus,
			config::mob_damage_dice
		},

		{
			config::Entity::Enemy,
			config::mob_sprite,
			{ 36, 67 },
			{ config::Actions::PatrolHorizontal, true, 0, 39 },
			config::mob_hp,
			config::mob_hp,
			config::mob_armor_class,
			config::mob_attack_bonus,
			config::mob_attack_dice,
			config::mob_damage_bonus,
			config::mob_damage_dice
		},

		{
			config::Entity::Enemy,
			config::mob_sprite,
			{ 34, 28 },
			{ config::Actions::PatrolHorizontal, false, 0, 39 },
			config::mob_hp,
			config::mob_hp,
			config::mob_armor_class,
			config::mob_attack_bonus,
			config::mob_attack_dice,
			config::mob_damage_bonus,
			config::mob_damage_dice
		},

		{
			config::Entity::Enemy,
			config::mob_sprite,
			{ 23, 69 },
			{ config::Actions::PatrolVertical, false, 0, 16 },
			config::mob_hp,
			config::mob_hp,
			config::mob_armor_class,
			config::mob_attack_bonus,
			config::mob_attack_dice,
			config::mob_damage_bonus,
			config::mob_damage_dice
		},

		{
			config::Entity::Enemy,
			config::mob_sprite,
			{ 39, 71 },
			{ config::Actions::PatrolVertical, true, 0, 16 },
			config::mob_hp,
			config::mob_hp,
			config::mob_armor_class,
			config::mob_attack_bonus,
			config::mob_attack_dice,
			config::mob_damage_bonus,
			config::mob_damage_dice
		},

		{
			config::Entity::Enemy,
			config::mob_sprite,
			{ 21, 93 },
			{ config::Actions::PatrolHorizontal, true, 0, 21 },
			config::mob_hp,
			config::mob_hp,
			config::mob_armor_class,
			config::mob_attack_bonus,
			config::mob_attack_dice,
			config::mob_damage_bonus,
			config::mob_damage_dice
		},

		{
			config::Entity::Enemy,
			config::mob_sprite,
			{ 19, 72 },
			{ config::Actions::PatrolHorizontal, false, 0, 21 },
			config::mob_hp,
			config::mob_hp,
			config::mob_armor_class,
			config::mob_attack_bonus,
			config::mob_attack_dice,
			config::mob_damage_bonus,
			config::mob_damage_dice
		},

		{
			config::Entity::Enemy,
			config::mob_sprite,
			{ 29, 93 },
			{ config::Actions::PatrolHorizontal, true, 0, 20 },
			config::mob_hp,
			config::mob_hp,
			config::mob_armor_class,
			config::mob_attack_bonus,
			config::mob_attack_dice,
			config::mob_damage_bonus,
			config::mob_damage_dice
		},

		{
			config::Entity::Enemy,
			config::mob_sprite,
			{ 31, 73 },
			{ config::Actions::PatrolHorizontal, false, 0, 20 },
			config::mob_hp,
			config::mob_hp,
			config::mob_armor_class,
			config::mob_attack_bonus,
			config::mob_attack_dice,
			config::mob_damage_bonus,
			config::mob_damage_dice
		},

		{
			config::Entity::Enemy,
			config::mob_sprite,
			{ 18, 7 },
			{ config::Actions::Stay, false, 0, 0 },
			config::mob_hp,
			config::mob_hp,
			config::mob_armor_class,
			config::mob_attack_bonus,
			config::mob_attack_dice,
			config::mob_damage_bonus,
			config::mob_damage_dice
		},

		{
			config::Entity::Enemy,
			config::mob_sprite,
			{ 20, 5 },
			{ config::Actions::Stay, false, 0, 0 },
			config::mob_hp,
			config::mob_hp,
			config::mob_armor_class,
			config::mob_attack_bonus,
			config::mob_attack_dice,
			config::mob_damage_bonus,
			config::mob_damage_dice
		},

		{
			config::Entity::Enemy,
			config::mob_sprite,
			{ 20, 9 },
			{ config::Actions::Stay, false, 0, 0 },
			config::mob_hp,
			config::mob_hp,
			config::mob_armor_class,
			config::mob_attack_bonus,
			config::mob_attack_dice,
			config::mob_damage_bonus,
			config::mob_damage_dice
		},

		{
			config::Entity::Enemy,
			config::mob_sprite,
			{ 2, 27 },
			{ config::Actions::Stay, false, 0, 0 },
			config::mob_hp,
			config::mob_hp,
			config::mob_armor_class,
			config::mob_attack_bonus,
			config::mob_attack_dice,
			config::mob_damage_bonus,
			config::mob_damage_dice
		},

		{
			config::Entity::Enemy,
			config::mob_sprite,
			{ 4, 22 },
			{ config::Actions::Stay, false, 0, 0 },
			config::mob_hp,
			config::mob_hp,
			config::mob_armor_class,
			config::mob_attack_bonus,
			config::mob_attack_dice,
			config::mob_damage_bonus,
			config::mob_damage_dice
		},

		{
			config::Entity::Enemy,
			config::mob_sprite,
			{ 9, 23 },
			{ config::Actions::Stay, false, 0, 0 },
			config::mob_hp,
			config::mob_hp,
			config::mob_armor_class,
			config::mob_attack_bonus,
			config::mob_attack_dice,
			config::mob_damage_bonus,
			config::mob_damage_dice
		},

		{
			config::Entity::Enemy,
			config::mob_sprite,
			{ 6, 30 },
			{ config::Actions::Stay, false, 0, 0 },
			config::mob_hp,
			config::mob_hp,
			config::mob_armor_class,
			config::mob_attack_bonus,
			config::mob_attack_dice,
			config::mob_damage_bonus,
			config::mob_damage_dice
		},

		{
			config::Entity::Enemy,
			config::mob_sprite,
			{ 5, 44 },
			{ config::Actions::Stay, false, 0, 0 },
			config::mob_hp,
			config::mob_hp,
			config::mob_armor_class,
			config::mob_attack_bonus,
			config::mob_attack_dice,
			config::mob_damage_bonus,
			config::mob_damage_dice
		},

		{
			config::Entity::Enemy,
			config::mob_sprite,
			{ 5, 48 },
			{ config::Actions::Stay, false, 0, 0 },
			config::mob_hp,
			config::mob_hp,
			config::mob_armor_class,
			config::mob_attack_bonus,
			config::mob_attack_dice,
			config::mob_damage_bonus,
			config::mob_damage_dice
		},

		{
			config::Entity::Enemy,
			config::mob_sprite,
			{ 6, 77 },
			{ config::Actions::Stay, false, 0, 0 },
			config::mob_hp,
			config::mob_hp,
			config::mob_armor_class,
			config::mob_attack_bonus,
			config::mob_attack_dice,
			config::mob_damage_bonus,
			config::mob_damage_dice
		},

		{
			config::Entity::Enemy,
			config::mob_sprite,
			{ 2, 73 },
			{ config::Actions::Stay, false, 0, 0 },
			config::mob_hp,
			config::mob_hp,
			config::mob_armor_class,
			config::mob_attack_bonus,
			config::mob_attack_dice,
			config::mob_damage_bonus,
			config::mob_damage_dice
		},

		{
			config::Entity::Enemy,
			config::mob_sprite,
			{ 2, 81 },
			{ config::Actions::Stay, false, 0, 0 },
			config::mob_hp,
			config::mob_hp,
			config::mob_armor_class,
			config::mob_attack_bonus,
			config::mob_attack_dice,
			config::mob_damage_bonus,
			config::mob_damage_dice
		},

		{
			config::Entity::Enemy,
			config::mob_sprite,
			{ 10, 73 },
			{ config::Actions::Stay, false, 0, 0 },
			config::mob_hp,
			config::mob_hp,
			config::mob_armor_class,
			config::mob_attack_bonus,
			config::mob_attack_dice,
			config::mob_damage_bonus,
			config::mob_damage_dice
		},

		{
			config::Entity::Enemy,
			config::mob_sprite,
			{ 10, 81 },
			{ config::Actions::Stay, false, 0, 0 },
			config::mob_hp,
			config::mob_hp,
			config::mob_armor_class,
			config::mob_attack_bonus,
			config::mob_attack_dice,
			config::mob_damage_bonus,
			config::mob_damage_dice
		},

		{
			config::Entity::Enemy,
			config::mob_sprite,
			{ 17, 87 },
			{ config::Actions::Stay, false, 0, 0 },
			config::mob_hp,
			config::mob_hp,
			config::mob_armor_class,
			config::mob_attack_bonus,
			config::mob_attack_dice,
			config::mob_damage_bonus,
			config::mob_damage_dice
		},

		{
			config::Entity::Enemy,
			config::mob_sprite,
			{ 17, 95 },
			{ config::Actions::Stay, false, 0, 0 },
			config::mob_hp,
			config::mob_hp,
			config::mob_armor_class,
			config::mob_attack_bonus,
			config::mob_attack_dice,
			config::mob_damage_bonus,
			config::mob_damage_dice
		},

		{
			config::Entity::Enemy,
			config::mob_sprite,
			{ 20, 28 },
			{ config::Actions::Stay, false, 0, 0 },
			config::mob_hp,
			config::mob_hp,
			config::mob_armor_class,
			config::mob_attack_bonus,
			config::mob_attack_dice,
			config::mob_damage_bonus,
			config::mob_damage_dice
		},

		{
			config::Entity::Enemy,
			config::mob_sprite,
			{ 18, 36 },
			{ config::Actions::Stay, false, 0, 0 },
			config::mob_hp,
			config::mob_hp,
			config::mob_armor_class,
			config::mob_attack_bonus,
			config::mob_attack_dice,
			config::mob_damage_bonus,
			config::mob_damage_dice
		},

		{
			config::Entity::Enemy,
			config::mob_sprite,
			{ 19, 55 },
			{ config::Actions::Stay, false, 0, 0 },
			config::mob_hp,
			config::mob_hp,
			config::mob_armor_class,
			config::mob_attack_bonus,
			config::mob_attack_dice,
			config::mob_damage_bonus,
			config::mob_damage_dice
		},

		{
			config::Entity::Enemy,
			config::mob_sprite,
			{ 19, 63 },
			{ config::Actions::Stay, false, 0, 0 },
			config::mob_hp,
			config::mob_hp,
			config::mob_armor_class,
			config::mob_attack_bonus,
			config::mob_attack_dice,
			config::mob_damage_bonus,
			config::mob_damage_dice
		},

		{
			config::Entity::Enemy,
			config::mob_sprite,
			{ 27, 49 },
			{ config::Actions::Stay, false, 0, 0 },
			config::mob_hp,
			config::mob_hp,
			config::mob_armor_class,
			config::mob_attack_bonus,
			config::mob_attack_dice,
			config::mob_damage_bonus,
			config::mob_damage_dice
		},

		{
			config::Entity::Enemy,
			config::mob_sprite,
			{ 27, 55 },
			{ config::Actions::Stay, false, 0, 0 },
			config::mob_hp,
			config::mob_hp,
			config::mob_armor_class,
			config::mob_attack_bonus,
			config::mob_attack_dice,
			config::mob_damage_bonus,
			config::mob_damage_dice
		},

		{
			config::Entity::Enemy,
			config::mob_sprite,
			{ 32, 49 },
			{ config::Actions::Stay, false, 0, 0 },
			config::mob_hp,
			config::mob_hp,
			config::mob_armor_class,
			config::mob_attack_bonus,
			config::mob_attack_dice,
			config::mob_damage_bonus,
			config::mob_damage_dice
		},

		{
			config::Entity::Enemy,
			config::mob_sprite,
			{ 32, 55 },
			{ config::Actions::Stay, false, 0, 0 },
			config::mob_hp,
			config::mob_hp,
			config::mob_armor_class,
			config::mob_attack_bonus,
			config::mob_attack_dice,
			config::mob_damage_bonus,
			config::mob_damage_dice
		},

		{
			config::Entity::Enemy,
			config::mob_sprite,
			{ 39, 7 },
			{ config::Actions::Stay, false, 0, 0 },
			config::mob_hp,
			config::mob_hp,
			config::mob_armor_class,
			config::mob_attack_bonus,
			config::mob_attack_dice,
			config::mob_damage_bonus,
			config::mob_damage_dice
		},

		{
			config::Entity::Enemy,
			config::mob_sprite,
			{ 39, 11 },
			{ config::Actions::Stay, false, 0, 0 },
			config::mob_hp,
			config::mob_hp,
			config::mob_armor_class,
			config::mob_attack_bonus,
			config::mob_attack_dice,
			config::mob_damage_bonus,
			config::mob_damage_dice
		},

		{
			config::Entity::Enemy,
			config::mob_sprite,
			{ 45, 5 },
			{ config::Actions::Stay, false, 0, 0 },
			config::mob_hp,
			config::mob_hp,
			config::mob_armor_class,
			config::mob_attack_bonus,
			config::mob_attack_dice,
			config::mob_damage_bonus,
			config::mob_damage_dice
		},

		{
			config::Entity::Enemy,
			config::mob_sprite,
			{ 45, 13 },
			{ config::Actions::Stay, false, 0, 0 },
			config::mob_hp,
			config::mob_hp,
			config::mob_armor_class,
			config::mob_attack_bonus,
			config::mob_attack_dice,
			config::mob_damage_bonus,
			config::mob_damage_dice
		},

		{
			config::Entity::Enemy,
			config::mob_sprite,
			{ 39, 27 },
			{ config::Actions::Stay, false, 0, 0 },
			config::mob_hp,
			config::mob_hp,
			config::mob_armor_class,
			config::mob_attack_bonus,
			config::mob_attack_dice,
			config::mob_damage_bonus,
			config::mob_damage_dice
		},

		{
			config::Entity::Enemy,
			config::mob_sprite,
			{ 39, 31 },
			{ config::Actions::Stay, false, 0, 0 },
			config::mob_hp,
			config::mob_hp,
			config::mob_armor_class,
			config::mob_attack_bonus,
			config::mob_attack_dice,
			config::mob_damage_bonus,
			config::mob_damage_dice
		},

		{
			config::Entity::Enemy,
			config::mob_sprite,
			{ 43, 26 },
			{ config::Actions::Stay, false, 0, 0 },
			config::mob_hp,
			config::mob_hp,
			config::mob_armor_class,
			config::mob_attack_bonus,
			config::mob_attack_dice,
			config::mob_damage_bonus,
			config::mob_damage_dice
		},

		{
			config::Entity::Enemy,
			config::mob_sprite,
			{ 41, 34 },
			{ config::Actions::Stay, false, 0, 0 },
			config::mob_hp,
			config::mob_hp,
			config::mob_armor_class,
			config::mob_attack_bonus,
			config::mob_attack_dice,
			config::mob_damage_bonus,
			config::mob_damage_dice
		},

		{
			config::Entity::Enemy,
			config::mob_sprite,
			{ 42, 34 },
			{ config::Actions::Stay, false, 0, 0 },
			config::mob_hp,
			config::mob_hp,
			config::mob_armor_class,
			config::mob_attack_bonus,
			config::mob_attack_dice,
			config::mob_damage_bonus,
			config::mob_damage_dice
		},

		{
			config::Entity::Enemy,
			config::mob_sprite,
			{ 40, 41 },
			{ config::Actions::Stay, false, 0, 0 },
			config::mob_hp,
			config::mob_hp,
			config::mob_armor_class,
			config::mob_attack_bonus,
			config::mob_attack_dice,
			config::mob_damage_bonus,
			config::mob_damage_dice
		},

		{
			config::Entity::Enemy,
			config::mob_sprite,
			{ 44, 41 },
			{ config::Actions::Stay, false, 0, 0 },
			config::mob_hp,
			config::mob_hp,
			config::mob_armor_class,
			config::mob_attack_bonus,
			config::mob_attack_dice,
			config::mob_damage_bonus,
			config::mob_damage_dice
		},

		{
			config::Entity::Enemy,
			config::mob_sprite,
			{ 39, 59 },
			{ config::Actions::Stay, false, 0, 0 },
			config::mob_hp,
			config::mob_hp,
			config::mob_armor_class,
			config::mob_attack_bonus,
			config::mob_attack_dice,
			config::mob_damage_bonus,
			config::mob_damage_dice
		},

		{
			config::Entity::Enemy,
			config::mob_sprite,
			{ 39, 61 },
			{ config::Actions::Stay, false, 0, 0 },
			config::mob_hp,
			config::mob_hp,
			config::mob_armor_class,
			config::mob_attack_bonus,
			config::mob_attack_dice,
			config::mob_damage_bonus,
			config::mob_damage_dice
		},

		{
			config::Entity::Enemy,
			config::mob_sprite,
			{ 44, 60 },
			{ config::Actions::Stay, false, 0, 0 },
			config::mob_hp,
			config::mob_hp,
			config::mob_armor_class,
			config::mob_attack_bonus,
			config::mob_attack_dice,
			config::mob_damage_bonus,
			config::mob_damage_dice
		},

		{
			config::Entity::Enemy,
			config::boss_sprite,
			{ 9, 91 },
			{ config::Actions::Stay, false, 0, 0 },
			config::boss_hp,
			config::boss_hp,
			config::boss_armor_class,
			config::boss_attack_bonus,
			config::boss_attack_dice,
			config::boss_damage_bonus,
			config::boss_damage_dice
		},

		{
			config::Entity::Enemy,
				config::boss_sprite,
			{ 44, 9 },
			{ config::Actions::Stay, false, 0, 0 },
				config::boss_hp,
				config::boss_hp,
				config::boss_armor_class,
				config::boss_attack_bonus,
				config::boss_attack_dice,
				config::boss_damage_bonus,
				config::boss_damage_dice
		},

		{
			config::Entity::Enemy,
			config::boss_sprite,
			{ 39, 89 },
			{ config::Actions::Stay, false, 0, 0 },
			config::boss_hp,
			config::boss_hp,
			config::boss_armor_class,
			config::boss_attack_bonus,
			config::boss_attack_dice,
			config::boss_damage_bonus,
			config::boss_damage_dice
		}

	};
	const int creation_size = sizeof(creation) / sizeof(creation[0]);

	// potion list
	const config::Position heal_potions[]
	{
		{5, 25},
		//{5, 27},
		{4, 29},

		{3, 75},
		//{3, 77},
		{3, 79},

		{23, 28},

		{15, 56},
		//{15, 59},
		{15, 62},

		{46, 58},
		{46, 60},
		//{46, 61},
		{46, 63}
	};
	const int heal_potions_size = sizeof(heal_potions) / sizeof(heal_potions[0]);

	// treasures
	const config::Position treasures[]
	{
		{8, 94},
		{46, 9},
		{44, 44}
	};
	const int treasures_size = sizeof(treasures) / sizeof(treasures[0]);

	// key
	const config::Position keys[]
	{
		{16, 9}
	};
	const int keys_size = sizeof(keys) / sizeof(keys[0]);

	// exit
	const config::Position exits[]
	{
		{ 39, 97}
	};
	const int exits_size = sizeof(exits) / sizeof(exits[0]);

	// broken rope
	const config::Position ropes[]
	{
		{ 27, 27}
	};
	const int ropes_size = sizeof(ropes) / sizeof(ropes[0]);

	// messages
	const config::Message message_list[]
	{
		{config::none_message, {0, 0}},
		{config::broken_rope_message, {27, 27}},
		{config::potion_message, {24, 28}},
		{config::scream_message, {23, 27}}
	};
	const int message_list_size = sizeof(message_list) / sizeof(message_list[0]);


	//dungeon
	const bool dungeon[config::map_height][config::map_width]
	{
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1},
		{1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1},
		{1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1},
		{1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1},
		{1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1},
		{1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1},
		{1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1},
		{1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
	};
}
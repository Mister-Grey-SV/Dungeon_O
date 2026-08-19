#pragma once
#include <cinttypes>


namespace config
{
	inline constexpr char cursor_sprite{ '>' };
	inline constexpr char no_cursor_sprite{' '};

	struct MenuPoint
	{
		char title;
		const char* name;

	};

	inline constexpr MenuPoint menu_points[]
	{
		{cursor_sprite, "Play"},
		{no_cursor_sprite, "Records"},
		{no_cursor_sprite, "Exit"}
	};
	inline constexpr int menu_points_size{ sizeof(menu_points) / sizeof(menu_points[0]) };

	inline constexpr const char* confirm[]
	{
		"    Are you sure?    ",
		"Yes { F }", 
		"No { Q }"
	};
	
	inline constexpr int configm_size	{ sizeof(confirm) / sizeof(confirm[0]) };

	inline constexpr int cursor_position_play		{ 0 };
	inline constexpr int cursor_position_records	{ 1 };
	inline constexpr int cursor_position_exit		{ 2 };


	enum class Dices
	{
		D4,
		D6,
		D8,
		D10,
		D12,
		D20
	};
	
	struct Position
	{
		int y{};
		int x{};
	};

	struct Stats
	{
		int max_hp{};
		int hp{};

		int armor_class{};

		int attack_bonus{};
		Dices attack_dice{};

		int damage_bonus{};
		Dices damage_dice{};

	};

	struct Inventory
	{
		int m_heal{};
		int m_treasure{};
		int m_keys{};
	};

	enum class Entity
	{
		Player,
		Enemy
	};

	struct MovementState
	{
		int actions;
		int moves;
	};

	enum class Command
	{
		None,

		Up,
		Down,
		Left,
		Right,

		Attack,
		Heal,

		EndTurn,
		Exit
	};

	enum class Actions
	{
		Stay,
		PatrolVertical,
		PatrolHorizontal
	};

	struct Behavior
	{
		Actions action;
		bool turn;
		int patrol_distance_done;
		int patrol_distance;

	};

	inline constexpr size_t map_width	{ 100 };
	inline constexpr size_t map_height	{ 50 };

	inline constexpr Position direction_none	{ 0, 0 };
	inline constexpr Position direction_up		{ -1, 0 };
	inline constexpr Position direction_down	{ 1, 0 };
	inline constexpr Position direction_left	{ 0,  -1 };
	inline constexpr Position direction_right	{ 0, 1 };

	inline constexpr char wall_sprite			{ '#' };
	inline constexpr char empty_sprite			{ ' ' };

	inline constexpr char heal_potion_sprite	{ '*' };
	inline constexpr char treasure_sprite		{ 'm' };
	inline constexpr char key_sprite			{ '\'' };
	inline constexpr char exit_sprite			{ '>' };
	inline constexpr char rope_sprite			{ 's' };

	inline constexpr char player_sprite			{ 'o' };
	inline constexpr char mob_sprite			{ '&' };
	inline constexpr char boss_sprite			{ 'O' };

	inline constexpr char dead_sprite			{ '+' };


	// messages
	inline constexpr uint16_t none_message			{ 0 };
	inline constexpr uint16_t broken_rope_message	{ 1 };
	inline constexpr uint16_t potion_message		{ 2 };
	inline constexpr uint16_t scream_message		{ 3 };
	inline constexpr uint16_t run_message			{ 4 };
	inline constexpr uint16_t locked_chest_message	{ 5 };
	inline constexpr uint16_t locked_dor_message	{ 6 };
	inline constexpr uint16_t first_key_message		{ 7 };
	inline constexpr uint16_t next_key_message		{ 8 };
	inline constexpr uint16_t open_message			{ 9 };

	inline constexpr uint16_t game_over_message		{ 10 };
	inline constexpr uint16_t empty_records_message	{ 11 };
	inline constexpr uint16_t top_15_message		{ 12 };

	inline constexpr int empty_records_len	{ 25 };
	inline constexpr int top_15_len			{ 6 };
	inline constexpr int game_over_len		{ 9 };

	inline constexpr const char* messages[]
	{
		"",
		"There's my broken rope...",
		"There's something here that looks like a Healing Potion...",

		"A shrill scream cuts into the ears!..",
		"Looks like I need to get out of here immediately!..",

		"The chest is locked, I need a key...",
		"The door is locked, I need a key...",

		"It looks like an old rusty key...",
		"This key looks like other one...",

		"It's open! The key broke...",

		"Game Over",
		"  You'll be my first...  ",
		"  Top 15  "
	};

	inline constexpr int default_distance_for_message	{ 17 };
	
	// player stats
	inline constexpr int def_player_heal_bonus		{ 2 };
	inline constexpr int def_player_heal_qty		{ 0 };
	inline constexpr int def_player_treasure_qty	{ 0 };

	inline constexpr int passive_regen_value		{ 1 };

	// player
	inline constexpr int	player_hp			{ 30 };
	inline constexpr int	player_armor_class	{ 16 };
	inline constexpr int	player_attack_bonus	{ 5 };
	inline constexpr Dices	player_attack_dice	{ Dices::D20 };
	inline constexpr int	player_damage_bonus	{ 2 };
	inline constexpr Dices	player_damage_dice	{ Dices::D8 };

	// mob
	inline constexpr int	mob_hp				{ 9 };
	inline constexpr int	mob_armor_class		{ 11 };
	inline constexpr int	mob_attack_bonus	{ 0 };
	inline constexpr Dices	mob_attack_dice		{ Dices::D20 };
	inline constexpr int	mob_damage_bonus	{ 0 };
	inline constexpr Dices	mob_damage_dice		{ Dices::D10 };

	// boss
	inline constexpr int	boss_hp				{ 52 };
	inline constexpr int	boss_armor_class	{ 17 };
	inline constexpr int	boss_attack_bonus	{ 3 };
	inline constexpr Dices	boss_attack_dice	{ Dices::D20 };
	inline constexpr int	boss_damage_bonus	{ 0 };
	inline constexpr Dices	boss_damage_dice	{ Dices::D12 };

	// movement state
	inline constexpr int moves_qty	{ 3 };
	inline constexpr int moves_pack	{ 5 };

	inline constexpr int actions_qty		{ 2 };
	inline constexpr int moves_pack_cost	{ 1 };
	inline constexpr int attack_cost		{ 1 };
	inline constexpr int attack_pack		{ 1 };
	inline constexpr int heal_cost			{ 1 };
	
	// AI
	inline constexpr int max_move_tries_qty		{ 3 };

	inline constexpr int vision_distance		{ 8 };

	// Render
	inline constexpr int render_distance	{ 10 };
	inline constexpr int reserve_distance	{ 1 };

	inline constexpr int logs_qty			{ 8 };

	inline constexpr int free_space		{ 16 };
	inline constexpr int work_space		{ 199 };
	inline constexpr int max_log_len	{ 80 };
	inline constexpr int down_space		{ 1 };

	inline constexpr int first_position	{ free_space };
	inline constexpr int last_position	{ free_space + work_space };

	inline constexpr int turn_of_len			{ 14 };

	inline constexpr int hp_title_len			{ 7 };
	inline constexpr int hp_len					{ player_hp + hp_title_len };

	inline constexpr int moves_len				{ 12 };
	inline constexpr int attacks_len			{ 13 };
	inline constexpr int keys_len				{ 10 };
	inline constexpr int heal_potions_len		{ 19 };
	inline constexpr int heal_potions_end_len	{ 1 };
	inline constexpr int treasures_len			{ 15 };

	inline constexpr int turn_of_position				{ last_position - work_space / 2 - turn_of_len / 2 };
	inline constexpr int hp_position					{ last_position - hp_len };
	inline constexpr int moves_position					{ last_position - hp_len };
	inline constexpr int attacks_position				{ last_position - attacks_len };
	inline constexpr int keys_position					{ last_position - hp_len };
	inline constexpr int heal_potions_start_position	{ last_position - heal_potions_len };
	inline constexpr int heal_potions_end_position		{ last_position - heal_potions_end_len};
	inline constexpr int treasures_position				{ last_position - treasures_len };


	inline constexpr int fool_screen_height	{ 61 };
	inline constexpr int free_lines			{ 2 };

	inline constexpr int menu_default_len	{ 9 };
	inline constexpr int menu_position		{ last_position - work_space / 2 - menu_default_len / 2 };

	inline constexpr int nemu_default_height	{ 5 };
	inline constexpr int start_menu_line	{ fool_screen_height / 2 - 1 };
	inline constexpr int end_menu_line		{ start_menu_line + nemu_default_height };

	inline constexpr int control_position	{ menu_position + 20 };
	inline constexpr int control_line_shift	{ 18 };

	inline constexpr int up_shift			{ 18 };
	inline constexpr int w_shift			{ 6 };
	inline constexpr int r_shift			{ 40 };
	inline constexpr int left_shift			{ 5 };
	inline constexpr int f_shift			{ 29 };
	inline constexpr int down_shift			{ 17 };
	inline constexpr int space_shift		{ 30 };

	inline constexpr int confirm_default_len	{ 21 };
	inline constexpr int confirm_space_len		{ 4 };
	inline constexpr int confirm_position		{ last_position - work_space / 2 - confirm_default_len / 2 };

	inline constexpr int confirm_default_height	{ 3 };
	inline constexpr int start_confirm_line		{ fool_screen_height / 2 };
	inline constexpr int end_confirm_line		{ start_confirm_line + confirm_default_height };

	inline constexpr int record_default_height		{ 3 };
	inline constexpr int record_default_len			{ 91 };
	inline constexpr int record_name_len			{ 29 };
	inline constexpr int record_name_spaces_len		{ 3 };
	inline constexpr int record_total_len			{ 14 };

	inline constexpr int record_enemies_killed_len	{ 21 };
	inline constexpr int record_turns_len			{ 13 };
	inline constexpr int record_treasures_len		{ 15 };
	inline constexpr int record_stats_spaces_len	{ 5 };

	inline constexpr int record_name_position				{ last_position - work_space / 2 - record_default_len / 2 };

	inline constexpr int record_start_total_position		{ record_name_position + record_default_len - record_total_len };
	inline constexpr int record_end_total_position			{ record_name_position + record_default_len - 1 };

	inline constexpr int record_enemies_killed_position		{ record_name_position + record_name_len + record_name_spaces_len};
	inline constexpr int record_turns_position				{ record_enemies_killed_position + record_enemies_killed_len + record_stats_spaces_len };
	inline constexpr int record_treasures_position			{ record_turns_position + record_turns_len + record_stats_spaces_len };

	inline constexpr int record_name_preview_len		{ 7 };
	inline constexpr int record_name_input_height		{ fool_screen_height / 2 - 1 };
	inline constexpr int record_name_input_position		{ record_name_position + record_name_preview_len };

	inline constexpr int records_title_height{ 2 };

	inline constexpr int start_game_over_line{ fool_screen_height / 2 + 1 };
	inline constexpr int game_over_position{ last_position - work_space / 2 - game_over_len / 2 };

	// random
	inline constexpr float mob_drop_chance{0.10f};

	struct Message
	{
		uint16_t message_num;
		Position message_position;
	};

	struct AttackLog
	{
		Entity m_attacker;
		Entity m_attacked;

		Dices m_attack_dice;
		int m_attack_bonus;
		int m_attack_roll;

		int m_armor_class;
		bool m_hit;

		Dices m_damage_dice;
		int m_damage_bonus;
		int m_damage_roll;
		bool m_killed;

		AttackLog
		(
			Entity attacker,
			Entity attacked,

			Dices attack_dice,
			int attack_bonus,
			int armor_class,

			Dices damage_dice,
			int damage_bonus
		)
			:m_attacker{ attacker },
			m_attacked{ attacked },
			m_attack_dice{ attack_dice },
			m_attack_bonus{attack_bonus},
			m_attack_roll{ 0 },
			m_armor_class{armor_class},
			m_hit{false},
			m_damage_dice{damage_dice},
			m_damage_bonus{damage_bonus},
			m_damage_roll{ 0 },
			m_killed{false}
		{ }
	};

	inline constexpr int log_list_size	{ 9 };

	struct EntityCreation
	{
		config::Entity m_entity;
		char m_sprite;
		config::Position m_position;
		config::Behavior m_beahvior;

		int m_max_hp;
		int m_hp;
		int m_armor_class;
		int m_attack_bonus;
		config::Dices m_attack_dice;
		int m_damage_bonus;
		config::Dices m_damage_dice;

		constexpr EntityCreation
		(
			config::Entity entity,
			char sprite,
			config::Position position,
			config::Behavior beahvior,

			int max_hp,
			int hp,
			int armor_class,
			int attack_bonus,
			config::Dices attack_dice,
			int damage_bonus,
			config::Dices damage_dice
		)
			:m_entity{ entity },
			m_sprite{ sprite },
			m_position{ position },
			m_beahvior{ beahvior },

			m_max_hp{ max_hp },
			m_hp{ hp },
			m_armor_class{ armor_class },
			m_attack_bonus{ attack_bonus },
			m_attack_dice{ attack_dice },
			m_damage_bonus{ damage_bonus },
			m_damage_dice{ damage_dice }
		{ }
	};

	struct Score
	{
		int turns{};
		int potions_found{};
		int potions_used{};
		int treasures{};
		int enemies_killed{};

		void clear()
		{
			turns = 0;
			potions_found	= 0;
			potions_used	= 0;
			treasures		= 0;
			enemies_killed	= 0;
		}
	};

	enum class GameResult
	{
		Quit,
		Victory,
		Defeat
	};

	struct Record
	{
		char name[21]{};
		int total_score{};

		int treasures{};
		int turns{};
		int enemies_killed{};
	};

	inline constexpr int base_score		{ 5000 };
	inline constexpr int treasure_bonus	{ 1000 };
	inline constexpr int potion_bonus	{ 100 };
	inline constexpr int potion_penalty	{ 100 };
	inline constexpr int kill_bonus		{ 25 };
	inline constexpr int turn_penalty	{ 30 };

}
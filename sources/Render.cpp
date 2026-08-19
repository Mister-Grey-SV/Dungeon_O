#include "Render.h"
#include "config.h"
#include "World.h"
#include "Player.h"
#include <iostream>
#include <Windows.h>

void Render::drawLevel(World& world, Player& player, const std::vector<config::AttackLog>& attack_logs, config::Entity turn_of)
{
	if (!m_screen.empty())
	{
		m_screen.clear();
	}

	for (int line = 0; line < config::free_lines; ++line)
	{
		m_screen.push_back("");
		m_screen[m_screen.size() - 1].append(config::last_position, ' ');
	}

	// draw map
	for (int y = 0; y < config::map_height; ++y)
	{
		m_screen.push_back("");
		m_screen[m_screen.size() - 1].append(config::free_space, ' ');

		for (int x = 0; x < config::map_width; ++x)
		{	
			if ((static_cast<int>(y) - player.getPosition().y) *
				(static_cast<int>(y) - player.getPosition().y) +
				(static_cast<int>(x) - player.getPosition().x) *
				(static_cast<int>(x) - player.getPosition().x) <
				config::render_distance * config::render_distance)
			{
				if (world.lineOfSight(player.getPosition(), { y, x }))
				{
					if (world.getCell(y, x).actor != nullptr)
					{
						m_screen[m_screen.size() - 1].push_back(world.getCell(y, x).actor->getSprite());
						m_screen[m_screen.size() - 1].push_back(' ');
					}

					else if (world.getCell(y, x).exit)
					{
						m_screen[m_screen.size() - 1].push_back(config::exit_sprite);
						m_screen[m_screen.size() - 1].push_back(' ');
					}

					else if (world.getCell(y, x).treasure)
					{
						m_screen[m_screen.size() - 1].push_back(config::treasure_sprite);
						m_screen[m_screen.size() - 1].push_back(' ');
					}

					else if (world.getCell(y, x).key)
					{
						m_screen[m_screen.size() - 1].push_back(config::key_sprite);
						m_screen[m_screen.size() - 1].push_back(' ');
					}

					else if (world.getCell(y, x).heal_potion)
					{
						m_screen[m_screen.size() - 1].push_back(config::heal_potion_sprite);
						m_screen[m_screen.size() - 1].push_back(' ');
					}

					else
					{
						m_screen[m_screen.size() - 1].push_back(world.getCell(y, x).title);
						m_screen[m_screen.size() - 1].push_back(' ');
					}
				}

				else if (y == 0 || x == 0 || y == config::map_height - 1 || x == config::map_width - 1)
				{
					m_screen[m_screen.size() - 1].push_back(world.getCell(y, x).title);
					m_screen[m_screen.size() - 1].push_back(' ');
				}
				
				else
				{
					m_screen[m_screen.size() - 1] += "  ";
				}
			}

			else if (y == 0 || x == 0 || y == config::map_height - 1 || x == config::map_width - 1)
			{
				m_screen[m_screen.size() - 1].push_back(world.getCell(y, x).title);
				m_screen[m_screen.size() - 1].push_back(' ');
			}
			
			else
			{
				m_screen[m_screen.size() - 1] += "  ";
			}
		}
	}

	// draw gameplay information
	m_screen.push_back("");
	for (int line = 0; line < config::logs_qty; ++line)
	{
		m_screen.push_back("");
		m_screen[m_screen.size() - 1].append(config::free_space, ' ');
		if (line < attack_logs.size())
		{
			switch (attack_logs[line].m_attacker)
			{
				case config::Entity::Player:	m_screen[m_screen.size() - 1] += "Player attacks ";	break;
				case config::Entity::Enemy:		m_screen[m_screen.size() - 1] += "Enemy attacks ";	break;
			}

			switch (attack_logs[line].m_attacked)
			{
				case config::Entity::Player:	m_screen[m_screen.size() - 1] += "Player: ";	break;
				case config::Entity::Enemy:		m_screen[m_screen.size() - 1] += "Enemy: ";		break;
			}

			switch (attack_logs[line].m_attack_dice)
			{
				case config::Dices::D4:		m_screen[m_screen.size() - 1] += " d4 ";	break;
				case config::Dices::D6:		m_screen[m_screen.size() - 1] += " d6 ";	break;
				case config::Dices::D8:		m_screen[m_screen.size() - 1] += " d8 ";	break;
				case config::Dices::D10:	m_screen[m_screen.size() - 1] += "d10 ";	break;
				case config::Dices::D12:	m_screen[m_screen.size() - 1] += "d12 ";	break;
				case config::Dices::D20:	m_screen[m_screen.size() - 1] += "d20 ";	break;
			}

			if (attack_logs[line].m_attack_bonus != 0)
			{
				m_screen[m_screen.size() - 1] += "+ " + std::to_string(attack_logs[line].m_attack_bonus);
			}

			m_screen[m_screen.size() - 1] += " => " + std::to_string(attack_logs[line].m_attack_roll) + " vs ";
			m_screen[m_screen.size() - 1] += std::to_string(attack_logs[line].m_armor_class) + " AC ";

			switch (attack_logs[line].m_hit)
			{
				case true:	m_screen[m_screen.size() - 1] += " hit! ";	break;
				case false:	m_screen[m_screen.size() - 1] += " miss. ";	break;

			}

			if (attack_logs[line].m_hit)
			{
				m_screen[m_screen.size() - 1] += "Damage: ";

				switch (attack_logs[line].m_damage_dice)
				{
					case config::Dices::D4:		m_screen[m_screen.size() - 1] += " d4 ";	break;
					case config::Dices::D8:		m_screen[m_screen.size() - 1] += " d8 ";	break;
					case config::Dices::D10:	m_screen[m_screen.size() - 1] += "d10 ";	break;
					case config::Dices::D20:	m_screen[m_screen.size() - 1] += "d20 ";	break;
				}

				if (attack_logs[line].m_damage_bonus != 0)
				{
					m_screen[m_screen.size() - 1] += "+ " + std::to_string(attack_logs[line].m_damage_bonus);
				}

				m_screen[m_screen.size() - 1] += " => " + std::to_string(attack_logs[line].m_damage_roll);

				if (attack_logs[line].m_killed)
				{
					m_screen[m_screen.size() - 1] += " killed.";
				}
			}
		}
		
		if (line == 0)
		{
			int spaces = config::turn_of_position - m_screen[m_screen.size() - 1].size();
			m_screen[m_screen.size() - 1].append(spaces, ' ');
			m_screen[m_screen.size() - 1] += "Turn of ";

			switch (turn_of)
			{
				case config::Entity::Player:	m_screen[m_screen.size() - 1] += "Player";	break;
				case config::Entity::Enemy:		m_screen[m_screen.size() - 1] += "Enemy ";	break;
			}
		
			spaces = config::hp_position - m_screen[m_screen.size() - 1].size();
			m_screen[m_screen.size() - 1].append(spaces, ' ');
			m_screen[m_screen.size() - 1] += "HP { ";

			int hp = player.getStats().hp;
			if(hp > 0) m_screen[m_screen.size() - 1].append(hp, '|');
			int rest = player.getStats().max_hp - ((player.getStats().hp > 0) ? player.getStats().hp : 0);
			m_screen[m_screen.size() - 1].append(rest, ' ');
			m_screen[m_screen.size() - 1] += " }";
		}

		else if (line == 2)
		{
			int spaces = config::hp_position - m_screen[m_screen.size() - 1].size();
			m_screen[m_screen.size() - 1].append(spaces, ' ');
			m_screen[m_screen.size() - 1] += "Moves { " + 
				std::to_string(player.getMovementState().moves + 
				player.getMovementState().actions * config::moves_pack) + " }";

			spaces = config::attacks_position - m_screen[m_screen.size() - 1].size();
			m_screen[m_screen.size() - 1].append(spaces, ' ');
			m_screen[m_screen.size() - 1] += "Attacks { " + 
				std::to_string(player.getMovementState().actions * config::attack_pack) + " }";
		}

		else if (line == 4)
		{
			int spaces = config::hp_position - m_screen[m_screen.size() - 1].size();
			m_screen[m_screen.size() - 1].append(spaces, ' ');

			m_screen[m_screen.size() - 1] += "Keys { " + 
				std::to_string(player.getInventory().m_keys) + " }";


			spaces = config::heal_potions_start_position - m_screen[m_screen.size() - 1].size();
			m_screen[m_screen.size() - 1].append(spaces, ' ');
			m_screen[m_screen.size() - 1] += "Heal Potions { " + 
				std::to_string(player.getInventory().m_heal);

			spaces = config::heal_potions_end_position - m_screen[m_screen.size() - 1].size();
			m_screen[m_screen.size() - 1].append(spaces, ' ');
			m_screen[m_screen.size() - 1] += "}";
		}

		else if (line == 7)
		{
			int spaces = config::treasures_position - m_screen[m_screen.size() - 1].size();
			m_screen[m_screen.size() - 1].append(spaces, ' ');

			m_screen[m_screen.size() - 1] += "Treasures { " + 
				std::to_string(player.getInventory().m_treasure) + " }";
		}

		else
		{
			int spaces = config::last_position + 1 - m_screen[m_screen.size() - 1].size();
			m_screen[m_screen.size() - 1].append(spaces, ' ');
		}

		m_screen[m_screen.size() - 1].push_back(' ');
	}
}

void Render::drawMessage(uint16_t message)
{
	if (!m_screen.empty())
	{
		m_screen.clear();
	}

	m_screen.push_back("");
	m_screen[m_screen.size() - 1].push_back(' ');
	m_screen[m_screen.size() - 1] += config::messages[message];
	m_screen[m_screen.size() - 1].push_back(' ');

}

void Render::drawMenu(config::MenuPoint m_list[])
{
	if (!m_screen.empty())
	{
		m_screen.clear();
	}

	for (int line = 0; line < config::start_menu_line; ++line)
	{
		m_screen.push_back("");
		m_screen[m_screen.size() - 1].append(config::last_position, ' ');
	}

	for (int line = 0; line < config::menu_points_size; ++line)
	{
		m_screen.push_back("");
		m_screen[m_screen.size() - 1].append(config::menu_position, ' ');
		m_screen[m_screen.size() - 1].push_back((m_list + line)->title);
		m_screen[m_screen.size() - 1] += " " + std::string{(m_list + line)->name} ;

		int spaces{};
		spaces = config::last_position - m_screen[m_screen.size() - 1].size();
		m_screen[m_screen.size() - 1].append(spaces, ' ');

		m_screen.push_back("");
		m_screen[m_screen.size() - 1].append(config::last_position, ' ');
	}

	for (int line = 0; line < config::control_line_shift; ++line)
	{
		m_screen.push_back("");
		m_screen[m_screen.size() - 1].append(config::last_position, ' ');
	}

	m_screen.push_back("");
	m_screen[m_screen.size() - 1].append(config::control_position, ' ');

	int spaces{};
	m_screen[m_screen.size() - 1].append(config::up_shift, ' ');
	m_screen[m_screen.size() - 1] += "Up";
	spaces = config::last_position - m_screen[m_screen.size() - 1].size();
	m_screen[m_screen.size() - 1].append(spaces, ' ');

	m_screen.push_back("");
	m_screen[m_screen.size() - 1].append(config::last_position, ' ');
	
	m_screen.push_back("");
	m_screen[m_screen.size() - 1].append(config::control_position, ' ');
	m_screen[m_screen.size() - 1] += "Exit { Q }";
	m_screen[m_screen.size() - 1].append(config::w_shift, ' ');
	m_screen[m_screen.size() - 1] += "{ W }";
	m_screen[m_screen.size() - 1].append(config::r_shift, ' ');
	m_screen[m_screen.size() - 1] += "{ R } Heal";
	spaces = config::last_position - m_screen[m_screen.size() - 1].size();
	m_screen[m_screen.size() - 1].append(spaces, ' ');

	m_screen.push_back("");
	m_screen[m_screen.size() - 1].append(config::last_position, ' ');

	m_screen.push_back("");
	m_screen[m_screen.size() - 1].append(config::control_position, ' ');
	m_screen[m_screen.size() - 1].append(config::left_shift, ' ');
	m_screen[m_screen.size() - 1] += "Left { A } ";
	m_screen[m_screen.size() - 1] += "{ S } ";
	m_screen[m_screen.size() - 1] += "{ D } Right";
	m_screen[m_screen.size() - 1].append(config::f_shift, ' ');
	m_screen[m_screen.size() - 1] += "{ F } Attack / Select";
	spaces = config::last_position - m_screen[m_screen.size() - 1].size();
	m_screen[m_screen.size() - 1].append(spaces, ' ');

	m_screen.push_back("");
	m_screen[m_screen.size() - 1].append(config::last_position, ' ');

	m_screen.push_back("");
	m_screen[m_screen.size() - 1].append(config::control_position, ' ');
	m_screen[m_screen.size() - 1].append(config::down_shift, ' ');
	m_screen[m_screen.size() - 1] += "Down";
	spaces = config::last_position - m_screen[m_screen.size() - 1].size();
	m_screen[m_screen.size() - 1].append(spaces, ' ');

	m_screen.push_back("");
	m_screen[m_screen.size() - 1].append(config::control_position, ' ');
	m_screen[m_screen.size() - 1].append(config::space_shift, ' ');
	m_screen[m_screen.size() - 1] += "{          Space          } Finish Turn";
	spaces = config::last_position - m_screen[m_screen.size() - 1].size();
	m_screen[m_screen.size() - 1].append(spaces, ' ');
}

void Render::drawInputName(const config::Record& record)
{
	if (!m_screen.empty())
	{
		m_screen.clear();
	}

	for (int line = 0; line < config::fool_screen_height / 2 - 1; ++line)
	{
		m_screen.push_back("");
		m_screen[m_screen.size() - 1].append(config::last_position, ' ');
	}

	m_screen.push_back("");
	m_screen[m_screen.size() - 1].append(config::record_name_position, ' ');

	m_screen[m_screen.size() - 1] += "Name { ";
	m_screen[m_screen.size() - 1].append(20, '.');
	m_screen[m_screen.size() - 1] += " }";

	int spaces{};
	spaces = config::record_start_total_position - m_screen[m_screen.size() - 1].size();
	m_screen[m_screen.size() - 1].append(spaces, ' ');

	m_screen[m_screen.size() - 1] += "Total { ";
	m_screen[m_screen.size() - 1] += std::to_string(record.total_score);
	spaces = config::record_end_total_position - m_screen[m_screen.size() - 1].size();
	m_screen[m_screen.size() - 1].append(spaces, ' ');
	m_screen[m_screen.size() - 1].push_back('}');

	spaces = config::last_position - m_screen[m_screen.size() - 1].size();
	m_screen[m_screen.size() - 1].append(spaces, ' ');

	m_screen.push_back("");
	spaces = config::record_enemies_killed_position - m_screen[m_screen.size() - 1].size();
	m_screen[m_screen.size() - 1].append(spaces, ' ');

	m_screen[m_screen.size() - 1] += "Enemies killed { ";
	m_screen[m_screen.size() - 1] += std::to_string(record.enemies_killed);
	m_screen[m_screen.size() - 1] += " }";

	spaces = config::record_turns_position - m_screen[m_screen.size() - 1].size();
	m_screen[m_screen.size() - 1].append(spaces, ' ');

	m_screen[m_screen.size() - 1] += "Turns { ";
	m_screen[m_screen.size() - 1] += std::to_string(record.turns);
	m_screen[m_screen.size() - 1] += " }";

	spaces = config::record_treasures_position - m_screen[m_screen.size() - 1].size();
	m_screen[m_screen.size() - 1].append(spaces, ' ');

	m_screen[m_screen.size() - 1] += "Treasures { ";
	m_screen[m_screen.size() - 1] += std::to_string(record.treasures);
	m_screen[m_screen.size() - 1] += " }";

	spaces = config::last_position - m_screen[m_screen.size() - 1].size();
	m_screen[m_screen.size() - 1].append(spaces, ' ');

	m_screen.push_back("");
	spaces = config::last_position - m_screen[m_screen.size() - 1].size();
	m_screen[m_screen.size() - 1].append(spaces, ' ');

	for (int line = 0; line < config::fool_screen_height - (config::fool_screen_height / 2 - 1 + config::record_default_height); ++line)
	{
		m_screen.push_back("");
		m_screen[m_screen.size() - 1].append(config::last_position, ' ');
	}
}

void Render::drawRecords()
{
	if (!m_screen.empty())
	{
		m_screen.clear();
	}

	for (int line = 0; line < config::fool_screen_height / 2 + 1; ++line)
	{
		m_screen.push_back("");
		m_screen[m_screen.size() - 1].append(config::last_position, ' ');
	}

	m_screen.push_back("");
	int spaces{};
	spaces = config::last_position - config::work_space / 2 - config::empty_records_len / 2;
	m_screen[m_screen.size() - 1].append(spaces, ' ');

	m_screen[m_screen.size() - 1] += std::string{ config::messages[config::empty_records_message] };
	spaces = config::last_position - m_screen[m_screen.size() - 1].size();
	m_screen[m_screen.size() - 1].append(spaces, ' ');

	for (int line = 0; line < config::fool_screen_height / 2 - 1; ++line)
	{
		m_screen.push_back("");
		m_screen[m_screen.size() - 1].append(config::last_position, ' ');
	}

}

void Render::drawRecords(const std::vector<config::Record>& table)
{
	if (!m_screen.empty())
	{
		m_screen.clear();
	}

	for (int line = 0; line < config::free_lines; ++line)
	{
		m_screen.push_back("");
		m_screen[m_screen.size() - 1].append(config::last_position, ' ');
	}
	
	m_screen.push_back("");
	int spaces{};
	spaces = config::free_space + config::work_space / 2 - config::top_15_len;
	m_screen[m_screen.size() - 1].append(spaces, ' ');

	m_screen[m_screen.size() - 1] += std::string{ config::messages[config::top_15_message] };

	spaces = config::last_position - m_screen[m_screen.size() - 1].size();
	m_screen[m_screen.size() - 1].append(spaces, ' ');

	m_screen.push_back("");
	m_screen[m_screen.size() - 1].append(config::last_position, ' ');

	for (const config::Record& record : table)
	{
		m_screen.push_back("");
		m_screen[m_screen.size() - 1].append(config::record_name_position, ' ');

		m_screen[m_screen.size() - 1] += "Name { ";
		m_screen[m_screen.size() - 1] += record.name;
		m_screen[m_screen.size() - 1] += " }";

		spaces = config::record_start_total_position - m_screen[m_screen.size() - 1].size();
		m_screen[m_screen.size() - 1].append(spaces, ' ');

		m_screen[m_screen.size() - 1] += "Total { ";
		m_screen[m_screen.size() - 1] += std::to_string(record.total_score);
		spaces = config::record_end_total_position - m_screen[m_screen.size() - 1].size();
		m_screen[m_screen.size() - 1].append(spaces, ' ');
		m_screen[m_screen.size() - 1].push_back('}');

		spaces = config::last_position - m_screen[m_screen.size() - 1].size();
		m_screen[m_screen.size() - 1].append(spaces, ' ');

		m_screen.push_back("");
		spaces = config::record_enemies_killed_position - m_screen[m_screen.size() - 1].size();
		m_screen[m_screen.size() - 1].append(spaces, ' ');

		m_screen[m_screen.size() - 1] += "Enemies killed { ";
		m_screen[m_screen.size() - 1] += std::to_string(record.enemies_killed);
		m_screen[m_screen.size() - 1] += " }";

		spaces = config::record_turns_position - m_screen[m_screen.size() - 1].size();
		m_screen[m_screen.size() - 1].append(spaces, ' ');

		m_screen[m_screen.size() - 1] += "Turns { ";
		m_screen[m_screen.size() - 1] += std::to_string(record.turns);
		m_screen[m_screen.size() - 1] += " }";

		spaces = config::record_treasures_position - m_screen[m_screen.size() - 1].size();
		m_screen[m_screen.size() - 1].append(spaces, ' ');

		m_screen[m_screen.size() - 1] += "Treasures { ";
		m_screen[m_screen.size() - 1] += std::to_string(record.treasures);
		m_screen[m_screen.size() - 1] += " }";

		spaces = config::last_position - m_screen[m_screen.size() - 1].size();
		m_screen[m_screen.size() - 1].append(spaces, ' ');

		m_screen.push_back("");
		spaces = config::last_position - m_screen[m_screen.size() - 1].size();
		m_screen[m_screen.size() - 1].append(spaces, ' ');
	}

	int lines{};
	lines = config::fool_screen_height - (config::free_lines + config::records_title_height + table.size() * config::record_default_height);
	for (int line = 0; line < lines ; ++line)
	{
		m_screen.push_back("");
		m_screen[m_screen.size() - 1].append(config::last_position, ' ');
	}
}

void Render::drawGameOver()
{
	if (!m_screen.empty())
	{
		m_screen.clear();
	}

	for (int line = 0; line < config::start_game_over_line; ++line)
	{
		m_screen.push_back("");
		m_screen[m_screen.size() - 1].append(config::last_position, ' ');
	}

	m_screen.push_back("");
	m_screen[m_screen.size() - 1].append(config::game_over_position, ' ');
	m_screen[m_screen.size() - 1] += std::string{ config::messages[config::game_over_message] };
	m_screen[m_screen.size() - 1].append(config::last_position - m_screen[m_screen.size() - 1].size() + 1, ' ');

	for (int line = 0; line < config::fool_screen_height - config::start_game_over_line; ++line)
	{
		m_screen.push_back("");
		m_screen[m_screen.size() - 1].append(config::last_position, ' ');
	}
}

void Render::drawConfirm()
{
	if (!m_screen.empty())
	{
		m_screen.clear();
	}

	for (int line = 0; line < config::start_confirm_line; ++line)
	{
		m_screen.push_back("");
		m_screen[m_screen.size() - 1].append(config::last_position, ' ');
	}

	m_screen.push_back("");
	m_screen[m_screen.size() - 1].append(config::confirm_position, ' ');
	m_screen[m_screen.size() - 1] += config::confirm[0];
	m_screen[m_screen.size() - 1].append(config::last_position - m_screen[m_screen.size() - 1].size() + 1, ' ');

	m_screen.push_back("");
	m_screen[m_screen.size() - 1].append(config::last_position, ' ');

	m_screen.push_back("");
	m_screen[m_screen.size() - 1].append(config::confirm_position, ' ');
	m_screen[m_screen.size() - 1] += config::confirm[1];
	m_screen[m_screen.size() - 1].append(config::confirm_space_len, ' ');
	m_screen[m_screen.size() - 1] += config::confirm[2];
	m_screen[m_screen.size() - 1].append(config::last_position - m_screen[m_screen.size() - 1].size() + 1, ' ');

	for (int line = 0; line < config::fool_screen_height - config::end_confirm_line; ++line)
	{
		m_screen.push_back("");
		m_screen[m_screen.size() - 1].append(config::last_position, ' ');
	}
}

void Render::showScreen() const
{
	for (auto& line : m_screen)
	{
		std::cout.write(line.data(), line.size());
		std::cout.put('\n');
	}
}

void Render::setCursor(short y, short x)
{
	HANDLE handle_console = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(handle_console, { x, y });
}
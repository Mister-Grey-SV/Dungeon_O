#include "Game.h"
#include "config.h"
#include "level_data.h"
#include <utility>
#include <thread>
#include <chrono>

#include "Render.h"
#include "World.h"
#include "Player.h"

#include "Interface.h"
#include "AI.h"

const config::Score& Game::getScore() const
{
	return m_score;
}

bool Game::run()
{
	World world;
	Render render;
	AI ai;

	resetState();
	createActors();
	fillWorld(world);

	m_running = true;
	while (m_running)
	{
		if (((m_actors[m_current].getPosition().y - m_actors[0].getPosition().y) *
			(m_actors[m_current].getPosition().y - m_actors[0].getPosition().y) +
			(m_actors[m_current].getPosition().x - m_actors[0].getPosition().x) *
			(m_actors[m_current].getPosition().x - m_actors[0].getPosition().x) <=
			(config::render_distance + config::reserve_distance) *
			(config::render_distance + config::reserve_distance) &&
			world.lineOfSight(m_actors[0].getPosition(), m_actors[m_current].getPosition())))
		{
			render.drawLevel(world, m_actors[0], m_fight_log, m_turn_of);
			render.setCursor(0, 0);
			render.showScreen();
		}

		if (m_actors[m_current].m_entity == config::Entity::Player &&
			world.getCell(m_actors[m_current].getPosition().y, m_actors[m_current].getPosition().x).message != config::none_message)
		{
			render.drawMessage(world.getCell(m_actors[m_current].getPosition().y, m_actors[m_current].getPosition().x).message);
			render.setCursor(getYForMessage(), getXForMessage());
			render.showScreen();
			
			if (world.getCell(m_actors[m_current].getPosition().y, m_actors[m_current].getPosition().x).message == config::scream_message)
			{
				Interface::getCommand();
				render.drawMessage(config::run_message);
				render.setCursor(getYForMessage(), getXForMessage());
				render.showScreen();
			}

			world.getCell(m_actors[m_current].getPosition().y, m_actors[m_current].getPosition().x).message = config::none_message;
		}

		if (m_locked_chest_message == true)
		{
			render.drawMessage(config::locked_chest_message);
			render.setCursor(getYForMessage(), getXForMessage());
			render.showScreen();
			m_locked_chest_message = false;
		}

		if (m_locked_dor_message == true)
		{
			render.drawMessage(config::locked_dor_message);
			render.setCursor(getYForMessage(), getXForMessage());
			render.showScreen();
			m_locked_dor_message = false;
		}

		if (m_open_message == true)
		{
			render.drawMessage(config::open_message);
			render.setCursor(getYForMessage(), getXForMessage());
			render.showScreen();
			m_open_message = false;
		}

		if (m_first_key_message == true)
		{
			render.drawMessage(config::first_key_message);
			render.setCursor(getYForMessage(), getXForMessage());
			render.showScreen();
			m_first_key_message = false;
		}

		if (m_next_key_message == true)
		{
			render.drawMessage(config::next_key_message);
			render.setCursor(getYForMessage(), getXForMessage());
			render.showScreen();
			m_next_key_message = false;
		}

		config::Command command{};
		if (m_actors[m_current].m_entity == config::Entity::Player)
		{
			command = Interface::getCommand();
		}

		else if (m_actors[m_current].m_entity == config::Entity::Enemy)
		{
			command = ai.getCommand(world, m_actors[m_current], m_actors[0].getPosition());
		}

		bool done{};
		switch (command)
		{
			case config::Command::Up:
				done = move(world, m_actors[m_current], config::direction_up);

				if (done) { ai.resetMoveTries(); }
				else { ai.incrementMoveTries(); }

				m_actors[m_current].setDirection(config::direction_up);
				break;

			case config::Command::Down:
				done = move(world, m_actors[m_current], config::direction_down);
			
				if (done) {	ai.resetMoveTries(); }
				else { ai.incrementMoveTries(); }

				m_actors[m_current].setDirection(config::direction_down);
				break;

			case config::Command::Left:
				done = move(world, m_actors[m_current], config::direction_left);
			
				if (done) { ai.resetMoveTries(); }
				else { ai.incrementMoveTries(); }

				m_actors[m_current].setDirection(config::direction_left);
				break;

			case config::Command::Right:
				done = move(world, m_actors[m_current], config::direction_right);
			
				if (done) { ai.resetMoveTries(); }
				else { ai.incrementMoveTries(); }

				m_actors[m_current].setDirection(config::direction_right);
				break;

			case config::Command::Attack:
				if (!m_actors[m_current].checkActions(config::attack_cost)) break;

				calculateAttack(world, m_actors[m_current]);
				break;

			case config::Command::Heal:
				if (m_actors[m_current].checkActions(config::heal_cost) &&
					m_actors[m_current].getInventory().m_heal > 0)
				{
					m_actors[m_current].heal(diceRoll(config::Dices::D10, config::def_player_heal_bonus));
					++m_score.potions_used;
					m_actors[m_current].spendActions(config::heal_cost);
				}
				break;
		
			case config::Command::EndTurn:
				m_actors[m_current].resetMovementState();
				m_actors[m_current].passiveRegen();
				ai.resetMoveTries();
				if(m_actors[m_current].m_entity == config::Entity::Player) ++m_score.turns;
				changeCurrent();
				m_turn_of = m_actors[m_current].m_entity;
				break;

			case config::Command::Exit:
			{
				bool choose{ true };
				while (choose)
				{
					render.drawConfirm();
					render.setCursor(0, 0);
					render.showScreen();
					switch (Interface::getCommand())
					{
						case config::Command::Exit:
							choose = false;
							break;

						case config::Command::Attack:
							choose = false;
							m_running = false;
							break;

						default: break;
					}
				}
			}
				break;
			

			default: break;
		
		}

		if (((m_actors[m_current].getPosition().y - m_actors[0].getPosition().y) *
			(m_actors[m_current].getPosition().y - m_actors[0].getPosition().y) +
			(m_actors[m_current].getPosition().x - m_actors[0].getPosition().x) *
			(m_actors[m_current].getPosition().x - m_actors[0].getPosition().x) <= 
			(config::render_distance + config::reserve_distance) * 
			(config::render_distance + config::reserve_distance)) &&
			world.lineOfSight(m_actors[0].getPosition(), m_actors[m_current].getPosition()))
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(50));
		}
	}

	switch (m_result)
	{
		case config::GameResult::Victory:
			render.drawLevel(world, m_actors[0], m_fight_log, m_turn_of);
			render.setCursor(0, 0);
			std::this_thread::sleep_for(std::chrono::milliseconds(1000));
			render.showScreen();
			return true;

		case config::GameResult::Defeat:
			render.drawLevel(world, m_actors[0], m_fight_log, m_turn_of);
			render.setCursor(0, 0);
			render.showScreen();
			std::this_thread::sleep_for(std::chrono::milliseconds(3000));
			return false;

		default: return false;
	}
}

void Game::resetState()
{
	m_current = 0;
	m_turn_of = config::Entity::Player;
	m_score.clear();
	m_locked_chest_message = false;
	m_locked_dor_message = false;
	m_open_message = false;
	m_first_key_message = false;
	m_next_key_message = false;
	m_result = config::GameResult::Quit;
	if (!m_fight_log.empty()) m_fight_log.clear();
}

void Game::createActors()
{
	if (!m_actors.empty()) m_actors.clear();

	for (int i = 0; i < level_data::creation_size; ++i)
	{
		m_actors.push_back
		(
			Player
			(
				level_data::creation[i].m_entity,
				level_data::creation[i].m_sprite,
				{
					level_data::creation[i].m_position.y,
					level_data::creation[i].m_position.x
				},
				level_data::creation[i].m_beahvior
			)
		);

		m_actors[m_actors.size() - 1].setStats
		(
			{
				level_data::creation[i].m_max_hp,
				level_data::creation[i].m_hp,
				level_data::creation[i].m_armor_class,
				level_data::creation[i].m_attack_bonus,
				level_data::creation[i].m_attack_dice,
				level_data::creation[i].m_damage_bonus,
				level_data::creation[i].m_damage_dice
			}
		);
	}
}

void Game::fillWorld(World& world)
{
	for (auto& actor : m_actors)
	{
		world.setLocation(&actor, actor.getPosition());
	}

	for (int i = 0; i < level_data::heal_potions_size; ++i)
	{
		world.getCell(level_data::heal_potions[i].y, level_data::heal_potions[i].x).heal_potion = true;
	}

	for (int i = 0; i < level_data::treasures_size; ++i)
	{
		world.getCell(level_data::treasures[i].y, level_data::treasures[i].x).treasure = true;
	}

	for (int key = 0; key < level_data::keys_size; ++key)
	{
		world.getCell(level_data::keys[key].y, level_data::keys[key].x).key = true;
	}

	for (int exit = 0; exit < level_data::exits_size; ++exit)
	{
		world.getCell(level_data::exits[exit].y, level_data::exits[exit].x).exit = true;
	}

	for (int rope = 0; rope < level_data::ropes_size; ++rope)
	{
		world.getCell(level_data::ropes[rope].y, level_data::ropes[rope].x).title = config::rope_sprite;
	}

	for (int message = 0; message < level_data::message_list_size; ++message)
	{
		world.getCell(level_data::message_list[message].message_position.y, level_data::message_list[message].message_position.x)
			.message = level_data::message_list[message].message_num;
	}
}

bool Game::chekCellIsFree(const World::Cell& cell) const
{
	return (cell.title != config::wall_sprite && cell.actor == nullptr);
}

bool Game::move(World& world, Player& player, const config::Position& direction)
{
	config::Position new_position
	{
		player.getPosition().y + direction.y,
		player.getPosition().x + direction.x
	};

	if (new_position.y < 0 ||
		new_position.y >= config::map_height ||
		new_position.x < 0 ||
		new_position.x >= config::map_width)
	{
		return false;
	}

	if (!chekCellIsFree(world.getCell(new_position.y, new_position.x)) ||
		!player.checkMovementState())
	{
		return false;
	}

	if (player.m_entity == config::Entity::Player &&
		world.getCell(new_position.y, new_position.x).heal_potion)
	{
		player.addHillPotiont();
		++m_score.potions_found;
		world.getCell(new_position.y, new_position.x).heal_potion = false;
		return false;
	}

	if (player.m_entity == config::Entity::Player &&
		world.getCell(new_position.y, new_position.x).key)
	{

		if (player.getInventory().m_keys == 0)
		{
			player.addKey();
			world.getCell(new_position.y, new_position.x).key = false;
			m_first_key_message = true;
			return false;
		}

		else
		{
			player.addKey();
			world.getCell(new_position.y, new_position.x).key = false;
			m_next_key_message = true;
			return false;
		}
		
	}

	if (player.m_entity == config::Entity::Player &&
		world.getCell(new_position.y, new_position.x).treasure)
	{
		if (player.getInventory().m_keys == 0)
		{
			m_locked_chest_message = true;
			return false;
		}

		else
		{
			player.addTreasure();
			++m_score.treasures;
			player.spendKey();
			world.getCell(new_position.y, new_position.x).treasure = false;
			m_open_message = true;
			return false;
		}
	}

	if (player.m_entity == config::Entity::Player &&
		world.getCell(new_position.y, new_position.x).exit)
	{
		if (player.getInventory().m_keys == 0)
		{
			m_locked_dor_message = true;
			return false;
		}

		else
		{
			player.spendKey();
			m_result = config::GameResult::Victory;
			m_running = false;
		}
	}

	player.spendMove();
	world.clearLocation(player.getPosition());
	player.setPosition(new_position.y, new_position.x);
	world.setLocation(&player, new_position);

	return true;
}

void Game::calculateAttack(World& world, Player& player)
{
	Player* target = world.getCell(
		player.getPosition().y + player.getDirection().y,
		player.getPosition().x + player.getDirection().x)
		.actor;

	if (target != nullptr)
	{
		config::AttackLog attack
		{
			player.m_entity,
			target->m_entity,
			player.getStats().attack_dice,
			player.getStats().attack_bonus,
			target->getStats().armor_class,
			player.getStats().damage_dice,
			player.getStats().damage_bonus
		};

		attack.m_attack_roll = diceRoll(attack.m_attack_dice, attack.m_attack_bonus);

		if (attack.m_attack_roll >= attack.m_armor_class)
		{
			attack.m_hit = true;
			attack.m_damage_roll = diceRoll(attack.m_damage_dice, attack.m_damage_bonus);
			target->takeDamage(attack.m_damage_roll);

			if (target->getStats().hp <= 0)
			{
				attack.m_killed = true;
				++m_score.enemies_killed;

				if (&m_actors[0] == target)
				{
					m_running = false;
					m_result = config::GameResult::Defeat;
				}

				switch (world.getCell(target->getPosition().y, target->getPosition().x).actor->getSprite())
				{
					case config::mob_sprite:
						if (dropRoll(config::mob_drop_chance))
						{
							world.getCell(target->getPosition().y, target->getPosition().x).heal_potion = true;
						}

						break;

					case config::boss_sprite:
						world.getCell(target->getPosition().y, target->getPosition().x).key = true;
						break;

					case config::player_sprite:
						target->setSprite(config::dead_sprite);
						break;

					default: break;
				}

				if (target->m_entity != config::Entity::Player)
				{
					world.getCell(target->getPosition().y, target->getPosition().x).actor = nullptr;

					for (int i = 0; i < m_actors.size(); ++i)
					{
						if (&m_actors[i] == target)
						{
							m_actors.erase(m_actors.begin() + i);
							if (i < m_current)
							{
								--m_current;
							}

							break;
						}
					}

					target = nullptr;

					for (auto& actor : m_actors)
					{
						world.setLocation(&actor, actor.getPosition());
					}
				}
			}
		}

		updateLog(attack);
		m_actors[m_current].spendActions(config::attack_cost);
	}
}

void Game::changeCurrent()
{
	m_current++;
	if (m_current == m_actors.size())
	{
		m_current = 0;
	}
}

int Game::diceRoll(config::Dices dice, int bonus)
{
	int max{};
	switch (dice)
	{
		case config::Dices::D4:		max = 4;	break;
		case config::Dices::D6:		max = 6;	break;
		case config::Dices::D8:		max = 8;	break;
		case config::Dices::D10:	max = 10;	break;
		case config::Dices::D12:	max = 12;	break;
		case config::Dices::D20:	max = 20;	break;
	}

	std::uniform_int_distribution<int> roll{ 1, max };

	return roll(m_random_generator) + bonus;
}

bool Game::dropRoll(float chance)
{
	std::bernoulli_distribution roll{chance};

	return roll(m_random_generator);
}

void Game::updateLog(config::AttackLog data)
{
	m_fight_log.push_back(data);
	if (m_fight_log.size() >= config::log_list_size)
	{
		m_fight_log.erase(m_fight_log.begin());
	}
}

const config::GameResult& Game::getResult() const
{
	return m_result;
}

short Game::getYForMessage() const
{
	return m_actors[0].getPosition().y - 2 + config::free_lines;
}
short Game::getXForMessage() const
{
	if (config::map_width - m_actors[0].getPosition().x >=
		config::default_distance_for_message)
	{
		return m_actors[0].getPosition().x * 2 + config::free_space;
	}

	else
	{
		return ( ( m_actors[0].getPosition().x ) * 2 - 
			( config::default_distance_for_message * 2 - 
				(config::map_width - m_actors[0].getPosition().x) * 2) * 2 + config::free_space);  // strenge situation
	}
}
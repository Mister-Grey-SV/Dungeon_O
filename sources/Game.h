#pragma once
#include "config.h"
#include "World.h"
#include "Player.h"
#include <vector>
#include <random>

class Render;

class Game
{
private:
	bool m_running{ true };
	size_t m_current{};
	std::mt19937 m_random_generator{ std::random_device{}() };

	std::vector<Player> m_actors;

	bool m_locked_chest_message{ false };
	bool m_locked_dor_message{ false };
	bool m_open_message{ false };
	bool m_first_key_message{ false };
	bool m_next_key_message{ false };

	std::vector<config::AttackLog> m_fight_log;
	config::Entity m_turn_of{config::Entity::Player};

	config::GameResult m_result{ config::GameResult::Quit };
	config::Score m_score;

public:
	Game() = default;

	const config::Score& getScore() const;
	bool run();
	void resetState();
	void createActors();
	void fillWorld(World& world);
	bool chekCellIsFree(const World::Cell& cell) const;
	bool move(World& world, Player& player, const config::Position& direction);
	void calculateAttack(World& world, Player& player);
	void changeCurrent();
	int diceRoll(config::Dices dice, int bonus );
	bool dropRoll(float chance);
	void updateLog(config::AttackLog data);
	const config::GameResult& getResult() const;

	short getYForMessage() const;
	short getXForMessage() const;
};


#pragma once
#include "config.h"

class Player;
class World;

class AI
{
public:
	enum class State
	{
		Default,
		Fight
	};

private:
	State m_state{};

	int	m_move_tries{};

	int m_patrol_moves_right{};
	int m_patrol_moves_left{};


	config::Position m_target{};
	

public:
	AI() = default;

	void incrementMoveTries();
	void resetMoveTries();

	void lookAround(World& world, Player& actor, config::Position player_position);

	config::Command defMode(World& world, Player& actor);
	config::Command fight(World& world, Player& actor);

	config::Command getCommand(World& world, Player& actor, config::Position player_position);

};


#include "AI.h"
#include "Player.h"
#include "World.h"
#include <cmath>

void AI::lookAround(World& world, Player& actor, config::Position player_position)
{
	m_target = { 0, 0 };
	m_state = AI::State::Default;

	config::Position my_position = actor.getPosition();

	if ((my_position.y - player_position.y) *
		(my_position.y - player_position.y) +
		(my_position.x - player_position.x) *
		(my_position.x - player_position.x) >
		config::vision_distance * config::vision_distance)
	{
		return;
	}

	else if (world.lineOfSight(my_position, player_position))
	{
		m_target = player_position;
		m_state = AI::State::Fight;
		return;
	}

	return;
}

void AI::incrementMoveTries()
{
		++m_move_tries;
}

void AI::resetMoveTries()
{
	m_move_tries = 0;
}

config::Command AI::defMode(World& world, Player& actor)
{
	config::Behavior& behavior = actor.getBehavior();

	while (true)
	{
		if (behavior.action == config::Actions::Stay)
		{
			return config::Command::EndTurn;
		}

		else if (!behavior.turn && behavior.patrol_distance_done < behavior.patrol_distance)
		{
			++behavior.patrol_distance_done;
			if (behavior.action == config::Actions::PatrolHorizontal)
			{
				return config::Command::Right;
			}

			else if (behavior.action == config::Actions::PatrolVertical)
			{
				return config::Command::Down;
			}

		}

		else if (!behavior.turn)
		{
			behavior.turn = true;
			behavior.patrol_distance_done = 0;
		}

		else if (behavior.turn && behavior.patrol_distance_done < behavior.patrol_distance)
		{
			++behavior.patrol_distance_done;
			if (behavior.action == config::Actions::PatrolHorizontal)
			{
				return config::Command::Left;
			}

			else if (behavior.action == config::Actions::PatrolVertical)
			{
				return config::Command::Up;
			}
		}

		else if (behavior.turn)
		{
			behavior.turn = false;
			behavior.patrol_distance_done = 0;
		}
	}
}

config::Command AI::fight(World& world, Player& actor)
{
	config::Position my_position = actor.getPosition();

	if (m_target.y == my_position.y + actor.getDirection().y &&
		m_target.x == my_position.x + actor.getDirection().x)
	{
		if (world.getCell(m_target.y,m_target.x).actor != nullptr && 
			world.getCell(m_target.y, m_target.x).actor->m_entity == config::Entity::Player)
		{
			if (actor.checkActions(config::attack_cost))
			{
				return config::Command::Attack;
			}

			return config::Command::EndTurn;
		}
	}

	if (std::abs(m_target.y - my_position.y) <= std::abs(m_target.x - my_position.x))
	{
		if (m_target.y < my_position.y)
		{
			return config::Command::Up;
		}

		else if (m_target.y > my_position.y)
		{
			return config::Command::Down;
		}

		else if (m_target.x < my_position.x)
		{
			return config::Command::Left;
		}

		else if (m_target.x > my_position.x)
		{
			return config::Command::Right;
		}
	}

	else
	{
		if (m_target.x < my_position.x)
		{
			return config::Command::Left;
		}

		else if (m_target.x > my_position.x)
		{
			return config::Command::Right;
		}

		else if (m_target.y < my_position.y)
		{
			return config::Command::Up;
		}

		else if (m_target.y > my_position.y)
		{
			return config::Command::Down;
		}
	}

	return config::Command::EndTurn;
}

config::Command AI::getCommand(World& world, Player& actor, config::Position player_position)
{
	lookAround(world, actor, player_position);

	if (!actor.checkMovementState() || m_move_tries >= config::max_move_tries_qty)
	{
		return config::Command::EndTurn;
	}

	if (m_state == State::Default)
	{
		return defMode(world, actor);
	}

	else if (m_state == State::Fight)
	{
		return fight(world, actor);
	}

	return config::Command::EndTurn;
}
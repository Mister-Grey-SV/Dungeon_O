#pragma once
#include "config.h"

class Player
{
public:
	config::Entity m_entity;

private:
	config::Position		m_position;
	config::Position		m_direction;
	config::Stats			m_stats;
	config::Inventory		m_inventory;

	char					m_sprite;

	config::MovementState	m_movement_state;

	config::Behavior m_behavior;

	Player
	(
		config::Entity entity,
		config::Position position,
		config::Position direction,
		config::Stats stats,
		config::Inventory inventory,
		char sprite,
		config::MovementState movement_state,
		config::Behavior behavior
	)
		:m_entity{ entity },
		m_position{ position },
		m_direction{ direction },
		m_stats{ stats },
		m_inventory{ inventory },
		m_sprite{ sprite },
		m_movement_state{ movement_state },
		m_behavior{behavior}

	{ }

public:
	Player
	(
		config::Entity entity,
		char sprite,
		config::Position position,
		config::Behavior beahavior
	)
		:Player
		(
			entity,
			position,
			config::direction_none,
			{ 
				config::player_hp, 
				config::player_hp,
				config::player_armor_class, 
				config::player_attack_bonus, 
				config::player_attack_dice, 
				config::player_damage_bonus, 
				config::player_damage_dice
			},
			{ 
				config::def_player_heal_qty,
				config::def_player_treasure_qty
			},
			sprite,
			{ 
				config::actions_qty, 
				config::moves_qty 
			},
			beahavior
		)

	{ }

	void setSprite(const char sprite);
	char getSprite() const;

	const config::Position& getPosition() const;
	void setPosition(int y, int x);

	const config::Stats& getStats();
	void setStats(config::Stats stats);

	const config::Inventory& getInventory();
	void addHillPotiont();
	void addTreasure();
	void addKey();

	void spendKey();

	const config::Position& getDirection() const;
	void setDirection(const config::Position& direction);

	bool checkMovementState() const;
	bool checkActions(const int qty) const;

	void spendMove();
	void spendActions(const int qty);

	void resetMovementState();

	const config::MovementState& getMovementState() const;

	config::Behavior& getBehavior();
	void setBehavior(const config::Behavior& behavior);

	void takeDamage(int damage);
	void heal(int heal_points);
	void passiveRegen();

};


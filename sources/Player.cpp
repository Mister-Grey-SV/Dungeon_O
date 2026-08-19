#include "Player.h"
#include "config.h"

void Player::setSprite(const char sprite)
{
	m_sprite = sprite;
}

char Player::getSprite() const
{
	return m_sprite;
}

const config::Position& Player::getPosition() const
{
	return m_position;
}

void Player::setPosition(int y, int x)
{
	m_position.y = y;
	m_position.x = x;
}

const config::Stats& Player::getStats()
{
	return m_stats;
}

void Player::setStats(config::Stats stats)
{
	m_stats = stats;
}

const config::Inventory& Player::getInventory()
{
	return m_inventory;
}

void Player::addHillPotiont()
{
	++m_inventory.m_heal;
}

void Player::addTreasure()
{
	++m_inventory.m_treasure;
}

void Player::addKey()
{
	++m_inventory.m_keys;
}

void Player::spendKey()
{
	--m_inventory.m_keys;
}

const config::Position& Player::getDirection() const
{
	return m_direction;
}

void Player::setDirection(const config::Position& direction)
{
	m_direction = direction;
}

bool Player::checkMovementState() const
{
	return (m_movement_state.actions > 0 || m_movement_state.moves > 0);
}

bool Player::checkActions(const int qty) const
{
	return (m_movement_state.actions - qty >= 0);
}

void Player::spendMove()
{
	if (m_movement_state.moves <= 0 && m_movement_state.actions > 0)
	{
		m_movement_state.actions -= config::moves_pack_cost;
		m_movement_state.moves += config::moves_pack;
	}

	m_movement_state.moves -= 1;
}

void Player::spendActions(const int qty)
{
	m_movement_state.actions -= qty;
}

void Player::resetMovementState()
{
	m_movement_state.actions = config::actions_qty;
	m_movement_state.moves = config::moves_qty;
}

const config::MovementState& Player::getMovementState() const
{
	return m_movement_state;
}

config::Behavior& Player::getBehavior()
{
	return m_behavior;
}

void Player::setBehavior(const config::Behavior& behavior)
{
	m_behavior = behavior;
}

void Player::takeDamage(int damage)
{
	m_stats.hp -= damage;
}

void Player::heal(int heal_points)
{
	if (m_inventory.m_heal > 0)
	{
		m_stats.hp = (m_stats.hp + heal_points < m_stats.max_hp) ? 
			(m_stats.hp + heal_points) : m_stats.max_hp;
		--m_inventory.m_heal;
	}
}

void Player::passiveRegen()
{
	m_stats.hp = (m_stats.hp + config::passive_regen_value < m_stats.max_hp) ?
		(m_stats.hp + config::passive_regen_value) : m_stats.max_hp;
}
#pragma once
#include "config.h"
#include <vector>
#include <string>


class World;
class Player;

class Render
{
private:
	std::vector<std::string> m_screen;

public:
	Render() = default;

	void drawLevel(World& world, Player& player, const std::vector<config::AttackLog>& attack_logs, config::Entity turn_of);
	void drawMessage(uint16_t message);
	void drawMenu(config::MenuPoint m_list[]);
	void drawInputName(const config::Record& record);
	void drawRecords();
	void drawRecords(const std::vector<config::Record>& table);
	void drawGameOver();
	void drawConfirm();
	void showScreen() const;
	void setCursor(short y, short x);
};
#include "Menu.h"
#include "config.h"
#include "Game.h"
#include "Interface.h"
#include "Render.h"
#include "RecordManager.h"

Menu::Menu()
	:m_running{ false },
	cursor_position{ config::cursor_position_play }
{
	for (int point = 0; point < config::menu_points_size; ++point)
	{
		m_list[point] = config::menu_points[point];
	}
}

void Menu::run()
{
	Render render;
	Game game;
	RecordManager manager;

	m_running = true;
	while (m_running)
	{
		render.drawMenu(m_list);
		render.setCursor(0, 0);
		render.showScreen();

		switch (Interface::getCommand())
		{
			case config::Command::Up:

				if (cursor_position == 0) break;
				m_list[cursor_position].title = config::no_cursor_sprite;
				m_list[cursor_position - 1].title = config::cursor_sprite;
				--cursor_position;
				break;

			case config::Command::Down:

				if (cursor_position == config::menu_points_size - 1) break;
				m_list[cursor_position].title = config::no_cursor_sprite;
				m_list[cursor_position + 1].title = config::cursor_sprite;
				++cursor_position;
				break;

			case config::Command::Attack:

				switch (cursor_position)
				{
					case config::cursor_position_play:
						if (game.run())
						{
							config::Record record = manager.createRecord(game.getScore());

							std::string name;
							while (name.empty())
							{
								render.drawInputName(record);
								render.setCursor(0, 0);
								render.showScreen();

								render.setCursor(config::record_name_input_height, config::record_name_input_position);
								name = Interface::getName();
							}

							for (int ch = 0; ch < (((sizeof(record.name) / sizeof(char) - 1) < name.size()) ?
								(sizeof(record.name) / sizeof(char) - 1) : name.size()); ++ch)
							{
								record.name[ch] = name[ch];
							}

							manager.addRecord(record);
							manager.saveRecords();

							render.drawRecords(manager.getRecordsTable());
							render.setCursor(0, 0);
							render.showScreen();

							Interface::getCommand();
						}

						else if (game.getResult() == config::GameResult::Defeat)
						{
							render.drawGameOver();
							render.setCursor(0, 0);
							render.showScreen();

							Interface::getCommand();
						}

						break;

					case config::cursor_position_records:

						if (manager.getRecordsTable().size() == 0)
						{
							render.drawRecords();
							render.setCursor(0, 0);
							render.showScreen();
						}

						else
						{
							render.drawRecords(manager.getRecordsTable());
							render.setCursor(0, 0);
							render.showScreen();
						}

						Interface::getCommand();
						break;


					case config::cursor_position_exit:
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

				break;

			default: break;
		}
	}
}
#include "RecordManager.h"
#include <algorithm>
#include <fstream>

RecordManager::RecordManager()
{
	loadRecords();
}

void RecordManager::loadRecords()
{
	config::Record buffer;

	std::ifstream load("statistics.save", std::ios::binary);
	if (load.is_open())
	{
		while (load.read(reinterpret_cast<char*>(&buffer), sizeof(config::Record)))
		{
			m_records_table.push_back(buffer);
		}
	}
}

void RecordManager::saveRecords()
{
	std::ofstream save("statistics.save", std::ios::binary);
	if (save.is_open())
	{
		for (const config::Record& record : m_records_table)
		{
			save.write(reinterpret_cast<const char*>(&record), sizeof(config::Record));
		}
	}
}

config::Record RecordManager::createRecord(const config::Score& score) const
{
	config::Record record;

	record.treasures		= score.treasures;
	record.turns			= score.turns;
	record.enemies_killed	= score.enemies_killed;

	record.total_score =
		config::base_score
		+ score.treasures		* config::treasure_bonus
		+ score.potions_found	* config::potion_bonus
		- score.potions_used	* config::potion_penalty
		+ score.enemies_killed	* config::kill_bonus
		- score.turns			* config::turn_penalty;

	return record;
}

void RecordManager::addRecord(const config::Record& record)
{
	m_records_table.push_back(record);
	std::sort
	(
		m_records_table.begin(), m_records_table.end(), 
		[](const config::Record& curr, const config::Record& next) 
		{
			return curr.total_score > next.total_score; 
		}
	);

	if (m_records_table.size() > 15)
	{
		m_records_table.resize(15);
	}

}

const std::vector<config::Record>& RecordManager::getRecordsTable() const
{
	return m_records_table;
}


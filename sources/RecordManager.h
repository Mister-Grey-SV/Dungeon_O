#pragma once
#include "config.h"
#include <vector>

class RecordManager
{
private:
	std::vector<config::Record> m_records_table;

public:
	RecordManager();

	config::Record createRecord(const config::Score& score) const;
	void addRecord(const config::Record& record);
	const std::vector<config::Record>& getRecordsTable() const;
	void loadRecords();
	void saveRecords();

};


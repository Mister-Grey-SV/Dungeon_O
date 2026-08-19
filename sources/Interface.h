#pragma once
#include "config.h"
#include <string>

class Interface
{
public:
	static config::Command getCommand();
	static std::string getName();


};
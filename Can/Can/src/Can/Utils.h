#pragma once

#include <string>
#include <sstream>
#include <vector>

namespace Can
{
	static std::vector<std::string> StringSplit(const std::string& s, char delimeter)
	{
		std::vector<std::string> elements;
		std::stringstream ss(s);
		std::string item;
		while (std::getline(ss, item, delimeter))
			elements.push_back(item);
		return elements;
	}
}
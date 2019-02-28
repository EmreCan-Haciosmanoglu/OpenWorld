#pragma once

#include<string>

namespace EmreCan3D
{
	static std::string read_file(const char *filepath)
	{
		FILE* file = fopen(filepath, "rt");
		fseek(file, 0, SEEK_END);
		unsigned long lenght = ftell(file);
		char *data = new char[lenght + 1];

		memset(data, 0, lenght + 1);
		fseek(file, 0, SEEK_SET);
		fread(data, 1, lenght, file);
		fclose(file);

		std::string result(data);
		delete[] data;
		return result;
	}
}
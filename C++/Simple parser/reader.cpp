#include "reader.h"
#include<list>
#include<string>
#include<fstream>

Reader::Reader()
{
}


void Reader::fill_list(std::wifstream &file)
{
	while (std::getline(file, str))
	{
		lines.push_front(str);
	}
}

std::list<std::wstring> Reader::get_list()
{
	return lines;
}

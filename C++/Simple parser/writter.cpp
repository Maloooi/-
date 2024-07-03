#include "writter.h"
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <fstream>

Writter::Writter()
{
};
Comporator::Comporator()
{
}

void Writter::print_table(std::wofstream file, std::map<std::wstring, int> preTable, int wordsNumber)
{
	std::vector<mappair> mapVector(preTable.begin(), preTable.end());
	std::sort(mapVector.begin(), mapVector.end(), Comporator());
	for (int i = mapVector.size() - 1; i >= 0; i--)
	{
			file << mapVector[i].first << ";" << mapVector[i].second << ";" << (float)(mapVector[i].second) * 100 / wordsNumber << "\n";
	}
}


bool Comporator::operator()(const mappair& lhs, const mappair& rhs)
{
	return lhs.second < rhs.second;
}

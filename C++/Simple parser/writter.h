#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <fstream>

typedef std::pair<std::wstring, int> mappair;

class Writter {
public:
	Writter();
	void print_table(std::wofstream file, std::map <std::wstring, int> preTable, int wordsNumber);
};

class Comporator {
public:
	Comporator();
	bool operator()(const mappair& lhs, const mappair& rhs);
};
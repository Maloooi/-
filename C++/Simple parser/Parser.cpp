#include <fstream>
#include <iostream>
#include "reader.h"
#include "splitter.h"
#include "writter.h"
#include<list>
#include "constants.h"


int main(int argc,char **argv)
{
	if (argc < NUM_OF_ARGUMENTS)
	{
		std::cout << "Not enough arguments";
		return 1;
	}
	setlocale(LC_ALL, "Russian");
	std::wifstream input;
	if(input.is_open() == 0)
	input.open(argv[IN_FILE]);
	if (input.is_open() == 0)
	{
		std::cout << "Write valid input file name";
		return 0;
	}
	std::wofstream output;
	output.open(argv[OUT_FILE]);
	if (input.is_open() == 0)
	{
		std::cout << "Write valid output file name";
		return 0;
	}
	Reader reader;
	reader.fill_list(input);
	input.close();
	Splitter splitter;
	std::list <std::wstring> l = reader.get_list();
	splitter.map_creater(l);
	Writter writter;
	int wordsNumber = splitter.get_wordsNumber();
	std::map <std::wstring, int> preTable = splitter.get_preTable();
	writter.print_table(std::move(output), preTable, wordsNumber);
	return 0;
}

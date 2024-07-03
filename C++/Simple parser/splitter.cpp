#include<list>
#include<string>
#include<fstream>
#include <vector>
#include <map>
#include "splitter.h"
#include <ctype.h>




Splitter::Splitter() {
	wordsNumbers = 0;	
}

void Splitter::map_creater(std::list<std::wstring> lines)
{
	words_splitter(lines);
	auto pointer = words.cbegin();
	for (unsigned int i = 0; i < words.size(); i++)
	{
		int counter = 1;
		std::wstring str = words[i];
		for (unsigned int j = i + 1; j < words.size(); j++)
		{
			if (str == words[j])
			{
				counter++;
				words.erase(pointer + j);
			}
		}
		preTable[str] = counter;
	}
}

int Splitter::get_wordsNumber()
{
	return wordsNumbers;
}

const std::map<std::wstring, int>& Splitter::get_preTable()
{
	return preTable;
}

void Splitter::words_splitter(std::list<std::wstring> lines)
{
	int linesSize = lines.size();
	for (int i = 0; i < linesSize; i++)
	{
		std::wstring str = lines.back();
		line_splitt(str, words);
		lines.pop_back();
	}
	wordsNumbers = words.size();
}

void Splitter::line_splitt(std::wstring str, std::vector<std::wstring>& words)
{ 
	wchar_t buff[BUFFER_SIZE] = { 0 };
	int charCounter = 0;
	int chSize = str.length();
	const wchar_t* ch = str.c_str();
	for (int i = 0; i < chSize; i++)
	{
		if (isalpha(ch[i])|| isdigit(ch[i] ))
		{
			buff[charCounter] = ch[i];
			charCounter++;
			if (i == chSize - 1)
			{
				charCounter = 0;
				words.emplace_back(buff);
				memset(buff, 0, sizeof(buff));
			}
		}
		else if (buff[0] != ENDOFLINE)
		{
			charCounter = 0;
			words.emplace_back(buff);
			memset(buff, 0, sizeof(buff));
		}
	}
}

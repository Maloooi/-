#include<list>
#include<string>
#include<fstream>
#include <vector>
#include <map>
#include <ctype.h>

class Splitter 
{
public:
	Splitter();
	void map_creater(std::list <std::wstring> lines);
	int get_wordsNumber();
	const std::map <std::wstring, int>& get_preTable();
private:
	int wordsNumbers;
	static const int BUFFER_SIZE = 256;
	static const wchar_t ENDOFLINE = '\0';
	std::map <std::wstring, int> preTable;
	std::vector <std::wstring> words;
	void words_splitter(std::list <std::wstring> lines);
	void line_splitt(std::wstring str, std::vector<std::wstring>& words);
};

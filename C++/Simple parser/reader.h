#include<list>
#include<string>
#include<fstream>

class Reader
{
public:
	Reader();
	void fill_list(std::wifstream &file);
	std::list<std::wstring> get_list();
private:
	std::wstring str;
	std::list <std::wstring>lines;
};


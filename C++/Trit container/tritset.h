#pragma once
#include <unordered_map>
#include "trit.h"
#include <vector>
#include <cmath>
#include <map>

typedef unsigned int uint;


class tritset
{
public:
	explicit tritset(int setSize);
	size_t capacity();
	void shrink();
	int cardinality(trit value);
	std::map< trit, int > cardinality();
	trit get_value(int index);
	void trim(size_t lastIndex);
	size_t length();
	size_t get_sizeInTrit();
	class reference
	{
		friend class tritset;
	public:
		tritset& set;
		int index;
		reference(tritset* set, int index);
		reference& operator= (trit x);
		bool operator==(const trit& a);
	};
	reference operator [](int index);
private:
	void set_value(trit a, int index);
	uint trit_to_uint(trit a);
	trit uint_to_trit(uint a);
	std::vector<uint> array;
	size_t sizeInTrit;
	size_t allocSize;
	size_t new_size(int arrayIndex);
};

tritset operator ! (tritset a);
tritset operator | (tritset a, tritset b);
tritset operator & (tritset a, tritset b);

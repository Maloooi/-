#include "tritset.h"
#include <unordered_map>

typedef unsigned int uint;
#define FALSE 1
#define UNKNOWN 0
#define TRUE 3

tritset::tritset(int setSize)
{
	array.assign(ceil((double)(setSize)/(4*sizeof(uint))),0);
	sizeInTrit = setSize;
	allocSize = array.size();
}

size_t tritset::capacity()
{
	return array.capacity() * sizeof(uint) * 4;
}

void tritset::shrink()
{
	size_t shrinkSize = allocSize;
	for(size_t i = array.size()-1; i >= 0; i--)
	{
		if(array[i] > 0)
		{
			shrinkSize = i+1;
			break;
		}
	}
	array.resize(shrinkSize);
	array.shrink_to_fit();
	sizeInTrit = new_size(shrinkSize-1);
}


int tritset::cardinality(trit value)
{
	size_t numTrit = 0;
	int cardinality = 0;
	for(size_t i = 0; i < sizeInTrit; i++)
	{
		if (get_value(i) == value)
			cardinality++;
	}
	return cardinality;
}

std::map<trit, int> tritset::cardinality()
{
	std::map<trit, int> tritCardinality;
	tritCardinality[trit::False] = cardinality(trit::False);
	tritCardinality[trit::Unknown] = cardinality(trit::Unknown);
	tritCardinality[trit::True] = cardinality(trit::True);
	return tritCardinality;
}

trit tritset::get_value(int index)
{
	size_t arrayIndex = index / (4*sizeof(uint));
	size_t tritIndex = index - arrayIndex * sizeof(uint)* 4;
	uint tritBlock = array[arrayIndex];
	tritBlock >>= (2*tritIndex);
	uint a = 3;
	tritBlock = tritBlock & a;
	return tritset::uint_to_trit(tritBlock);
}

void tritset::set_value(trit a, int index)
{
	size_t arrayIndex = index / (4 * sizeof(uint));
	size_t tritIndex = index - arrayIndex * sizeof(uint) * 4;
	uint aTrit = trit_to_uint(a);
	uint cleanTrit = TRUE;
	uint newTritBlock = array[arrayIndex];
	aTrit = aTrit << (2 * tritIndex);
	cleanTrit = cleanTrit << (2 * tritIndex);
	cleanTrit = ~cleanTrit;
	newTritBlock = newTritBlock & cleanTrit;
	array[arrayIndex] = newTritBlock | aTrit;
}

void tritset::trim(size_t lastIndex)
{
	for (size_t i = lastIndex; i < sizeInTrit; i++)
	{
		set_value(trit::Unknown, i);
	}
	shrink();
}

size_t tritset::length()
{
	int index = 0;
	for (size_t i = array.size() - 1; i > 0; i--)
	{
		if(array[i]>0)
		{
			index = i;
			break;
		}
	}
	for (int i = 0; i < sizeof(uint)*4; i++)
	{
		if(get_value(index*sizeof(uint)*4+ i) == trit::Unknown)
		{
			return index * sizeof(uint) * 4 + i+1;
		}
	}
	return (index+1) * sizeof(uint) * 4;
}

size_t tritset::get_sizeInTrit()
{
	return sizeInTrit;
}

uint tritset::trit_to_uint(trit a)
{
	if (a == trit::True) return TRUE;
	else if (a == trit::False) return FALSE;
	else return UNKNOWN;
}
trit tritset::uint_to_trit(uint a)
{
	if (a == TRUE) return trit::True;
	else if (a == FALSE) return trit::False;
	else return trit::Unknown;
}

size_t tritset::new_size(int arrayIndex)
{
	for(int i = sizeof(uint) * 4; i > 0;i++)
	{
		if (get_value(arrayIndex * sizeof(uint) * 4+1) == trit::Unknown)
		{
			return arrayIndex * sizeof(uint) * 4 + 1;
		}
	}
}

tritset operator !(tritset a)
{
	tritset set(a.get_sizeInTrit());
	for(size_t i = 0; i < set.get_sizeInTrit();i++)
	{
		set[i] = !a.get_value(i);
	}
	return set;
}

tritset operator|(tritset a, tritset b)
{
	size_t biggerSize, smallerSize;
	bool aFlag;
	if (a.get_sizeInTrit() > b.get_sizeInTrit()) {
		biggerSize = a.get_sizeInTrit();
		smallerSize = b.get_sizeInTrit();
		aFlag = false;
	}
	else {
		biggerSize = b.get_sizeInTrit();
		smallerSize = a.get_sizeInTrit();
		aFlag = true;
	}
	tritset set(biggerSize);
	for (size_t i = 0 ; i < set.get_sizeInTrit(); i++)
	{
		if (i+1 > smallerSize)
		{
			set[i] = (aFlag == 1 ? b.get_value(i) | trit::Unknown : a.get_value(i) | trit::Unknown);
			continue;
		}
		set[i] = a.get_value(i) | b.get_value(i);
	}
	return set;
}

tritset operator&(tritset a, tritset b)
{
	size_t biggerSize, smallerSize;
	bool aFlag;
	if (a.get_sizeInTrit() > b.get_sizeInTrit()) {
		biggerSize = a.get_sizeInTrit();
		smallerSize = b.get_sizeInTrit();
		aFlag = false;
	}
	else {
		biggerSize = b.get_sizeInTrit();
		smallerSize = a.get_sizeInTrit();
		aFlag = true;
	}
	tritset set(biggerSize);
	for (size_t i = 0; i < set.get_sizeInTrit(); i++)
	{
		if (i > smallerSize)
		{
			set[i] = (aFlag == 1 ? a.get_value(i) & trit::Unknown : b.get_value(i) & trit::Unknown);
			continue;
		}
		set[i] = a.get_value(i) & b.get_value(i);
	}
	return set;
}

tritset::reference::reference(tritset* set, int index) : set(*set), index(index)
{
}

tritset::reference tritset::operator[] (int index) {
	return reference(this, index);
}

tritset::reference& tritset::reference::operator=(trit val) {
	set.set_value(val, index);
	return *this;
}

bool tritset::reference::operator==(const trit& a)
{
	return set.get_value(index) == a;
}



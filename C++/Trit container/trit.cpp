#include "trit.h"

std::ostream& operator<<(std::ostream& stream, trit a)
{
	if (a == trit::True) return stream << "True";
	else if (a == trit::False) return stream << "False";
	else return stream << "Unknown";
}


trit operator! (trit a)
{
	if (a == trit::True) return trit::False;
	else if (a == trit::False) return trit::True;
	else return trit::Unknown;
}

trit operator | (trit a, trit b)
{
	if (a == trit::True) return trit::True;
	else if (a == trit::False)
	{
		if (b == trit::True) return trit::True;
		else if (b == trit::False) return trit::False;
		else return trit::Unknown;
	}
	else
	{
		if (b == trit::True) return trit::True;
		else return trit::Unknown;
	}
}

trit operator & (trit a, trit b)
{
	if (a==trit::True)
	{
		if (b == trit::True) return trit::True;
		else if (b == trit::False) return trit::False;
		else return trit::Unknown;
	}
	else if (a == trit::False) return trit::False;
	else
	{
		if (b == trit::False) return trit::False;
		else return trit::Unknown;
	}
}






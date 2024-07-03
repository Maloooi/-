#pragma once
#include <iostream>

enum class trit{False,Unknown,True};

std::ostream& operator << (std::ostream& stream, trit a);
trit operator ! (trit a);
trit operator | (trit a, trit b);
trit operator & (trit a, trit b);



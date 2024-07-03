#include <iostream>
#include "tritset.h"
#include "gtest/gtest.h"
typedef unsigned int uint;

int main(int argc, char* argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();

}


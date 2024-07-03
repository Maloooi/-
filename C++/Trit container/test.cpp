#include <iostream>
#include "tritset.h"
#include "gtest/gtest.h"

TEST(MemoryTest, ConstructorTest) {
    for (int i = 1; i <= 100; ++i) {
        tritset set(i);
        size_t allocLength = set.capacity();
        EXPECT_GE(allocLength, ceil((double)(i) / (4 * sizeof(uint))) * sizeof(uint) * 4);
    }
}

TEST(MemoryTest, UnknownTrit) {
    tritset set(6);
    set[0] = trit::True;
    EXPECT_TRUE(set[5] == trit::Unknown);
}

TEST(MemoryTest, TritValueMemory) {
    tritset set(6);
    set[0] = trit::True;
    set[1] = trit::Unknown;
    set[2] = trit::False;
    set[3] = trit::True;
    set[4] = trit::Unknown;
    set[5] = trit::False;

    EXPECT_TRUE(set[0] == trit::True);
    EXPECT_TRUE(set[1] == trit::Unknown);
    EXPECT_TRUE(set[2] == trit::False);
    EXPECT_TRUE(set[3] == trit::True);
    EXPECT_TRUE(set[4] == trit::Unknown);
    EXPECT_TRUE(set[5] == trit::False);
}

TEST(MemoryTest, ShrinkTest) {
    tritset set(30);
    set[15] = trit::False;
    set.shrink();
    EXPECT_EQ(set.capacity(), sizeof(unsigned int) * 4);
}

TEST(OperationTest, OrTest)
{
    tritset setA(5);
    tritset setB(5);

    setA[0] = trit::Unknown;
    setA[1] = trit::Unknown;
    setA[2] = trit::Unknown;
    setA[3] = trit::True;
    setA[4] = trit::False;

    setB[0] = trit::True;
    setB[1] = trit::False;
    setB[2] = trit::Unknown;
    setB[3] = trit::False;
    setB[4] = trit::True;

    tritset setC = setA | setB;

    EXPECT_TRUE(setC[0] == trit::True);
    EXPECT_TRUE(setC[1] == trit::Unknown);
    EXPECT_TRUE(setC[2] == trit::Unknown);
    EXPECT_TRUE(setC[3] == trit::True);
    EXPECT_TRUE(setC[4] == trit::True);
}

TEST(OperationTest, AndTest)
{
    tritset setA(5);
    tritset setB(5);

    setA[0] = trit::Unknown;
    setA[1] = trit::Unknown;
    setA[2] = trit::Unknown;
    setA[3] = trit::True;
    setA[4] = trit::False;

    setB[0] = trit::True;
    setB[1] = trit::False;
    setB[2] = trit::Unknown;
    setB[3] = trit::False;
    setB[4] = trit::True;

    tritset setC = setA & setB;

    EXPECT_TRUE(setC[0] == trit::Unknown);
    EXPECT_TRUE(setC[1] == trit::False);
    EXPECT_TRUE(setC[2] == trit::Unknown);
    EXPECT_TRUE(setC[3] == trit::False);
    EXPECT_TRUE(setC[4] == trit::False);
}

TEST(OperationTest, NegationTest) {
    tritset setA(3);
    setA[0] = trit::Unknown;
    setA[1] = trit::True;
    setA[2] = trit::False;
    tritset setB = !setA;
    EXPECT_TRUE(setB[0] == trit::Unknown);
    EXPECT_TRUE(setB[1] == trit::False);
    EXPECT_TRUE(setB[2] == trit::True);
}

TEST(MethodTest, CardinalityTest) {
    tritset set(6);
    set[0] = trit::True;
    set[1] = trit::True;
    set[2] = trit::False;
    set[3] = trit::False;
    set[4] = trit::Unknown;
    set[6] = trit::Unknown;
    EXPECT_EQ(set.cardinality(trit::True), 2);
    EXPECT_EQ(set.cardinality(trit::False), 2);
    EXPECT_EQ(set.cardinality(trit::Unknown), 2);
}

TEST(MethodTest, LengthTest)
{
    tritset set(6);
    set[0] = trit::True;
    set[1] = trit::True;
    set[2] = trit::False;
    set[3] = trit::False;
    set[4] = trit::Unknown;
    set[5] = trit::Unknown;

    EXPECT_EQ(set.length(), 5);
}

TEST(MethodTest, TrimTest)
{
    tritset set(40);

    set[6] = trit::False;
    set[39] = trit::True;

    set.trim(8);
    EXPECT_EQ(set.capacity(), sizeof(unsigned int) * 4);
}
#include <gtest/gtest.h>

#include "class1/Student.h"

#include <sstream>

TEST(StudentContructor, ConstructorWithoutParameters_InvalidID1)
{
    Student s;
    std::istringstream input("\nnguyen van a\n18\n2.3\n");
    std::cin.rdbuf(input.rdbuf());

    EXPECT_FALSE(s.inputInfo());
}

TEST(StudentContructor, ConstructorWithoutParameters_InvalidID2)
{
    Student s;
    std::istringstream input("sv123\nnguyen van a\n18\n2.3\n");
    std::cin.rdbuf(input.rdbuf());

    EXPECT_FALSE(s.inputInfo());
}

TEST(StudentContructor, ConstructorWithoutParameters_InvalidID3)
{
    Student s;
    std::istringstream input("nv123456\nnguyen van a\n18\n2.3\n");
    std::cin.rdbuf(input.rdbuf());

    EXPECT_FALSE(s.inputInfo());
}

TEST(StudentContructor, ConstructorWithoutParameters_InvalidID4)
{
    Student s;
    std::istringstream input("SV000000\nnguyen van a\n18\n2.3\n");
    std::cin.rdbuf(input.rdbuf());

    EXPECT_FALSE(s.inputInfo());
}

TEST(StudentContructor, ConstructorWithoutParameters_InvalidName1)
{
    Student s;
    std::istringstream input("SV123000\n\n18\n2.3\n");
    std::cin.rdbuf(input.rdbuf());

    EXPECT_FALSE(s.inputInfo());
}

TEST(StudentContructor, ConstructorWithoutParameters_InvalidName2)
{
    Student s;
    std::istringstream input("SV123000\n12nguyen van a\n18\n2.3\n");
    std::cin.rdbuf(input.rdbuf());

    EXPECT_FALSE(s.inputInfo());
}

TEST(StudentContructor, ConstructorWithoutParameters_InvalidAge1)
{
    Student s;
    std::istringstream input("SV123000\nnguyen van a\n-1\n2.3\n");
    std::cin.rdbuf(input.rdbuf());

    EXPECT_FALSE(s.inputInfo());
}

TEST(StudentContructor, ConstructorWithoutParameters_InvalidAge2)
{
    Student s;
    std::istringstream input("SV123000\nnguyen van a\n99\n2.3\n");
    std::cin.rdbuf(input.rdbuf());

    EXPECT_FALSE(s.inputInfo());
}

TEST(StudentContructor, ConstructorWithoutParameters_InvalidGPA1)
{
    Student s;
    std::istringstream input("SV123000\nnguyen van a\n20\n-1.3\n");
    std::cin.rdbuf(input.rdbuf());

    EXPECT_FALSE(s.inputInfo());
}

TEST(StudentContructor, ConstructorWithoutParameters_InvalidGPA2)
{
    Student s;
    std::istringstream input("SV123000\nnguyen van a\n20\n5.6\n");
    std::cin.rdbuf(input.rdbuf());

    EXPECT_FALSE(s.inputInfo());
}

TEST(StudentContructor, ConstructorWithoutParameters_IncorrectResult)
{
    Student s;
    std::istringstream input("SV123000\nnguyen van a\n20\n2.3\n");
    std::cin.rdbuf(input.rdbuf());

    EXPECT_TRUE(s.inputInfo());
    EXPECT_EQ(s.getID(), "SV123000");
    EXPECT_NE(s.getName(), "nguyen van a");
    EXPECT_EQ(s.getAge(), 20);
    EXPECT_FLOAT_EQ(s.getGPA(), 2.3);
}

TEST(StudentContructor, ConstructorWithoutParameters_CorrectResult)
{
    Student s;
    std::istringstream input("SV123000\nnguyen van a\n20\n2.3\n");
    std::cin.rdbuf(input.rdbuf());

    EXPECT_TRUE(s.inputInfo());
    EXPECT_EQ(s.getID(), "SV123000");
    EXPECT_EQ(s.getName(), "Nguyen Van A");
    EXPECT_EQ(s.getAge(), 20);
    EXPECT_FLOAT_EQ(s.getGPA(), 2.3);
}

TEST(StudentContructor, ConstructorWithParameters_IncorrectResult)
{
    Student s("SV123000", "nguyen van a", 18, 2.3);
    EXPECT_EQ(s.getID(), "SV123000");
    EXPECT_NE(s.getName(), "nguyen van a");
    EXPECT_EQ(s.getAge(), 18);
    EXPECT_FLOAT_EQ(s.getGPA(), 2.3);
}

TEST(StudentContructor, ConstructorWithParameters_CorrectResult)
{
    Student s("SV123000", "nguyen van a", 18, 2.3);
    EXPECT_EQ(s.getID(), "SV123000");
    EXPECT_EQ(s.getName(), "Nguyen Van A");
    EXPECT_EQ(s.getAge(), 18);
    EXPECT_FLOAT_EQ(s.getGPA(), 2.3);
}

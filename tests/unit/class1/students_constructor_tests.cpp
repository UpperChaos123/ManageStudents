#include "class1/Student.h"

TEST(StudentContructor, ConstructorWithoutParameters_InvalidID1)
{
    Student s;
    istringstream input("\nnguyen van a\n18\n2.3\n");
    cin.rdbuf(input.rdbuf());

    EXPECT_FALSE(s.inputInfo());
}

TEST(StudentContructor, ConstructorWithoutParameters_InvalidID2)
{
    Student s;
    istringstream input("sv123\nnguyen van a\n18\n2.3\n");
    cin.rdbuf(input.rdbuf());

    EXPECT_FALSE(s.inputInfo());
}

TEST(StudentContructor, ConstructorWithoutParameters_InvalidID3)
{
    Student s;
    istringstream input("nv123456\nnguyen van a\n18\n2.3\n");
    cin.rdbuf(input.rdbuf());

    EXPECT_FALSE(s.inputInfo());
}

TEST(StudentContructor, ConstructorWithoutParameters_InvalidID4)
{
    Student s;
    istringstream input("SV000000\nnguyen van a\n18\n2.3\n");
    cin.rdbuf(input.rdbuf());

    EXPECT_FALSE(s.inputInfo());
}

TEST(StudentContructor, ConstructorWithoutParameters_InvalidName1)
{
    Student s;
    istringstream input("SV123000\n\n18\n2.3\n");
    cin.rdbuf(input.rdbuf());

    EXPECT_FALSE(s.inputInfo());
}

TEST(StudentContructor, ConstructorWithoutParameters_InvalidName2)
{
    Student s;
    istringstream input("SV123000\n12nguyen van1\n18\n2.3\n");
    cin.rdbuf(input.rdbuf());

    EXPECT_FALSE(s.inputInfo());
}

TEST(StudentContructor, ConstructorWithoutParameters_InvalidAge1)
{
    Student s;
    istringstream input("SV123000\nnguyen van a\n-1\n2.3\n");
    cin.rdbuf(input.rdbuf());

    EXPECT_FALSE(s.inputInfo());
}

TEST(StudentContructor, ConstructorWithoutParameters_InvalidAge2)
{
    Student s;
    istringstream input("SV123000\nnguyen van a\n99\n2.3\n");
    cin.rdbuf(input.rdbuf());

    EXPECT_FALSE(s.inputInfo());
}

TEST(StudentContructor, ConstructorWithoutParameters_InvalidGPA1)
{
    Student s;
    istringstream input("SV123000\nnguyen van a\n18\n-1.3\n");
    cin.rdbuf(input.rdbuf());

    EXPECT_FALSE(s.inputInfo());
}

TEST(StudentContructor, ConstructorWithoutParameters_InvalidGPA2)
{
    Student s;
    istringstream input("SV123000\nnguyen van a\n18\n5.6\n");
    cin.rdbuf(input.rdbuf());

    EXPECT_FALSE(s.inputInfo());
}

TEST(StudentContructor, ConstructorWithoutParameters_IncorrectResult1)
{
    Student s;
    istringstream input("SV123000\n12nguyen van1\n18\n2.3\n");
    cin.rdbuf(input.rdbuf());

    EXPECT_FALSE(s.inputInfo());
    EXPECT_EQ(s.getID(), "INVALID");
    EXPECT_EQ(s.getName(), "INVALID");
    EXPECT_EQ(s.getAge(), -1);
    EXPECT_FLOAT_EQ(s.getGPA(), -1);
}

TEST(StudentContructor, ConstructorWithoutParameters_IncorrectResult2)
{
    Student s;
    istringstream input("SV123000\nnguyen van a\n18\n2.3\n");
    cin.rdbuf(input.rdbuf());

    EXPECT_TRUE(s.inputInfo());
    EXPECT_EQ(s.getID(), "SV123000");
    EXPECT_NE(s.getName(), "nguyen van a");
    EXPECT_EQ(s.getAge(), 18);
    EXPECT_FLOAT_EQ(s.getGPA(), 2.3);
}

TEST(StudentContructor, ConstructorWithoutParameters_CorrectResult)
{
    Student s;
    istringstream input("SV123000\nnguyen van a\n18\n2.3\n");
    cin.rdbuf(input.rdbuf());

    EXPECT_TRUE(s.inputInfo());
    EXPECT_EQ(s.getID(), "SV123000");
    EXPECT_EQ(s.getName(), "Nguyen Van A");
    EXPECT_EQ(s.getAge(), 18);
    EXPECT_FLOAT_EQ(s.getGPA(), 2.3);
}

TEST(StudentContructor, ConstructorWithParameters_IncorrectResult1)
{
    Student s("SV123000", "12nguyen van1", 18, 2.3);
    EXPECT_EQ(s.getID(), "INVALID");
    EXPECT_EQ(s.getName(), "INVALID");
    EXPECT_EQ(s.getAge(), -1);
    EXPECT_FLOAT_EQ(s.getGPA(), -1);
}

TEST(StudentContructor, ConstructorWithParameters_IncorrectResult2)
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

#include "class1/Student.h"

TEST(StudentContructor, ConstructorWithoutParameters_InvalidID1)
{
    Student st;
    std::istringstream input("\nnguyen van a\n18\n2.3\n");
    std::cin.rdbuf(input.rdbuf());

    EXPECT_FALSE(st.inputInfo());
}

TEST(StudentContructor, ConstructorWithoutParameters_InvalidID2)
{
    Student st;
    std::istringstream input("sv123\nnguyen van a\n18\n2.3\n");
    std::cin.rdbuf(input.rdbuf());

    EXPECT_FALSE(st.inputInfo());
}

TEST(StudentContructor, ConstructorWithoutParameters_InvalidID3)
{
    Student st;
    std::istringstream input("nv123456\nnguyen van a\n18\n2.3\n");
    std::cin.rdbuf(input.rdbuf());

    EXPECT_FALSE(st.inputInfo());
}

TEST(StudentContructor, ConstructorWithoutParameters_InvalidID4)
{
    Student st;
    std::istringstream input("SV000000\nnguyen van a\n18\n2.3\n");
    std::cin.rdbuf(input.rdbuf());

    EXPECT_FALSE(st.inputInfo());
}

TEST(StudentContructor, ConstructorWithoutParameters_InvalidName1)
{
    Student st;
    std::istringstream input("SV123000\n\n18\n2.3\n");
    std::cin.rdbuf(input.rdbuf());

    EXPECT_FALSE(st.inputInfo());
}

TEST(StudentContructor, ConstructorWithoutParameters_InvalidName2)
{
    Student st;
    std::istringstream input("SV123000\n12nguyen van1\n18\n2.3\n");
    std::cin.rdbuf(input.rdbuf());

    EXPECT_FALSE(st.inputInfo());
}

TEST(StudentContructor, ConstructorWithoutParameters_InvalidAge1)
{
    Student st;
    std::istringstream input("SV123000\nnguyen van a\n-1\n2.3\n");
    std::cin.rdbuf(input.rdbuf());

    EXPECT_FALSE(st.inputInfo());
}

TEST(StudentContructor, ConstructorWithoutParameters_InvalidAge2)
{
    Student st;
    std::istringstream input("SV123000\nnguyen van a\n99\n2.3\n");
    std::cin.rdbuf(input.rdbuf());

    EXPECT_FALSE(st.inputInfo());
}

TEST(StudentContructor, ConstructorWithoutParameters_InvalidGPA1)
{
    Student st;
    std::istringstream input("SV123000\nnguyen van a\n18\n-1.3\n");
    std::cin.rdbuf(input.rdbuf());

    EXPECT_FALSE(st.inputInfo());
}

TEST(StudentContructor, ConstructorWithoutParameters_InvalidGPA2)
{
    Student st;
    std::istringstream input("SV123000\nnguyen van a\n18\n5.6\n");
    std::cin.rdbuf(input.rdbuf());

    EXPECT_FALSE(st.inputInfo());
}

TEST(StudentContructor, ConstructorWithoutParameters_IncorrectResult1)
{
    Student st;
    std::istringstream input("SV123000\n12nguyen van1\n18\n2.3\n");
    std::cin.rdbuf(input.rdbuf());

    EXPECT_FALSE(st.inputInfo());
    EXPECT_EQ(st.getID(), "INVALID");
    EXPECT_EQ(st.getName(), "INVALID");
    EXPECT_EQ(st.getAge(), -1);
    EXPECT_FLOAT_EQ(st.getGPA(), -1.0);
}

TEST(StudentContructor, ConstructorWithoutParameters_IncorrectResult2)
{
    Student st;
    std::istringstream input("SV123000\nnguyen van a\n18\n2.3\n");
    std::cin.rdbuf(input.rdbuf());

    EXPECT_TRUE(st.inputInfo());
    EXPECT_NE(st.getName(), "nguyen van a");
}

TEST(StudentContructor, ConstructorWithoutParameters_CorrectResult)
{
    Student st;
    std::istringstream input("SV123000\nnguyen van a\n18\n2.3\n");
    std::cin.rdbuf(input.rdbuf());

    EXPECT_TRUE(st.inputInfo());
    EXPECT_EQ(st.getID(), "SV123000");
    EXPECT_EQ(st.getName(), "Nguyen Van A");
    EXPECT_EQ(st.getAge(), 18);
    EXPECT_FLOAT_EQ(st.getGPA(), 2.3);
}

TEST(StudentContructor, ConstructorWithParameters_IncorrectResult1)
{
    Student st("SV123000", "12nguyen van1", 18, 2.3);
    EXPECT_EQ(st.getID(), "INVALID");
    EXPECT_EQ(st.getName(), "INVALID");
    EXPECT_EQ(st.getAge(), -1);
    EXPECT_FLOAT_EQ(st.getGPA(), -1.0);
}

TEST(StudentContructor, ConstructorWithParameters_IncorrectResult2)
{
    Student st("SV123000", "nguyen van a", 18, 2.3);
    EXPECT_NE(st.getName(), "nguyen van a");
}

TEST(StudentContructor, ConstructorWithParameters_CorrectResult)
{
    Student st("SV123000", "nguyen van a", 18, 2.3);
    EXPECT_EQ(st.getID(), "SV123000");
    EXPECT_EQ(st.getName(), "Nguyen Van A");
    EXPECT_EQ(st.getAge(), 18);
    EXPECT_FLOAT_EQ(st.getGPA(), 2.3);
}

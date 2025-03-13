#include "class1/Student.h"

TEST(StudentFunction, OutputInfo_IncorrectResult1)
{
    Student s;
    istringstream input("SV123000\nnguyen van a\n18\n2.3\n");
    cin.rdbuf(input.rdbuf());

    EXPECT_TRUE(s.inputInfo());

    std::ostringstream output;
    std::streambuf *oldCout = std::cout.rdbuf(output.rdbuf());

    s.outputInfo();

    std::cout.rdbuf(oldCout);

    string expectOutput =
        "Ma sinh vien: SV123000\n"
        "Ten sinh vien: nguyen van a\n"
        "Tuoi: 18\n"
        "Diem trung binh: 2.3\n";

    EXPECT_NE(output.str(), expectOutput);
}

TEST(StudentFunction, OutputInfo_CorrectResult1)
{
    Student s;
    istringstream input("SV123000\nnguyen van a\n18\n2.3\n");
    cin.rdbuf(input.rdbuf());

    EXPECT_TRUE(s.inputInfo());

    std::ostringstream output;
    std::streambuf *oldCout = std::cout.rdbuf(output.rdbuf());

    s.outputInfo();

    std::cout.rdbuf(oldCout);

    string expectOutput =
        "Ma sinh vien: SV123000\n"
        "Ten sinh vien: Nguyen Van A\n"
        "Tuoi: 18\n"
        "Diem trung binh: 2.3\n";

    EXPECT_EQ(output.str(), expectOutput);
}

TEST(StudentFunction, OutputInfo_IncorrectResult2)
{
    Student s("SV123000", "nguyen van a", 18, 2.3);

    std::ostringstream output;
    std::streambuf *oldCout = std::cout.rdbuf(output.rdbuf());

    s.outputInfo();

    std::cout.rdbuf(oldCout);

    string expectOutput =
        "Ma sinh vien: SV123000\n"
        "Ten sinh vien: nguyen van a\n"
        "Tuoi: 18\n"
        "Diem trung binh: 2.3\n";

    EXPECT_NE(output.str(), expectOutput);
}

TEST(StudentFunction, OutputInfo_CorrectResult2)
{
    Student s("SV123000", "nguyen van a", 18, 2.3);

    std::ostringstream output;
    std::streambuf *oldCout = std::cout.rdbuf(output.rdbuf());

    s.outputInfo();

    std::cout.rdbuf(oldCout);

    string expectOutput =
        "Ma sinh vien: SV123000\n"
        "Ten sinh vien: Nguyen Van A\n"
        "Tuoi: 18\n"
        "Diem trung binh: 2.3\n";

    EXPECT_EQ(output.str(), expectOutput);
}

TEST(StudentFunction, updateGPA_InvalidData1)
{
    Student s;
    istringstream input("SV123000\nnguyen van a\n18\n2.3\n");
    cin.rdbuf(input.rdbuf());

    EXPECT_FALSE(s.updateGPA(-1.4));
}

TEST(StudentFunction, updateGPA_InvalidData2)
{
    Student s;
    istringstream input("SV123000\nnguyen van a\n18\n2.3\n");
    cin.rdbuf(input.rdbuf());

    EXPECT_FALSE(s.updateGPA(5.6));
}

TEST(StudentFunction, updateGPA_ValidData1)
{
    Student s;
    istringstream input("SV123000\nnguyen van a\n18\n2.3\n");
    cin.rdbuf(input.rdbuf());

    EXPECT_TRUE(s.updateGPA(2.3));
    EXPECT_FLOAT_EQ(s.getGPA(), 2.3);
}

TEST(StudentFunction, updateGPA_InvalidData3)
{
    Student s("SV123000", "nguyen van a", 18, 2.3);

    EXPECT_FALSE(s.updateGPA(-1.4));
}

TEST(StudentFunction, updateGPA_InvalidData4)
{
    Student s("SV123000", "nguyen van a", 18, 2.3);

    EXPECT_FALSE(s.updateGPA(6.7));
}

TEST(StudentFunction, updateGPA_ValidData2)
{
    Student s("SV123000", "nguyen van a", 18, 2.3);

    EXPECT_TRUE(s.updateGPA(3.4));
    EXPECT_FLOAT_EQ(s.getGPA(), 3.4);
}

#include "class1/Student.h"

TEST(StudentFunction, OutputInfo_IncorrectResult1)
{
    Student st;
    std::istringstream input("SV123000\nnguyen van a\n18\n2.3\n");
    std::cin.rdbuf(input.rdbuf());

    EXPECT_TRUE(st.inputInfo());

    std::ostringstream output;
    std::streambuf *oldCout = std::cout.rdbuf(output.rdbuf());

    st.outputInfo();

    std::cout.rdbuf(oldCout);

    std::string expectOutput =
        "Ma sinh vien: SV123000\n"
        "Ten sinh vien: nguyen van a\n"
        "Tuoi: 18\n"
        "Diem trung binh: 2.3\n";

    EXPECT_NE(output.str(), expectOutput);
}

TEST(StudentFunction, OutputInfo_IncorrectResult2)
{
    Student st("SV123000", "nguyen van a", 18, 2.3);

    std::ostringstream output;
    std::streambuf *oldCout = std::cout.rdbuf(output.rdbuf());

    st.outputInfo();

    std::cout.rdbuf(oldCout);

    std::string expectOutput =
        "Ma sinh vien: SV123000\n"
        "Ten sinh vien: nguyen van a\n"
        "Tuoi: 18\n"
        "Diem trung binh: 2.3\n";

    EXPECT_NE(output.str(), expectOutput);
}

TEST(StudentFunction, OutputInfo_CorrectResult1)
{
    Student st;
    std::istringstream input("SV123000\nnguyen van a\n18\n2.3\n");
    std::cin.rdbuf(input.rdbuf());

    EXPECT_TRUE(st.inputInfo());

    std::ostringstream output;
    std::streambuf *oldCout = std::cout.rdbuf(output.rdbuf());

    st.outputInfo();

    std::cout.rdbuf(oldCout);

    std::string expectOutput =
        "Ma sinh vien: SV123000\n"
        "Ten sinh vien: Nguyen Van A\n"
        "Tuoi: 18\n"
        "Diem trung binh: 2.3\n";

    EXPECT_EQ(output.str(), expectOutput);
}

TEST(StudentFunction, OutputInfo_CorrectResult2)
{
    Student st("SV123000", "nguyen van a", 18, 2.3);

    std::ostringstream output;
    std::streambuf *oldCout = std::cout.rdbuf(output.rdbuf());

    st.outputInfo();

    std::cout.rdbuf(oldCout);

    std::string expectOutput =
        "Ma sinh vien: SV123000\n"
        "Ten sinh vien: Nguyen Van A\n"
        "Tuoi: 18\n"
        "Diem trung binh: 2.3\n";

    EXPECT_EQ(output.str(), expectOutput);
}

TEST(StudentFunction, updateGPA_InvalidGPA1)
{
    Student st;
    std::istringstream input("SV123000\nnguyen van a\n18\n2.3\n");
    std::cin.rdbuf(input.rdbuf());

    EXPECT_FALSE(st.updateGPA(-1.4));
}

TEST(StudentFunction, updateGPA_InvalidGPA2)
{
    Student st;
    std::istringstream input("SV123000\nnguyen van a\n18\n2.3\n");
    std::cin.rdbuf(input.rdbuf());

    EXPECT_FALSE(st.updateGPA(5.6));
}

TEST(StudentFunction, updateGPA_ValidGPA1)
{
    Student st;
    std::istringstream input("SV123000\nnguyen van a\n18\n2.3\n");
    std::cin.rdbuf(input.rdbuf());

    EXPECT_TRUE(st.updateGPA(2.3));
    EXPECT_FLOAT_EQ(st.getGPA(), 2.3);
}

TEST(StudentFunction, updateGPA_ValidData2)
{
    Student s("SV123000", "nguyen van a", 18, 2.3);

    EXPECT_TRUE(s.updateGPA(3.4));
    EXPECT_FLOAT_EQ(s.getGPA(), 3.4);
}

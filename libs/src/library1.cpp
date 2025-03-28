#include "library1.h"

#include <regex>

bool checkIDOfStudents(const std::string &_ID)
{
    const std::regex pattern(R"(^SV[0-9]{6}$)");

    if (!std::regex_match(_ID, pattern))
    {
        std::cerr << "ID gom 8 ky tu:" << std::endl;
        std::cerr << "- 2 ky tu dau la SV" << std::endl;
        std::cerr << "- 6 ky tu sau bat dau tu 000001 den 999999" << std::endl;

        return false;
    }

    return true;
}

bool checkNameOfStudents(const std::string &_name)
{
    const std::regex pattern(R"(^[A-Za-z ]+$)");

    if (!std::regex_match(_name, pattern))
    {
        std::cerr << "Ten sinh vien chi chua chu cai va khoang trang" << std::endl;
        return false;
    }

    return true;
}

bool checkEmailOfStudents(const std::string &_email)
{
    const std::regex pattern(R"(^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$)");

    if (!std::regex_match(_email, pattern))
    {
        std::cerr << "Email khong dung dinh dang" << std::endl;
        return false;
    }

    return true;
}

int checkNumberInput(int &number)
{
    while (!(std::cin >> number))
    {
        std::cerr << "Vui long nhap so nguyen: ";
        std::cin.clear();
        std::cin.ignore(1000, '\n');
    }

    return number;
}

float checkNumberInput(float &number)
{
    while (!(std::cin >> number))
    {
        std::cerr << "Vui long nhap so thuc: ";
        std::cin.clear();
        std::cin.ignore(1000, '\n');
    }

    return number;
}
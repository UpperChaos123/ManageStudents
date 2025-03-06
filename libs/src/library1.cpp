#include "library1.h"

#include <iostream>
#include <sstream>
#include <cctype>

float convertStringToNumber(std::string str)
{
    std::stringstream ss;
    ss << str;
    float x = 0;
    ss >> x;
    return x;
}

bool checkIDOfStudents(std::string ID)
{
    if (ID.empty())
    {
        std::cout << "Ma sinh vien khong duoc de trong" << std::endl;
        return false;
    }

    if (ID.length() != 8)
    {
        std::cout << "Ma sinh vien phai co dung 8 ky tu" << std::endl;
        return false;
    }

    if (ID.substr(0, 2) != "SV")
    {
        std::cout << "Ma sinh vien phai bat dau bang SV" << std::endl;
        return false;
    }

    std::string str = ID.substr(2);
    if (convertStringToNumber(str) < 1 || convertStringToNumber(str) > 999999)
    {
        std::cout << "So thu tu cua ma sinh vien phai bat dau tu 000001 den 999999" << std::endl;
        return false;
    }

    return true;
}

bool checkNameOfStudents(std::string name)
{
    if (name.empty())
    {
        std::cout << "Ten sinh vien khong duoc de trong" << std::endl;
        return false;
    }

    for (auto &x : name)
    {
        if (!(isalpha(x) || x == ' '))
        {
            std::cout << "Ten sinh vien chi chua chu cai va khoang trang" << std::endl;
            return false;
        }
    }

    return true;
}
#include "library1.h"

float convertStringToNumber(string str)
{
    std::stringstream ss;
    ss << str;
    float x = 0;
    ss >> x;
    return x;
}

bool checkIDOfStudents(string _ID)
{
    if (_ID.empty())
    {
        cout << "Ma sinh vien khong duoc de trong" << endl;
        return false;
    }

    if (_ID.length() != 8)
    {
        cout << "Ma sinh vien phai co dung 8 ky tu" << endl;
        return false;
    }

    if (_ID.substr(0, 2) != "SV")
    {
        cout << "Ma sinh vien phai bat dau bang SV" << endl;
        return false;
    }

    string str = _ID.substr(2);
    if (convertStringToNumber(str) < 1 || convertStringToNumber(str) > 999999)
    {
        cout << "So thu tu cua ma sinh vien phai bat dau tu 000001 den 999999" << endl;
        return false;
    }

    return true;
}

bool checkNameOfStudents(string _name)
{
    if (_name.empty())
    {
        cout << "Ten sinh vien khong duoc de trong" << endl;
        return false;
    }

    for (auto &x : _name)
    {
        if (!(isalpha(x) || x == ' '))
        {
            cout << "Ten sinh vien chi chua chu cai va khoang trang" << endl;
            return false;
        }
    }

    return true;
}
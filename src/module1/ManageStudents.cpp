#include "module1/ManageStudents.h"
#include "library1.h"

#include <iostream>

void createListOfStudents(std::vector<Student> &students)
{
    std::cout << "---Them sinh vien vao danh sach---" << std::endl;
    Student st;
    bool check = st.inputInfo();

    if (!check)
    {
        std::cout << "Them sinh vien thai bai" << std::endl;
    }
    else
    {
        students.emplace_back(st);
        std::cout << "Them sinh vien thanh cong" << std::endl;
    }

    std::cout << std::endl;
}

void displayListsOfStudents(std::vector<Student> students)
{
    if (students.empty())
    {
        std::cout << "Danh sach trong" << std::endl;
        std::cout << std::endl;
    }
    else
    {
        std::cout << "---Danh sach sinh vien---" << std::endl;
        for (auto &x : students)
        {
            x.outputInfo();
        }
    }
}

int findStudentsByID(std::vector<Student> students)
{
    std::cout << "---Tim kiem sinh vien theo ID---" << std::endl;
    std::cout << "Nhap ID: ";
    std::string ID;
    std::getline(std::cin, ID);

    std::cout << std::endl;

    if (!checkIDOfStudents(ID))
    {
        return -1;
    }

    for (int i = 0; i < students.size(); i++)
    {
        if (students[i].getID() == ID)
        {
            return i;
        }
    }

    return -1;
}

int findStudentsByName(std::vector<Student> students)
{
    std::cout << "---Tim kiem sinh vien theo ten---" << std::endl;
    std::cout << "Nhap ten: ";
    std::string name;
    std::getline(std::cin, name);

    std::cout << std::endl;

    if (!checkNameOfStudents(name))
    {
        return -1;
    }

    for (int i = 0; i < students.size(); i++)
    {
        if (students[i].getName() == name)
        {
            return i;
        }
    }

    return -1;
}

void findStudents(std::vector<Student> students)
{
    std::cout << "---Tim kiem sinh vien theo ID hoac ten---" << std::endl;
    int choose, index = -1;

    do
    {
        std::cout << "1. Theo ID" << std::endl;
        std::cout << "2. Theo ten" << std::endl;
        std::cout << "3. Quay lai" << std::endl;
        std::cout << "Lua chon: ";

        while (!(std::cin >> choose))
        {
            std::cout << "Vui long nhap so nguyen: ";
            std::cin.clear();
            std::cin.ignore(1000, '\n');
        }

        std::cout << std::endl;

        std::cin.ignore();

        switch (choose)
        {
        case 1:
            index = findStudentsByID(students);

            if (index == -1)
            {
                std::cout << "ID khong hop le hoac sinh vien khong co trong danh sach" << std::endl;
            }
            else
            {
                std::cout << "Sinh vien co ID la " << students[index].getID() << " co trong danh sach" << std::endl;
            }

            std::cout << std::endl;
            return;

        case 2:
            index = findStudentsByName(students);

            if (index == -1)
            {
                std::cout << "Ten khong hop le hoac khong co sinh vien trong danh sach" << std::endl;
            }
            else
            {
                std::cout << "Sinh vien co ten la " << students[index].getName() << " co trong danh sach" << std::endl;
            }

            std::cout << std::endl;
            return;

        case 3:
            return;

        default:
            std::cout << "Khong co lua chon vua nhap. Vui long nhap lai" << std::endl;
        }
    } while (choose != 3);
}

void removeStudentsByID(std::vector<Student> &students)
{
    int index = findStudentsByID(students);

    if (index == -1)
    {
        std::cout << "ID khong hop le hoac sinh vien khong co trong danh sach" << std::endl;
    }
    else
    {
        students.erase(students.begin() + index);
        std::cout << "Xoa sinh vien khoi danh sach thanh cong" << std::endl;
    }

    std::cout << std::endl;
}

void updateGPAOfStudents(std::vector<Student> &students)
{
    int index = findStudentsByID(students);

    if (index == -1)
    {
        std::cout << "ID khong hop le hoac sinh vien khong co trong danh sach" << std::endl;
    }
    else
    {
        float newGPA;
        std::cout << "Nhap diem moi: ";

        while (!(std::cin >> newGPA))
        {
            std::cout << "Vui long nhap so thuc: " << std::endl;
            std::cin.clear();
            std::cin.ignore(1000, '\n');
        }

        std::cout << std::endl;

        bool check = students[index].updateGPA(newGPA);
        if (!check)
        {
            std::cout << "Cap nhat diem that bai" << std::endl;
        }
        else
        {
            std::cout << "Cap nhat diem thanh cong" << std::endl;
            std::cout << "Diem trung binh moi cua " << students[index].getName() << " la " << students[index].getGPA() << std::endl;
        }
    }

    std::cout << std::endl;
}
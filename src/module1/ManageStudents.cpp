#include "module1/ManageStudents.h"
#include "library1.h"

void createListOfStudents(vector<Student> &students)
{
    cout << "---Them sinh vien vao danh sach---" << endl;
    Student st;
    bool check = st.inputInfo();

    if (!check)
    {
        cout << "Khong the them sinh vien vi loi du lieu dau vao" << endl;
    }
    else
    {
        students.emplace_back(st);
        cout << "Them sinh vien thanh cong" << endl;
    }

    cout << endl;
}

void displayListsOfStudents(vector<Student> students)
{
    if (students.empty())
    {
        cout << "Danh sach trong" << endl;
        cout << endl;
    }
    else
    {
        cout << "---Danh sach sinh vien---" << endl;

        for (auto &x : students)
        {
            x.outputInfo();
            cout << endl;
        }
    }
}

int findStudentsByID(vector<Student> students)
{
    cout << "---Tim kiem sinh vien theo ID---" << endl;
    cout << "Nhap ID: ";
    string ID;
    std::getline(std::cin, ID);

    cout << endl;

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

int findStudentsByName(vector<Student> students)
{
    cout << "---Tim kiem sinh vien theo ten---" << endl;
    cout << "Nhap ten: ";
    string name;
    std::getline(std::cin, name);

    cout << endl;

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

void findStudents(vector<Student> students)
{
    cout << "---Tim kiem sinh vien theo ID hoac ten---" << endl;
    int choose, index = -1;

    do
    {
        cout << "1. Theo ID" << endl;
        cout << "2. Theo ten" << endl;
        cout << "3. Quay lai" << endl;
        cout << "Lua chon: ";

        while (!(std::cin >> choose))
        {
            cout << "Vui long nhap so nguyen: ";
            std::cin.clear();
            std::cin.ignore(1000, '\n');
        }

        cout << endl;

        std::cin.ignore();

        switch (choose)
        {
        case 1:
            index = findStudentsByID(students);

            if (index == -1)
            {
                cout << "ID khong hop le hoac sinh vien khong co trong danh sach" << endl;
            }
            else
            {
                cout << "Sinh vien co ID la " << students[index].getID() << " co trong danh sach" << endl;
            }

            cout << endl;
            return;

        case 2:
            index = findStudentsByName(students);

            if (index == -1)
            {
                cout << "Ten khong hop le hoac khong co sinh vien trong danh sach" << endl;
            }
            else
            {
                cout << "Sinh vien co ten la " << students[index].getName() << " co trong danh sach" << endl;
            }

            cout << endl;
            return;

        case 3:
            return;

        default:
            cout << "Khong co lua chon vua nhap. Vui long nhap lai" << endl;
        }
    } while (choose != 3);
}

void removeStudentsByID(vector<Student> &students)
{
    int index = findStudentsByID(students);

    if (index == -1)
    {
        cout << "ID khong hop le hoac sinh vien khong co trong danh sach" << endl;
    }
    else
    {
        students.erase(students.begin() + index);
        cout << "Xoa sinh vien khoi danh sach thanh cong" << endl;
    }

    cout << endl;
}

void updateGPAOfStudents(vector<Student> &students)
{
    int index = findStudentsByID(students);

    if (index == -1)
    {
        cout << "ID khong hop le hoac sinh vien khong co trong danh sach" << endl;
    }
    else
    {
        float newGPA;
        cout << "Nhap diem trung binh moi: ";

        while (!(std::cin >> newGPA))
        {
            cout << "Vui long nhap so thuc: " << endl;
            std::cin.clear();
            std::cin.ignore(1000, '\n');
        }

        cout << endl;

        bool check = students[index].updateGPA(newGPA);
        if (!check)
        {
            cout << "Cap nhat diem that bai" << endl;
        }
        else
        {
            cout << "Cap nhat diem thanh cong" << endl;
        }
    }

    cout << endl;
}
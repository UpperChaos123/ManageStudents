#include "module1/ManageStudents.h"

#include <cstddef>

void addStudentsToList(std::vector<std::unique_ptr<Student>> &students)
{
    std::cout << "---Them sinh vien vao danh sach---" << std::endl;

    std::unique_ptr<Student> sv = std::make_unique<Student>();
    bool check = sv->inputInfo();

    if (!check)
    {
        std::cerr << "Khong the them sinh vien vi loi du lieu dau vao" << std::endl;
    }
    else
    {
        for (auto &x : students)
        {
            if (sv->getID() == x->getID())
            {
                std::cerr << "Khong the them sinh vien vi trung ID" << std::endl;
            }
            else
            {
                students.push_back(std::move(sv));
                std::cout << "Them sinh vien thanh cong" << std::endl;
            }
        }
    }

    std::cout << "\n";
}

void displayListOfStudents(const std::vector<std::unique_ptr<Student>> &students)
{
    if (students.empty())
    {
        std::cout << "Danh sach trong" << std::endl;
        std::cout << "\n";
    }
    else
    {
        std::cout << "---Danh sach sinh vien---" << std::endl;

        for (auto &x : students)
        {
            x->outputInfo();
            std::cout << "\n";
        }
    }
}

int findStudentsByID(const std::vector<std::unique_ptr<Student>> &students)
{
    std::cout << "---Tim kiem sinh vien theo ID---" << std::endl;

    std::cout << "Nhap ID: ";
    std::string ID;
    std::getline(std::cin, ID);

    std::cout << "\n";

    if (!checkIDOfStudents(ID))
    {
        return -1;
    }

    for (size_t i = 0; i < students.size(); ++i)
    {
        if (students[i]->getID() == ID)
        {
            return i;
        }
    }

    return -1;
}

void removeStudentsByID(std::vector<std::unique_ptr<Student>> &students)
{
    int index = findStudentsByID(students);

    if (index == -1)
    {
        std::cerr << "ID khong hop le hoac sinh vien khong co trong danh sach" << std::endl;
    }
    else
    {
        students.erase(students.begin() + index);
        std::cout << "Xoa sinh vien thanh cong" << std::endl;
    }

    std::cout << "\n";
}

int findStudentsByName(const std::vector<std::unique_ptr<Student>> &students)
{
    std::cout << "---Tim kiem sinh vien theo ten---" << std::endl;

    std::cout << "Nhap ten sinh vien: ";
    std::string name;
    std::getline(std::cin, name);

    std::cout << "\n";

    if (!checkNameOfStudents(name))
    {
        return -1;
    }

    for (size_t i = 0; i < students.size(); ++i)
    {
        if (students[i]->getName() == name)
        {
            return i;
        }
    }

    return -1;
}

void findStudents(const std::vector<std::unique_ptr<Student>> &students)
{
    int choose, index = -1;

    do
    {
        std::cout << "---Tim kiem sinh vien theo ID hoac ten---" << std::endl;

        std::cout << "1. Theo ID" << std::endl;
        std::cout << "2. Theo ten" << std::endl;
        std::cout << "3. Quay lai" << std::endl;
        std::cout << "Lua chon: ";

        choose = checkNumberInput(choose);

        std::cout << "\n";
        std::cin.ignore();

        switch (choose)
        {
        case 1:
            index = findStudentsByID(students);

            if (index == -1)
            {
                std::cerr << "ID khong hop le hoac sinh vien khong co trong danh sach" << std::endl;
            }
            else
            {
                std::cout << "Sinh vien co ID la " << students[index]->getID() << " co trong danh sach" << std::endl;
            }

            break;

        case 2:
            index = findStudentsByName(students);

            if (index == -1)
            {
                std::cerr << "Ten sinh vien khong hop le hoac khong co sinh vien trong danh sach" << std::endl;
            }
            else
            {
                std::cout << "Sinh vien co ten la " << students[index]->getName() << " co trong danh sach" << std::endl;
            }

            break;

        case 3:
            return;

        default:
            std::cerr << "Khong co lua chon vua nhap. Vui long nhap lai" << std::endl;
        }
    } while (choose != 3);

    std::cout << "\n";
}

void updateGPAOfStudents(std::vector<std::unique_ptr<Student>> &students)
{
    int index = findStudentsByID(students);

    if (index == -1)
    {
        std::cerr << "ID khong hop le hoac sinh vien khong co trong danh sach" << std::endl;
    }
    else
    {
        float newGPA;
        std::cout << "Nhap diem trung binh moi: ";

        newGPA = checkNumberInput(newGPA);

        std::cout << "\n";

        bool check = students[index]->updateGPA(newGPA);
        if (!check)
        {
            std::cerr << "Cap nhat diem that bai" << std::endl;
        }
        else
        {
            std::cout << "Cap nhat diem thanh cong" << std::endl;
        }
    }

    std::cout << "\n";
}

void sortListOfStudents(std::vector<std::unique_ptr<Student>> &students)
{
    int choose, choose1;

    do
    {
        std::cout << "---Sap xep danh sach sinh vien---" << std::endl;

        std::cout << "1. Theo ten sinh vien" << std::endl;
        std::cout << "2. Theo GPA" << std::endl;
        std::cout << "3. Theo ID" << std::endl;
        std::cout << "4. Quay lai" << std::endl;
        std::cout << "Lua chon: ";

        choose = checkNumberInput(choose);

        switch (choose)
        {
        case 1:
            do
            {
                std::cout << "1. Tu A den Z" << std::endl;
                std::cout << "2. Tu Z den A" << std::endl;
                std::cout << "3. Quay lai" << std::endl;
                std::cout << "Lua chon: ";

                choose1 = checkNumberInput(choose1);

                switch (choose1)
                {
                case 1:
                    std::sort(students.begin(), students.end(), [](std::unique_ptr<Student> a, std::unique_ptr<Student> b)
                              {
                        if(a->getName() == b->getName()){
                            return a->getID() < b->getID();
                        }
                        
                        return a->getName() < b->getName(); });

                    displayListOfStudents(students);
                    break;

                case 2:
                    std::sort(students.begin(), students.end(), [](std::unique_ptr<Student> a, std::unique_ptr<Student> b)
                              {
                        if(a->getName() == b->getName()){
                            return a->getID() < b->getID();
                        }
                        
                        return a->getName() > b->getName(); });

                    displayListOfStudents(students);
                    break;

                case 3:
                    break;

                default:
                    std::cerr << "Khong co lua chon vua nhap. Vui long nhap lai" << std::endl;
                }
            } while (choose1 != 3);

            std::cout << "\n";
            break;

        case 2:
            do
            {
                std::cout << "1. Tang dan" << std::endl;
                std::cout << "2. Giam dan" << std::endl;
                std::cout << "3. Quay lai" << std::endl;
                std::cout << "Lua chon: ";

                choose1 = checkNumberInput(choose1);

                switch (choose1)
                {
                case 1:
                    std::sort(students.begin(), students.end(), [](std::unique_ptr<Student> a, std::unique_ptr<Student> b)
                              {
                        if(a->getGPA() == b->getGPA()){
                            return a->getID() < b->getID();
                        }
                        
                        return a->getGPA() < b->getGPA(); });

                    displayListOfStudents(students);
                    break;

                case 2:
                    std::sort(students.begin(), students.end(), [](std::unique_ptr<Student> a, std::unique_ptr<Student> b)
                              {
                        if(a->getGPA() == b->getGPA()){
                            return a->getID() < b->getID();
                        }
                        
                        return a->getGPA() > b->getGPA(); });

                    displayListOfStudents(students);
                    break;

                case 3:
                    break;

                default:
                    std::cerr << "Khong co lua chon vua nhap. Vui long nhap lai" << std::endl;
                    std::cout << "\n";
                }
            } while (choose1 != 3);

            std::cout << "\n";
            break;

        case 3:
            do
            {
                std::cout << "1. Tang dan" << std::endl;
                std::cout << "2. Giam dan" << std::endl;
                std::cout << "3. Quay lai" << std::endl;
                std::cout << "Lua chon: ";

                choose1 = checkNumberInput(choose1);

                switch (choose1)
                {
                case 1:
                    std::sort(students.begin(), students.end(), [](std::unique_ptr<Student> a, std::unique_ptr<Student> b)
                              { return a->getID() < b->getID(); });

                    displayListOfStudents(students);
                    break;

                case 2:
                    std::sort(students.begin(), students.end(), [](std::unique_ptr<Student> a, std::unique_ptr<Student> b)
                              { return a->getID() > b->getID(); });

                    displayListOfStudents(students);
                    break;

                case 3:
                    break;

                default:
                    std::cerr << "Khong co lua chon vua nhap. Vui long nhap lai" << std::endl;
                    std::cout << "\n";
                }
            } while (choose1 != 3);

            std::cout << "\n";
            break;

        default:
            std::cerr << "Khong co lua chon vua nhap. Vui long nhap lai" << std::endl;
            std::cout << "\n";
        }
    } while (choose != 4);
}
#include "module1/ManageStudents.h"

void addStudentsToList(std::vector<std::shared_ptr<Student>> &students,
                       std::unordered_set<std::string> &idSet,
                       std::unordered_set<std::string> &phoneSet,
                       std::unordered_set<std::string> &emailSet)
{
    std::cout << "---Them sinh vien vao danh sach---" << std::endl;

    std::shared_ptr<Student> sv = std::make_shared<Student>();

    if (!sv->inputInfo())
    {
        std::cerr << "Khong the them sinh vien vi loi du lieu dau vao" << std::endl;
        std::cout << "\n";

        return;
    }

    if (idSet.count(sv->getID()))
    {
        std::cerr << "Khong the them sinh vien vi trung ID" << std::endl;
        std::cout << "\n";

        return;
    }

    if (phoneSet.count(sv->getPhone()))
    {
        std::cerr << "Khong the them sinh vien vi trung so dien thoai" << std::endl;
        std::cout << "\n";

        return;
    }

    if (emailSet.count(sv->getEmail()))
    {
        std::cerr << "Khong the them sinh vien vi trung email" << std::endl;
        std::cout << "\n";

        return;
    }

    idSet.insert(sv->getID());
    phoneSet.insert(sv->getPhone());
    emailSet.insert(sv->getEmail());

    students.push_back(sv);

    std::cout << "Them sinh vien thanh cong" << std::endl;
    std::cout << "\n";
}

void displayListOfStudents(const std::vector<std::shared_ptr<Student>> &students)
{
    if (students.empty())
    {
        std::cout << "Danh sach trong" << std::endl;
        std::cout << "\n";
    }
    else
    {
        std::cout << "---Danh sach sinh vien---" << std::endl;

        for (const auto &x : students)
        {
            x->outputInfo();
            std::cout << "\n";
        }
    }
}

void findStudentsByID(const std::vector<std::shared_ptr<Student>> &students)
{
    std::cout << "---Tim kiem sinh vien theo ID---" << std::endl;

    std::cout << "Nhap ID: ";
    std::string ID;
    std::getline(std::cin, ID);

    std::cout << "\n";

    std::vector<std::weak_ptr<Student>> id_students;

    if (ID == "")
    {
        std::cerr << "Khong co ket qua phu hop" << std::endl;
        std::cout << "\n";

        return;
    }

    for (const auto &x : students)
    {
        if (x->getID().find(ID) != std::string::npos)
        {
            id_students.push_back(x);
        }
    }

    if (id_students.empty())
    {
        std::cerr << "Khong co ket qua phu hop" << std::endl;
        std::cout << "\n";
    }
    else
    {
        std::sort(id_students.begin(), id_students.end(), [](std::weak_ptr<Student> &a, std::weak_ptr<Student> &b)
                  {
            auto ptra = a.lock();
            auto ptrb = b.lock();

            return ptra && ptrb && ptra->getID() < ptrb->getID(); });

        for (const auto &x : id_students)
        {
            if (const auto ptr = x.lock())
            {
                ptr->outputInfo();
                std::cout << "\n";
            }
        }
    }
}

void removeStudentsByID(std::vector<std::shared_ptr<Student>> &students)
{
    std::cout << "---Xoa sinh vien theo ID---" << std::endl;

    std::cout << "Nhap ID: ";
    std::string ID;
    std::getline(std::cin, ID);

    std::cout << "\n";

    if (!checkIDOfStudents(ID))
    {
        std::cerr << "ID khong hop le" << std::endl;
    }
    else
    {
        int index = -1;

        for (size_t i = 0; i < students.size(); ++i)
        {
            if (students[i]->getID() == ID)
            {
                index = i;
                break;
            }
        }

        if (index == -1)
        {
            std::cerr << "Khong co sinh vien trong danh sach" << std::endl;
        }
        else
        {
            students.erase(students.begin() + index);
            std::cout << "Xoa sinh vien thanh cong" << std::endl;
        }
    }

    std::cout << "\n";
}

void findStudentsByName(const std::vector<std::shared_ptr<Student>> &students)
{
    std::cout << "---Tim kiem sinh vien theo ten---" << std::endl;

    std::cout << "Nhap ten sinh vien: ";
    std::string name;
    std::getline(std::cin, name);

    std::cout << "\n";

    std::vector<std::weak_ptr<Student>> name_students;

    for (const auto &x : students)
    {
        if (x->getName().find(name) != std::string::npos)
        {
            name_students.push_back(x);
        }
    }

    if (name_students.empty())
    {
        std::cerr << "Khong co ket qua phu hop" << std::endl;
        std::cout << "\n";
    }
    else
    {
        std::sort(name_students.begin(), name_students.end(), [](std::weak_ptr<Student> &a, std::weak_ptr<Student> &b)
                  {
            auto ptra = a.lock();
            auto ptrb = b.lock();

            return ptra && ptrb && ((ptra->getName() == ptrb->getName()) ? (ptra->getID() < ptrb->getID()) : (ptra->getName() < ptrb->getName())); });

        for (const auto &x : name_students)
        {
            if (const auto ptr = x.lock())
            {
                ptr->outputInfo();
                std::cout << "\n";
            }
        }
    }
}

void findStudentsByGPA(const std::vector<std::shared_ptr<Student>> &students)
{
    std::cout << "---Tim kiem sinh vien theo khoang GPA---" << std::endl;

    std::cout << "GPA thap nhat: ";
    float min = checkNumberInput(min);

    std::cout << "GPA cao nhat: ";
    float max = checkNumberInput(max);

    std::cout << "\n";
    std::cin.ignore();

    std::vector<std::weak_ptr<Student>> gpa_students;

    for (auto &x : students)
    {
        if (x->getGPA() >= min && x->getGPA() <= max)
        {
            gpa_students.push_back(x);
        }
    }

    if (gpa_students.empty())
    {
        std::cerr << "Khong co ket qua phu hop" << std::endl;
        std::cout << "\n";
    }
    else
    {
        std::sort(gpa_students.begin(), gpa_students.end(), [](std::weak_ptr<Student> &a, std::weak_ptr<Student> &b)
                  {
            auto ptra = a.lock();
            auto ptrb = b.lock();

            return ptra && ptrb && ((ptra->getGPA() == ptrb->getGPA()) ? (ptra->getID() < ptrb->getID()) : (ptra->getGPA() < ptrb->getGPA())); });

        for (const auto &x : gpa_students)
        {
            if (const auto ptr = x.lock())
            {
                ptr->outputInfo();
                std::cout << "\n";
            }
        }
    }
}

void findStudents(const std::vector<std::shared_ptr<Student>> &students)
{
    int choose;

    do
    {
        std::cout << "---Tim kiem sinh vien---" << std::endl;

        std::cout << "1. Theo ID" << std::endl;
        std::cout << "2. Theo ten sinh vien" << std::endl;
        std::cout << "3. Theo khoang GPA" << std::endl;
        std::cout << "4. Quay lai" << std::endl;
        std::cout << "Lua chon: ";

        choose = checkNumberInput(choose);

        std::cout << "\n";
        std::cin.ignore();

        switch (choose)
        {
        case 1:
            findStudentsByID(students);
            break;

        case 2:
            findStudentsByName(students);
            break;

        case 3:
            findStudentsByGPA(students);
            break;

        case 4:
            return;

        default:
            std::cerr << "Khong co lua chon vua nhap. Vui long nhap lai" << std::endl;
            std::cout << "\n";
        }
    } while (choose != 4);
}

void updateGPAOfStudents(std::vector<std::shared_ptr<Student>> &students)
{
    std::cout << "---Cap nhat diem trung binh cua sinh vien---" << std::endl;

    std::cout << "Nhap ID: ";
    std::string ID;
    std::getline(std::cin, ID);

    std::cout << "\n";

    if (!checkIDOfStudents(ID))
    {
        std::cerr << "ID khong hop le" << std::endl;
    }
    else
    {
        int index = -1;

        for (size_t i = 0; i < students.size(); ++i)
        {
            if (students[i]->getID() == ID)
            {
                index = i;
                break;
            }
        }

        if (index == -1)
        {
            std::cerr << "Khong co sinh vien trong danh sach" << std::endl;
        }
        else
        {
            std::cout << "Nhap diem moi: ";
            float newGPA = checkNumberInput(newGPA);

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
    }

    std::cout << "\n";
}

void sortListOfStudents(std::vector<std::shared_ptr<Student>> &students)
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

        std::cout << "\n";
        std::cin.ignore();

        switch (choose)
        {
        case 1:
            do
            {
                std::cout << "---Sap xep theo ten sinh vien---" << std::endl;

                std::cout << "1. Tu A den Z" << std::endl;
                std::cout << "2. Tu Z den A" << std::endl;
                std::cout << "3. Quay lai" << std::endl;
                std::cout << "Lua chon: ";

                choose1 = checkNumberInput(choose1);

                std::cout << "\n";
                std::cin.ignore();

                switch (choose1)
                {
                case 1:
                    std::sort(students.begin(), students.end(), [](std::shared_ptr<Student> &a, std::shared_ptr<Student> &b)
                              {
                        if(a->getName() == b->getName()){
                            return a->getID() < b->getID();
                        }
                        
                        return a->getName() < b->getName(); });

                    displayListOfStudents(students);
                    break;

                case 2:
                    std::sort(students.begin(), students.end(), [](std::shared_ptr<Student> &a, std::shared_ptr<Student> &b)
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
                    std::cout << "\n";
                }
            } while (choose1 != 3);

            std::cout << "\n";
            break;

        case 2:
            do
            {
                std::cout << "---Sap xep theo GPA---" << std::endl;

                std::cout << "1. Tang dan" << std::endl;
                std::cout << "2. Giam dan" << std::endl;
                std::cout << "3. Quay lai" << std::endl;
                std::cout << "Lua chon: ";

                choose1 = checkNumberInput(choose1);

                std::cout << "\n";
                std::cin.ignore();

                switch (choose1)
                {
                case 1:
                    std::sort(students.begin(), students.end(), [](std::shared_ptr<Student> &a, std::shared_ptr<Student> &b)
                              {
                        if(a->getGPA() == b->getGPA()){
                            return a->getID() < b->getID();
                        }
                        
                        return a->getGPA() < b->getGPA(); });

                    displayListOfStudents(students);
                    break;

                case 2:
                    std::sort(students.begin(), students.end(), [](std::shared_ptr<Student> &a, std::shared_ptr<Student> &b)
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
                std::cout << "---Sap xep theo ID---" << std::endl;

                std::cout << "1. Tang dan" << std::endl;
                std::cout << "2. Giam dan" << std::endl;
                std::cout << "3. Quay lai" << std::endl;
                std::cout << "Lua chon: ";

                choose1 = checkNumberInput(choose1);

                std::cout << "\n";
                std::cin.ignore();

                switch (choose1)
                {
                case 1:
                    std::sort(students.begin(), students.end(), [](std::shared_ptr<Student> &a, std::shared_ptr<Student> &b)
                              { return a->getID() < b->getID(); });

                    displayListOfStudents(students);
                    break;

                case 2:
                    std::sort(students.begin(), students.end(), [](std::shared_ptr<Student> &a, std::shared_ptr<Student> &b)
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

        case 4:
            return;

        default:
            std::cerr << "Khong co lua chon vua nhap. Vui long nhap lai" << std::endl;
            std::cout << "\n";
        }
    } while (choose != 4);
}
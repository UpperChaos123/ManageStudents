#include "app.h"
#include "module1/ManageStudents.h"

void runApp()
{
    int choose;
    std::vector<std::unique_ptr<Student>> students;
    std::unordered_set<std::string> idSet;
    std::unordered_set<std::string> phoneSet;
    std::unordered_set<std::string> emailSet;

    do
    {
        std::cout << "---Chuong trinh quan ly danh sach sinh vien---" << std::endl;

        std::cout << "1. Them sinh vien vao danh sach" << std::endl;
        std::cout << "2. Hien thi danh sach sinh vien" << std::endl;
        std::cout << "3. Xoa sinh vien theo ID" << std::endl;
        std::cout << "4. Tim kiem sinh vien theo ID hoac ten" << std::endl;
        std::cout << "5. Cap nhat diem trung binh cua sinh vien" << std::endl;
        std::cout << "6. Sap xep danh sach sinh vien" << std::endl;
        std::cout << "7. Ket thuc chuong trinh" << std::endl;
        std::cout << "Lua chon: ";

        choose = checkNumberInput(choose);

        std::cout << "\n";
        std::cin.ignore();

        switch (choose)
        {
        case 1:
            addStudentsToList(students, idSet, phoneSet, emailSet);
            break;

        case 2:
            displayListOfStudents(students);
            break;

        case 3:
            removeStudentsByID(students);
            break;

        case 4:
            findStudents(students);
            break;

        case 5:
            updateGPAOfStudents(students);
            break;

        case 6:
            sortListOfStudents(students);
            break;

        case 7:
            return;

        default:
            std::cerr << "Khong co lua chon vua nhap. Yeu cau nhap lai" << std::endl;
            std::cout << "\n";
        }
    } while (choose != 7);
}

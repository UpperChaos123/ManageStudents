#include "app.h"
#include "module1/ManageStudents.h"

void runApp()
{
    int choose;
    vector<Student> students;

    do
    {
        cout << "---Chuong trinh quan ly danh sach sinh vien---" << endl;
        cout << "1. Them sinh vien vao danh sach" << endl;
        cout << "2. Hien thi danh sach sinh vien" << endl;
        cout << "3. Xoa sinh vien theo ID" << endl;
        cout << "4. Tim kiem sinh vien theo ID hoac ten" << endl;
        cout << "5. Cap nhat diem trung binh cua sinh vien" << endl;
        cout << "6. Ket thuc chuong trinh" << endl;
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
            createListOfStudents(students);
            break;

        case 2:
            displayListsOfStudents(students);
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
            return;

        default:
            cout << "Khong co lua chon vua nhap. Yeu cau nhap lai" << endl;
        }
    } while (choose != 6);
}

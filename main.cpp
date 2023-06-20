#include <iostream>

using namespace std;

#include "manager.h"

int main()
{
    StudentManager stm;
    int choice;
    while (true)
    {
        stm.showMenu();
        cout << "Input your choice: " << endl;
        cin >> choice;
        switch (choice)
        {
        case 0:
            stm.exitSystem();
            break;
        case 1:
            stm.addInfo();
            break;
        case 2:
            stm.showStudent();
            break;
        case 3:
            stm.delStudent();
            break;
        case 4:
            stm.modStudent();
            break;
        case 5:
            stm.findStudent();
            break;
        case 6:
            stm.cleanFile();
            break;
        default:
            system("cls");
            break;
        }
    }

    system("pause");
    return 0;
}
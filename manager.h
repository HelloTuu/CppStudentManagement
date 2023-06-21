#include <string>
#include <vector>
#include <fstream>
#include <iostream>

#include "student.h"

using namespace std;

#define FILENAME "stdFile.txt"

class StudentManager
{
public:
    StudentManager();
    void showMenu();
    void exitSystem();
    void addInfo();
    void save();
    void initStudent();
    void showStudent();
    void delStudent();
    void modStudent();
    void findStudent();
    void cleanFile();
    int isExist(string id);

    ~StudentManager();

    vector<Student *> *m_StudentArray;
    bool m_FileIsEmpty;
};

StudentManager ::StudentManager()
{
    ifstream ifs;
    ifs.open(FILENAME, ios::in);
    // File not exist
    if (!ifs.is_open())
    {
        cout << "File not exist." << endl;
        this->m_FileIsEmpty = true;
        this->m_StudentArray = NULL;
        ifs.close();
        return;
    }
    // File is empty
    char ch;
    ifs >> ch;
    if (ifs.eof())
    {
        cout << "File is empty." << endl;
        this->m_FileIsEmpty = true;
        this->m_StudentArray = NULL;
        ifs.close();
        return;
    }
    // File is good
    this->m_StudentArray = new vector<Student *>;
    this->initStudent();
}

void StudentManager::showMenu()
{
    cout << "------------------------------" << endl;
    cout << "---------- Welcome -----------" << endl;
    cout << "---------- 0.Exit ------------" << endl;
    cout << "---------- 1.Add -------------" << endl;
    cout << "---------- 2.Show ------------" << endl;
    cout << "---------- 3.Delete ----------" << endl;
    cout << "---------- 4.Modify ----------" << endl;
    cout << "---------- 5.Find ------------" << endl;
    cout << "---------- 6.Clear -----------" << endl;
    cout << "------------------------------" << endl;
    cout << endl;
}

void StudentManager::exitSystem()
{
    cout << "Thanks for using." << endl;
    exit(-3);
}

void StudentManager::addInfo()
{
    if (!this->m_StudentArray)
    {
        this->m_StudentArray = new vector<Student *>;
    }
    cout << "Add student begin." << endl;
    int i = 1;
    while (true)
    {
        char flag;
        string id;
        string name;
        string dep;
        cout << "Input No." << i << "student id: " << endl;
        cin >> id;
        cout << "Input No." << i << "student name: " << endl;
        cin >> name;
        cout << "Input No." << i << "student job (A/B/C): " << endl;
        cin >> dep;
        Student *std = NULL;
        if (dep == "A")
        {
            std = new PresidentStudent(id, name, dep);
        }
        else if (dep == "B")
        {
            std = new LeaderStudent(id, name, dep);
        }
        else if (dep == "C")
        {
            std = new NormalStudent(id, name, dep);
        }
        else
        {
            cout << "Student job not exit. Add student end with error." << endl;
            break;
        }
        this->m_StudentArray->push_back(std);
        i++;
        this->m_FileIsEmpty = false;
        cout << "Continue add?(y/n)" << endl;
        cin >> flag;
        if (flag == 'y')
        {
            continue;
        }
        else
        {
            break;
        }
    }
    cout << "Add " << i - 1 << " students successfully." << endl;
    this->save();
    // system("pause");
    // system("cls");
}

void StudentManager::save()
{
    ofstream ofs;
    ofs.open(FILENAME, ios::out);
    for (int i = 0; i < this->m_StudentArray->size(); ++i)
    {
        ofs << this->m_StudentArray->at(i)->StId << " "
            << this->m_StudentArray->at(i)->m_name << " "
            << this->m_StudentArray->at(i)->m_Dept << endl;
    }
    ofs.close();
}

void StudentManager::initStudent()
{
    ifstream ifs;
    ifs.open(FILENAME, ios::in);
    string id;
    string name;
    string dep;
    while (ifs >> id && ifs >> name && ifs >> dep)
    {
        Student *std = NULL;
        if (dep == "A")
        {
            std = new PresidentStudent(id, name, dep);
        }
        else if (dep == "B")
        {
            std = new LeaderStudent(id, name, dep);
        }
        else if (dep == "C")
        {
            std = new NormalStudent(id, name, dep);
        }
        this->m_StudentArray->push_back(std);
    }
    this->m_FileIsEmpty = false;
    this->save();
}

void StudentManager::showStudent()
{
    if (this->m_FileIsEmpty)
    {
        cout << "File not exist or file is empty." << endl;
    }
    else
    {
        for (int i = 0; i < this->m_StudentArray->size(); ++i)
        {
            this->m_StudentArray->at(i)->showInfo();
        }
    }
    // system("pause");
    // system("cls");
}

void StudentManager::delStudent()
{
    if (this->m_FileIsEmpty)
    {
        cout << "File not exist or file is empty." << endl;
    }
    else
    {
        cout << "Input ID of delete student: " << endl;
        string id;
        cin >> id;
        int index = this->isExist(id);
        if (index != -1)
        {
            this->m_StudentArray->erase(this->m_StudentArray->begin() + index);
            this->save();
            cout << "Delete successfully." << endl;
        }
        else
        {
            cout << "Delete fail, for ID not exist." << endl;
        }
    }
    // system("pause");
}

int StudentManager::isExist(string id)
{
    int len = this->m_StudentArray->size();
    int index = -1;
    for (int i = 0; i < len; ++i)
    {
        if (this->m_StudentArray->at(i)->StId == id)
        {
            index = i;
            break;
        }
    }
    return index;
}

void StudentManager::modStudent()
{
    if (this->m_FileIsEmpty)
    {
        cout << "File not exist or file is empty." << endl;
    }
    else
    {
        cout << "Input ID of modify student: " << endl;
        string id;
        cin >> id;
        int index = this->isExist(id);
        if (index != -1)
        {
            string newid;
            string newname;
            string newdep;
            Student *std = NULL;
            cout << "Found student of ID " << id << ", input new ID: " << endl;
            cin >> newid;
            cout << "Input new name: " << endl;
            cin >> newname;
            cout << "Input new job: " << endl;
            cin >> newdep;
            if (newdep == "A")
            {
                std = new PresidentStudent(newid, newname, newdep);
            }
            else if (newdep == "B")
            {
                std = new LeaderStudent(newid, newname, newdep);
            }
            else if (newdep == "C")
            {
                std = new NormalStudent(newid, newname, newdep);
            }
            this->m_StudentArray->at(index) = std;
            cout << "Modify successfully." << endl;
            this->save();
        }
        else
        {
            cout << "Modify fail, student ID not exist." << endl;
        }
    }
}

void StudentManager::findStudent()
{
    if (this->m_FileIsEmpty)
    {
        cout << "File not exist or file is empty." << endl;
    }
    else
    {
        cout << "Input ID of find student: " << endl;
        string id;
        cin >> id;
        int index = this->isExist(id);
        if (index != -1)
        {
            cout << "Find successfully, the student is: " << endl;
            this->m_StudentArray->at(index)->showInfo();
        }
        else
        {
            cout << "Find fail, student not exist." << endl;
        }
    }
}

void StudentManager::cleanFile()
{
    cout << "Confirm clear data?" << endl;
    cout << "1: yes" << endl;
    cout << "2: no" << endl;
    string select = "0";
    cin >> select;
    if (select == "1")
    {
        // Clear file
        ofstream ofs(FILENAME, ios::trunc);
        ofs.close();
        if (this->m_StudentArray)
        {
            // Move pointer to the start without releasing memory
            this->m_StudentArray->clear();
            // Release memory
            vector<Student *>().swap(*this->m_StudentArray);
            // or
            // this->m_StudentArray->swap(vector<Student *>());
            this->m_FileIsEmpty = true;
            this->m_StudentArray = NULL;
        }
        cout << "Clear sucessfully." << endl;
    }
    else
    {
        cout << "Delete nothing, continue." << endl;
    }
    // system("pause");
    // system("cls");
}

StudentManager::~StudentManager()
{
    if (this->m_StudentArray)
    {
        this->m_StudentArray->clear();
        delete[] this->m_StudentArray;
        this->m_StudentArray = NULL;
    }
}
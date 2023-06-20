#include <string>
#include <iostream>

using namespace std;

class Student
{
public:
    virtual void showInfo() = 0;

    string StId;
    string m_name;
    string m_Dept;
};

class NormalStudent : public Student
{
public:
    NormalStudent(string Id,
                  string name,
                  string dep);
    void showInfo();
};

class PresidentStudent : public Student
{
public:
    PresidentStudent(string Id,
                     string name,
                     string dep);
    void showInfo();
};

class LeaderStudent : public Student
{
public:
    LeaderStudent(string Id,
                  string name,
                  string dep);
    void showInfo();
};

NormalStudent::NormalStudent(string Id, string name, string dep)
{
    this->StId = Id;
    this->m_name = name;
    this->m_Dept = dep;
}

void NormalStudent::showInfo()
{
    cout << "ID:" << this->StId
         << "\tname:" << this->m_name
         << "\tjob:" << this->m_Dept
         << "\tjob: listen" << endl;
}

PresidentStudent::PresidentStudent(string Id, string name, string dep)
{
    this->StId = Id;
    this->m_name = name;
    this->m_Dept = dep;
}

void PresidentStudent::showInfo()
{
    cout << "ID:" << this->StId
         << "\tname:" << this->m_name
         << "\tjob:" << this->m_Dept
         << "\tjob: rule leader and class" << endl;
}

LeaderStudent::LeaderStudent(string Id, string name, string dep)
{
    this->StId = Id;
    this->m_name = name;
    this->m_Dept = dep;
}

void LeaderStudent::showInfo()
{
    cout << "ID:" << this->StId
         << "\tname:" << this->m_name
         << "\tjob:" << this->m_Dept
         << "\tjob: contact with teachers" << endl;
}
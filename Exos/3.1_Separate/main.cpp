#include <iostream>
#include "Student.h"

using namespace std;

struct StudentStruct
{
   string name;
   int netID;
};

void printStud(const Student *const stuPtr);

int main()
{
   int id;

   cout << "Enter student's NetID: ";
   cin >> id;

   Student stu2;
   cout << endl << "OOP" << endl;
   stu2.setNetID(id);
   stu2.printNetID();

   cout << endl << "Enter student's netID: ";
   cin >> id;

   Student stu3;
   Student *stuPtr = nullptr;
   stuPtr = &stu3;
   stuPtr -> setNetID(id);
   (*stuPtr).printNetID();
   printStud(stuPtr);

   stuPtr = new Student;
   stuPtr -> setNetID(789);
   stuPtr -> setName("Uhura");
   printStud(stuPtr);

   return 0;
}

void printStud(const Student *const stuPtr)
{
   cout << endl << "Print with printStud" << endl;
   cout << stuPtr -> getName() << " has netID " << stuPtr -> getNetID() << endl;
}
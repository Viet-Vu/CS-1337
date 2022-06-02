/*
 * An object is a software entity that contains data (member variables)
 * and the functions that operate on the data (member functions).
 * An object is created from a class (class is a template).
 * Each object has its own copy of the member variables, but there
 * is only one copy of the member functions.
 * A class can be seen as an extension of the structure to include
 * functions.
 * Unlike structures, access to members can be controlled by
 * access specifiers: private, public.
 * With the access specifiers, it's possible to control access
 * by the outside code. Outside code is any code that is not
 * a member function of the class, ex: main function.
 * To access the members which are accessible, use the dot notation.
 * A few fundamental concepts in OOP:
 *    1) Data hiding: Restricts access.
 *    2) Encapsulation: Data and functions are combined in the same
 *       object.
 *
 * An object has a memory address. To hold the address, use a pointer
 * to an object.
 * Same concepts and syntax as for structures: can assign nullptr,
 * can use the & operator, can dereference, can use the arrow
 * notation.
 * Can dynamically create an object with the "new" operator.
 * Use delete to release the dynamically created object.
 */

#include <iostream>

using namespace std;

struct StudentStruct
{
   string name;
   int netID;
};

class Student
{
   private:
      string name;
      int netID;
   public:
      void setNetID(int);
      void printNetID() const;
      void setName(string);
      string getName() const;
      int getNetID() const;
};

void setNetID(StudentStruct *const stuPtr, int id);
void printNetID(const StudentStruct *const stuPtr);
void printStud(const Student *const stuPtr);

int main()
{
   int id;

   cout << "Enter student's NetID: ";
   cin >> id;

   StudentStruct stu1;
   cout << endl << "Procedural programming" << endl;
   setNetID(&stu1, id);
   printNetID(&stu1);

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

void setNetID(StudentStruct *const stuPtr, int id)
{
   stuPtr->netID = id;
}

void printNetID(const StudentStruct *const stuPtr)
{
   cout << "Student ID is " << stuPtr->netID << endl;
}

void Student::setNetID(int id)
{
   if (id > 0)
      netID = id;
   else
   {
      cout << "Error, Id must be positive" << endl;
      exit(EXIT_FAILURE);
   }
}

void Student::printNetID() const
{
   cout << "Student ID is " << netID << endl;
}

void Student::setName(string s)
{
   name = s;
}

string Student::getName() const
{
   return name;
}

int Student::getNetID() const
{
   return netID;
}

void printStud(const Student *const stuPtr)
{
   cout << endl << "Print with printStud" << endl;
   cout << stuPtr -> getName() << " has netID " << stuPtr -> getNetID() << endl;
}
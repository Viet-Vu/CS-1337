/*
 * A constructor is a special member function that is automatically
 * called (no explicit call by programmer) when an object is created
 * statically or dynamically.
 *
 * Constructor must have the same name as the class. It has no return
 * type (not even void).
 *
 * A constructor can take zero or more arguments.
 *
 * A default constructor is a constructor that is called when an
 * object is created with no argument.
 *
 * A class can have more than one constructor through overloading
 * but can have only one default constructor.
 *
 * Refer to diagram on Slide 53 for summary.
 */

#include <iostream>

using namespace std;

class Student
{
   private:
      string name;
      int netID;
   public:
      Student();
      Student(string, int);
      Student(string);
      void setNetID(int);
      void printNetID() const;
      void setName(string);
      string getName() const;
      int getNetID() const;
};

void printStud(const Student *const stuPtr);

int main()
{
   cout << "Create object stu1" << endl;
   Student stu1;
   printStud(&stu1);

   cout << endl << "Create object stu2" << endl;
   Student stu2("Han Solo", 101);
   printStud(&stu2);

   cout << endl << "Create object stu3" << endl;
   Student stu3("Scotty");
   printStud(&stu3);

   cout << endl << "Dynamically create object" << endl;
   Student *stuPtr = new Student("Scotty");
   printStud(stuPtr);

   cout << endl << "Dynamically create object" << endl;
   stuPtr = new Student;
   printStud(stuPtr);

   return 0;
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

Student::Student()
{
   cout << "Inside default constructor of Student" << endl;
   name = "";
   netID = 0;
}

Student::Student(string s, int id)
{
   cout << "Inside constructor with 2 arguments of Student" << endl;
   name = s;
   netID = id;
}

Student::Student(string s)
{
   cout << "Inside constructor with 1 argument of Student" << endl;
   name = s;
}
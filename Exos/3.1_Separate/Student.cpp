#include <iostream>
#include "Student.h"

using namespace std;

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

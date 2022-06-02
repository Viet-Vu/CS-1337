/*
 * Nested structure: A structure can have another structure as a member.
 *
 * We can pass a structure member or a whole structure variable as argument to a function.
 *
 * By default, a structure variable is passed by value (can also pass by reference with &).
 * You get faster execution and more efficient memory usage when you pass by reference.
 *
 * When you pass by reference, you can use const to prevent the function from modifying the structure.
 *
 * A function can return a structure.
 *
 * A structure variable has an address. To hold the address, use a pointer to a structure.
 * Everything that we learned about pointers applies.
 * - Can assign nullptr or a valid structure address to the pointer.
 * - Dereference the pointer to access the structure variable (use *).
 *
 * You can pass a structure pointer to a function:
 * 1. Use * in parameter list of prototype and function header.
 * 2. Dereference the pointer inside the function (but you can use -> notation as an alternative).
 * 3. Pass the address of the structure using & when you call the function.
 *
 * To access a structure member from a pointer, there are 2 options:
 * 1. Dereference the pointer, then use the dot notation, but make sure the parens in the right place,
 * ex: (*studPtr).GPA
 * 2. Use the arrow notation, ex: studPtr->GPA
 *
 * Can dynamically allocate a structure (or array of structures) with the "new" operator.
 * Need a pointer to store the address.
 * Should return the chunk of memory when done, using "delete".
 *
 * Same concepts and syntax as in Chapter 9.
 */

#include <iostream>

using namespace std;

struct Person
{
   string name;
   int bMonth;
   int bDay;
   int bYear;
};

struct Student
{
   Person studPerson;
   double GPA;
};

Student getStudentInfo();
void printStu(Student s);
void printStu2(const Student &s);
void printStu3(const Student *const sPtr);

int main()
{
   int numStudents;

   cout << "A structure can be nested within another structure" << endl;

   Student stu1;
   stu1 = getStudentInfo();

   cout << endl;
   printStu(stu1);

   cout << endl;
   printStu2(stu1);

   cout << endl << "Address of stu1 is " << &stu1;

   Student *studPtr = &stu1;

   cout << endl << "Print stu1 using pointer" << endl;
   printStu3(studPtr);

   cout << endl << "Enter number of students:";
   cin >> numStudents;
   cin.ignore();
   studPtr = new Student[numStudents];

   for (int i = 0; i < numStudents; i++)
      studPtr[i] = getStudentInfo();

   cout << endl << "Student array" << endl;
   for (int i = 0; i < numStudents; i++)
   {
      printStu(studPtr[i]);
      cout << endl;
   }

   delete[] studPtr;

   return 0;
}

Student getStudentInfo()
{
   Student stud;
   cout << "Enter student's name:";
   getline(cin, stud.studPerson.name);

   cout << "Enter month, day, year of birth:";
   cin >> stud.studPerson.bMonth >> stud.studPerson.bDay >> stud.studPerson.bYear;

   cout << "Enter GPA:";
   cin >> stud.GPA;

   cin.ignore();
   return stud;
}

void printStu(Student s)
{
   cout << "Name: " << s.studPerson.name << ", DOB " << s.studPerson.bMonth << "/" << s.studPerson.bDay << "/" << s.studPerson.bYear << ", GPA: " << s.GPA;
}

void printStu2(const Student &s)
{
   cout << "Name: " << s.studPerson.name << ", DOB " << s.studPerson.bMonth << "/" << s.studPerson.bDay << "/" << s.studPerson.bYear << ", GPA: " << s.GPA;
}

void printStu3(const Student *const sPtr)
{
   cout << "Name: " << sPtr->studPerson.name << ", DOB " << sPtr->studPerson.bMonth << "/" << sPtr->studPerson.bDay << "/" << (*sPtr).studPerson.bYear << ", GPA: " << (*sPtr).GPA;
}
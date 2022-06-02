/*
 * The data types we already know are the primitive (built-in)
 * data types: int, double, etc. They come with the language.
 *
 * Attributes of a data type are the values that the type can take,
 * and the operations you can perform. For example, the values of
 * int are the numbers without a fraction between INT_MIN and INT_MAX.
 * The operations are +, -, *, /, etc.
 *
 * An abstract data type is a data type where you don't know the
 * implementation. A good example is C++ string class (not C-string).
 *
 * A structure is a grouping of variables not necessarily of the
 * same type (unlike arrays).
 *
 * A structure declaration (definition) is a template The name of the
 * template is "structure tag". No memory is allocated.
 *
 * Once a structure has been declared, can define instances built
 * according to the template. They are called "structure variables".
 * Memory is allocated.
 *
 * Use the dot operator to access a member of a structure variable.
 *
 * Can use an initialization list to initialize a structure variable
 * when it's defined.
 * Partial list is possible. Omitted values are set to zero, or
 * empty string.
 *
 * Arrays of structures can be used in place of parallel arrays.
 */

#include <iostream>

using namespace std;

int main()
{
   struct Student
   {
      string netID;
      double GPA;
   };

   Student stu1;
   cout << endl << "Enter the student's netID, then GPA:";
   cin >> stu1.netID >> stu1.GPA;
   cout << "stu1: Student's netID and GPA are ";
   cout << stu1.netID << ", " << stu1.GPA << endl;

   Student stu2 = {"def456", 100};
   cout << endl << "Initialize structure with a list" << endl;
   cout << "stu2: Student's netID and GPA are ";
   cout << stu2.netID << ", " << stu2.GPA << endl;

   Student stu3;
   stu3.netID = "ghi789";
   stu3.GPA = 2.0;
   cout << endl << "Initialize member by member" << endl;
   cout << "stu3: Student's netID and GPA are ";
   cout << stu3.netID << ", " << stu3.GPA << endl;

   Student stu4 = {"jkl7890"};
   cout << endl << "Initialize with partial list" << endl;
   cout << "stu4: Student's netID and GPA are ";
   cout << stu4.netID << ", " << stu4.GPA << endl;

   const int NUM_ELMTS = 3;
   Student stuArr[NUM_ELMTS];
   cout << endl << "Array of structures" << endl;
   for (int i = 0; i < NUM_ELMTS; i++)
   {
      cout << endl << "Enter the netID and GPA of student " << (i + 1) << ":";
      cin >> stuArr[i].netID >> stuArr[i].GPA;
      cout << "Student's netID and GPA are ";
      cout << stuArr[i].netID << ", " << stuArr[i].GPA << endl;
   }

   return 0;
}
/*
 * C++ has a library of functions for C++ string class. Examples:
 * - getline(cin, myString) reads the whole line and puts into myString.
 * - Relational operators: ex. str1 < str2.
 * - Can initialize a string with a literal, another string, or a char array (C-string).
 * - + means concatenation.
 * - [] references a character in the string.
 * - .length member function returns the number of characters.
 * Many other functions.
 */

#include <iostream>

using namespace std;

int main()
{
   string name;
   cout << "Input your name:";
   getline(cin, name);
   cout << "Name is " << name << endl;

   string myOtherString("Chris");
   string myStr(myOtherString);
   cout << "myStr is " << myStr << ", myOtherString is " << myOtherString << endl;
   char myArr[40] = {'J', 'o', 'e', '\0'};
   string mySecondStr(myArr);
   cout << "myArr is " << myArr << ", mySecondStr is " << mySecondStr << endl;

   cout << endl << "2nd character of myStr is " << myStr[1] << endl;

   cout << "Length of myStr is " << myStr.length();

   return 0;
}
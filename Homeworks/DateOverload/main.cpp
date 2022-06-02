/*
 * Program Name: Homework 8 - Section 1.11, Date Operator Overloading
 * Author: Viet Vu
 * Date: April 9, 2022
 * Program Description: This program functions with and manipulates date strings using overloaded operators on a Date class object.
 */

#include <iostream>
#include "Date.h"

using namespace std;

// These are the function prototypes that each get an element of an overall date string.
int getMonth(string);
int getDay(string);
int getYear(string);
int getHour(string);

// This is the main function copied and pasted from the ZyLabs with few edits.
int main()
{
   int month, day, year, hour;

   // This block creates the arrays of the data that the program will work with.
   const int NUM_DATES_SUBTRACT = 4, NUM_DATES_RELATIONAL = 5;
   string dateArraySubtract[NUM_DATES_SUBTRACT] = {"01/01/2097/20", "02/12/2098/00", "02/13/2100/13","12/31/2103/23"};
   string dateArrayRelational[NUM_DATES_RELATIONAL] = {"01/01/2097/20", "01/01/2097/21", "01/02/2097/20","02/01/2097/20", "01/01/2098/20"};

   // This block creates the title block that marks the beginning of the relational operator output.
   string title = "Overloaded relational operators";
   string underline;
   underline.assign(title.length(), '-');
   cout << title << endl << underline << endl;

   // This block loops through all of the data and processes it according to its relevant functions.
   Date d1, d2;
   for (int i = 0; i < NUM_DATES_RELATIONAL; i++)
      for (int j = 0; j < NUM_DATES_RELATIONAL; j++)
      {
         // This block uses all of the stand-alone functions to extract the month, day, year, and hour for date 1 and outputs it.
         month = getMonth(dateArrayRelational[i]);
         day = getDay(dateArrayRelational[i]);
         year = getYear(dateArrayRelational[i]);
         hour = getHour(dateArrayRelational[i]);
         d1.set(month, day, year, hour);
         cout << endl << "============================================" << endl;
         cout << "d1: ";
         d1.print();

         // This block uses all of the stand-alone functions to extract the month, day, year, and hour for date 2 and outputs it.
         month = getMonth(dateArrayRelational[j]);
         day = getDay(dateArrayRelational[j]);
         year = getYear(dateArrayRelational[j]);
         hour = getHour(dateArrayRelational[j]);
         d2.set(month, day, year, hour);
         cout << ", d2: ";
         d2.print();
         cout << endl;

         // This block uses the overloaded operators and outputs the cases according to if their respective cases pass.
         if (d1 < d2)
            cout << "(d1 < d2) ";
         if (d2 < d1)
            cout << "(d2 < d1) ";
         if (d1 == d2)
            cout << "(d2 == d1) ";
         if (d1 <= d2)
            cout << "(d1 <= d2) ";
         if (d2 <= d1)
            cout << "(d2 <= d1) ";
      }

   // This block creates the title block that marks the beginning of the overloaded subtraction operator output.
   title = "Overloaded - operator";
   underline.assign(title.length(), '-');
   cout << endl << endl << title << endl << underline << endl;

   // This block loops through all of the data and processes it according to its relevant functions.
   for (int i = 0; i < NUM_DATES_SUBTRACT; i++)
      for (int j = 0; j < NUM_DATES_SUBTRACT; j++)
      {
         // This block uses all of the stand-alone functions to extract the month, day, year, and hour for date 1 and outputs it.
         month = getMonth(dateArraySubtract[i]);
         day = getDay(dateArraySubtract[i]);
         year = getYear(dateArraySubtract[i]);
         hour = getHour(dateArraySubtract[i]);
         d1.set(month, day, year, hour);
         cout << endl << "============================================\n";
         cout << "d1: ";
         d1.print();

         // This block uses all of the stand-alone functions to extract the month, day, year, and hour for date 2 and outputs it.
         month = getMonth(dateArraySubtract[j]);
         day = getDay(dateArraySubtract[j]);
         year = getYear(dateArraySubtract[j]);
         hour = getHour(dateArraySubtract[j]);
         d2.set(month, day, year, hour);
         cout << ", d2: ";
         d2.print();
         cout << endl;

         // This line outputs the difference in hours between date 1 and 2.
         cout << "d2 - d1 = " << d2 - d1 << " hours"<< endl;
      }
}

// This function loops up to the first '/' of the date string and returns the month value.
int getMonth(string d)
{
   string month = "";
   // This block builds the month string from the start of the date string up to the first '/'.
   for (int i = 0; i < d.length(); i++)
      if (d[i] != '/')
         month += d[i];
      else
         break;

   return stoi(month);
}

// This function loops between the first and second '/' of the date string and returns the day value.
int getDay(string d)
{
   string day = "";
   // This block builds the day string after the first '/' is found up to the next '/'.
   for (int i = 0, count = 0; i < d.length(); i++)
      if ((count == 0) && (d[i] == '/'))
         count++;
      else if ((count == 1) && (d[i] != '/'))
         day += d[i];
      else if ((count == 1) && (d[i] == '/'))
         break;

   return stoi(day);
}

// This function loops between the second and third '/' of the date string and returns the year value.
int getYear(string d)
{
   string year = "";
   // This block builds the year string after the second '/' is found up to the next '/'.
   for (int i = 0, count = 0; i < d.length(); i++)
      if ((count < 2) && (d[i] == '/'))
         count++;
      else if ((count == 2) && (d[i] != '/'))
         year += d[i];
      else if ((count == 2) && (d[i] == '/'))
         break;

   return stoi(year);
}

// This function loops after the third '/' of the date string and returns the hour value.
int getHour(string d)
{
   string hour = "";
   // This block builds the hour string after the third '/' is found up to the end of the date string.
   for (int i = 0, count = 0; i < d.length(); i++)
      if ((count < 3) && (d[i] == '/'))
         count++;
      else if ((count == 3) && (d[i] != '/'))
         hour += d[i];

   return stoi(hour);
}
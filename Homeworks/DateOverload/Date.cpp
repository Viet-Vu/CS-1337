/*
 * Program Name: Homework 8 - Section 1.11, Date Operator Overloading
 * Author: Viet Vu
 * Date: April 9, 2022
 * Program Description: This program functions with and manipulates date strings using overloaded operators on a Date class object.
 */

#include <iostream>
#include "Date.h"

using namespace std;

// This function sets the month, day, year, and hour values according to ts given parameters.
void Date::set(int month_, int day_, int year_, int hour_)
{
   month = month_;
   day = day_;
   year = year_;
   hour = hour_;
}

// This function overloads the '<' relational operator.
bool Date::operator < (const Date &rhs)
{
   // This block goes down each variable from highest to lowest value and returns a '<' relation whenever the values do not match.
   if (year != rhs.year)
      return (year < rhs.year);
   else if (month != rhs.month)
      return (month < rhs.month);
   else if (day != rhs.day)
      return (day < rhs.day);
   else
      return (hour < rhs.hour);
}

// This function overloads the '==' relational operator.
bool Date::operator == (const Date &rhs)
{
   // This line returns true only if the month, day, year, and hour values all match.
   return ((month == rhs.month) && (day == rhs.day) && (year == rhs.year) && (hour == rhs.hour));
}

// This functon overloads the '<=' relational operator.
bool Date::operator <= (const Date &rhs)
{
   // This line combines the previously established '==' and '<' relational operators and returns according to their rules.
   return ((*this == rhs) || (*this < rhs));
}

// This function overloads the '-' operator.
int Date::operator - (const Date &rhs)
{
   // This array holds the values of the days of the year of each first day of every month.
   int firstMonths[] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};

   // This block uses the formula given by ZyBooks to determine the number of total hours of a given date since 01/01/0001/00.
   int n1 = ((365 * (rhs.year - 1) + firstMonths[rhs.month - 1] + rhs.day) * 24) + rhs.hour;
   int n2 = ((365 * (year - 1) + firstMonths[month - 1] + day) * 24) + hour;

   // This block counts the number of leap years between two given years.
   int count = 0;
   for (int i = rhs.year; i <= year; i++)
      if (((i % 4 == 0) && (i % 100 != 0)) || (i % 400 == 0))
         count++;

   // This line returns the difference of the two dates' hour counts plus the leap year hours.
   return ((n2 - n1) + (count * 24));
}

// This function prints the date with the proper formatting using a month name array.
void Date::print()
{
   string monthArray[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
   cout << monthArray[month - 1] << " " << day << ", " << year << ", " << hour << ":00";
}
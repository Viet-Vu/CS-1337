/*
 * Program Name: Homework 9, Section 1.12 - Transaction File Management
 * Author: Viet Vu
 * Date: April 15, 2022
 * Program Description: This program is designed to read a file and create account object each with their own unique
 *                      transactions and their various corresponding data.
 */

#include "Date.h"

// This line creates an array of each month's name spelled out.
string Date::monthName[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

// This function sets the contents of a Date object with its given values.
void Date::set(int month_, int day_, int year_, int hour_)
{
   month = month_;
   day = day_;
   year = year_;
   hour = hour_;
}

// This function overloads the '<' operator to work with dates.
bool Date::operator < (const Date &rhs)
{
   if (year != rhs.year)
      return (year < rhs.year);
   else if (month != rhs.month)
      return (month < rhs.month);
   else if (day != rhs.day)
      return (day < rhs.day);
   else
      return (hour < rhs.hour);
}

// This function outputs the date with the correct formatting.
void Date::print() const
{
   cout << monthName[month - 1] << " " << day << ", " << year << ", " << hour << ":00";
}

// This function gathers the month value.
int Date::getMonthFromDate() const
{
   return month;
}

// This function gathers the day value.
int Date::getDayFromDate() const
{
   return day;
}

// This function gathers the year value.
int Date::getYearFromDate() const
{
   return year;
}

// This function gathers the hour value.
int Date::getHourFromDate() const
{
   return hour;
}
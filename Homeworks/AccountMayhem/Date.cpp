/*
 * Program Name: Homework 10: Section 1.13 - Account Inheritance and Separation
 * Author: Viet Vu
 * Date: April 26, 2022
 * Program Description: This program is designed to use multiple .cpp files to manage an Account array with varying
 *                      Account types, Regular and Premium.
 */

#include "Date.h"

// This function sets the month, day, year, and hour of an Account with given values.
void Date::set(int month_, int day_, int year_, int hour_)
{
   month = month_;
   day = day_;
   year = year_;
   hour = hour_;
}

// This function prints a Date with proper formatting.
void Date::print() const
{
   string monthNames[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
   cout << monthNames[month - 1] << " " << day << ", " << year << ", " << hour << ":00";
}

// This function returns the month of a Date.
int Date::getMonth() const
{
   return month;
}

// This function returns the day of a Date.
int Date::getDay() const
{
   return day;
}

// This function returns the year of a Date.
int Date::getYear() const
{
   return year;
}

// This function returns the hour of a Date.
int Date::getHour() const
{
   return hour;
}
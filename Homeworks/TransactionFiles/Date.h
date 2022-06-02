#ifndef TRANSACTIONFILES_DATE_H
#define TRANSACTIONFILES_DATE_H

#include <iostream>
#include <string>

using namespace std;

class Date
{
private:
   int month, day, year, hour;
   static string monthName[13];
   int calcElapsedDay(Date d);
public:
   void set(int month_, int day_, int year_, int hour_);
   bool operator < (const Date &rhs);
   void print() const;
   int getMonthFromDate() const;
   int getDayFromDate() const;
   int getYearFromDate() const;
   int getHourFromDate() const;
};

#endif

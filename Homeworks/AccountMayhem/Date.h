#ifndef ACCOUNTMAYHEM_DATE_H
#define ACCOUNTMAYHEM_DATE_H

#include <iostream>

using namespace std;

class Date
{
private:
   int month, day, year, hour;
   int calcElapsedTime(Date d);
public:
   void set(int month_, int day_, int year_, int hour_);
   int getMonth() const;
   int getDay() const;
   int getYear() const;
   int getHour() const;
   void print() const;
};

#endif

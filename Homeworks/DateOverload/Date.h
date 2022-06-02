#ifndef DATEOVERLOAD_DATE_H
#define DATEOVERLOAD_DATE_H

#include <string>

using namespace std;

class Date
{
private:
   int month, day, year, hour;
   int calcElapsedTime(Date);
public:
   void set(int, int, int, int);
   bool operator<(const Date&);
   bool operator==(const Date&);
   bool operator<=(const Date&);
   int operator-(const Date&);
   void print();
};

#endif

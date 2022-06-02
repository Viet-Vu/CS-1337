#ifndef INC_3_1_SEPARATE_STUDENT_H
#define INC_3_1_SEPARATE_STUDENT_H
#include <string>

using namespace std;

class Student
{
   private:
      string name;
      int netID;
   public:
      void setNetID(int);
      void printNetID() const;
      void setName(string);
      string getName() const;
      int getNetID() const;
};

#endif
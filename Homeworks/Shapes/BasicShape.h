#ifndef SHAPES_BASICSHAPE_H
#define SHAPES_BASICSHAPE_H

#include <string>

using namespace std;

class BasicShape
{
   private:
      double area;

   public:
      class NegativeValue {};

      double getArea() const
      {
         return area;
      }

      virtual double calcArea() const = 0;

      void setArea(double area_)
      {
         area = area_;
      }
};

#endif
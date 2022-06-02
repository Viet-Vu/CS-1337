#ifndef SHAPES_RECTANGLE_H
#define SHAPES_RECTANGLE_H

#include "BasicShape.h"

class Rectangle : public BasicShape
{
   private:
      double width;
      double length;

   public:
      Rectangle(double w, double l);
      double calcArea() const;
};

#endif

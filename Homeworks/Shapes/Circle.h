#ifndef SHAPES_CIRCLE_H
#define SHAPES_CIRCLE_H

#include "BasicShape.h"

class Circle : public BasicShape
{
   private:
      double centerX;
      double centerY;
      double radius;
   public:
      Circle(double x, double y, double rad);
      double calcArea() const;
};

#endif

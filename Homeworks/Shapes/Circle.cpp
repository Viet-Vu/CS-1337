/*
 * Program Name: Homework 11 - Section 1.14, Shape Area Overload and Exceptions
 * Author: Viet Vu
 * Date: 04 30, 2022
 * Program Description: This program is designed to use exception class loops to gather the area for circles and rectangles.
 */

#include "Circle.h"

// This is the constructor for Circle.
Circle::Circle(double x, double y, double rad)
{
   // This block throws a NegativeValue exception if any of the given values are negative.
   if (x < 0 || y < 0 || rad < 0)
      throw NegativeValue();

   // This block sets all of the values of Circle.
   centerX = x;
   centerY = y;
   radius = rad;

   // This line uses the given values to calculate and set the Circle's area.
   setArea(calcArea());
}

// This function overloads calcArea to return (PI) * R^2.
double Circle::calcArea() const
{
   return (3.14159 * radius * radius);
}
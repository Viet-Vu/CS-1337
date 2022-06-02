/*
 * Program Name: Homework 11 - Section 1.14, Shape Area Overload and Exceptions
 * Author: Viet Vu
 * Date: 04 30, 2022
 * Program Description: This program is designed to use exception class loops to gather the area for circles and rectangles.
 */

#include "Rectangle.h"

// This is the constructor for Rectangle.
Rectangle::Rectangle(double w, double l)
{
   // This block throws a NegativeValue exception if any of the given values are negative.
   if (w < 0 || l < 0)
      throw NegativeValue();

   // This block sets all of the values of Rectangle.
   width = w;
   length = l;

   // This line uses the given values to calculate and set the Rectangle's area.
   setArea(calcArea());
}

// This function overloads calcArea to return L * W.
double Rectangle::calcArea() const
{
   return (width * length);
}
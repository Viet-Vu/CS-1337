/*
 * Program Name: Homework 11 - Section 1.14, Shape Area Overload and Exceptions
 * Author: Viet Vu
 * Date: 04 30, 2022
 * Program Description: This program is designed to use exception class loops to gather the area for circles and rectangles.
 */

#include <iostream>
#include "Circle.h"
#include "Rectangle.h"

using namespace std;

// These are the function prototypes in the general order in which they appear.
void getCircle();
void getRectangle();

// This is the main function that only calls the two other functions in this program.
int main()
{
   getCircle();
   getRectangle();

   return 0;
}

// This function gathers the user's data for their Circle.
void getCircle()
{
   cout << "================= Circle =================" << endl;

   double circleX, circleY, radius;
   bool isValid = false;

   // This block loops so long as there is no valid (negative) input value.
   while (!isValid)
   {
      // This block gathers the user's x-coordinate, y-coordinate, and circle radius values.
      cout << "Please enter the x coordinate of the circle's center: ";
      cin >> circleX;

      cout << "Please enter the y coordinate of the circle's center: ";
      cin >> circleY;

      cout << "Please enter the radius of the circle: ";
      cin >> radius;

      // This block tries to create a Circle object with the given values.
      try
      {
         Circle circ(circleX, circleY, radius);

         // This block outputs the success message and breaks the loop.
         cout << "***** The area of the circle is " << circ.getArea() << "." << endl << endl;
         isValid = true;
      }
      // This block outputs an error message if any of the user's inputs are negative.
      catch (Circle::NegativeValue)
      {
         cout << "***** Negative input value" << endl << endl;
      }
   }
}

void getRectangle()
{
   cout << "================= Rectangle =================" << endl;

   double length, width;
   bool isValid = false;

   // This block loops so long as there is no valid (negative) input value.
   while (!isValid)
   {
      // This block gathers the user's length and width values.
      cout << "Please enter the length of the rectangle: ";
      cin >> length;

      cout << "Please enter the width of the rectangle: ";
      cin >> width;

      // This block tries to create a Rectangle object with the given values.
      try
      {
         Rectangle rect(width, length);

         // This block outputs the success message and breaks the loop.
         cout << "***** The area of the rectangle is " << rect.getArea() << ".";
         isValid = true;
      }
      // This block outputs an error message if any of the user's inputs are negative.
      catch (Rectangle::NegativeValue)
      {
         cout << "***** Negative input value" << endl << endl;
      }
   }
}
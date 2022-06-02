// Program Name: Homework 6 - Section 1.9, Inventory Management with OOP
// Author: Viet Vu
// Date: March 26, 2022
// Program Description: This program is designed to manage an object array read from a file and manipulate its values using OOP.

#include "Product.h"

using namespace std;

// This function sets each of the values of a given Product.
void Product::setProductAttributes(string PLUVal, string nameVal, int typeVal, double priceVal, int inventoryVal)
{
   PLU = PLUVal;
   name = nameVal;
   type = typeVal;
   price = priceVal;
   inventory = inventoryVal;
}

// This function sets only the inventory of a given Product.
void Product::setInventory(int inventoryVal)
{
   inventory = inventoryVal;
}

// This function gathers a Product's PLU value.
string Product::getPLU() const
{
   return PLU;
}

// This function gathers a Product's name.
string Product::getName() const
{
   return name;
}

// This function gathers a Product's type value.
int Product::getType() const
{
   return type;
}

// This function gathers a Product's price value.
double Product::getPrice() const
{
   return price;
}

// This function gathers a Product's inventory value.
int Product::getInventory() const
{
   return inventory;
}
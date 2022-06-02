// Program Name: Homework 3, Section 1.6 Grocery Checkout Validation
// Author: Viet Vu
// Date: March 8, 2022
// Program Description: This program is designed to take in a file of data and validate if they meet their respective requirements.

#include <iostream>
#include <fstream>

using namespace std;

// These are the function prototypes. They generally follow the Principle of Least Privilege.
string tokenize(string &);
bool isValidPLU(string const);
bool isValidName(string const);
bool isValidType(string const);
bool isValidPrice(string const);
bool isValidLevel(string const);

// This is the main function. It generally follows the suggested outline set by ZyBooks.
int main()
{
   bool isValidFile = true;
   string token, line;
   int tokenIndex;

   // This block prompts the user for their input file name and creates the input file.
   string input;
   cout << "Enter input file:";
   getline(cin, input);
   ifstream inputFile(input);

   // This block returns exit failure if the input file cannot be opened.
   if (!inputFile)
      return -1;

   // This block sets the appropriate bar spacing in the initializing output according to the input file name's length.
   if (input.length() == 6)
      cout << endl << "Checking " << input << endl << "---------------" << endl;
   else
      cout << endl << "Checking " << input << endl << "----------------" << endl;

   // This while loop does the main work of the program. Each block will be explained as it is reached.
   while (getline(inputFile, line))
   {
      // This index is used to determine which isValid function will be called, or if the file exceeds/subceeds the required token count.
      tokenIndex = 1;

      // This block breaks the outer while loop if the file is invalid. This connects to how the inner while loop breaks, as well.
      if (!isValidFile)
         break;

      // This line spaces out the output blocks by file line.
      cout << endl;

      // This inner while loop processes each line of the input file. The condition is based on a constantly reducing string.
      while (line != "")
      {
         // This token is created by extracting the first non-space block of the overall line using the "tokenize" function.
         token = tokenize(line);

         // This block detects if the token count subceeds its required amount, outputs the error message, and breaks out of the while loops.
         if (token == "" && tokenIndex <= 5)
         {
            cout << "Inventory is invalid, record has missing items" << endl;
            isValidFile = false;
            break;
         }

         // This block calls the corresponding isValid function depending on what the tokenIndex is and updates isValidFile accordingly.
         if (tokenIndex == 1)
            isValidFile = isValidPLU(token);
         else if (tokenIndex == 2)
            isValidFile = isValidName(token);
         else if (tokenIndex == 3)
            isValidFile = isValidType(token);
         else if (tokenIndex == 4)
            isValidFile = isValidPrice(token);
         else if (tokenIndex == 5)
            isValidFile = isValidLevel(token);
         // This part of the block detects if the token count exceeds its maximum amount and outputs the appropriate error message.
         else if (tokenIndex >= 6 && token != "")
         {
            cout << "Token #" << tokenIndex << " is " << token << ", Too many items in record" << endl;
            isValidFile = false;
         }

         // This block breaks out of the inner while loop depending on the status of isValidFile.
         if (!isValidFile)
            break;

         tokenIndex++;
      }
   }

   // This block produces the final output line depending on if the input file is valid or not.
   if (isValidFile)
      cout << endl << "######## " << input << " has valid content ########" << endl;
   else
      cout << endl << "######## " << input << " has invalid content ########" << endl;

   inputFile.close();
   return 0;
}

// This function constantly updates the overall line, breaking up the string by the delimiters and extracting the first non-delimiter element.
string tokenize(string &line)
{
   string token = "";
   int index = 0, delimsFound = 0;
   bool isTokenFound = false;

   // This block is used to find the index of the first non-space element.
   for (; index < line.length(); index++)
      if (!isspace(line[index]))
         break;

   // This block starts off at the now-found index and loops through the rest of the string, finding the token element.
   for (; index < line.length(); index++)
   {
      // This is the case for if the index is a space. It updates the delimiter count accordingly.
      if (isspace(line[index]))
      {
         // This block states that if the index is at a space and the token is not empty, then the token is found.
         if (token != "")
            isTokenFound = true;
         delimsFound++;
      }
      // This is the case for if the index is at a non-space element, where it adds the contents of index to the token.
      else
         token += line[index];

      // This stops the loop if the token is found and the index is at the first space after the token.
      if (isTokenFound && delimsFound > 0)
         break;
   }

   // This block updates the line to the stopped-index value and returns the created token.
   line = line.substr(index);
   return token;
}

// This function tests the PLU value and determines if it is valid according to the conditions set on ZyBooks.
bool isValidPLU(string const plu)
{
   bool isValid = true;

   // This block invalidates the PLU if it is not 4 characters long.
   if (plu.length() != 4)
      isValid = false;

   // This block invalidates the PLU if it does not only contain alphanumeric characters.
   for (int i = 0; i < plu.length(); i++)
      if (!isalnum(plu[i]))
         isValid = false;

   // This block outputs the appropriate output depending on the isValid status.
   if (isValid)
      cout << "Token #1 is " << plu << ", PLU is valid" << endl;
   else
      cout << "Token #1 is " << plu << ", PLU is invalid" << endl;

   return isValid;
}

// This function tests the Product Name value and determines if it is valid according to the conditions set on ZyBooks.
bool isValidName(string const productName)
{
   bool isValid = true;

   // This block invalidates the product name if the first character is non-alphabetical.
   if (!isalpha(productName[0]))
      isValid = false;

   // This block outputs the appropriate output depending on the isValid status.
   if (isValid)
      cout << "Token #2 is " << productName << ", Product name is valid" << endl;
   else
      cout << "Token #2 is " << productName << ", Product name is invalid" << endl;

   return isValid;
}
// This function tests the Sales Type value and determines if it is valid according to the conditions set on ZyBooks.
bool isValidType(string const type)
{
   bool isValid = true;

   // This block invalidates the sales type if it is not 1 or 0.
   if (type != "1" && type != "0")
      isValid = false;

   // This block outputs the appropriate output depending on the isValid status.
   if (isValid)
      cout << "Token #3 is " << type << ", Sales type is valid" << endl;
   else
      cout << "Token #3 is " << type << ", Sales type is invalid" << endl;

   return isValid;
}

// This function tests the Item Price value and determines if it is valid according to the conditions set on ZyBooks.
bool isValidPrice(string const price)
{
   bool isValid = true;
   int dotCount = 0;

   // This block goes through the item price and determines its validity based on the dot count, numeric presence, and dot placement.
   for (int i = 0; i < price.length(); i++)
   {
      // This block invalidates the item price if it does not only contain numbers or dots.
      if (!isdigit(price[i]) && price[i] != '.')
         isValid = false;
      // This block counts the dots found in the item price string.
      if (price[i] == '.')
      {
         // This block invalidates the item price if a dot is found more than two digits away from the end of the item price.
         if (i + 3 < price.length())
            isValid = false;
         dotCount++;
      }
   }

   // This block invalidates the item price if the dot count exceeds 1.
   if (dotCount > 1)
      isValid = false;

   // This block outputs the appropriate output depending on the isValid status.
   if (isValid)
      cout << "Token #4 is " << price << ", Price is valid" << endl;
   else
      cout << "Token #4 is " << price << ", Price is invalid" << endl;

   return isValid;
}

// This function tests the Inventory Level value and determines if it is valid according to the conditions set on ZyBooks.
bool isValidLevel(string const inventoryLevel)
{
   bool isValid = true;

   // This block invalidates the inventory level if it contains non-numeric characters.
   for (int i = 0; i < inventoryLevel.length(); i++)
      if (!isdigit(inventoryLevel[i]))
         isValid = false;

   // This block outputs the appropriate output depending on the isValid status.
   if (isValid)
      cout << "Token #5 is " << inventoryLevel << ", Inventory is valid" << endl;
   else
      cout << "Token #5 is " << inventoryLevel << ", Inventory is invalid" << endl;

   return isValid;
}
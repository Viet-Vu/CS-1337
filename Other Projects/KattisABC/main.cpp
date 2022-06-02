#include <iostream>
#include <string>

using namespace std;

int findLowest(int val1, int val2, int val3);
int findMiddle(int val1, int val2, int val3);
int findHighest(int val1, int val2, int val3);
void sortABC(int arr[], string abc, int val1, int val2, int val3);

int main()
{
   int val1, val2, val3;
   string abc;

   cin >> val1 >> val2 >> val3;
   cin >> abc;

   int arr[3];
   sortABC(arr, abc, val1, val2, val3);
   cout << arr[0] << " " << arr[1] << " " << arr[2];

   return 0;
}

int findLowest(int val1, int val2, int val3)
{
   int lowest = val1;

   if (lowest > val2) lowest = val2;
   if (lowest > val3) lowest = val3;

   return lowest;
}

int findMiddle(int val1, int val2, int val3)
{
   int lowest = findLowest(val1, val2, val3);
   int highest = findHighest(val1, val2, val3);

   int sum = val1 + val2 + val3;

   return sum - (lowest + highest);
}

int findHighest(int val1, int val2, int val3)
{
   int highest = val1;

   if (highest < val2) highest = val2;
   if (highest < val3) highest = val3;

   return highest;
}

void sortABC(int arr[], string abc, int val1, int val2, int val3)
{
   if (abc.at(0) == 'A')
      arr[0] = findLowest(val1, val2, val3);
   else if (abc.at(0) == 'B')
      arr[0] = findMiddle(val1, val2, val3);
   else
      arr[0] = findHighest(val1, val2, val3);

   if (abc.at(1) == 'A')
      arr[1] = findLowest(val1, val2, val3);
   else if (abc.at(1) == 'B')
      arr[1] = findMiddle(val1, val2, val3);
   else
      arr[1] = findHighest(val1, val2, val3);

   if (abc.at(2) == 'A')
      arr[2] = findLowest(val1, val2, val3);
   else if (abc.at(2) == 'B')
      arr[2] = findMiddle(val1, val2, val3);
   else
      arr[2] = findHighest(val1, val2, val3);
}
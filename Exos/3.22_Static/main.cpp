/*
 * A static member variable is associated with a class, and not specific
 * to an object.
 * There is only one copy, shared with all the objects.
 * The static variable needs to be declared in the class declaration
 * and defined (memory is allocated) outside of the class declaration.
 * A simple rule is to put the definition in the className.cpp, if it
 * exists.
 * A static member function allows us to access a static member
 * variable even if no object exists. It is called from the class,
 * ex: Tree::getTreeCountStatic().
 * It can also be called from an object, ex: t1.getTreeCountStatic().
 *
 * A static member function is not allowed to access an instance member
 * variable.
 * A regular member function can access a static member variable.
 */

#include <iostream>

using namespace std;

class Tree
{
private:
   static int treeCount;
   int type;
   static string descr[3];
public:
   Tree(int typeVal)
   {
      type = typeVal;
      treeCount++;
   }
   static int getTreeCountStatic()
   {
      return treeCount;
   }
   int getTreeCount() const
   {
      return treeCount;
   }
   string getDescr(int type) const
   {
      return descr[type];
   }
   static void printDescr()
   {
      for (int i = 0; i < 3; i++)
         cout << i << ": " << descr[i] << endl;
   }
};

int Tree::treeCount = 0;
string Tree::descr[] = {"Firs", "Pine", "Oak"};

int main()
{
   cout << "Get treeCount, using static member function from a class:" << Tree::getTreeCountStatic() << endl;

   Tree t1(0), t2(1);
   cout << "Get treeCount, using a regular member function:" << t1.getTreeCount() << endl;
   cout << "Get treeCount, using static member function from an object:" << t1.getTreeCountStatic() << endl;

   cout << "Description of types of trees" << endl;
   Tree::printDescr();

   cout << endl << t1.getDescr(0);

   return 0;
}
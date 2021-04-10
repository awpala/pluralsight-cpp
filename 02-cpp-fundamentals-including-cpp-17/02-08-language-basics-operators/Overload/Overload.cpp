#include "Person.h"
#include <iostream>
using std::cout;
using std::endl;

int main()
{
  Person p1("Kate", "Gregory", 123);
  Person p2("Someone", "Else", 456);
  cout << "p1 is ";
  if (!(p1 < p2)) // uses overloaded `<` of class `Person`
    cout << "not ";
  cout << "less than p2" << endl;

  cout << "p1 is ";
  if (!(p1 < 300)) // uses overloaded `<` of class `Person`
    cout << "not ";
  cout << "less than 300" << endl;

  cout << "300 is ";
  if (!(300 < p1)) // uses overloaded `<` of class `Person`
    cout << "not ";
  cout << "less than p1" << endl;

  return 0;
}

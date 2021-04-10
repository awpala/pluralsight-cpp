#include <iostream>
#include "Person.h"

using std::string;

int main()
{
  Person p1("Kate", "Gregory", 123);
  Person p2; // initialized via default constructor

  string name = p1.getName();
  std::cout << "p1's name is " << name << std::endl;

  return 0;
}

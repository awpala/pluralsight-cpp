#include "Person.h"
#include <iostream>


Person::Person(std::string first, std::string last,
  int arbitrary) : firstname(first), lastname(last),
  arbitrarynumber(arbitrary)
{
  std::cout << "constructing " << getName() << std::endl;
}
Person::Person() : arbitrarynumber(0)
{
  std::cout << "constructing " << getName() << std::endl;
}

Person::~Person()
{
  std::cout << "destructing " << getName() << std::endl;
}

std::string Person::getName()
{
  return firstname + " " + lastname;
}

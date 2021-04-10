#include "Person.h"
#include <iostream>


Person::Person(std::string first, std::string last,
  int arbitrary) : firstname(first), lastname(last),
  arbitrarynumber(arbitrary)
{
}

std::string Person::getName()
{
  return firstname + " " + lastname;
}

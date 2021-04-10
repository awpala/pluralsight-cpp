#include "Person.h"
using std::string;

Person::Person(string first,string last, int arbitrary) 
  : firstname(first),lastname(last), arbitrarynumber(arbitrary)
{
}

Person::~Person()
{
}

string Person::GetName() const
{
  return firstname + " " + lastname;
}

bool Person::operator<(Person const& p) const
{
  return arbitrarynumber < p.arbitrarynumber;
}

bool Person::operator<(int i) const
{
  return arbitrarynumber < i;
}

// free function
bool operator<(int i, Person const& p) 
{
  return i < p.GetNumber(); // calls `public` function `GetNumber()` of class `Person` (i.e., cannot access `p.arbitrarynumber` directly)
}

// bool operator<(int i, Person const& p) 
// {
//   return i < p.arbitrarynumber; // if declared as `friend` within class `Person`, `operator<()` can access member variables directly (e.g., `p.arbitrarynumber`)
// }

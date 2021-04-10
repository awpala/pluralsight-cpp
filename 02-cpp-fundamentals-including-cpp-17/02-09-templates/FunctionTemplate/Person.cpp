#include "Person.h"

using namespace std;

Person::Person(string first,string last,
  int arbitrary) : firstname(first),lastname(last),
  arbitrarynumber(arbitrary)
{
}

Person::~Person()
{
}

string Person::GetName()
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

bool operator<(int i, Person const& p)
{
  return i < p.arbitrarynumber;
}

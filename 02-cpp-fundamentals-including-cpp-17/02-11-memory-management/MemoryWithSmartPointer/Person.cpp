
#include "Person.h"

using namespace std;

Person::Person(string first,string last, int arbitrary)
	: firstname(first),lastname(last), arbitrarynumber(arbitrary)
{
}

string Person::GetName() const
{
  return firstname + " " + lastname;
}

void Person::AddResource()
{
  pResource.reset(); // the method `reset()` handles the case where `AddResource()` is called twice (or more) without a corresponding intermediate `delete` to destroy the first one
  pResource = std::make_shared<Resource>("Resource for " + GetName()); // `std::make_shared()` performs the equiavelnt of `new` for a raw pointer (N.B. there is also a corresponding `std::make_unique()` for `unique_ptr`)
}

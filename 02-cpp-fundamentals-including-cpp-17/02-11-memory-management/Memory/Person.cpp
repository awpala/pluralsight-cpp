#include "Person.h"

using namespace std;

Person::Person(string first,string last, int arbitrary)
	: firstname(first),lastname(last), arbitrarynumber(arbitrary), pResource(nullptr) // N.B. initialize `pResource` to `nullptr` (i.e., object has no resource by default) for safety
{
}

Person::~Person()
{
  delete pResource; // destructor deletes `pResource` when `Person` object goes out of scope to prevent memory leak (N.B. recall that calling `delete` on `nullptr` is safe/harmless)
}

string Person::GetName() const
{
  return firstname + " " + lastname;
}


void Person::AddResource()
{
  delete pResource; // this guard condition is necessary to prevent a memory leak if `AddResource()` is called multiple times (cf. `Memory.cpp`) -- N.B. It is safe to call `delete` on `nullptr`
  pResource=new Resource("Resource for " + GetName());
}

Person::Person(Person const & p)
{
  pResource = new Resource(p.pResource->GetName()); // creates a new, independent copy of the `Resource` object on the free store
}

Person& Person::operator=(const Person& p) // N.B. this copy assignment constructor is not a robust implementation, as it does not cover the scenario of `Kate = Kate;` (i.e., guarding against self-assignment); for simplicity, `Memory.cpp` does not attempt self-assignment
{
  delete pResource;
  pResource = new Resource(p.pResource->GetName());
  return *this;
}

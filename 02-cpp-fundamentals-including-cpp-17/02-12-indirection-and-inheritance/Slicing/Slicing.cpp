#include "Person.h"
#include "Tweeter.h"
#include <iostream>
using std::cout;
using std::endl;
#include <memory>
using std::shared_ptr;
using std::make_shared;

int Dummy(Person const& p) { return p.GetNumber(); } // declaring the parameter `const&` prevents slicing from occurring if passed a reference to a derived class instance

int main()
{
  Person Kate ("Kate", "Gregory",456); // base class instance
  Tweeter KateGregcons ("Twitter","User",567,"@gregcons"); // derived class instance


  //Person* Someone = new Tweeter("Someone", "Else", 567, "@someone");
  //cout << Someone->GetName() << endl;
  //delete Someone;

	// below are equivalent to the previous group of statements
  shared_ptr<Person> spKate = make_shared<Tweeter>("Third", "Name", 678, "@handle");
  cout << spKate->GetName() << endl; // correctly calls the derived class (`Twitter`) version of `GetName()` despite being called by a base class (`Person`) pointer


  //KateGregcons = Kate; // error -- cannot copy a base class (`Person`) object to a derived class (`Tweeter`) object (`Person` does not have a `twitterhandle` value)

  Kate = KateGregcons; // copying a derived class (`Twitter`) object to a base class (`Person`) object is permissible -- however, there is slicing (i.e., of `twitterhandle` from the former)
  cout << Kate.GetName() << endl;


  int x;
  x = Dummy(Kate); // returns `567` via `Person::GetNumber()`
  x = Dummy(KateGregcons); // returns `0` via `Tweeter::GetNumber()` (i.e., the expected polymorphic behavior) -- slicing is prevented here by making `Dummy()` receive its argument by reference rather than by value (which would cause `Person::GetNumber()` to be called inside of `Dummy()` instead due to copying)

  return 0;
}

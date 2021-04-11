#include "Person.h"
#include "Tweeter.h"
#include <iostream>

using std::cout;
using std::endl;

int main()
{
  Person Kate("Kate", "Gregory",456); // base class instance
  Person& rKate = Kate;
  Person* pKate = &Kate;

  Tweeter KateGregcons ("Kate","Gregory",567,"@gregcons"); // derived class instance
  Person* pKateGregcons = &KateGregcons; // base class indirection
  Person& rpKateGregcons = KateGregcons; // base class indirection
  Tweeter& rtKateGregcons = KateGregcons; // derived class indirection

	// accessing the base class instance
  cout << rKate.GetName() << endl;
  cout << pKate->GetName() << endl;

	cout << endl;

	// accessing the derived class instance
  cout << KateGregcons.GetName() << endl; 
  cout << rpKateGregcons.GetName() << endl; // `GetName()` must be `virtual` to call the derived class version of the function here
  cout << rtKateGregcons.GetName() << endl;
  cout << pKateGregcons->GetName() << endl; // `GetName()` must be `virtual` to call the derived class version of the function here

	cout << endl;

	// example with a raw-pointer instance
  Person* Someone = new Tweeter("Someone", "Else", 567, "@someone"); // derived class (`Tweeter`) object pointed to by base class (`Person`) pointer variable
  cout << Someone->GetName() << endl; // `GetName()` must be `virtual` to call the derived class version of the function here
  delete Someone; // destructor of `Person` must be `virtual` to ensure this derived class instance performs appropariate cleanup when it goes out of scope

  return 0;
}

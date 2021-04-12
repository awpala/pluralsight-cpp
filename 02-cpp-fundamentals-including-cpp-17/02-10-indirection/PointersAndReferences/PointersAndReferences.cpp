#include <string>
using std::string;
#include <iostream>
using std::cout;
using std::endl;

#include "Person.h"


int main()
{
  /* references */
  int a = 3;
  cout << "a is " << a << endl;
  int& rA = a; // reference to `a` -- when declaring a reference, it must be initialized to a value
  rA = 5; // equivalent to `a = 5;`
  cout << "a is " << a << endl;

  Person Kate("Kate", "Gregory", 234);
  Person& rKate = Kate;
  rKate.SetNumber(345);
  cout << "rKate: " << rKate.GetName() << " " << rKate.GetNumber() << endl;

  // The following statements are invalid -- cannot declare a reference without initializing its value
  //int& badReference;
  //badReference = 3;
  //cout << badReference;

  cout << endl;


  /* pointers */
  int* pA = &a; // pointer to `a`
  *pA = 4; // equivalent to `a = 4`, but assigned using indirection via `*`
  cout << "a is " << a << endl;
  int b = 100;
  pA = &b; // unlike references (which are fixed), a pointer can be reassigned to a new value (of compatible type, e.g., `int` in this statements)
  (*pA)++; // increments the value of `b`, while `a` remains unchanged (`pA` no longer points to `a`)
  cout << "a " << a << ", *pA " << *pA << endl; 

  Person* pKate = &Kate;
  (*pKate).SetNumber(235); // access member of object via `.`, dereference pointer to object via `*`
  pKate->SetNumber(236); // `->` is equivalent to `(*...).`
  cout << "Kate: " << Kate.GetName() << " " << Kate.GetNumber() << endl;
  cout << "pKate: " << pKate->GetName() << " " << pKate->GetNumber() << endl;

  // The following statements are valid but a bad practice
  // int* badPointer; // pointer is declared but not initialized
  // *badPointer = 3; // assigning to unknown memory location -- bad!
  // cout << *badPointer << endl; 

  // The following statements are a safer alternative to the previous statements
  int* badPointer = nullptr; // initialize to keyword `nullptr` to avoid unsafe access to arbirary memory upon declaring the pointer
  if (badPointer) // guard condition will prevent statements from executing (`nullptr` is evaluated as `false`)
  {
    *badPointer = 3;
    cout << *badPointer << endl;
  }

  return 0;
}

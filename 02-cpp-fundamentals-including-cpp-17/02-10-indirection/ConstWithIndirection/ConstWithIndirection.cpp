#include "Person.h"


int main()
{
  int i = 3;
  int j = 10;
  Person Kate("Kate", "Gregory", 234);

  int* pI = &i; // pointer to an `int`
  // int* pII = &pI; // error -- cannot initialize an `int` pointer (i.e., type `int*`) with a dereferenced `int` pointer (i.e., type `int**`) since the types are not compatible (this is an example of type safety in the context of pointers/indirection)
  // pI = &Kate; // error -- similarly, cannot assign type `Person*` to a pointer of type `int*`
  
  int const * pcI = pI; // pointer to a `const`
  //*pcI = 4; // error -- cannot change the value of target `pI`
  pcI = &j; // okay to change the value of `pcI`, however (i.e., to a target/different reference)
  j = *pcI; // okay to dereference `pcI` to read its value

  int * const cpI = pI; // `const` pointer
  *cpI = 4; // okay to assign a new value to the target
  // cpI = &j; // error -- cannot change the reference of a `const` pointer after its initial declaration

  int const * const crazy = pI; // `const` pointer to a `const`
  //*crazy = 4; // error -- cannot change the value of the `const` target
  //crazy = &j; // error -- cannot change the reference of the `const` pointer
  j = *crazy; // okay to dereference `crazy` to read its value

  return 0;
}

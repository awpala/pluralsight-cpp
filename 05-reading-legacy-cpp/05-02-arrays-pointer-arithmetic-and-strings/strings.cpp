#include <cstring>
#include <string>

int main()
{
  char const* s1 = "Hello"; // due to C++'s C-compatible heritage, a string literal can be used to initialize an array of type `char*` (which includes allocating the terminal `'\0'`)
  int i = strlen(s1);

  char* s2 = new char[strlen(s1) + strlen(" Kate")]; // dynamic C-style array
  strcpy(s2, s1); // copies `s1` into `s2`
  strcat(s2, " Kate"); // concatenates `s2` and `"Kate"` -- however, `s2` was not allocated with sufficient size to hold the terminal `'\0'`, so `strcat()` writes the terminal `'\0'` into unrelated memory on the free store (bad!)

  char c = s2[10]; // array access via `[...]`

  char hello[] = { ' ','w', 'o','r','l','d' }; // initialization with an array of `char`s -- however, forgot to include terminating `'\0'`
  size_t j = strlen(hello); // `strlen()` returns the count up to when `'\0'` is next encountered in (free-store) memory
  
  char better[] = "better"; // initialization with a string literal is a better approach, because the terminating `'\0'` is included automatically by the compiler 
  int k = strlen(better); // correctly counts `6`

  //mix and match new and old
  std::string s(s1); // convert C-style string `s1` to a `std::string` object `s` -- the latter much safer and easier to use!
  s += " modern C++"; // concatenation via overloaded operator `+=`
  char* s3 = new char[s.length() + 1]; // `s` is "size-aware" via method `length()`
  // s3 = s; // invalid -- `s3` is a pointer to `char`, whereas `s` is a `std::string` object
  // s3 = s.c_str(); // invalid -- C-style strings (i.e., `s.c_str()`) have type `const char*` and cannot be assigned to non-`const` pointer (`const char* s4 = s.c_str();` would be valid, however)
  strcpy(s3, s.c_str()); // method `c_str()` converts `std::string` object back to a C-style string

  // manual cleanup required for C-style arrays
  delete[] s2;
  delete[] s3;

  return 0;
} // no need to delete `s` (a `std::string` object) -- it automatically cleans itself up once it goes out of scope

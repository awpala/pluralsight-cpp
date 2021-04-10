// VariablesAndTypes.cpp : Defines the entry point for the console application.

#include <iostream>

int main()
{
	// alternative forms of integer declarations
  int i1 = 1; // simultaneous declaration and initialization
  std::cout << "i1= " << i1 << std::endl;
  int i2; // declare variable first -- variable is uninitialized (i.e., has "garbage" data/contents)
  i2 = 2; // then assign a value 
  std::cout << "i2= " << i2 << std::endl;
  int i3(3); // initialize via (...)
  std::cout << "i3= " << i3 << std::endl;
  int i4{ 4 }; // initialize via {...}
  std::cout << "i4= " << i4 << std::endl;

	std::cout << std::endl; // N.B. line break to separate sections in console output

	// declarations of doubles
  double d1 = 2.2; 
  double d2 = i1; // if initializing a double with an int, there is no loss of precision
  int i5 = d1; // conversely, initializing an int with a double will cause a loss of precision (i.e., truncation of the fractional part)
  std::cout << "d1= " << d1 << std::endl;
  std::cout << "d2= " << d2 << std::endl;
  std::cout << "i5= " << i5 << std::endl;

	std::cout << std::endl;

	// declarations of chars
	char c1 = 'a';
  // char c2 = "b"; // this is an error -- "..." represents a string literal, not a single character (i.e., '...'); furthermore, there is no conversion performed by the compiler, but rather an error is generated
  std::cout << "c1= " << c1 << std::endl;

	std::cout << std::endl;

	// declarations of bools
	bool flag = false; // `false` represents the integer value `0`
  std::cout << "flag= " << flag << std::endl;
  flag =  i1; // any non-zero number assigned to a bool is converted to `true`/`1`
  std::cout << "flag= " << flag << std::endl;
  flag =  d1;
  std::cout << "flag= " << flag << std::endl;

	std::cout << std::endl;

	// declarations via `auto`
	auto a1 = 1; // int
  auto a2 = 2.2; // double (N.B. by design, the compiler deduces a double from a floating-point literal, i.e., rather than float)
  auto a2f = 2.2f; // float -- appending `f` produces a float literal
	auto a3 = 'c'; // char
  auto a4 = "s"; // const char* (a C-style string, i.e., the two-character array ['s', '\0'] with null terminator '\0') -- N.B. this is distinct from the C++ std::string data type
  auto a5 = true; // bool
  auto a6 = 3L; // long -- appending 'L' (or 'l', i.e., "ell") produces a long literal
  auto a7 = 1'000'000'000'000; // long (inferred based on size of the integer literal) -- N.B. C++14 and later supports `'` as a separator in an integer literal at arbitrary positions (it is ignored by the compiler)
  auto a8 = 0xFF; // decimal integer 255 -- prefix `0x` (or `0X`) denotes a hexadecimal integer
  auto a9 = 0b111; // decimal integer 7 -- prefix `0b` (or `0B`) denotes an octal integer (as of C++14 and later)

	a1 = a2; // this will generate a warning due to conversion from double to int

	// using chars
	unsigned char n1 = 128; // okay -- unsigned char holds integers between 0 and 255
  char n2 = 128; // signed char cannot hold 128, its acceptable values range from -127 to 127 (i.e., assigning outside of this range results in overflow/underflow)
  std::cout << "n1= " << n1 << std::endl;
  std::cout << "n2= " << n2 << std::endl;
  n1 = 254;
  n2 = 254; // overflows
  std::cout << "n1= " << n1 << std::endl;
  std::cout << "n2= " << n2 << std::endl;
  n1 = 300; // overflows
  n2 = 300; // overflows
  std::cout << "n1= " << n1 << std::endl;
  std::cout << "n2= " << n2 << std::endl;

	// N.B. As above lines demonstrate, use chars for their intended purpose (e.g., to store ASCII characters); if you want to store larger numbers, use another more appropriate integer type instead

  return 0;
}

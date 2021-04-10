#include <string>

class Person
{
private:
  std::string firstname;
  std::string lastname;
  int arbitrarynumber;

public:
  Person(std::string first, std::string last, int arbitrary); // this constructor definition eliminates the default constructor provided by the compiler
  Person()=default; // a user-defined default constructor can also be additionally provided (i.e., overloaded); additionally, using `=default` will instruct the compiler to automatically create the default constructor
  std::string getName();
};

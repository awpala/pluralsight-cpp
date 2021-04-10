#include <string>

class Person
{
private:
  std::string firstname;
  std::string lastname;
  int arbitrarynumber;

public:
  Person(std::string first, std::string last, int arbitrary);
  Person(); // N.B. user-defined default constructor (i.e., rather than using compiler-provided =default)
  ~Person(); // destructor, denoted via `~`
  std::string getName();
};

#include <string>
// N.B. `using` statements are generally ill-advised in header files, as this can create ambiguity in the other files that use the header

class Person
{
private:
  std::string firstname;
  std::string lastname;
  int arbitrarynumber;

public:
  Person(std::string first, std::string last, int arbitrary);
  Person();
  ~Person();
  std::string getName();
};

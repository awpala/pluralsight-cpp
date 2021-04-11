#pragma once
#include <string>

class Person
{
private:
  std::string firstname;
  std::string lastname;
  int arbitrarynumber;

public:
  Person(std::string first, std::string last, int arbitrary);
  virtual ~Person(); // `virtual` destructor ensures that `Tweeter` instances pointed to by `Person` pointers perform proper cleanup when the `Tweeter` instance goes out of scope
  virtual std::string GetName() const; // `virtual` function -- allows for `Tweeter` instances pointing to by `Person` pointers to call `Tweeter`'s overload of this function
  int GetNumber() const {return arbitrarynumber;}
  void SetNumber(int number) {arbitrarynumber = number;}
  void SetFirstName(std::string first) {firstname = first;}
};

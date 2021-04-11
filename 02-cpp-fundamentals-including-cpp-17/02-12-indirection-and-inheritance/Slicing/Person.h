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
  virtual ~Person();
  virtual std::string GetName() const;
  virtual int GetNumber() const {return arbitrarynumber;} // base class member function `GetNumber()` is marked both `const` and `virtual`
  void SetNumber(int number) {arbitrarynumber = number;}
  void SetFirstName(std::string first) {firstname = first;}
};

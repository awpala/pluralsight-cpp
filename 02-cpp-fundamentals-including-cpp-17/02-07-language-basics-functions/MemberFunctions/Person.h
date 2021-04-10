#pragma once
#include <string>
class Person
{
private:
  std::string firstname;
  std::string lastname;
  int arbitrarynumber;

public:
  Person(std::string first,
    std::string last,
    int arbitrary);
  ~Person();
  std::string GetName() const;
  int GetNumber() const {return arbitrarynumber;} // function is implemented "inline"
  void SetNumber(int number) {arbitrarynumber = number;} // function is implemented "inline" (N.B. `void` indicates no value is returned)
};

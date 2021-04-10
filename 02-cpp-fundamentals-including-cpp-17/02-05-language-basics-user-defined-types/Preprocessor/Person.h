#pragma once // prevents multiple inclusions of this header file (which is included in both `Preprocessor.cpp` and `Tweeter.h`)
#include <string>

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

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
  Person();
  std::string GetName() const { return firstname + " " + lastname; }
  int GetNum() const { return arbitrarynumber; }
};

#pragma once
#include "Person.h"
#include <string>

class Tweeter :
  public Person
{
private:
  std::string twitterhandle;
public:
  Tweeter(std::string first,
    std::string last,
    int arbitrary,
    std::string handle);
  ~Tweeter(void);
  std::string GetName() const;
  int GetNumber() const { return 0; } // override of base class function `GetNumber()`
};

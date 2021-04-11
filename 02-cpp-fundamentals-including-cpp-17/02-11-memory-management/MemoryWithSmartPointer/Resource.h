#pragma once
#include <string>

class Resource
{
private:
  std::string name;
public:
  Resource(std::string n);
  ~Resource(void);
  std::string GetName() const {return name;}
};

#pragma once
#include <string>

class Resource
{
private:
  std::string name;
public:
  Resource(std::string n);
  //Resource(const Resource& r);
  //Resource& operator=(const Resource& r);
  //Resource(Resource&& r); // move constructor
  //Resource& operator=(Resource&& r); // move assignment operator
  //~Resource(void);

	// comparison operators for algorithm functions using iterator
  bool operator>(const Resource& r) { return name > r.name; }
  bool operator<(const Resource& r) { return name < r.name; }
  bool operator==(const Resource& r) { return name == r.name; }

  std::string GetName() const { return name; }
};

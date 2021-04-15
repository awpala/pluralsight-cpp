#pragma once
#include <string>

class Resource
{
private:
  std::string name;
public:
  Resource(std::string n);

  /*
  N.B. The below constructors are not needed in this particular example for
  the speedup/optimization of moving, because its `std::string` member (`name`)
  already performs this optimization; however, they are shown here for
  completeness and to demonstrate move semantics explicitly
  */
  Resource(const Resource& r);
  Resource& operator=(const Resource& r);
  Resource(Resource&& r); // move constructor
  Resource& operator=(Resource&& r); // move assignment operator
  ~Resource(void);

	// comparison operators for algorithm functions using iterator
  bool operator>(const Resource& r) { return name > r.name; }
  bool operator<(const Resource& r) { return name < r.name; }
  bool operator==(const Resource& r) { return name == r.name; }

  std::string GetName() const { return name; }
};

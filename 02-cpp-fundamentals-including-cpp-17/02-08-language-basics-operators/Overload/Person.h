#include <string>
class Person
{
private:
  std::string firstname;
  std::string lastname;
  int arbitrarynumber;

	// Alternatively to using the free function outside of the class declaration, can also declare `operator<()` to be `friend` within the class declaration
	// friend bool operator<(int i, Person const& p);

public:
  Person(std::string first, std::string last, int arbitrary);
  ~Person();
  std::string GetName() const;
  int GetNumber() const {return arbitrarynumber;}
  void SetNumber(int number) {arbitrarynumber = number;}

	// overloaded operator `<` as member functions
  bool operator<(Person const& p) const;
  bool operator<(int i) const;
};

// overloaded operator `<` as free function
bool operator<(int i, Person const& p);

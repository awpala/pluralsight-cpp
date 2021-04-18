// Demo: Vector of Custom Objects

#include <iostream>
using std::cout;
#include <string>
using std::string;
#include <vector>
using std::vector;


class Person {
public:
  Person() = default;

  Person(const string& name, int age)
    : m_name(name), m_age(age)
  {}

  const string& Name() const {
    return m_name;
  }

  int Age() const {
    return m_age;
  }

  void SayHi() const {
    cout << " Hi! My name is " << m_name 
        << ", and I'm " << m_age << " years old. \n";
  }

private:
  string m_name{};
  int m_age{};
};


int main() {
  vector<Person> persons { 
    {"Connie", 30}, 
    {"Rita", 10}, 
    {"Monna Lisa", 516} 
  };

  persons.push_back(Person{"John", 40});

  for (const auto& p : persons) { // using `const` reference to read/observe each `Person` object `p` prevents unnecessary expensive copies (i.e., reads the original vector's elements instead)
    p.SayHi();
  }

  return 0;
}

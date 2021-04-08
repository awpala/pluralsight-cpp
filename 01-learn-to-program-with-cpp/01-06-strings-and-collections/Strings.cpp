#include <iostream>
using std::cout;
using std::cin;

#include <string>
using std::string;

int main()
{
  // using operators with strings
  string name;
  cout << "who are you? ";
  cin >> name;
  string greeting = "Hello, " + name;
  if (name == "Kate")
  {
    greeting += ", I know you!";
  }
  cout << greeting << '\n';

  // using string methods
  int l = greeting.length();
  cout << "\"" + greeting + "\" is " << l << " characters long." << '\n';
  string beginning = greeting.substr(greeting.find(' ') + 1); // common idiom: nested member function calls
  cout << beginning << '\n';
  if (beginning == name)
  {
    cout << "expected result." << '\n';
  }

  return 0;
}

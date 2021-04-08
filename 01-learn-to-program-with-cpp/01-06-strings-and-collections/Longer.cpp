#include <iostream>
using std::cout;
using std::cin;

#include <string>
using std::string;

int main()
{
  string phrase1;
  string phrase2;

  cout << "Enter a phrase: ";
  getline(cin, phrase1); // N.B. function `getline` allows to read entire lines (cf. `cin <<` would parse input `hello world` as two strings, rather than a single string)

  cout << "Enter another phrase: ";
  getline(cin, phrase2);

  if (phrase1.length() == phrase2.length())
  {
    cout << "They are the same length." << '\n';
  }

  if (phrase1.length() > phrase2.length())
  {
    cout << "The first phrase is longer." << '\n';
  }

  if (phrase1.length() < phrase2.length())
  {
    cout << "The second phrase is longer." << '\n';
  }

  return 0;
}

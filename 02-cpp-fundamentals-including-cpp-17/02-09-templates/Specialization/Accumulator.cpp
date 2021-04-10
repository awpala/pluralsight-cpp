#include <string>
using std::string;
#include <iostream>
using std::cout;
using std::endl;
#include "Person.h"
#include "Accum.h"


int main()
{
  Accum<Person> people(0);
  Person p1("Kate", "Gregory", 123);
  Person p2("Someone", "Else", 456);
  people += p1;
  people += p2;
  cout << people.GetTotal() << endl;

  return 0;
}

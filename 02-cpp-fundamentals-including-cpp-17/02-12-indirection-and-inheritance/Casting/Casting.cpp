#include "Person.h"
#include "Tweeter.h"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include "Resource.h" // N.B. `Resource` is a separate class from the inheritance hierarchy of `Person`-`Tweeter`

int main()
{
  /* `static_cast` example */
  Tweeter t("Kate","Gregory",123,"@gregcons");
  Person* p = &t;
  // Tweeter* pt = (Tweeter*)p; // C-style cast -- not recommended, use templated cast instead
  Tweeter* pt = static_cast<Tweeter*>(p); // templated cast to `Tweeter` pointer 
  cout << pt->GetName() << endl;

  //int i = 3;
  //Tweeter* pi = static_cast<Tweeter*>(&i); // `static_cast` provides type safety -- it will not simply permit any arbitrary casting (e.g., from `int*` to `Tweeter*`, which is nonsensical)

  cout << endl;


  /* `dynamic_cast` example */
  Resource r("local");
  Tweeter* pt2;
  cout << "Use Resource (r) or Tweeter (t)? ";
  std::string answer;
  std::cin >> answer;

  if (answer == "r")
  {
    pt2 = dynamic_cast<Tweeter*>(&r); // results in assignment of `nullptr` to `p2`, since the cast cannot be performed (because `Resource` is not in an inheritance hierarchy with `Tweeter`)
  }
  else
  {
    pt2 = dynamic_cast<Tweeter*>(p);
  }

  if (pt2)
  {
    cout << pt2->GetName() << endl; // calls `Tweeter::GetName()`
  }
  else
  {
    cout << "pointer Resource* cannot be cast to pointer Tweeter*" << endl;
  }

  return 0;
}

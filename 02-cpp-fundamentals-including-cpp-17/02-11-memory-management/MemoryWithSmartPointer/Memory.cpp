#include "Person.h"
#include <string>
using std::string;

int Dummy(Person p) { return p.GetNumber(); }

int main()
{
  {
    Person Kate("Kate", "Gregory", 345);
    Kate.AddResource();
    string s1 = Kate.GetResourceName();
    Kate.AddResource(); // The smart pointer member `Kate.pResource` handles cleanup of the old resource (i.e., without explicit `delete`)

    Person Kate2 = Kate; // initialization causes a copy to occur -- this causes the `shared_ptr` reference count to increase to 2
    Kate = Kate2; // assignment causes a copy to occur -- the reference count remains 2, since there is no net difference resulting from this assignment operation
    int j = Dummy(Kate2); // `Kate2` is passed by value, which also causes a copy to occur -- this correspondingly increases the reference count to increase to 3 immediately prior to the function call to `Dummy()`, but then the reference count decreases back to 2 upon return from the function call since the copied object is destroyed after going out of the function's scope
  } // `Kate` and `Kate2` go out of scope here, with cleanup of their respective `pResource` members performed automatically (thereby preventing any potential memory leaks)
  return 0;
}

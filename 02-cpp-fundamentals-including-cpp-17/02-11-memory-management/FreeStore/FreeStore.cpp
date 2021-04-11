#include "Resource.h"
#include <string>
using std::string;

int main()
{
  {
    Resource localResource ("local"); // `localResource` is scoped locally (i.e., stack-based)
    string localString = localResource.GetName();
  } // `localResource` goes out of scope here, and its destructor is called
  

	Resource* pResource = new Resource("created with new"); // pResource points to `Resource` object created on the free store via operator `new`
  string newString = pResource->GetName();
	// delete pResource; // runs destructor and releases memory on the free store
	// string string3 = pResource->GetName(); // error -- cannot use member function `GetName()` on a destroyed object

  // int j = 3;
  // if (j == 3)
  // {
  //   return 0; // if `delete pResource;` is not run preior to exiting `main()`, then the memory is not released -- this causes a memory leak (bad)!
  // }


  Resource* p2 = pResource; // creates a copy of the pointer (not the object itself), i.e., mutual references to the same object on the free store

  delete pResource;
  pResource = nullptr; // it is a best practice to assign to `nullptr` after deletion to prevent "dangling pointers"
  //string string2 = p2->GetName(); // error -- cannot access deleted object
  delete pResource; // N.B. it is safe to call `delete` on a `nullptr` albeit non-sensical (conversely, without resetting `pResource` to `nullptr`, this subsequent `delete pResource;` would cause an error)
  // delete p2; // error -- object has already been deleted

  return 0;
}

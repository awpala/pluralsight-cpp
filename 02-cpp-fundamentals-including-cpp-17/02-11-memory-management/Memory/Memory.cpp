#include "Person.h"

int main()
{
  Person Kate("Kate", "Gregory", 345);
  Kate.AddResource();
  Kate.SetFirstName("Kate2");
  Kate.AddResource(); // creates a new resource, but `AddResource()` must manage/delete the previously allocated resource on the free store in order to prevent a memory leak
  
	Person Kate2 = Kate; // per Rule of 3, a copy constructor and copy assignment constructor are required if a destructor is defined (otherwise, when `Kate2` goes out of scope, it will attempt to "delete again" when `Kate` goes out of scope and calls its own destructor)

  return 0;
} // `Kate` and `Kate2`	go out of scope here

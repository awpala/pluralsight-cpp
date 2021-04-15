#include <iostream>
using std::cout;
using std::endl;
#include <vector>
using std::vector;
using std::begin;
using std::end;
#include <algorithm>
using std::for_each;
#include <string>
using std::string;
using std::to_string;
#include <memory>
using std::unique_ptr;
using std::make_unique;

#include "Resource.h"


int main()
{
  //capturing by value and reference explicitly  [x,y,&message]
  vector nums { 2,3,4,-1,1 };
  int x = 3;
  int y = 7;
  string message = "elements between ";
  message += to_string(x) + " and " + to_string(y) + " inclusive: " ;
  for_each(begin(nums), end(nums), 
    [x,y, &message](int n) // anonymous lambda -- N.B. In this context, the anonymous lambda is serving as the "predicate" to function `for_each`
    {
      if (n >= x && n <= y)
        message += " " + to_string(n);
    });
  cout << message << endl;

  cout << endl;


  ///////////////////

  x = y = 0;
  cout << "before `for_each`: "
    << "x = " << x << " "
    << "y = " << y << endl;

  //x by value, rest by ref
  for_each(begin(nums), end(nums), 
    [&, x](int element) mutable // `mutable` indicates that the captured values can be changed
    {
      x += element; // N.B. `mutable` is required to perform this operation since `x` is captured by value, otherwise the compiler generates an error
      y += element;
    });

  cout << "after `for_each`:  "
    << "x = " << x << " "
    << "y = " << y << endl;

  cout << endl;


  ///////////////////

  { //braces for scope
    auto pResource = make_unique<Resource>(", ");
    string newMessage = "";

    cout << "before lambda with move capture..." << endl;

    for_each(begin(nums), end(nums),
    [=, &newMessage, p=std::move(pResource)](int n) // move capture (introduced in C++14) via `std::move` transfers ownership `pResource` to the lambda when `pResource` goes out of scope in the caller
    {
      if (n >= x && n <= y)
        newMessage += p->GetName() + to_string(n);
    }); // `pResource` is out of scope here if move capture is used -- and should not be used subsequently by the caller!

    cout << "after lambda with move capture..." << endl;
    cout << "`newMessage` via `for_each`: " << newMessage << endl;

    // `pResource` is not out of scope yet here if move capture is not used
  } // `pResource` goes out of scope here if move capture is not used -- therefore, if `pResource` were captured by reference (i.e., `&pResource`) instead of using a move capture (i.e., `p=std::move(pResource)`), it would create a dangling reference in the resulting lambda object

  return 0;
}

#include <vector>
using std::vector;
#include <iostream>
using std::cout;
#include <exception>
using std::exception;
using std::out_of_range;

int main()
{
  vector<int> v;
  v.push_back(1);
  try
  {
    int j = v.at(99); // attempt to assign out of range
  }
  catch (out_of_range & e) // `std::out_of_range` inherits from `std::exception`
  {
    cout << " out of range exception " << e.what(); // member function `what()` prints the compiler-generated error message
  }
  catch (exception &  e)
  {
    cout << e.what();
  }
  return 0;
}

#include <vector>
using std::vector;
#include <string>
using std::string;
#include <algorithm>
using std::find;
using std::find_if;


int main()
{
  vector<int> v{  4, 6, 6, 1, 3, -2, 0, 11, 2, 3, 2, 4, 4, 2, 4 };
  string s{ "Hello I am a sentence" };

  /* `std::find() */

  //find the first zero in the collection
  auto result = find(begin(v), end(v), 0);
  int weLookedFor = *result; // use operator `*` to access the value of the returned iterator

  //find the first 2 after that zero
  result = find(result, end(v), 2); // search beginning from `result` of previous call to `std::find()`
  if (result != end(v)) // using guard condition to prevent dereferencing an invalid iterator
  {
    weLookedFor = *result;
  }

  //find the first `a`
  auto letter = find(begin(s), end(s), 'a');
  char a = *letter;


  /* `std::find_if() */

  //find first odd value
  result = find_if(begin(v), end(v), [](auto elem) {return elem % 2 != 0; });
  weLookedFor = *result;

  //find first even value
  result = find_if_not(begin(v), end(v), [](auto elem) {return elem % 2 != 0; });
  weLookedFor = *result;

  return 0;
}

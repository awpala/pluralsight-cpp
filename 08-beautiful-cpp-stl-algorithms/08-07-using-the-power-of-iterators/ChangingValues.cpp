#include <vector>
using std::vector;
#include <algorithm>
using std::transform;
using std::copy_if;
using std::unique_copy;
using std::reverse_copy;
#include <numeric>
using std::iota;
#include <iterator>
using std::back_inserter;
#include <string>
using std::string;


int main()
{
  vector<int> v1(10);
  iota(begin(v1), end(v1), 1);

  // with inserting iterators (e.g., `std::back_inserter()`), no need to pre-allocate the size of the `std::vector` object; 
  // compare the following examples to the previous similar demos (cf. Section 6)
  vector<int> v2;
  v2.clear();
  transform(begin(v1), end(v1), back_inserter(v2), // no need to pre-allocate `v2`'s size -- use iterator `std::back_inserter()` instead
    [](int elem) {return elem * 2; });

  vector<int> v3{ 3, 6, 1, 0, -2, 5 };
  vector<int> v5;
  copy_if(begin(v3), end(v3), back_inserter(v5), 
    [](int elem) {return elem % 2 == 0; });

  v3[3] = -2;
  vector<int> v6;
  unique_copy(begin(v3), end(v3), back_inserter(v6));

  string sentence = "Hello, world!";
  string reverse; // no need to pre-allocate `reverse` to an appropriately sized `string`, since `std::back_inserter()` is used to perform `std::copy_if()` in the following line
  reverse_copy(begin(sentence), end(sentence), back_inserter(reverse));

  return 0;
}

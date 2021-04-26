#include <vector>
using std::vector;
#include <algorithm>
using std::find;
#include <numeric>
using std::iota;
#include <array>
using std::array;


int main()
{
  vector<int> v1(10);
  iota(begin(v1), end(v1), 1);
  vector<int> v2;
  v2.clear();
  copy(rbegin(v1), rend(v1), back_inserter(v2));

  /* regular/non-`const` iterators to `const` elements/values */
  array<const int, 5> ca = { 3,1,6,0,2 }; // `std::array` container `ca` has five `const int` elements
  auto it = begin(ca);
  it++; // incrementing an iterator to a `const` element is permissible
  //*it = 7; // however, modifying a `const` element is not allowed
  int i = *it; // the pointed-to `const` element can be dereferenced, however

  //vector<const int> vc; // error -- cannot declare with `const` elements without initializing values

  it = find(begin(ca), end(ca), 1); // `std::find()` is a read-only operation, which also returns a non-`const`/regular iterator that can be stored in a variable (i.e., `it`)
  it++;
  //*it = 7;
  //it = cbegin(ca); // error -- cannot assign a `const` iterator to a regular/non-`const` iterator


  /* regular iterators vs. `const` iterators */
  auto it2 = begin(v2); // `it2` is a regular iterator
  it2++;
  *it2 = 7;

  auto cit = cbegin(v2); // `cit` is a `const` iterator
  cit++; // a `const` iterator can be incremented to a new element position
  //*cit = 7; // however, a `const` iterator cannot modify the pointed-to element's value

  return 0;
}

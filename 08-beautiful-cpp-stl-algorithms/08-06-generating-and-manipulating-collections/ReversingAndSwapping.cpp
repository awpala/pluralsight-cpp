#include <vector>
using std::vector;
#include <algorithm>
using std::reverse;
using std::iter_swap;
using std::reverse_copy;
#include <string>
using std::string;


int main()
{
  vector<int> source {3, 6, 1, 0, -2, 5};

  string sentence = "Hello, world!";
  reverse(begin(sentence), end(sentence)); // `sentence` is now `"!dlrow ,olleH"`

  auto v7 = source;
  iter_swap(begin(v7), end(v7) - 1); // swaps first and last elements of `v7` in-place

  string orig="             "; // N.B. pre-allocated via string literal to hold copy
  reverse_copy(begin(sentence), end(sentence), begin(orig)); // copies reversed string to `origin` without modifying `sentence`

  return 0;
}

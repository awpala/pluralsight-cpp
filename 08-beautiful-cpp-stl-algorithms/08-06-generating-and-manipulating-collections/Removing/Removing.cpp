#include <vector>
using std::vector;
#include <algorithm>
using std::remove;
using std::remove_if;
#include "Resource.h"


int main()
{
  vector<int> source {3, 6, 1, 0, -2, 5};
  auto v3 = source;

  auto newend = remove(begin(source),end(source), 3);
  int s = source.size(); // still the same size after removal
  int logicalsize = newend - begin(source); // the "effective size" of the container after removal of `3`
  source.erase(newend, end(source)); // contracts `source.size()` so that now `logicalsize == source.size()`

  source = v3;
  source.erase(remove(begin(source), end(source), 3), end(source)); // equivalent to previous statement -- more idiomatic to perform as a single-line step if the intention is to contract the container (i.e., with no further processing of the past-the-end elements)

  // a collection of `Resource` object instances
  vector<Resource> vr(2);
  vr[0].setValue(8);
  vr[1].setValue(9);

  auto newend2 = remove_if(begin(vr),end(vr), [](const Resource& r) {return r.getvalue() == 8; }); // using `std::remove_if()` with a predicate
  vr.erase(newend2, end(vr));

  return 0;
}

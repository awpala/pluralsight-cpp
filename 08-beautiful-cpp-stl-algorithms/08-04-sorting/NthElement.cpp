#include <vector>
using std::vector;
#include <algorithm>
using std::nth_element;


int main()
{
  vector<int> v2 = {1,5,4,2,9,7,3,8,2};
  int i = *(begin(v2) + 4);
  nth_element(begin(v2), begin(v2)+4, end(v2));
  i = *(begin(v2) + 4);

  return 0;
}

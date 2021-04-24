#include <vector>
using std::vector;
#include <algorithm>
using std::sort;
using std::shuffle;
#include <random>
using std::random_device;
using std::mt19937;


int main()
{
  vector<int> v{ 4,1,0,1,-2,3,7,-6,2,0,0,-9,9 };
  auto v2 = v;
  sort(begin(v2), end(v2));

  random_device randomdevice;
  mt19937 generator(randomdevice());
  
  shuffle(begin(v2), end(v2), generator);

  return 0;
}

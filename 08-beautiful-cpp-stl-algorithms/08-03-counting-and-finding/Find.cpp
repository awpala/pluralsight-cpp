#include <vector>
using std::vector;
#include <string>
using std::string;
#include <algorithm>
using std::find;


int main()
{
  vector<int> v{  4, 6, 6, 1, 3, -2, 0, 11, 2, 3, 2, 4, 4, 2, 4 };
  string s{ "Hello I am a sentence" };

  //find the first zero in the collection
  auto result = find(begin(v), end(v), 0);
  int weLookedFor = *result;

  //find the first 2 after that zero
  result = find(result, end(v), 2); 
  if (result != end(v))
  {
    weLookedFor = *result;
  }

  //find the first a
  auto letter = find(begin(s), end(s), 'a');
  char a = *letter;

  //find first odd value
  result = find_if(begin(v), end(v), [](auto elem) {return elem % 2 != 0; });
  weLookedFor = *result;

  //find first even value
  result = find_if_not(begin(v), end(v), [](auto elem) {return elem % 2 != 0; });
  weLookedFor = *result;

  vector<int> primes{ 1,2,3,5,7,11,13 };
  result = find_first_of(begin(v), end(v), begin(primes), end(primes));
  weLookedFor = *result;

  vector<int> subsequence{ 2,4 };
  result = search(begin(v), end(v), begin(subsequence), end(subsequence));
  weLookedFor = *result;
  result++; result++;
  int six = *result;

  string am = "am";
  letter = search(begin(s), end(s), begin(am), end(am));
  a = *letter;

  result = find_end(begin(v), end(v), begin(subsequence), end(subsequence));
  result++; result++;
  if (result != end(v))
  {
    weLookedFor = *result;
  }

  result = search_n(begin(v), end(v), 2, 4);
  result--;
  int two = *result;

  result = adjacent_find(begin(v), end(v));
  six = *result;
  result++;
  six = *result;

  return 0;
}

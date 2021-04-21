#include <vector>
using std::vector;
#include <string>
using std::string;
#include <algorithm>
using std::find_first_of;
using std::search;
using std::find_end;
using std::search_n;
using std::adjacent_find;


int main()
{
  vector<int> v{  4, 6, 6, 1, 3, -2, 0, 11, 2, 3, 2, 4, 4, 2, 4 };
  string s{ "Hello I am a sentence" };

  vector<int> primes{ 1,2,3,5,7,11,13 };
  auto result = find_first_of(begin(v), end(v), begin(primes), end(primes));
  auto weLookedFor = *result;

  vector<int> subsequence{ 2,4 };
  result = search(begin(v), end(v), begin(subsequence), end(subsequence));
  weLookedFor = *result;
  result++; result++;
  int six = *result;

  string am = "am";
  auto letter = search(begin(s), end(s), begin(am), end(am));
  auto a = *letter;

  result = find_end(begin(v), end(v), begin(subsequence), end(subsequence));
  result++; result++; // iterates past the end of `v`
  if (result != end(v)) // guarding `if` to prevent dereferencing invalid iterator
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

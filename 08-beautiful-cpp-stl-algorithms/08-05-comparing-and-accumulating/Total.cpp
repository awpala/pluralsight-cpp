#include <vector>
using std::vector;
#include <numeric>
using std::accumulate;
#include <string>
using std::string;
using std::to_string;


int main()
{
  vector<int> a{ 1, 2, 3, 4, 5 };

  // totalling via ranged `for` loop
  int total = 0;
  for (int i : a)
  {
    total += i;
  }

  // totalling via `std::accumulate()` -- better approach
  total = accumulate(begin(a), end(a), 0); // equivalent to previous `for` loop construct
  total = accumulate(begin(a), end(a), 0, 
    [](int total, int i) {if (i % 2 == 0) return total + i; return total; }); // using predicate to only accumulate even numbers
  total = accumulate(begin(a), end(a), 1, 
    [](int total, int i) {return total * i; }); // using predicate to accumulate/total as a product rather than as a sum


  vector<string> words{ "one","two","three" };
  auto allwords = accumulate(begin(words), end(words), string{}); // concatenates to one string by default via overloaded operator `+`
  int length = allwords.size(); // `11` via `"onetwothree"`
  allwords = accumulate(begin(words), end(words), string{"Words:"}, [](const string& total, string& s) {return total + " " + s; });
  length = allwords.size(); // `20` via ``Words: one two three"`

  string s = accumulate(begin(a), end(a), string{"The numbers are:"}, 
    [](const string& total, int i) {return total + " " + to_string(i); }); // `"The numbers are: 1 2 3 4 5"`

  return 0;
}

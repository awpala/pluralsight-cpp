#include <vector>
using std::vector;
#include <algorithm>
using std::sort;
using std::all_of;
using std::find;
using std::count_if;
#include <string>
using std::string;


int main()
{
  vector<int> v4;
  int i = 0;
  std::generate_n(std::back_inserter(v4), 5,[&]() { return i++; } );

	v4.push_back(-2);
	v4.push_back(7);
	v4.push_back(0);
	v4.push_back(1);

  // sorting via `std::sort()`
	sort(begin(v4), end(v4));
	// sort(v4); // C++20 provides this even more compact range-based version of the statement above

  // test all elements of an array via `std::all_of()`
	bool allpositive = all_of(begin(v4), end(v4), [](int elem) {return elem >= 0; });

  // `std::string` is also a Standard Library collection (implemented as a collection of `char`s)
	string s{ "Hello I am a sentence" };
	auto letter = find(begin(s), end(s), 'a'); 	//find the first `'a'` in string `s`
	auto caps = count_if(begin(s), end(s), [](char c) {return (c != ' ') && (toupper(c) == c); }); // count the capital letters in string `s`

  return 0;
}

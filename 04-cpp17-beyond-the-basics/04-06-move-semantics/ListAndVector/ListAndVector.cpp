#include "Resource.h"

#include <iostream>
using std::cout;
using std::endl;

#include <chrono>
using std::chrono::system_clock;
using std::chrono::steady_clock;
using std::chrono::duration_cast;
using std::chrono::seconds;
using std::chrono::milliseconds;

#include <string>
using std::string;

#include <vector>
#include <list>
using std::vector;
using std::list;

#include <algorithm>

template <typename Func>
long long TimeFunc(Func f)
{
  auto begin = steady_clock::now();
  f();
  auto end = steady_clock::now();

  return duration_cast<milliseconds>(end - begin).count();
}


template <typename T> // `T` is the collection to be exercised (e.g., `std::string`)
void exercise(int size, string commonname)
{
  T v;
  typename T::template value_type res1("starting entry"); // `value_type` infers `T`'s type from the initializer
  v.push_back(res1);

	// build the sorted vector `v`
  for (int i = 0; i < size; i++)
  {
    int r = (int)rand();
    string s;
    int ss = r % 100; // random integer between 0 and 99
    s.reserve(ss); // create capacity for `ss` characters in string `s`
    std::generate_n(std::back_inserter(s), ss, [ss]() {return (char)('!' + ss / 2); }); // build a string in `s` consisting of `ss` repetitions of ASCII character `!` + `ss`/2 (i.e., ranging from ASCII `'!'`/`33` to `'R'`/`82`)
    typename T::template value_type res(s);
    
		// insert string `s` in to `v` in sorted order
		bool inserted = false;
    for (auto it = begin(v); it != end(v); it++)
    {
      if (*it > res)
      {
        v.insert(it, res);
        inserted = true;
        break;
      }
    }
    if (!inserted) // `res` is the largest string (in sorted order), therefore add to end of `v`
      v.push_back(res);
  }

	// using functions from the Standard Library
  auto it = max_element(begin(v), end(v));
  typename T::template value_type maxV = *it;
	auto maxStr = it->GetName();

  it = min_element(begin(v), end(v));
  typename T::template value_type minV = *it;
	auto minStr = it->GetName();

	cout << "`v` of type " << commonname <<  " contains resources `" 
		<< minStr << "` to `" << maxStr << "`" <<  endl;


  bool sorted = is_sorted(begin(v), end(v));
	
	cout << "`v` of type " << commonname <<  " is sorted?\t" << sorted << endl;
}


int main()
{
  const int size = 8'000;

  auto vectormilliseconds = TimeFunc([&]() {exercise<vector<Resource>>(size, "vector"); });
  cout << endl;
	auto listmilliseconds = TimeFunc([&]() {exercise<list<Resource>>(size, "list"); });
	cout << endl;

	cout << "Time required to insert " << size 
    << " sorted random `Resource` objects into std::vector : "
    << vectormilliseconds << " ms" << endl;
	cout << endl;
  cout << "Time required to insert " << size 
    << " sorted random `Resource` objects into std::list   : "
    << listmilliseconds << " ms" << endl;

	return 0;
}

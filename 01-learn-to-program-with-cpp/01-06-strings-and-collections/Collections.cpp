#include <iostream>
using std::cout;
using std::cin;

#include <string>
using std::string;

#include <vector>
using std::vector;
using std::begin;
using std::end;

#include <algorithm> 
using std::sort;
using std::count;

int main()
{
  vector<int> nums;

  for (int i = 0; i < 10; i++) // traditional for loop
  {
    nums.push_back(i);
  }

  for (auto item : nums) // range-based for loop
  {
    cout << item << " ";
  } // N.B. `item` goes out of scope here
  cout << '\n';

  // nums.push_back("Kate"); // not permissible -- nums can only hold int's


  vector<string> words;

  cout << "enter three words ";
  for (int i = 0; i < 3; i++)
  {
    string s;
    cin >> s;
    words.push_back(s);
  } // N.B. `s` goes out of scope here

  for (auto item : words)
  {
    cout << item << " ";
  }
  cout << '\n';

  // using vector member function size()
  cout << "int vector nums has " << nums.size() << " elements." << '\n';

  // accessing vector elements via operator [] (N.B. vectors have zero-based indices)
  nums[5] = 3;
  nums[6] = -1;
  nums[1] = 99;

  // all three for loops below produce equivalent output
  for (auto item : nums)
  {
    cout << item << " ";
  }
  cout << '\n';

  for (unsigned int i = 0; i < nums.size(); i++)
  {
    cout << nums[i] << " ";
  }
  cout << '\n';

  for (auto i = begin(nums); i != end(nums); i++) // N.B. collections' elements can also be accessed with iterators (e.g., `i`) via `begin` and `end` (where `end` is one index past the last element in the collection)
  {
    cout << *i << " ";
  }
  cout << '\n';

  // using std::sort from `algorithm` library on a vector container
  sort(begin(words), end(words));
  for (auto item : words)
  {
    cout << item << " ";
  }
  cout << '\n';

  // using std::count from `algorithm` library on a vector container
  int threes = count(begin(nums), end(nums), 3);
  cout << "vector of ints has " << threes << " elements with value 3" << '\n';

  // using std::count from `algorithm` on a string
  int tees = count(begin(words[0]), end(words[0]), 't'); // N.B. words[0] is a string
  cout << "first word has " << tees << " letter t's" << '\n';

  return 0;
}

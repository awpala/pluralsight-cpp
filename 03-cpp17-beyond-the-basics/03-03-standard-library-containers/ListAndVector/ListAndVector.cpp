#include <iostream>
using std::cout;
using std::endl;

#include <chrono>
using std::chrono::system_clock;
using std::chrono::steady_clock;
using std::chrono::duration_cast;
using std::chrono::seconds;
using std::chrono::milliseconds;

#include <vector>
using std::vector;
#include <list>
using std::list;

#include "Builders.h"


template <typename Func> // templated function
long long TimeFunc(Func f)
{
  auto begin = steady_clock::now();
  f();
  auto end = steady_clock::now();

  return duration_cast<milliseconds>(end - begin).count();
}


int main()
{
  int const size = 30'000;

  vector<int> v;
  v.push_back(0);

  list<int> l;
  l.push_back(0);

  auto vectormilliseconds = TimeFunc([&]() {BuildVector(size,v); }); // N.B. Using lambda to call build function (lambdas are discussed later in the course)
  auto listmilliseconds = TimeFunc([&]() {BuildList(size,l); });

  cout << "Time required to insert " << size 
    << " sorted random integers into std::vector : "
    << vectormilliseconds << " ms" << endl;
  cout << "Time required to insert " << size 
    << " sorted random integers into std::list   : "
    << listmilliseconds << " ms" << endl;

  return 0;
}

#pragma once
#include <vector>


class Collection
{
private:
  // "old" version -- raw C-style array
  int * OldNumbers; // could be any arbitrary type
  int count; // separate variable `count` required to track size
  // "new" version -- `std::vector` object instance
  std::vector<int> NewNumbers;

public:
  void OldOne(int howmany);
  void OldTwo(int repeat, int value);
  void OldThree();
  void NewOne(int howmany);
  void NewTwo(int repeat, int value);
  void NewThree();
};

#include <cstdlib>
using std::rand;

#include <vector>
using std::vector;
#include <list>
using std::list;

#include "Builders.h"

/* 
  These "build" functions receive a container of size `size`
  and insert randomly generated elements into the container
  in sorted order -- note the similarity/genericity between
  these two functions; this is a key aspect of using 
  Standard Library containers
*/

void BuildVector(const int& size, vector<int>& v)
{
  for (int i = 0; i < size; i++)
  {
    int r = (int)rand();
    bool inserted = false;
    for (auto it = begin(v); it != end(v); it++) // N.B. `it` is the iterator, which traverses the container
    {
      if (*it > r)
      {
        v.insert(it, r);
        inserted = true;
        break;
      }
    }
    if (!inserted) // `r` is larger than all elements in the container, therefore add `r` to the end of container
      v.push_back(r);
  }
}

void BuildList(const int& size, list<int>& l)
{
  for (int i = 0; i < size; i++)
  {
    int r = (int)rand();
    bool inserted = false;
    for (auto it = begin(l); it != end(l); it++)
    {
      if (*it > r)
      {
        l.insert(it, r);
        inserted = true;
        break;
      }
    }
    if (!inserted)
      l.push_back(r);
  }
}

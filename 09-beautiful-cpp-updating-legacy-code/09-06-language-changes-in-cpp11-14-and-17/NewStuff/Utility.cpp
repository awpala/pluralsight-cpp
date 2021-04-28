#include "Utility.h"

bool isOdd(int i) 
{ 
  return i % 2 != 0; 
}

bool ShouldBeCounted(int i)
{
  return ((i == 2)||( i == 3));
}

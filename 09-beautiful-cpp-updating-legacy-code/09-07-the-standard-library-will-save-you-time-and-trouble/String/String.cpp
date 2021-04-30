#include <string.h>
#include "CommandLine.h"

int main()
{
  CommandLine CL;
  
  char test1[256]; // temporary buffer array `test1`
  strncpy(test1, "first second", 256); // copy string `"first second"` to buffer
  CL.oldway(test1); // pass `test1` as argument

  CL.newway("first second"); // equivalent to above

  return 0;
}

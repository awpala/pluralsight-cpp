#include "Resource.h"

#include <cstdlib>
using std::strtol;


Resource::Resource(char const * const filepath)
{
  f = fopen(filepath, "r");
  if (f)
  {
    read = fgets(line, maxlinelength, f);
    char* end;
    arraylength = strtol(line, &end, 10);
    numbers = new int[arraylength];
  }
} // resource is acquired here

bool Resource::OK()
{
  return ((f != nullptr) && (read != nullptr));
}


int Resource::ProcessLines()
{
  bool keepgoing = true;
  char* end;
  //read all the lines
  while (keepgoing)
  {
    read = fgets(line, maxlinelength, f);
    if (read)
    {
      numbers[linesread] = strtol(line, &end, 10);
      linesread++;
    }
    else
    {
      keepgoing = false;
    }
  }
  return linesread;
}

int Resource::AccessNumber(int index)
{
  if (numbers && index < arraylength)
  {
    return numbers[index];
  }
  return 0;
}


Resource::~Resource()
{
  if (numbers)
  {
    delete[] numbers;
  }
  if (f)
  {
    fclose(f);
  }
} // resource is released here
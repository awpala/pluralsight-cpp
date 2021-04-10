#include "status.h"

int main()
{
  Status s = Pending;
  s = Approved;

  FileError fe = FileError::notfound;
  fe = FileError::ok;

  NetworkError ne = NetworkError::disconnected;
  ne = NetworkError::ok;

  return 0;
}

#include "Collection.h"

int main()
{
  Collection C;

  // "old" version implementation
  C.OldOne(10);
  C.OldTwo(11, 3);
  C.OldTwo(8, 4);
  C.OldThree();

  // "new" version implementation -- its use here is equivalent to above/"old," but underlying implementation is cleaner and safer
  C.NewOne(10);
  C.NewTwo(11, 3);
  C.NewTwo(8, 4);
  C.NewThree();

  return 0;
}

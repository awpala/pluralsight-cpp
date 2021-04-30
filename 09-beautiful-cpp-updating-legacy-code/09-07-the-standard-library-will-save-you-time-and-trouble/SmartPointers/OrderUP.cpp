#include "OrderUP.h"
using std::make_unique;

void OrderUP::SetDiscount(int amt)
{
  discount = make_unique<Discount>(amt);
}

int OrderUP::getDiscountAmount()
{
  if (discount)
    return discount->getAmount();
  return 0;
}

#include "OrderSP.h"
using std::make_shared;

void OrderSP::SetDiscount(int amt)
{
  discount = make_shared<Discount>(amt);
}

int OrderSP::getDiscountAmount()
{
  if (discount)
    return discount->getAmount();
  return 0;
}

/*
OrderSP::~OrderSP() // not necessary -- smart pointer member `discount` cleans up itself automatically
{
}
*/

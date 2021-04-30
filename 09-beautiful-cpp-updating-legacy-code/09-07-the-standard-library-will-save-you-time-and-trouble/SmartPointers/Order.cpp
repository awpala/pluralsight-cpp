#include "Order.h"

void Order::SetDiscount(int amt)
{
  if (discount)
    delete discount;
  discount = new Discount(amt);
}

int Order::getDiscountAmount()
{
  if (discount)
    return discount->getAmount();
  return 0;
}

Order::~Order()
{
  delete discount;
}

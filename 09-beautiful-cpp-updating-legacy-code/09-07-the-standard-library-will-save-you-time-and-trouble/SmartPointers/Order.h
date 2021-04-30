#pragma once
#include "Discount.h"


class Order
{
private:
  Discount * discount = nullptr;
public:
  void SetDiscount(int amt);
  int getDiscountAmount();
  ~Order();
  // N.B. class `Order` violates rule of three: also needs copy constructor and copy assignment operator
};

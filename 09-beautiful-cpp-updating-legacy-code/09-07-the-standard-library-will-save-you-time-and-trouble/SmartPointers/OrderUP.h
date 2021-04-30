#pragma once
#include "Discount.h"
#include <memory>

class OrderUP
{
private:
  std::shared_ptr<Discount> discount;
public:
  void SetDiscount(int amt);
  int getDiscountAmount();
};

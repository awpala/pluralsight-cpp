#pragma once
#include "Discount.h"
#include <memory>

class OrderSP
{
private:
  std::shared_ptr<Discount> discount;
public:
  void SetDiscount(int amt);
  int getDiscountAmount();
  // ~OrderSP(); // not necessary -- smart pointer member `discount` cleans up itself automatically
};

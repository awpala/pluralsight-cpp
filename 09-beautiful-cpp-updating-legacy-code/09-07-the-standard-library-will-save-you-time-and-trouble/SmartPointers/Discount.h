#pragma once

class Discount
{
private:
  int amount;
public:
  Discount(int amt) : amount(amt) {}
  int getAmount() { return amount; }
};

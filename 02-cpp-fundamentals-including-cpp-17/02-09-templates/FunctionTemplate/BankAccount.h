#pragma once
#include <string>
class BankAccount
{
public:
  BankAccount();
  ~BankAccount();
private:
  int BalanceInPennies;
//TODO: finish writing this class
public:
  std::string GetHolderName() { return "NotImplemented";}
};

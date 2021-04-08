#include <vector>
#include <string>
#include "Transaction.h"

// N.B. It is a best practice to avoid `using` statements in header flies to avoid side effects from including the header elsewhere

class Account
{
private:
  int balance;
  std::vector<Transaction> log;
  int limit;
public:
  Account();
  std::vector<std::string> Report();
  bool Deposit(int amount);
  bool Withdraw(int amount);
  int GetBalance() { return balance; }
};

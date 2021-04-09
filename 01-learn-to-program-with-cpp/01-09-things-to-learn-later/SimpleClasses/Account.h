#include <vector>
#include <string>
#include "Transaction.h"

class Account
{
private:
  int balance;
  std::vector<Transaction> log;
  int limit;
public:
  Account();
  std::vector<std::string> Report() const; // `const` is used to designate a member function which does not change any member variables (i.e., "read-only")
  bool Deposit(int amount); // N.B. `Deposit()` is not a suitable candidate for a `const` member function since it modifies the member variable `amount`
  bool Withdraw(int amount);
  int GetBalance() const { return balance; }
};

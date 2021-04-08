#include <string>

class Transaction
{
private:
  int amount;
  std::string type; // N.B. a better way exists

public:
  Transaction(int amt, std::string kind);
  std::string Report();
};

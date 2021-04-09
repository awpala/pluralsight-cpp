#include <string>

class Transaction
{
private:
  int amount;
  std::string type;

public:
  Transaction(int amt, std::string kind);
  std::string Report() const; // `const` is used to designate a member function which does not change any member variables (i.e., "read-only")
};

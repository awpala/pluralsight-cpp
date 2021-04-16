#include <iostream>
using namespace std;

int Fibonacci(int n) {
  switch (n) {
    // F_0 = 0
    case 0: return 0;

    // F_1 = 1
    case 1: return 1;

    // F_n = F_(n-1) + F_(n-2)
    default:
      return Fibonacci(n-1) + Fibonacci(n-2);
  }
}

int main() {
  cout << "Index? ";
  int i{};
  cin >> i;

  cout << " F_" << i << " = " << Fibonacci(i) << '\n';
}

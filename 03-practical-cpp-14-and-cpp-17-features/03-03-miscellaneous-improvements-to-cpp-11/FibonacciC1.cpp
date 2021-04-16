// Demo code containing a **constexpr** Fibonacci function.
// This function is executed at **compile-time**.
//
// This version of the code contains a wrong static_assert (on purpose):
// verify that you get a compile-time error, since the Fibonacci
// function is *constexpr*, and as such executed at compile-time.

#include <iostream>
using namespace std;

constexpr int Fibonacci(int n) {
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
  // Verify **compile-time** execution of Fibonacci()
  // using static_assert.
  //
  // This time the static_assert will fail, and you'll get a
  // **compile-time** error.
  static_assert(Fibonacci(10) == 1, "Unexpected Fibonacci number.");
}


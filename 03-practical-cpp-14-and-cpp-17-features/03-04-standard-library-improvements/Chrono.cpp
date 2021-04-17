#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

void print(milliseconds ms) { // here, `std::chrono::milliseconds` is much safer than `int`, as the former will perform necessary time unit conversions for arguments of any type `std::chrono::duration` (e.g., `seconds`, `minutes`, etc.)
  cout << ms.count() << "ms \n";
}

int main() {
  auto x = 2s;
  cout << " x = 2s    : "; print(x); // `print()` automatically performs the appropriate conversion from `s` (argument `x`) to `ms` (parameter `ms`) via corresponding `std::chrono` objects

  auto y = 150ms;
  cout << " y = 150ms : "; print(y);

  auto z = x + y; // `auto` performs the necessary time unit conversion to matching units
  cout << " z = x + y : "; print(z);

  constexpr auto timeLimit = 3s;
  cout << "\n Time limit is "; print(timeLimit);
  auto message = (z < timeLimit) ? " All right! \n" : " Out of time! \n"; // comparison with `std::chrono` objects can be performed (e.g., `z < timeLimit`) with appropriate type conversion occurring automatically as necessary
  cout << message;

  return 0;
}

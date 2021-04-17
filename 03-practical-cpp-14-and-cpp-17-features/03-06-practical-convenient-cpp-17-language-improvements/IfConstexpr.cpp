#include <iostream>     // For std::cout
#include <string>       // For std::string
#include <type_traits>  // For std::is_integral
using namespace std;

// non-`if constexpr` version of template function `length()` -- does not compile
/*
template <typename T>
auto length(T const& value) {
  if (is_integral<T>::value) {
    // The length of an integer number is the number itself
    return value;
  } else {
    // Invoke the `length()` method in the general case 
    return value.length(); // error -- compiler cannot invoke method `length()` on `value` of type `int` during compile-time
  }
}
*/

// `if constexpr` version of template function `length()` -- does compile
template <typename T>
auto length(T const& value) {
  if constexpr(is_integral<T>::value) {
    // The length of an integer number is the number itself
    return value;
  } else {
    // Invoke the length method in the general case 
    return value.length(); // this statement is not executed by the compiler, and can only be accessed during run-time
  }
}


int main() {
  int n{64};
  string s{"Connie"};

  cout << " n = " << n << ";     length(n) = " << length(n) << '\n';
  cout << " s = " << s << "; length(s) = " << length(s) << '\n';

  return 0;
}

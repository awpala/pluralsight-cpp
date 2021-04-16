// Demo on variable templates and their specialization.

#include <iostream>
using namespace std;

// Generic variable template
template <typename T>
constexpr T maxValue = T(1000);

// Specialized case for double
template <>
constexpr double maxValue<double> = 2000;

// Specialized case for char
template <>
constexpr char maxValue<char> = 'Z';


int main() {
  // using the generic template
  cout << " maxValue<int>    : " << maxValue<int>    << '\n';
  cout << " maxValue<float>  : " << maxValue<float>  << '\n';
  // using the specialized templates
  cout << " maxValue<double> : " << maxValue<double> << '\n';
  cout << " maxValue<char>   : " << maxValue<char>   << '\n';  
}

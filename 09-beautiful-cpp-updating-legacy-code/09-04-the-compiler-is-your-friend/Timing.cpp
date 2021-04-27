#include <iostream>
using std::cout;
#include <chrono>
using std::chrono::system_clock;
using std::chrono::steady_clock;
using std::chrono::duration_cast;
using std::chrono::seconds;


template <typename Func>
long long TimeFunc(Func f)
{
  auto begin = steady_clock::now();
  f();
  auto end = steady_clock::now();

  return duration_cast<seconds>(end - begin).count();
}

long fibonacci(unsigned n)
{
  //the nth fibonacci number
  if (n < 2)
  {
    return n; //starts 0, 1, ...
  }
  return fibonacci(n - 2) + fibonacci(n - 1);
}

long Fib20()
{
  return fibonacci(20);
}


int main()
{
  int fib40;
  auto seconds = TimeFunc([&]() {fib40 = fibonacci(40); });
  cout << "`fib40` (function-calling lambda): " << seconds << " seconds\n";
  
  double thirty;
  seconds = TimeFunc([&]() {thirty = 10.0 + 20.0; });
  cout << "`thirty` (single-value lambda): " << seconds << " seconds\n";
  
  seconds = TimeFunc(Fib20); // via function pointer `Fib20`
  cout << "`Fib20` (function pointer): " << seconds << " seconds\n";

  // seconds = TimeFunc(42); // error -- cannot call `TimeFunc()` with a value, must use a function or lambda (taking zero arguments)

	return 0;
}

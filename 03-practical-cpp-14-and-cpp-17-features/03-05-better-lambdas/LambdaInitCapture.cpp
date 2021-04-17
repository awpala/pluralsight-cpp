#include <iostream>
#include <memory>
using namespace std;

int main() {
  auto p = make_unique<int>(64); // N.B. compiler deduces type `std::unique_ptr<int>`
  
  // cannot capture `p` in this manner, as `p` is non-copyable
  /*
  auto lambda = [](){ 
    cout << " Inside the lambda -- value = " << *p << '\n'; 
  };
  */

  // use `std::move()` instead to capture by move (i.e., transfer `p` from external scope to `ptr` inside the lambda)
  auto lambda = [ptr = move(p)](){
    cout << " Inside the lambda -- value = " << *ptr << '\n'; 
  };

  lambda(); // call `lambda` using the function call operator `()`

  return 0;
}

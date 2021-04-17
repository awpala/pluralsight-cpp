#include <iostream>
#include <memory> // provides `std::unique_ptr` and `std::make_unique()`
using namespace std;

class X {
public:
  X() {
    cout << " X constructor \n";
  }

  ~X() {
    cout << " X destructor \n";
  }

  void SayHi() {
    cout << " X says hi! :) \n";
  }

private:
  // Some data members ...
  int m1{};
  double m2{3.14};
};

int main() {
  /* raw pointer */
  X * pX = new X{};
  pX->SayHi();
  delete pX; // omitting this will cause a memory leak when the program exits, as the memory is still allocated prior to this statement
  pX = nullptr; // set to `nullptr` to prevent a dangling-pointer reference to heap memory

  /* smart pointer */
  auto spX = make_unique<X>(); // `std::make_unique()` returns a `std::unique_ptr` object (inferred automatically here by the compiler via `auto`)
  spX->SayHi();

  return 0;
} // `spX` is automatically released upon leaving scope

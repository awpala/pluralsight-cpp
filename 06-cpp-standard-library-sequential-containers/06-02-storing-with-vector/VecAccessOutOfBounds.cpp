#include <iostream>
using std::cout;
#include <vector>
using std::vector;

int main() {
  vector<int> v{10, 20, 30};

  cout << " Initial vector: ";
  for (const auto& x : v) {
    cout << x << ' ';
  }
  cout << '\n';

  cout << " Vector size: " << v.size() << "\n\n";

  cout << " Trying: v[6] = 64; \n\n";
  // v[6] = 64; // writes to out-of-bounds memory (bad!) -- can cause buffer overflow (a security threat!)

  cout << " Reading v[6]: " 
    << v[6] // reads out-of-bounds memory
    << '\n';

  return 0;
}

#include <iostream>

int main()
{
  double d1 = 2.2; 
  //int i5 = d1; // implicit cast -- generates a warning due to loss of data (i.e., truncation of fractional part of d1)
  int i5 = static_cast<int>(d1); // this is a better approach than the preceding line, i.e., use an explicit cast instead
  std::cout << "d1= " << d1 << std::endl;
  std::cout << "i5= " << i5 << std::endl;

  std::cout << std::endl;

  auto a1 = 1;
  auto a2 = 2.2;
  //  a1 = a2; // implicit cast
  a1 = static_cast<int>(a2); // explicit cast
  std::cout << "a1=" << a1 << std::endl;
  std::cout << "a2=" << a2 << std::endl;

  return 0;
}

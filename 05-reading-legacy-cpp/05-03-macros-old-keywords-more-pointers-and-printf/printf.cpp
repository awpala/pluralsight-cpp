#include <cstdio> // provides `printf()`

int addition(int a, int b) { return (a + b); }
int subtraction(int a, int b) { return (a - b); }
typedef int (*operation)(int a, int b);

#define ARRAYSIZE 5

int main()
{
  int numbers[ARRAYSIZE] = { 200, 600, 123, 456, 789 };

  int total = 0;
  operation op = addition;
  for (int n = 0; n < ARRAYSIZE; n++)
  {
    total = op(total, numbers[n]);
  }

  printf("Array total: %d \n", total);
  printf("\n\n");

  op = subtraction;
  total = op(total, numbers[ARRAYSIZE - 1]);
  printf("Array total without last element: %d \n", total);
  printf("\n\n");

  const char* greeting = "hello";
  printf("string: %s", greeting);
  printf("\n\n");
  printf("character: %c", greeting[0]);
  printf("\n\n");
  printf("pointer: %p", greeting);
  printf("\n\n");
  printf("hex: 0x%08x", greeting);
  printf("\n\n");

  return 0;
}

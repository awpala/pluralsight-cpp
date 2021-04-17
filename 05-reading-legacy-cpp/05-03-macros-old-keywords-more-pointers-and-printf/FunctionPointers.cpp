#define ARRAYSIZE 5

// function definitions
int addition(int a, int b) { return (a + b); }
int subtraction(int a, int b) { return (a - b); }

// function pointer `operation`
typedef int (*operation)(int a, int b);

int main()
{
  int numbers[ARRAYSIZE] = { 200, 600, 123, 456, 789 };

  int total = 0;
  operation op = addition;
  for (int n = 0; n < ARRAYSIZE; n++)
  {
    total = op(total, numbers[n]);
  }

  op = subtraction;
  total = op(total, numbers[ARRAYSIZE - 1]);

  return 0;
}

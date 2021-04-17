#define ARRAYSIZE 5

#define SQ(a) (a)*(a)

int main()
{
  int numbers[ARRAYSIZE] = { 200, 600, 123, 456, 789 };
  int twentyfive = SQ(ARRAYSIZE); // N.B. IDE syntax highlighting shows macro expansion of `SQ` via mouse pointer hover

  return 0;
}

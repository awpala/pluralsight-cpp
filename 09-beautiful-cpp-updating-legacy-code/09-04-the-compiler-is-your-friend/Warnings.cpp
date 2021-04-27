int foo(int a, int /*unused*/) // no longer need second `int`
{
  return a*a;
}

bool final() { return true; }


int main()
{
	// these keywords can be used as variable name outside of their respective contexts
  int final = 3;
  auto override = 2;

  //auto noexcept = 0; // error -- cannot use this keyword as a variable name


  int i = 0;
  int j = 2;
  int k = 3;

  auto u = 1u;

  auto f = foo(i, j);

  if (f = j)
    j++;

  if (f < u) // warning -- comparing `int` to `unsigned int`
    f=3;

  u -= f; // warning -- subtracting from an `unsigned int`

  unsigned int really = -2; // warning -- assigning negative value to `unsigned int` 
  really = -k;

  if (f > j)
    really++;
    return i;


  if (i < f)
    j++;
    i++;

  return 0;
}

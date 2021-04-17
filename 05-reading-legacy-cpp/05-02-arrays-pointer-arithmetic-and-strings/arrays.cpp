
int main()
{
  const int howmanynumbers = 4;
  int numbers[howmanynumbers];
  numbers[0] = 8;
  numbers[1] = 7;
  numbers[2] = 6;
  numbers[3] = 5;

  for (int i = 0; i < howmanynumbers; i++)
  {
    numbers[i] += 1;
  }

  *(numbers + 1) = 1; // changes the second element's value to `1`

  double morenumbers[] = { 1.1,2.2,3.3,4.4,0 }; // using `0` as a "sentinel" value
  for (double* p = morenumbers; *p != 0; p++)
  {
    *p += 1.0;
  }

  int extent = numbers[0] - numbers[3];  // ad hoc calculation using elements from `number`
  int* dynamicnumbers = new int[extent]; // N.B. `extent == 3`
  dynamicnumbers[0] = 4; // array access via `[]`
  dynamicnumbers[1] = 3;
  dynamicnumbers[2] = 2;
  *(dynamicnumbers + 3) = 1; // equivalent array acces via `*(...).` -- however, note that this statement is accessing out of range (bad!), since `dynamicnumbers` only holds three elements

	// idiom for determining array size -- used commonly in legacy code, but is highly error-prone
  int localsize = sizeof(numbers) / sizeof(numbers[0]);
  int freestoresize = sizeof(dynamicnumbers) / sizeof(dynamicnumbers[0]); // evaluates to `freestoresize == 1`, which is incorrect!

  delete[] dynamicnumbers;

  return 0;
}

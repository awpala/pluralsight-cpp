#include <iostream>
using std::cout;
using std::cin;

int main()
{
  int answer = 5;
  int guess;
  bool notguessed = true;
  while (notguessed)
  {
    cout << "Guess my number: ";
    cin >> guess;
    if (guess == answer)
    {
      cout << "Yes!" << '\n';
      notguessed = false;
    }
    if (guess < answer)
    {
      cout << "Too low..." << '\n';
    }
    if (guess > answer)
    {
      cout << "Too high..." << '\n';
    }
  }

  return 0;
}

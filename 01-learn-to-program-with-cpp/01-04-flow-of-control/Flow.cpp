#include <iostream>
using std::cout;
using std::cin;

int main()
{
  int firstNumber;
  int secondNumber;
  bool keepgoing = true;
  int answer;
  while(keepgoing)
  {
    cout << "Enter a number: ";
    cin >> firstNumber;
    cout << "You entered " << firstNumber << ". Enter another number: ";
    cin >> secondNumber;
		cout << '\n';

    if (firstNumber < secondNumber)
    {
      cout << "The first number, " << firstNumber << ", is less than the second number, " << secondNumber << '\n';
    }
    else
    {
      cout << "The first number, " << firstNumber << ", is not less than the second number, " << secondNumber << '\n';
    }
    if (firstNumber == secondNumber)
    {
      cout << "The first number, " << firstNumber << ", is equal to the second number, " << secondNumber << '\n';
    }
    if (firstNumber > secondNumber)
    {
      cout << "The first number, " << firstNumber << ", is greater than the second number, " << secondNumber << '\n';
    }
    for (int loop = 0; loop < 10; loop++)
    {
      cout << loop << " ";
    }
		cout << '\n';

    cout << "\nCompare another pair? 0 means no, any other number means yes: ";
    cin >> answer;
    if (answer == 0)
    {
      keepgoing = false;
    }
		cout << '\n';
  }
}

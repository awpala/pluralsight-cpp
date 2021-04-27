#include <iostream>
using std::cout;
using std::cin;
#include "Resource.h"

int main()
{
  //ask for file name
  cout << "Enter full path to file ";
  char filepath[255];
  cin.getline(filepath, 255);

  try
  {
    //open file
    Resource numbersfile{ filepath };

    if (numbersfile.OK())
    {
      cout << "first line is: \n";
      cout << numbersfile.GetLine();
      char ans;
      cout << "Continue? (y/n)";
      cin >> ans;
      if (ans == 'y')
      {
        numbersfile.ProcessLines();
        cout << numbersfile.GetLineCount() + 1 << " lines read. \n";
      }
    }
    else
    {
      cout << "Could not open file: " << filepath << "\n";
    }


    //actually use numbers for something or otherwise genuinely process the file
    // eg numbersfile.AccessNumber(i)

  }
  catch (...)
  {
    cout << "An error occurred.";
  }

  return 0;
}

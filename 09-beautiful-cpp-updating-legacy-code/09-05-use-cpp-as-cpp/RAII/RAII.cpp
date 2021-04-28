#include <iostream>
using std::cout;
using std::cin;
#include "Resource.h"

int main()
{
  // ask for file name
  cout << "Enter full path to file: ";
  char filepath[255];
  cin.getline(filepath, 255);


  /* --- old code --- */
  /*
  FILE* f = nullptr;
  int* numbers = nullptr;

  try
  {
    // open file
    f = fopen(filepath, "r");

    char line[255];
    size_t const maxlinelength = 255;

    char* read = nullptr;

    if (f)
    {
      read = fgets(line, maxlinelength, f);
    }
    else
    {
      cout << "Could not open file: " << filepath << "\n";
    }

    // show first line and ask if they want to read it
    if (read)
    {
      cout << "first line is: \n";
      cout << line;
      char ans;
      cout << "Continue? (y/n)";
      cin >> ans;
      if (ans == 'y')
      {
        // allocate memory for array of lines
        char* end;
        int numlines = strtol(line, &end, 10);
        numbers = new int[numlines];
        bool keepgoing = true;
        int linesread = 0;
        // read all the lines
        while (keepgoing)
        {
          read = fgets(line, maxlinelength, f);
          if (read)
          {
            numbers[linesread] = strtol(line, &end, 10);
            linesread++;
          }
          else
          {
            keepgoing = false;
          }
        }
        cout << linesread + 1 << " lines read. \n";
      }
    }

    // actually use numbers for something or otherwise genuinely process the file
    
    if (numbers)
    {
      delete[] numbers; // cleanup
    }
  }
  catch (...)
  {
    cout << "An error occurred.";
    if (numbers)
    {
      delete[] numbers; // separate/repeated cleanup
    }
  }

  if (f)
  {
    fclose(f);
  }
  */


  /* --- after encapsulation of file resource in class `Resource`  --- */
  try
  {
    // open file
    Resource numbersfile{ filepath }; // `numbersfile` created on the stack (resource is managed on the heap via RAII-based class `Resource`)

    if (numbersfile.OK())
    {
      cout << "first line is: \n";
      cout << numbersfile.GetLine();
      char ans;
      cout << "Continue? (y/n) ";
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

    // actually use numbers for something or otherwise genuinely process the file
    // e.g., numbersfile.AccessNumber(i)

  } // RAII handles cleanup if file-resource object goes out of scope here
  catch (...) // refactored `catch` block is much simpler
  {
    cout << "An error occurred.";
  } // RAII handles cleanup if file-resource object goes out of scope here

  return 0;
}

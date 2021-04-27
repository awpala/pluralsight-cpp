#include <cstring>

#define CURRENT_YEAR 2017 //remember to update this each new year


int main()
{
  char empName[100];
  int NameLength;
  double empSalary;
  int empStartYear;
  bool empIsExempt;

  strcpy(empName, "Kate Gregory");
  NameLength = strlen(empName);
  empSalary = 1;
  empStartYear = 1986;
  empIsExempt = false;

  char* fname = strtok(empName, " ");
  char* lname = strtok(NULL, " ");

  char revName[100];
  strcpy(revName, lname);
  strcat(revName, ", ");
  strcat(revName, fname);

  if (!empIsExempt)
  {
    empSalary *= 1.05;
  }

  if ((CURRENT_YEAR - empStartYear) % 5 == 0)
  {
    empSalary *= 1.20;
  }

  // ... etc

  return 0;
}

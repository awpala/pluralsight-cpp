#include "Employee.h"
#include <cstring>


Employee::Employee(char const * name, double salary, int startyear, bool isexempt) : 
  empSalary(salary), empStartYear(startyear), empIsExempt(isexempt)
{
  strcpy(empName, name);
  NameLength = strlen(empName);
}

void Employee::ReverseName(char * revName)
{
  char* fname = strtok(empName, " ");
  char* lname = strtok(NULL, " ");

  strcpy(revName, lname);
  strcat(revName, ", ");
  strcat(revName, fname);
}

void Employee::AdjustSalary()
{
  if (!empIsExempt)
  {
    empSalary *= 1.05;
  }

  if ((CURRENT_YEAR - empStartYear) % 5 == 0)
  {
    empSalary *= 1.20;
  }
}

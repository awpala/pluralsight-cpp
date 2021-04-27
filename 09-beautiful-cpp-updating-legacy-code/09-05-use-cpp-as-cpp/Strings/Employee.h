#pragma once

#define CURRENT_YEAR 2017 //remember to update this each new year


class Employee
{
private:
  char empName[100];
  int NameLength;
  double empSalary;
  int empStartYear;
  bool empIsExempt;
public:
  Employee(char const * name, double salary, int startyear, bool isexempt);
  void ReverseName(char * revName);
  void AdjustSalary();
};

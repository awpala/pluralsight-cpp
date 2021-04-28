#include "Employee.h"
#include <cstring>

int main()
{
	/* ---- old code ---- */
	/*
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

	char revName[100]; // temporary buffer
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

	// ... etc.
	*/


	/* ---- after encapsulation of business logic in class `Employee` ---- */
	Employee e{ "Kate Gregory", 1, 1986, false };

	char revName[100];
	e.ReverseName(revName);

	e.AdjustSalary();

	// ... etc

	return 0;
}

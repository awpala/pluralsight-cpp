#include "Employee.h"
#include <cstring>

int main()
{
	Employee e{ "Kate Gregory", 1, 1986, false };
	char revName[100];
	e.ReverseName(revName);
	e.AdjustSalary();
	// ... etc

	return 0;
}

#include <iostream>
using std::cout;

int main()
{
	cout << '\n' << '\n';
	int i = 2 + 2; // an expression can be used to initialize a variable
	cout << i << '\n';
	i = i * 3; // a variable can be assigned a new value (of compatible type)
	cout << i << '\n';

	int j = 2;
	cout << j << '\n';

	i = 4.9; // causes a trunctation since `i` is an int
	j = 9 / 5; // causes a trunctation since `j` is an int
	cout << i << "  " << j << '\n';

  // i = "hello"; // causes a compiler error -- `i` must be an int

	float f = 4.9;
	cout << f << '\n';

	f = 9.0 / 5; // N.B. 9 / 5 will evaluate to 1.0, so 9.0 must be used to create a fractional part
	cout << f << '\n';

}

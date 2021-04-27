#include <cstring>

/* ---- Macro Example 1 ----  */

// function defined as a macro
/*
 #define sq1(x) x * x
*/

// better alternative to macro: use a template function instead
template<typename T>
T sq1(T x) { return x * x; }


/* ---- Macro Example 2 ----  */

// old macro-based approach to handling wide vs. non-wide characters
/*
#ifdef _UNICODE // header guard used to define alternate parameter types
wchar_t wAt(wchar_t const* // alternative 1 (wide)
#else
char At(char const* // alternative 2 (non-wide)
#endif
	string, int offset)
{
	return string[offset];
}
*/

// better alternative: use template code instead
template<typename Char>
Char AtImpl(Char const * string, int offset) // templated implementation function
{
  return string[offset];
}

wchar_t wAt(wchar_t const * string, int offset) // alternative 1 (wide)
{
  return AtImpl(string, offset);
}

char At(char const * string, int offset) // alternative 2 (non-wide)
{
  return AtImpl(string, offset);
}

/* ---- Macro Example 3 ----  */

// defining constant values via definitions
/*
#define MAX_EMPLOYEES 25

#define FILE_OK 0
#define FILE_ERROR 1

#define NETWORK_WARNING 0 // same alias of `0` as for `FILE_OK` -- can cause logic errors
#define NETWORK_ERROR 1
#define NETWORK_OK 2
*/

// better alternative: use classes with `static const` members, `enum`s, and `enum class`es instead 
class Department
{
public:
  static int const MaxEmployees = 25;
  // ...
};

enum class FileStatus
{
  Ok = 0,
  Error
};

enum class NetworkStatus
{
  Warning = 0,
  Error, // does not conflict with `FileStatus::Error`
  Ok // does not conflict with `FileStatus::Ok`
};


bool statusOK(FileStatus status)
{
  return status == FileStatus::Ok;
}


int main()
{
  /* Macro Example 1 */
  int i = 2;
  i = sq1(3);
  i = sq1(i);
  i = sq1(1 + 2); // `1+2*1+2` via macro -- unexpected result due to order of operations
  i = sq1(++i);  // `++i*++i` via macro -- unexpected result due to order of operations
  double d = sq1(2.0);
  //auto s = sq1("Hello");


  /* Macro Example 2 */
  auto c = wAt(L"Hello", 2);


  /* Macro Example 3 */
  auto j = Department::MaxEmployees; // N.B. scoping additionally adds documentation

	// macro-based code
	/*
	int status = FILE_OK;
	status++; // this is permissible, but why would you do this?
	if (status == FILE_ERROR) // could also pass if `status == NETWORK_ERROR`
		j++;

	*/

  FileStatus fStatus = FileStatus::Ok;
  //fStatus++; // error
  if (fStatus == FileStatus::Error)
    j++;

  // if (statusOK(NetworkStatus::Ok)) // error -- wrong `Ok` provided to function `statusOk`
	if (statusOK(FileStatus::Ok))
  {
    i++;
  }
  else
  {
    j++;
  }

  return 0;
}

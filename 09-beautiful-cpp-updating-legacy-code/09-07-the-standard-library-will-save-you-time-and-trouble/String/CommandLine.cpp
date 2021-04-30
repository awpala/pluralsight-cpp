#include "CommandLine.h"
#include <string.h>
#include <string>
using std::string;
#include <sstream>
using std::stringstream;


// simulating a more complicated header
#define FALSE false;
#define TRUE true;

// this function is hard to read and understand
bool CommandLine::oldway(char * lpCmdLine)
{
  char *ptr;

  ptr = strchr(lpCmdLine, ' ');
  if (!ptr) // test for null pointer
    return FALSE;
  *ptr = 0; // write null terminator to string
  strncpy(szDriverName, lpCmdLine, 32); // copies up to first-encountered null character into `szDriverName`
  *ptr = ' ';
  while (*ptr && isspace(*ptr)) // move `ptr` to end of the string
    ptr++;
  if (!*ptr)
    return FALSE;
  sprintf(lpszPipename, /* 256, */ "\\\\.\\pipe\\%s", ptr); // print into `lpszPipename` -- N.B. second argument `256` only used in `sprintf_s()` (this function is not supported by g++, however)

  return TRUE;
}

// this function is much more readable
bool CommandLine::newway(string const & CommandLine)
{
  stringstream ss(CommandLine); // `stringstream` treats the input as a (string) stream
  ss >> DriverName >> Pipename; // extracts the input string (parses whitespace as well, without additional logic required)

  if (DriverName == "" || Pipename == "") // can use comparison operator `==` directly
    return false;
  
  Pipename = R"(\\.\pipe\)" + Pipename; // no need to escape `\` when using a raw string literal via `R"..."`; also, concatenating directly via overloaded operator `+` (i.e., rather than using `sprintf()` with a format string, for example)

  return true;
}

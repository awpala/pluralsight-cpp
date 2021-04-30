#pragma once
#include <string>


class CommandLine
{
private:
  // old way member variables -- N.B. using Hungarian notation for variable names
  char szDriverName[32]; // `sz...` denotes size
  char lpszPipename[256]; // `lpsz...` denotes long pointer to zero-terminated string
  // new way member variables
  std::string DriverName;
  std::string Pipename;
public:
  bool oldway(char* lpCmdLine);
  bool newway(std::string const& CommandLine);
};

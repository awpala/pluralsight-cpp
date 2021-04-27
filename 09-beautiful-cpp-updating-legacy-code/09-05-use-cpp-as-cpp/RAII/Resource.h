#pragma once
#include <cstdio>
using std::FILE;

class Resource
{
private:
	FILE * f = nullptr;
	int* numbers = nullptr;
	int arraylength = 0;
	int linesread = 0;
	char* read = nullptr;
	char line[255];
	size_t const maxlinelength = 255;

public:
	Resource(char const * const filepath);
	bool OK();
	char* GetLine() { return line; }
	int GetLineCount() { return linesread; }
	int ProcessLines();
	int AccessNumber(int index);
	Resource(Resource const& other) = delete;
	Resource& operator=(Resource const& other) = delete;
	~Resource();
};

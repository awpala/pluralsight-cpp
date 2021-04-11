#include "Tweeter.h"
#include <iostream>


Tweeter::Tweeter(
		std::string first,
		std::string last,
		int arbitrary,
		std::string handle
	)
	: Person(first, last, arbitrary), twitterhandle(handle)
{
}


Tweeter::~Tweeter(void)
{
}

std::string Tweeter::GetName() const
{
  return Person::GetName() + " " + twitterhandle;
}

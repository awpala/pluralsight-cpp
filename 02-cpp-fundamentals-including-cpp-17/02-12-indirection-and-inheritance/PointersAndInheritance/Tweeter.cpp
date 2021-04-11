#include "Tweeter.h"
#include <iostream>


Tweeter::Tweeter(
		std::string first,
		std::string last,
		int arbitrary,
		std::string handle
	)
	: Person(first,last, arbitrary), twitterhandle(handle)
{
}

Tweeter::~Tweeter()
{
}

std::string Tweeter::GetName() const
{
  return Person::GetName() + " " + twitterhandle; // since `firstname` and `lastname` are `private` in the base class (`Person`), use the `public` base class method `Person::GetName()` to access these values instead
}

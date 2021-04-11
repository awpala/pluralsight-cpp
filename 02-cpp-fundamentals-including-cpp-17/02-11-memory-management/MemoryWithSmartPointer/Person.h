#pragma once
#include <string>

#include "Resource.h"
#include <memory> // provides `shared_ptr`

class Person
{
private:
  std::string firstname;
  std::string lastname;
  int arbitrarynumber;
  std::shared_ptr<Resource> pResource; // `shared_ptr` is used here instead of a raw pointer

public:
  Person(std::string first, std::string last, int arbitrary);
	// N.B. with a smart pointer member variable, a destructor is not required (nor are the corresponding copy constructors) -- the smart pointer will handle its own cleanup automatically!
  std::string GetName() const;
  int GetNumber() const {return arbitrarynumber;}
  void SetNumber(int number) {arbitrarynumber = number;}
  void SetFirstName(std::string first) {firstname = first;}
  void AddResource();
  std::string GetResourceName() const { return pResource ? pResource->GetName() : ""; } // N.B. An unitialized smart pointer evaluates as `false`
};

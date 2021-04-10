#pragma once
template <class T>
class Accum
{
private: 
  T total;
public:
  Accum(T start): total(start) {};
  T operator+=(T const& t){return total = total + t;};
  T GetTotal() const {return total;}
};

// specialized class template `Accum` for particular type/class `Person`
template <>
class Accum<Person>
{
private:
  int total; // using specific type `int` rather than `T` for the particular semantics of this design
public:
  Accum(int start) : total(start) {};
  int operator+=(Person const& t) { return total = total + t.GetNumber(); };
  int GetTotal() const { return total; }
};

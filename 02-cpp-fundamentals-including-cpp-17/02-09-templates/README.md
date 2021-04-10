# Section 9 - Templates

## Templates

### C++ Implements Genericity with Templates

In C++, **templates** are resolved at compile-time rather than at run-time (i.e,. there are no run-time checks); this slows down the compilation time, but dramatically improves the run-time speed of the application
  * Inasmuch as a program is generally run more often than it is compiled, this is a valuable trade-off

### Write a Class or Function Once

The basic premise of a template is to write a class or function *once* (e.g., `Average()`, `Largest()`, `Smallest()`, etc.), in a manner that is compatible with any artibrary type

Templates additionally provide the ability to design type-safe collections, which are also compatible with algorithms from the Standard Library

In C++, templates often rely on operator overloads

### Much of the Standard Library is Template-Based

The previously seen `std::string` is template-based

The header `<algorithm>` provides many useful features for working with collections (e.g., sorting, searching, element operations, etc.)

Additionally, the collections from the Standard Library are themselves template-based
  * In fact, the old name for the C++ Standard Library was the "Standard Template Library*

## Template Functions

A templated function can be written and used similarly to an ordinary function, e.g.,:
```cpp
/* templated function definition */
template <class T> // identifies a templated function, where `T` is a placeholder for a generic type (called `T` by convention)
T max(T const& t1, T const& t2) // N.B. const& is useful here in case `T` is a complex object
{
  return t1 < t2 ? t2 : t1;
}

/* using the templated function `max()` */
max(33, 44); // int
max(x, 0); // int
max(s1, s2); // string
max(p1, p2); // Person
max<double>(33, 2.0); // returns a double -- compiler deduces the type in this case (i.e., promotes 33 to a double)
```

N.B.The Standard Library already provides a templated function `max()`, however, it is useful here for illustrative purposes

### **DEMO: Template Functions**

cf. `/FunctionTemplate`

## Template Classes

In addition to templated functions, C++ also provides the ability to create and use templated classes (e.g., the collections in the Standard Library)

For example:
```cpp
/* templated class defintion */
template <class T> // N.B.As before, `T` is a placeholder type
class Accum
{
  private:
    T total;
  public:
    Accum(T start): total(start) {};
    T operator+=(T const& t) {return total = total + t;};
    T GetTotal() const {return total;};
};

/* using the templated  class `Accum` */
Accum<int> integers(0); // specify the type when using the class
Accum<string> strings("");
```

N.B. Template implementations are typically in header files (i.e., as opposed to implementation in a separate source file)

N.B. C++17 introduced automatic type deduction for templated classes (e.g., `Accum<> integers(0);`, `Accum<> strings("")`, etc.)

### **DEMO: Template Classes**

cf. `/ClassTemplate`

## Template Specialization

Sometimes a template will not work for a particular class
  * An operator or function is missing (and you cannot add it)
  * Logic in the operator will not work for this case

The first choice is always to add the operator or function with the intended logic

The second choice is to **specialize** the template, i.e., to define the templated class for a particular type

### **DEMO: Template Specialization**

cf. `/Specialization`

## Summary

Templates add tremendous power and flexibility to C++
  * Compile-time checking means no run-time performance hit for genericity

Currently (as of C++17), the author of the code that uses templates must ensure that types are compatible with the template chosen
  * This typically involves evaluating the template's code, though compiler error messages are improving over time to facilitate this (e.g., identifying specific functions or operators that must be implemented to use the template)

Template specializations let you handle special cases

Many C++ developers never write a template; however, it is still a useful skill, as is understanding how to read and to use code for preexisting templates

All good C++ developers should use templates
  * Save development time
  * Error checking and edge cases are not forgotten
  * Flexibility in the face of future enhancements
  * Perservation of run-time performance and type safety

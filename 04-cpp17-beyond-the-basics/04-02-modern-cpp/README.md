# Section 2 - Modern C++

## What Makes C++ Modern

Modern C++ is...
  * *expressive*: choose keywords and constructs (e.g., range-based `for` loops) that suit specific needs
  * *fully C++*: do not reject lambdas, templates, `const`, and/or other recent additions to the language
  * *readable*: do not write obscure or opaque code
  * *stack semantics*: pointers are not your first choice anymore; it is simple avoid manual memory management (i.e., raw pointers) using modern C++
    * Objects are created on the stack, and any pointer member variables are smart pointers which are managed in an RAII manner automatically

## Fundamentals Review

### C++ and Libraries

The C++ Standard Library is not the largest (e.g., as compared to Java and .NET), but it is still large and growing
  * The Standards Committee is actively working on bridging gaps in the Standard Library
  * "Smaller" does not imply non-existent--do not ingore what is already available!

#### The Standard Library

Each compiler vendor (e.g., MSVC, gcc, clang, etc.) includes an implementation of the Standard Library

The function signatures and performance characteristics are established by the Standards Committee

The Standard Library is shipped as only header files; include only what you use, e.g.,:
```cpp
#include <string>
#include <vector>
```

### Standard Library Smart Pointers

Recall that in modern C++, raw pointers are raraely used; instead, if it is necessary to perform lifetime management of a resource, raw pointers are wrapped in **smart pointers**, which are stack-based objects containing a destructor which handles cleanup of the free store memory that was allocated
  * `shared_ptr` achieves this with reference counting, with the destructor being called automatically when the reference count reaches `0`
  * `weak_ptr` (a companion to `shared_ptr`) lets to "peek into" a `shared_ptr` and use the pointer without contributing to the reference count, thereby not impacting the pointer's lifetime
  * `unique_ptr` is the best starting point; it is slightly more difficult to use since it is non-copyable (relying on **move semantics** via `std::move` instead), but just like `shared_ptr`, when `unique_ptr` goes out of scope (i.e., when no more copies remain) its destructor is called automatically

Smart pointers operate on an intuitive basis: while the object is still in scope the pointer is still usable, otherwise when the object goes out of scope the pointer is automatically destroyed

### `const`

`const` is a way to commit to the compiler that you will not change something, e.g.,:
  * When declaring a local variable (e.g., `int const zero = 0;`)
  * As a function parameter (e.g., `int taxes(int const total);`, `int something(Person const& p);`, etc.)
  * As a modifier on a member function of a class (e.g., `int GetName() const;`)

`const` correctness can be difficult
  * It is more difficult to add `const` correctness after developing and building, therefore it is instead advisable to incorporate `const` correctness from the beginning during the design and development processes (it is much easier to remove `const` later if necessary)

#### `const`: Before or After?

From the compiler's perspective, the following two styles are semantically equivalent:
```cpp
int const ci = 3; // style 1 (`const` after)
const int ci = 3; // style 1 (`const` before)
```

However, these styles are distinct in their readability; accordingly, `const` after style is recommended due to its more intuitive expression of pointers and references--`const` is simply placed *after* the thing that will not change (e.g., `ci` is an `int` that cannot change)
  * N.B. This course will use `const` after style exclusively

### The Standards Process

While some programming languages are managed exclusively by a single vendor, this is not the case for C++; C++ is governed by the **ISO Standard Committee** (e.g., keywords, punctuation, Standard Library capabilities, etc.)
 
 C++ is under the auspices of ISO WG21 (Working Group 21), comprised of study groups and technical specifications which work to propose new features

As of the last decade or so, the Committee has released a new version of the C++ standard at a cadence of approximately once every three years

#### Standard Releases

**C++11** was a milestone revision to the standard (the previous standard, C++03, was a minor addendum to the previous major release, C++98); C++11 introduced many powerful features, including:
  * Move semantics and rvalues
  * `auto` compiler deduction
  * Range-based `for` loops
  * Lambdas
  * Scoped enumerations (also called enum classes)
  * Variadic templates
  * Defaulted and deleted functions
  * `std::tuple`
  * Smart pointers
  * ...and much more!

**C++14** subsequently added the following:
  * Generic lambdas
  * Capture expressions in lambdas
  * Standard user-defined literals

**C++17++** added:
  * Structured bindings
  * `if` initializers
  * Class template type deduction from arguments
  * `string_view`
  * `std::optional`
  * Parallel versions of all of the algorithms

N.B. While an encyclopedic knowledge of these features is not necessary for writing modern C++, eschewing them altogether is!

This course will cover many of these modern features, though not necessarily in chronological order, but rather they will be introduced when they are useful for the topic at hand

## Summary

Modern C++ is readable and simple

Use the full power of the C++ language and the Standard Library

Emphasize expressing your intent while minimizing your effort

Modern C++ is very different from the older "C with Classes"-style C++

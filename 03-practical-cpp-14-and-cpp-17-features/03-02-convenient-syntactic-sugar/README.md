# Section 2 - Convenient Syntactic Sugar

## Introduction

### Prerequisites and Learning Objectives

C++11 was a massive improvement over the previous C++98 and C++03 standards

Subsequently, C++14 and C++17 were more incremental additions to C++11--however, these later standards nevertheless introduced several important features which extend the "modern C++ programming" landscape
  * These standards provide tools for writing simpler, clearer, higher-quality C++ code

N.B. A basic knowledge of C++11 is a prerequisite for this course
  * Any additional concepts will be introduced in this course in the context of the corresponding C++14/C++17 feature

N.B. If C++14 is already familiar, you can skip directly to Section 6 (*Practical Convenient C++17 Language Improvements*)

### Standard C++

This course covers standard, cross-platform C++ (i.e., without relying on any platform-specific extensions)

N.B. The course video demos will use the clang compiler
  * Corresponding code in this repository will use the GCC C++ compiler

## Digit Separators

Digit separators improve readability of long numbers by grouping numbers in a human-readable way

C++14 introduced digit separation via `'` (character U+0027), e.g.,:
```cpp
long x = 10'000'000;
long y = 10'00'00'00; // == x
double EarthDiameterKm = 12'742;
```

N.B. The position of `'` is arbitrary (the compiler ignores it altogether), however, it is a best practice to use it sensibly (e.g., `1'000` is more sensible than `1'0'0'0`)

## Binary Values

C++14 introduced the write binary literals via prefix `0b` (or `0B`) e.g.,:
```cpp
auto d = 0b01000111;
auto word = 0b01000111'01000011; // can also use digit separator `'` in binary literals
```

## Automatic Return Type Deduction

C++14 introduced the ability for the compiler to automatically deduce the return type of functions (via keyword `auto` as the return type), e.g.,:
```cpp
auto AreaOfSquare(double side) {
  return side * side; // compiler deduces return type of `double`
}
```

Automatic return type deduction is particularly useful for templates and cumbersome/"noisy" types, e.g.,:
```cpp
auto ComplexFunctionTemplate(...) {
  // complex template code ...
  return result;
}
```

Automatic return type deduction is also useful for avoiding the need to indicate the return type *twice*, e.g.,:
```cpp
auto BuildCoolMap() {
  std::map<std::string, SomeLongValueType> result;
  // fill the `result` object
  return result; // `auto` deduces the type `std::map<std::string, SomeLongValueType>`
}
```

There is a balance/trade-off in using `auto` return type deduction: looking *inside* the function implementation vs. *not* having *repeated* type information (particularly when dealing with long, cumbersome types)

## Summary

Digit separators promote writing clearer numeric literals

Binary literals are convenient for working with binary forms

Automatic return type deduction simplifies code by avoiding repetition of long, cumbersome types

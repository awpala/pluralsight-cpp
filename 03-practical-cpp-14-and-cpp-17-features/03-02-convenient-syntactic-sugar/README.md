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





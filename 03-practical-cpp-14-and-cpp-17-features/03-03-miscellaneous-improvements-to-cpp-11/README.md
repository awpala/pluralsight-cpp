# Section 3 - Miscellaneous Improvements to C++11

## Relaxed `constexpr` Functions

### The C++ Compilation Model

To understand `constexpr` functions, consider a refresher of some key points of the C++ compilation model (cf. https://bit.ly/CppComp)

The **C++ compiler** is essentially a *translator* from C++ source code to an executable binary file (machine code that is understood and executed by the CPU)

There are two distinct phases of a program:
  1. **Compile-time**: the compiler is translating your code (i.e., source code to binary)
  2. **Run-time**: the CPU is executing your program

Interestingly, there are some kinds of computations that can be performed earlier (i.e., at compile-time rather than at run-time); this means that the result is *already* avaiable at run-time
  * Performing extensive computations during compile-time (as opposed to run-time) is a key feature of C++, which lends to its high performance

### `constexpr` Functions

In C++, ordinary functions are executed at *run-time*, e.g.,:
```cpp
double DoSomething() {
  // ...
}
```

However, in C++11, `constexpr` functions were introduced, which are executed at compile-time, e.g.,:
```cpp
constexpr double DoSomething() {
  // ...
}
```

C++11 imposed several restrictions on `constexpr` functions (e.g., cannot use `if` or `for` statements inside the function body)

However, C++14 *relaxed* may of the highly-constraining `constexpr` requirements of C++11, e.g.,:
  * Permitting declaration of local variables inside the function body
  * Permitting use of control flow statements (e.g., `for`, `if`, `switch`, etc.)

### **DEMO: Relaxed `constexpr` Functions in Action**

cf. `Fibonacci.cpp`

cf. `FibonacciC.cpp` (`constexpr` version)

cf. `FibonacciC1.cpp` (not compilable -- has invalid static assertion)

N.B. `static_assert()` performs compile-time checking (i.e., as opposed to run-time checking)
  * Verifies correctness of the `constexpr` function during compilation

## Variable Templates

### Class Templates

Recall (cf. https://bit.ly/CppStdVector) that class templates provide type-generic behavior, e.g., `std::vector<T>` (of generic type `T`) can be used to instantiate container instances of different types (e.g., `std::vector<int>`, `std::vector<double>`, `std::vector<std::string>`, `std::vector<image>`, etc.)

### Function Templates

Additionally, recall that C++ provides generic function templates as well, e.g.,:
```cpp
/* function template */
template <typename T>
T Max(T a, T b) { // N.B. In practice, better to use parameters `const T& a` and `const T& b` for performance
  return (a > b) ? a : b;
}

/* compiler-generated function declarations */
int Max(int, int);
double Max(double, double);
// etc.
```

### C++14 Variable Templates

C++14 extends the concepts of templates by allowing for the definition of **variable templates**, e.g.,:
```cpp
// value of pi for generic type `T`
template <typename T>
constexpr T pi = T(3.141592653589793238462643383);


// compiler-generated variables
pi<double> // more precise, but occupies more memory
pi<float> // less precise, but occupies less memory
```

### **DEMO: Specializing Variable Templates**

cf. `VariableTemplates.cpp`

## The Attribute `[[deprecated]]`

### Codebase Evolution

The source code of actively maintained software projects is *dynamic*, i.e., it changes over time

C++14 introduced the attribute `[[deprecated]]`, which can be used to decorate an entity (e.g., function) that is still useable but being changed, e.g.,:
```cpp
[[deprecated]] // minimal version 
void DoSomething() {
  // code -- should not be used
}

[[deprecated("DoSomething is inefficient")]] // longer form to include custom message describing reason for deprecating
void DoSomething() {
  // code -- should not be used
}
```

### **DEMO: Deprecating Code**

cf. `Deprecated.cpp`

## Summary

C++14 introduced relaxed `constexpr` functions, which are executed at compile-time during compilation, rather than ordinary functions which execute at run-time during program execution

Variable templates are a C++14 addition which complements the previous class and function templates

The attribute `[[deprecated]]` is used to discourage use of deprecated features/entities in the codebase

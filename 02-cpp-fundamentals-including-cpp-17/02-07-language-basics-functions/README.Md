# Section 6 - Language Basics: Functions

## Free Functions

In C++, a function does not have to be a member of a class; such a "standalone" function is called a **free function** 

For example:
```cpp
int DoubleIt(int x) // parameter `x` is taken by value (normal/default behavior) -- `x` inside of the function body is a copy
{
  x = x * 2;
  return x; // `x` is returned by value -- the coresponding argument from the calling scope is unchanged
}
```

Arguments can also be passed by reference, for example:
```cpp
int DoubleIt(int& x) // `x` is taken by reference via `&`
{
  x = x * 2;
  return x; // `x` is returned by reference -- the corresponding argument from the calling scope is changed
}
```

N.B. Passing by reference will be discussed later in the course in the context of indirection

### **DEMO: Free Functions**

cf. `/FreeFunctions`

## Member Functions

When you write a class...
  * The class is declared (i.e., in a header file, `.h`)
  * The member functions of the class are implemented (i.e., in a source file, `.cpp`)
    * Member function implementations use the fully qualified name via operator `::` (e.g., `Person::GetName()`)

A member function can also be implemented "inline" within the declaration; this is particularly useful for short function definitions

Regardless of where a member function is implemented (i.e., "inline" or in a separate implementation file), it should be marked as `const` unless it cannot be (i.e., the intended logic requires changing the member variables)
  * This is useful for both compiler optimizations as well as communicating intent of the code
  * It is a **best practice** to add `const` during design than *after* the code has been written

### **DEMO: Member Functions**

cf. `/MemberFunctions`

## Understanding Error Messages

### Building

In the build process, when a program is split across multiple files (e.g., multiple header files and source/implementation files), preprocessor directives such as `#include ...` are "promises" to the build system

### Error Messages

In the build process, if errors occur, it is important to understand whether the error(s) originate from the compiler and/or the linker
  * **compiler**: have you *declared* that function?
    * usually declared in a header file `.h`
    * compiler errors occur around "*making* a promise"
  * **linker**: have you *implemented* that function?
    * usually implemented in a source file `.cpp`
    * linker errors occur around "*keeping* a promise"

### **DEMO: Understanding Error Messages**

cf. video (making deliberate errors in `.h` and `.cpp` files to generate compiler and linker errors, respectively)

N.B. The IDE is useful for detecting errors (e.g., Visual Studio identifies compiler errors with error codes `C...` and linker errors with error codes `LNK...`)

N.B. If many errors are generated, start by resolving the first one and re-building, and iterating in this manner
  * Errors subsequent to the first one oftentimes can be generated as "cascades" stemming from the first error

## Causes of Error Messages

### Different Mistakes, Different Errors

The following examples generate compiler errors:
  * Typing the name incorrectly when calling a function
  * Passing the incorrect number or types of arguments when calling a function
  * Incorrect function declarations
  * Incorrect function implementations (also generates a corresponding linker error in the calling code)
  * Omitting a header file inclusion when calling its function
  * Omitting a header file inclusion when implementing its function (also generates a corresponding linker error in the calling code)

The following examples generate linker errors:
  * Omitting a function implementation
  * Omitting an implementation file in the build system

## Summary

Functions in C++ can be either free functions (not belonging to a class) or member functions (belonging to a class); either way, functions must be declared before they are called
  * Conventionally, functions are declared in header files (`.h`)

Function declarations are included...
  * In the class declaration for member functions
  * Usually in the header file for free functions

Functions are implemented somewhere where the linker will use them (e.g., in an implementation file, `.cpp`)

Functions can take arguments by value or by reference
  * The corresponding parameters can perform side effects on arguments passed by reference; if this is not desired, then the parameters can also be declared as const reference (i.e., `const&`)

Understanding the build process and error messages will not be a mystery if you have an intution for where the errors originate (i.e., compiler vs. linker)
  * Error messages can "cascade", therefore resolve the first-occurring error message first, rebuild, and then iterate in this manner until all errors are resolved

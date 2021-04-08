# Section 3 - Stream I/O and Local Variables

## Libraries

Some languages provide **keywords** to perform specific tasks (e.g., `print`, `eval`, `call`, etc.)

C++ uses functions, objects, and classes for just about everything, and attempts to avoid adding superfluous keywords
  * C++ even uses these constructs in places that do not resemble function calls (as will be seen later)

Both functions and classes can be distributed in a **library**
  * These are then **linked** into the application along with your object files, or **included** into your code to be compiled

A library called the **Standard Library** comes with your tools (i.e., the compiler)
  * Furthermore, the tools are configured to know where to find it

## Stream I/O

The C++ Standard Library is *enormous*; covering it exhaustively is beyond the scope of this course
  * In practice, it is less important to have an "encyclopedic" knowledge of the Standard Library as it is to be able to navigate it effectively for the specific intended use case(s)

**I/O** stands for **input/output**
  * The **input** typically represents the keyboard
  * The **output** typically represents the screen

I/O also applies to reading out of and writing into **files** (e.g., text files), as well as other sources/targets that support **streaming**

This streaming concept is in contrast to "record-based" or "fixed" I/O used historically; for example, streaming would *not* be amenable to the following use cases:
  * Databases
  * One line in the middle of a large file

However, stream I/O is very useful nonetheless, and C++ supports stream I/O with **operators**:
  * `<<` sends something to a stream
  * `>>` reads something from a stream

Furthermore, the Standard Library can create **objects** to use the operators with:
  * `cout` is the **console output** (e.g., screen)
  * `cin` is the **console input** (e.g., keyboard)

For example:
```cpp
std::cout << "Hello!";
std::cout << "Hello!\n";
std::cout << "Hello!" << '\n'; // equivalent to previous line
```
N.B. `\n` is an **escape sequence**, which can be embedded in a string literal to create a newline (e.g., `Hello\n`).

### **DEMO: Stream Output**

cf. `Output.cpp`

## Some Syntax Notes

Anything from `\\` to the end of the line is a **comment**, even if it looks like code (i.e., "commented out" code)

`"..."` (double quotes) and `'...'` (single quotes) are distinct -- look closely to avoid mixing these up!
  * Single quotes are only used for *single* characters, including escape sequences (e.g., `'\n'`)
  * Double quotes are used to create a **string literal** (which will be examined later)

Remember that almost every line is terminated with `;` (semicolon)
  * Exceptions to this will be encountered later

### **Exercise**

Write your own version of `Output.cpp` that prints out some words and some numbers.
  * Use double quotes `"` not single quotes `'` around words and groups of words
  * Use as many `\n`s as desired
  * Numbers can be calculated (e.g., `2 + 2`) or entered directly (e.g., `42`)
  * Try some non-integer numbers too and examine the resulting behavior

Do *not* ask for the impossible, e.g.,:
  * `3/0`
  * `"hello" + 2`
  * etc.

The errors for these mistakes will not make sense (yet!)

Get in the **habit** of writing code incrementally: building and testing, and then iterating this process

## Include

**Including** a file into your application is done using the **preprocessor directive** `#include` (e.g., `#include <iostream>`)
  * This opens up a world of libraries and capabilities

For some libraries, it is also necessary to **link** in the library (e.g., header-only libraries); this will be discussed later

## Namespaces

Good libraries are in a **namespace**. To use something that is in a namespace, use the **fully qualified name** (via the **scope resolution operator** `::`), e.g.,:
```cpp
std::cout << 2+2 << "Hello!"; // `std::` denotes the standard library namespace
```

Namespaces prevent conflicts if other libraries use the same names

To save typing, the statement `using` can be applied to use an entire namespace or just a piece(s) of it (the latter is usually a better practice, as it prevents ambiguity and additionally serves as a form of "documentation," i.e., explicitly identifying the specific component(s) being used), e.g.,:
```cpp
using namespace std; // entire standard library namespace
using std::cout; // just the object `cout`
```

## Local Variables

Rather than relying on hard-coded values (i.e., **literals**), applications are more interesting when they are able to perform calculations and other actions; the first step towards this goal is to use **local variables**

In C++, **variables** have an associated **type** (e.g., string, number, date, Employee, etc.)
  * Some types are built into the language (e.g., integers)
  * Other types are **user-defined**
    * N.B. Some "users" are actually Standard Library authors

Variables must be **declared** before they are used; part of this declaration is to specify the variable's type, e.g.,:
```cpp
int limit; // variable `limit` is declared as an integer type
float rate; // variables `rate` is declared as a floating-point type
```

**Built-in types** are *not* automatically **initialized** with a value, but rather contain a "garbage"/insignificant value; conversely, user-defined types may be automatically initialized by design

Therefore, as a **best practice**, declare and initialize variables simultaneously, e.g.,:
```cpp
int limit=100;
float rate=0.23;
```

Furthermore, if initializing during declaration, the compiler can be used to **deduce** the type automatically via keyword `auto`, e.g.,:
```cpp
auto x = 7; // `x` is an int
```

## Type Safety

C++ enforces types (i.e., C++ is a **type-safe** language)
  * Upon declaration, **variables** have an associated type which cannot be changed subsequently in the program
  * Similarly, **expressions** have an associated type

In C++, it is permissible for a type to be **promoted**, e.g.,store an `int` (e.g., `3`) into a `float` (i.e., promoted to `3.0`)

However, attempting to **demote** a type will generate a compiler warning, e.g., )store a `float` (e.g., `4.9`) into an `int` will result in truncation (i.e., demoted/truncated to `4`)

Certain nonsensical combinations are simply not allowed at all by the compiler, e.g.,:
  * Attempting to store a string in an integer
  * Attempting to multiply a string and a float

### **DEMO: Local Variables**

cf. `LocalVars.cpp`

## Keyboard Input

You can store keyboard input into a local variable via `std::cin` from `iostream`, e.g.,:
```cpp
std::cin >> i;
```

The Standard Library takes care of parsing, however, the type rules still apply in agreement with type safety

### **DEMO: Keyboard Input**

cf. `Input.cpp`

## Summary

The **C++ Standard Library** provides all you need to read from the keyboard or to write to the screen

In C++, all **variables** have a type that does not change throughout the lifetime of the program

All **expressions** also have a type

The compiler enforces a number of **rules** related to the type system

Users (e.g., you, library authors, etc.) can define new types (discussed later)

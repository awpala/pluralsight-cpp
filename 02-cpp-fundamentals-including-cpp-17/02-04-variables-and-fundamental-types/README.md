# Section 4 - Variables and Fundamental Types

## Language Basics: Variables

C++ is a **strongly typed** language
  * Variables can only hold ***one*** type of value throughout the lifetime of the program
  * Variables must be **declared** before they are used, and their type cannot be changed subsequently thereafter
  * "*The compiler is your friend*"

C++ provides fundamental **built-in types** (e.g,. numbers, booleans, and single characters)

Additionally, C++ allows for **user-defined types** (e.g., by application developers, library writers, etc.)
  * Examples include strings, dates, business objects, etc.
  * In C++, user-defined types can be created as structs and/or classes (these are discussed later in the course)

In C++, user-defined types are *full participants* in the language (i.e., their behavior is idiomatic/resembling of built-in types when properly designed to do so)

## Fundamental Types

C++ provides **integers**: `short`, `long`, `int`
  * N.B. `int` is designed to be sized appropriately to the target machine, and is a useful "default" choice among these
  * C++ also provides `unsigned` and `signed` designations for integers

C++ provides **real numbers**: `float`, `double`
  * `double` is a double-precision floating-point number

C++ provides **characters**: `char`, `unsigned char`
  * N.B. While in practice characters are used to hold letters, the compiler simply views them as small integers

C++ provides **Booleans**: `bool`
  * The two Boolean literals are `true` and `false`

## `auto`

There are times when it is tedious or difficult to identify the explicit type of a variable; the keyword `auto` helps to resolve this issue

`auto` asks the compiler to deduce the type (i.e., based on the value or expression used to initialize a variable)

A variable whose type is deduced by `auto` is still strongly typed

`auto` is particularly useful for avoiding having to write "ugly" declarations (e.g., long iterator declarations, as will be discussed later in the course)

When using lambdas (discussed later), `auto` can also be useful and sometimes even necessary (i.e., when the type cannot be manually deduced a priori)

## **DEMO: Fundamental Types**

cf. `VariablesAndTypes.cpp`

N.B. To build the executable using Linux Ubuntu running g++, compile from command line or use an IDE tool (e.g., Visual Studio Code with `Code Runner` extension). For example, via Linux command line (where `$` is the terminal prompt running from the directory containing the source code file `VariablesAndTypes.cpp`):
```
$ g++ VariablesAndTypes.cpp -o VariablesAndTypes
$ ./VariablesAndTypes
```

N.B. cf. https://docs.microsoft.com/en-us/cpp/cpp/fundamental-types-cpp for a comprehensive list of C++ built-in data types, and https://docs.microsoft.com/en-us/cpp/cpp/data-type-ranges for ranges of values that each built-in data type can hold

## Casting

The compiler will (implicitly) convert between types if it is sensible and possible to do so (e.g., promote an `int` to a `double`)
  * This requires the types to be compatible; nonsensical conversions are not performed but rather generate a compiler error (e.g., attempting to convert a `char` to a string literal)
  * Attempting to create a conversion to a less precise data type (e.g., demoting a `double` to an `int`) may be permissible but will generate a warning

C++ additionally provides an explicit **casting** mechanism to make intentional type conversions more explicitly clear
  * However, the operative word here is "intentional": a cast should *not* be used simply to resolve a compiler warning if that is not the true intention

It is recommended to use C++'s **safe casts** (also called **templated casts**) to perform explicit type conversions: `static_cast<>` (e.g., `static_cast<int>`)
  * N.B. C-style casts (e.g., `(int)`) can be unsafe and are not generally recommended to use in modern C++ programs

N.B. Suffixes can also be used to denote the type of a literal (e.g., `L`/`long`, `f`/`float`, `u`/`unsigned`, etc.), which similarly serve to be more explicit about the intended data type

### **DEMO: Casting**

cf. `Casting.cpp`

## Summary

Variables have a type and must be declared before they are used

Different types hold different kinds of data
  * Have different lengths and ranges of values
  * The compiler knows and will help you

Be aware that overflow/underflow can occur silently (i.e., without compiler error)
  * Avoid using very small types like `char` for numbers

To instruct the compiler that you know what you are doing, use a safe cast (e.g., `static_cast<>`) to be explicit






# Section 3 - Macros, Old Keywords, More Pointers, and `printf`

## Macros

Macros are an old C construct that used to be a prominent part of C++ code, e.g.,:
```cpp
#define PI 3.14
```

Defining macros in this manner only performs a literal substitution; in modern C++, a more type-safe approach is to use a `const` instead (or perhaps a `static` member variable, inside a namespace, etc.)

In older C++ programming style (and remeniscent of C), macros were used to perform increasingly complicated tasks, such as defining "functions", e.g.,:
```cpp
#define SQR(x) (x*x)
```

However, this is unsafe as it does not provide type safety (it is simply a literal text substitution)

Furthermore, if written incorrectly, it can produce an unintended result (e.g., `SQR(1+1)` will expand to `(1+1*1+1`, *not* `((1+1) + (1+1))`)

A better approach would be to simply use a function, or a templated function if multiple types must be used

N.B. Modern IDEs do provide better analysis of macros to facilitate understanding their expansion, however, their use is still considered to be a bad practice in modern C++

### **DEMO: Macros**

cf. `macros.cpp`

## `typedef`

Similarly to a macro, a `typedef` is a way to provide an alternate name; however, instead of an arbitrary literal expression (as in the case of a macro), a `typedef` names a type

A `typedef` defines a "synonym" that appears to be a new type, but actually is just a new name for an existing type (e.g., `typedef int BOOL`)

`typedef`s are used for a variety of reasons:
  * To make code more portable
  * For expressivity/readability
  * To reduce typing or "fear" of templates via `<..>` (e.g., `typedef std::vector<int> VectorOfInt; VectorOfInt numbers;`)

## Function Pointers

Function pointers are rarely used in modern C++; however, their corresponding *uses* are still commonly used (e.g., decide at run-time what function to execute; this is very powerful)

In C (and corresponding legacy C++), function pointers provide the only way to accomplish this

However, modern C++ has **polymorphism** to achieve the same feature (e.g., `Account->Update()` will use the correct subclass's method called `Update()`)
  * Polymorphism also provides the additional benefit of type safety

Additionally, C++11 introduced **lambdas**, which allow to put the *actual code* to execute (rather than a function pointer) as a parameter to another function call

### Function Pointer Syntax

Declaring function pointers is tricky, so it is very common to use a `typedef`, e.g.,:
```cpp
// `CHANGER` is a function pointer which takes two `int` parameters and returns an `int`
typedef int (*CHANGER)(int i, int j);

// declare an instance of `CHANGER` called `Method`
CHANGER Method;

// initialize `Method`
Method = CalculateSlowly; // N.B. `()` is not used to initialize a pointer function (i.e., not `CalculateSlowly()`)

// call `Method` via `(...)`
Method(a, b);
```

The example shown above demonstrates a function function pointer for a free function; working with pointers to member functions in C++ is even more complicated, e.g.,:
```cpp
// include class name (e.g.., `Utility`) when setting up the `typedef`
typedef int (Utility::* UF)();

// use the class name and operator `&` when setting
UF action;
action = &Utility::triplex;

// use `*` to call via dereference with a specific instance `u`
return (u.*action)();
```

### **DEMO: Function Pointers**

cf. `FunctionPointers.cpp`

## Casting

Old C++ code commonly uses C-style casts via `(...)`, e.g.,:
```cpp
int i = (int) 4.9;
```

The more modern C++ style is to perform explicit casting via the templated cast `static_cast<>`, e.g.,:
```cpp
int i = static_cast<int>(4.9);
```

C-style casts do not provide comprehensive type safety, allowing for other kinds of casts using the same syntax, e.g.,:
```cpp
p = (Employee*) input; // if `Employee` is in an inheritance hierarchy, slicing may occur
x = (Transaction) t;
```

Many other anomalies can occur with C-style casts, e.g.,:
  * Casting away `const`
  * Data trunctation or loss (e.g., casting `float` to `int`, `unsigned` to `signed`, etc.)

Therefore, C-style casts are tricky to work with because they can oftentimes "hide" the actual kind of cast that is being performed
  * Templated casts are recommended as a a better (i.e., type-safe) alternative

## `void*`

The idea of a **void pointer** (i.e., `void*`) can be confusing to the uninitiated observer

`void*` is neither a pointer to "nothing" (i.e., "pointer to `void`) nor a null pointer; rather, `void*` is a used to indicate a pointer to *anything* (i.e., of no particular *type*)

Any pointer type (e.g., `char*`, `Employee*`, `int*`, etc.) can be cast to `void*`; this is a form of **type erasure**
  * However, `void*` cannot be used as-is, but rather must be cast to a specific type

N.B. `void*` is used commonly as a function parameter

While casting to `void*` loses the type information, a `void*` pointer can be cast back to a specific type

In modern C++, however, this sort of type erasure is generally unnecessary; rather, polymorphism or dynamic casting can be used to achieve the same purpose
  * Type erasure removes the type safety of C++, which is one of its key features

## `printf()`

Legacy C++ code often uses `printf`, which is the C-style way of writing output to the screen/console, to files, etc.
  * The name `printf` denotes "print with format"

`printf` takes a variable number of parameters, however, the first parameter is called a **format string**, which is a mix of literal text and placeholders (called **format specifiers**)

For example:
```cpp
printf("Array total: %d \n", total); // `%d` is substituted with the value of `total` in the output
```

### Format Strings

The format specifiers `%s` (string), `%d` (digit/`int`), `%f` (`float`), and `%x` (lowercase hexadecimal digit) are very common

Additionally, **escape sequences** can be used, e.g., `\n` (newline), `\t` (tab), etc.

The format string can also be decorated/formatted with details (e.g., number of decimal places, leading zeros, padding, etc.), e.g.,:
```cpp
printf("Return address: 0x08%x\n", return_address);
printf("In File: %s (Line: %d)\n\n", file_name, line_number);
```

N.B. For purposes of *reading* code, the specific meaning of each particular format specifier is rarely vital and can be inferred from the corresponding output
  * Consult the appropriate online documentation for further assitance if necessary

### **DEMO: `printf()`**

cf. `printf.cpp`

N.B. cf. https://en.cppreference.com/w/cpp/io/c/fprintf for full reference of format specifiers

## Summary

Much of C++'s reputation for difficulty stems from old constructs
  * In practice, these is rarely needed in modern C++ code

You can read and learn about the old-style C++ as you encounter it, but do *not* use it as a starting point
  * Never copy-and-paste without understanding (e.g., referencing legacy C++ sources rather than modern ones)

Modern IDEs provide a lot of assistance with reading macros and `typedef`s
  * Even the C++98 code itself is easier to work with using modern tools!

C-style casts, `void*`, and `printf` can hide a lot of bugs
  * If the code works, do not rush to change it, as it may be brittle (and certainly do not reference it to write new/modern code!)

# Section 5 - Functions and Headers

## Functions

To use a function, you simply **call** it

However, before this can be done, the compiler must be "aware" of the function; formally, this "awareness" is called a **function declaration** (or **function prototype**)

In addition to a function declaration, the function itself must be *implemented* somewhere; this implementation is called the **function definition**

The "somewhere" can be anywhere; the **linker** will link the function to the code that calls it

### Examples of Functions

```cpp
// this is a function definition
int add(int x, int y) // `x` and `y` are input parameters fo function `add`
{
  return x + y; // function `add` returns an int
}

// this is a function call
int a = add(3, 4);
```

In the function definition shown above, the **function header** has the following **general form** (consisting of its **return type** and input **parameters**):
```
returnType functionName(firstParamType firstParamName, secondParamType secondParamName, ...)
```

N.B. The compiler enforces type rules when a function is called (e.g., in the function call shown above, `a` must be of type `int` to store the return value of function `add`)

## Type Safety

Recall that C++ is a **type-safe** language
  * When you call a function, the **arguments** that you supply might be converted if their types are disparate from the parameters that the function takes
    * This is possibly risky, and typically will generate a compiler warning
  * Furthermore, the return value from the function might be converted as part of assigning the value

N.B. This type safety in the context of functions usage is an illustrative example of a **key principle**: *the compiler is your friend!*

## Overloads

A key feature of C++ is that it allows for a function name to be reused; this is called **overloading**

Therefore, in C++, there is no need to twist names to include parameter information (e.g., `add2` and `add3` as two variations of an addition function)

Two (or more) functions can have the same name as long as the compiler can distinguish them
  * Taking a different number of arguments is a candidate for distinguishing overloads
  * However, note that the return type alone *cannot* be used to distinguish overloads (i.e., while otherwise having hte same parameters list)

N.B. Taking the same number of arguments, but of different types, is risky (due to type conversions)

### **DEMO: Overloads**

cf. `Overloads.cpp`

## Multiple Files

In theory, a C++ application can be one large, monolithic `.cpp` file
  * This requires compiling the file when making any changes, which becomes cumbersome as the file size grows
  * This also precludes simple coordination of work among several developers
  * This also makes it difficult to find what you want to change (e.g., in a 10,000-line or even larger file)

### Building

Recall that in C++, the build process is as follows:
  1. source file (e.g., `example.cpp`) is compiled to an object file (e.g., `example.o`)
  2. The object file is then linked to an executable file (e.g., `a.out`)

### Building with Multiple Files

In practice, a C++ application is split over multiple files

The compiler is instructed to compile each file and then the linker is instructed to link them together
  * The mechanics for this process vary from tool to tool and platform to platform

### **DEMO: Multiple Files**

cf. `/MultipleFiles`

N.B. To compile, link, and run this program (using Linux Ubuntu), navigate to the directory `/MultipleFiles` in the terminal/command line and then issue command `make` to run the commands in the makefile (discussed later in the course). Then, to run the executable from the terminal, issue the comand `./MultipleFiles`. Thus (where `$` is the terminal prompt, *not* part of the command):
```
$ cd /MultipleFiles
$ make
$ ./MultipleFiles
```

## Header Files

Note the following **important rule**: To use a function implemented in other files, you must inform the compiler about it
  * Long collections of declarations in many files have disadvantages, however; furthermore, this is challenging to maintain, and it can obscure the "more important" code

To address these issues, **header files** allow to put declarations in a *single* separate file that is included into each file that uses them as you compile the files; this can be done using `#include` (cf. `#include <iostream>`, which includes features from the Standard Library)

N.B. Any line beginning with `#` is an instruction to the preprocessor (called a **preprocessor directive**), which is a step that runs before the compiler

When a header file is included (i.e., via `#include ...`) the entire contents of that file are pasted in, and then during subsequent compilation the entire file is compiled as a single **translation unit**; this results in code that is neater, easier to undrestand, and easier to maintain

N.B. While `#include <...>` is used to include header files from the Standard Library (e.g., `#include <iostream>`), user-defined header files are included via `#include "..."` (e.g., `#include "MyHeader.h"`)

### **DEMO: Header Files**

cf. `/HeaderFiles`

N.B. Use makefile to compile and run this program (cf. `Multiple Files` demo above for full instructions)

## Building with Multiple Files

When working with multiple source files, as part of the compilation step, the preprocessor pastes in the contents of the `#include`s (any repetition/redudancy among these is handled by the compiler)

Subsequently, the compiler generates object files, which are then linked by the linker into the final application executable

## Compiler and Linker Errors

### Common Compiler Errors

You can forget to declare a function before you call it
  * Forget to include the header(s)
  * Function(s) is not declared in the header(s)

### Common Linker Errors

You can forget to implement a function
  * Code for the function is not in the `.cpp` file
  * The `.cpp` file is not being linked

### Error Resolution

Be mindful of these issues; *do not* try to fix what is not wrong, but rather start from evaluating potential errors in these sources

### **DEMO: Compiler and Linker Errors**

N.B. There is no code associated with this demo, see tutorial video for reference

## Summary

Writing functions and calling them is better than a giant block of code, and they prevent a common coding anti-pattern: DRY (Don't Repeat Yourself)

Functions also promote more expressive code

Functions can be implemented in a separate `.cpp` source file
  * But the functions must be declared before they are used

Including a header file is an easy, effective way to declare many functions at once
  * Header files can be included in both the calling code and the implementing code

Compiler errors and linker errors are caused by different mistakes
  * As a rule of thumb, linker errors are commonly caused by header files (relating to issues with function declarations) and compiler errors are commonly caused by source files (relating to issues with function definitions/implementations)

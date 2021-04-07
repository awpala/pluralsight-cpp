# Section 2 - Getting Started

## How Text Becomes Executable

C++ is a compiled language, which uses the following **tools**:
* A **compiler** takes source code you can read and write, and transforms it into a different format
* The compiler gives you **error messages**
* The output of the compiler is generally called an **object file**

Any program larger than a demo is made of several **source files**
* Each is compiled individually, and then the object files are linked together to create an **executable file** (e.g., `exe`)
    * In some projects, you would create a **library file** instead
    * The **linker** gives you error messages if it cannot link the objects

Finally, you **run** the application
  * There may be **runtime messages** or dialogs from the operating system, or that you wrote yourself

This course focuses on how to write source code that the compiler and linker can transform into an application that can run

## C++ Is Unusual

C++ does not "belong" to a single vendor

Tools are available from many sources at many price levels (including no cost)

All vendors try to implement the **standard**, however
  * The C++ standard is governed by the ISO Committee
  * The standard updates every 3 years
    * Compilers are typically released even more frequently than this, which expose experimental features ahead of the official standard release
    * It is therefore advisable to use relatively recent tools

## What Tools Do You Need?

Bare minimum:
  * Text editor
  * Compiler (e.g., gcc, clang, etc.)
  * Linker

Nice additions:
  * Code-aware editor
  * Debugger
  * Code-specific tools (e.g., static analysis, diagramming tools, etc.)
  * Libraries and Frameworks

N.B. Since C++ is standardized, it is not necessary to be "stuck" with one set of tools. New and/or additional tools can be introduced as uses, needs, and preferences change over time.

### Free Tools

Windows
  * Visual Studio Community Edition
  * MinGW (not an IDE)

Mac
  * XCode

Cross-Platform
  * Visual Studio Code (N.B. For Windows, Visual Studio is a recommended alterantive)
  * Qt Creator (particularly for GUI development)
  * compilers (*not* an IDE): gcc and clang

### DEMO: Tools

https://isocpp.org (official website of the Standards Committee)
  * https://isocpp.org/get-started

## What Can You Write?

C++ targets *ALL* platforms
  * e.g., Windows, macOS, Linux
  * phones (i.e., native applications)
  * embedded systems (e.g., robots, IoT, etc.)

### Different Coding Patterns and Libraries

There are many application domains where C++ is used, for example:
  * Games
  * High-performance, low-latency
  * Server (no UI)
  * Corporate GUI
  * and many more!

However, to eliminate dependency on frameworks, dependencies, and domain-specific knowledge, this course will focus on building basic **console applications** to demonstrate the core C++ language itself, irrespective of the target domain
  * Furthermore, this illustrates teh point that all of these domains are based on the common syntax of C++ and the same standard libraries

## Command Line

A **command-line application** runs in a "console" or "terminal" or "shell" and simply outputs characters to the screen (i.e., no GUI); furthermore, input is received from the user typing characters (i.e., via keyboard input)

While such a program is "contrived" with respect to production-level applications, it is useful for pedagogical purposes; furthermore, it makes for a good "common denominator"

## Smallest C++ Application

C++ is case-sensitive

`{` and `}` are distinct from `(` and `)`
  * Furthermore, each is paired (i.e., beginning and end must match

Most lines (i.e., **statements**) are terminated with `;`

### DEMO: Smallest

cf. `Small.cpp` (this is the smallest possible C++ applciation!)

N.B. Run the `Small.cpp` application using the IDE (e.g., Visual Studio, Visual Studio Code with `Code Runner` extention, etc.) or via command-line compilation

## Errors

### Compiler Errors

The compiler assumes you are trying to make sense
  * This can cause misleading **error messages**

Furthermore, not all the errors you can get when you build are compiler errors
  * Other types of errors (e.g., linker errors) will be discussed later in the course

Compilers also give **warnings**
  * Unlike compiler errors, which prevent the file from compiling, warnings do *not* prevent compilation
  * New developers should *not* ignore warnings

N.B. When troubleshooting/debugging compiler errors, it is often most useful to resolve the first occurring error first, re-compile, and iterate in this manner, as oftentimes an initial error will cause a subsequent "cascade" of errors.

## Summary

Since C++ is not exclusive to one vendor, there are many C++ compilers available
  * N.B. This course uses Visual Studio Community, however, the repository code has been compiled via Linux Ubuntu with g++ compiler
  * Any suitable compiler can be used on the source code

C++ is maintained by a Standards Committee

To "build" your source code into executable code...
1. First, the code is compiled
2. If that succeeds, then the compiler output is linked
3. The resulting executable is what you run as the application
  * The executable can be run from inside the IDE, or from a command prompt, and even by double-clicking via the operating systems file navigation GUI

Console applications have a particular **structure** you must follow, i.e.,:
```cpp
int main()
{
  // statements

  return 0;
}
```

# Section 3 - Tools

## What Do You Need?

The following tools are necessary to write C++ programs:
  * A **compiler** and **linker**, which transform source code into an executable that can be run on the target machine
  * An **editor** for creating and editing source code
    * Ideally, the editor should be language-aware, including useful syntax highlighting, interactive documentation, warnings, auto-completion, etc.
  * A **debugger** to evaluate/monitor program execution and eliminate bugs

## Building

Modern systems combine compilation and linking into a single **build** step, however, be aware that these are indeed distinct, separate steps in the process

In a simple program, the following sequence is performed to build an application:
  1. A **source file** (`.cpp`) is compiled to an **object file** (`.obj`, `.o`, etc.)
  2. An object file(s) is then **linked** to create the **executable file** (`.exe`, etc.)

N.B. While this seems trivial for a single file, in practice a C++ application consists of many source files with complex inter-dependencies, therefore this sequence *is* necessary
  * Modern build systems may require an hour (or more) to build the application!

## Popular Tools

The tools used for creating C++ applications depend on *both* the platform used to create them and on the target platform on which they are used

Some popular compiler/linker systems include:
  * GCC (GNU Compiler Colection)
  * Clang

Furthermore, popular **integrated development environments (IDEs)** include:
  * Visual Studio (for Windows)
  * Visual Studio Code (for macOS and Linux)
  * CLion (various platforms)

N.B. There are also online compilers available to perform builds in a browser-based web application (e.g., https://godbolt.org)
  * This is useful for comparing compilers, particularly for testing new language or library features
  * This is also useful for sharing a code snippet for demonstrations or when seeking help

N.B. cf. https://isocpp.org/get-started for a list of available tools

In C++, **backwards compatibility** is a fundamental design feature, therefore newer versions of compilers will always support previous standard features by design, in order to prevent breaking legacy codebases

## Integrated Development Environment: Visual Studio

The video course will use Microsoft Visual Studio
  * N.B. This companion repo's code is created with g++ on Linux Ubuntu

In general, an **integrated development environment (IDE)** provides the following features:
  * An **editor**
  * A **compiler** and **linker**
  * A **debugger**
  * And other related tools (e.g., profilers)

N.B. This course uses standard C++ features understood by virtually all modern build systems, therefore, it is not strictly necessary to use Visual Studio

### Visual Studio Editions

Visual Studio Community is completely free and has no restricted features

Visual Studio Professional is intended for larger companies and may be required per the license agreement depending on the size of the company and/or revenue generated (but otherwise the features are not much different from Community edition)

Visual Studio Enterprise provides additional top-end features and support

N.B. cf. https://visualstudio.com/vs/compare

## Kinds of Applications

Some languages only support creating a particular type of application

C++, however, is a general-purpose programming language which can be used to create a huge variety of applications, including:
  * Phone and other client apps, including games which run directly on the device
  * Console applications
  * Services (e.g., background and infrastructure processes)
  * Servers
  * Libraries

This course will focus on console applications, which are simplest to demonstrate and do not distract from the focus on the language by adding additional "overhead" to the source code

Console applications ssimply do the following:
  * Write text to the screen
  * Read text from the keyboard
  * No graphics, controls, UI elements, etc.

N.B. Later in your development, you will typically use a framework for a specific application domain (e.g., user interfaces, phone applications, etc.)--fundamentally, these will still be based around the core syntax discussed in this course

## **DEMO**: Visual Studio Hello World

cf. video for this topic

Reference source code from video:
```cpp
// Hello.cpp : Defines the entry point for the console application.

#include <iostream>
#include <string>

int main()
{
  std::cout << "Type your name" << std::endl;
  std::string name;
  std::cin >> name;
  std::cout << "Hello, " << name << std::endl;

  return 0;
}
```

## Console Application Structure

`// ...` defines an inline comment
   * N.B. C++ also supports C-style (multi-line) comments, i.e., `/* ... */`

`#` defines a **preprocessor directive**; the preprocessor directive `#include` is used to include/import external features, e.g.,:
```cpp
#include <iostream> // I/O stream library
#include <string> // string library
```

N.B. Preprocessing is a separate step prior to compiling, e.g., `#include` "pastes in" the external code prior to compiling the source file

All console applications require the function `main()`, which defines the entry point into the program and by convention returns an integer, i.e.,:
```cpp
// directives, declarations, and definitions

int main()
{
  // statements

  return 0;
}
```

N.B. In older style programs, `main()` can receive arguments (e.g., `int main(int argc, char* argv[]) { ... }`) in order to run the application from the command line

The majority of statements in C++ are terminated with `;`, with the exception of `{ ... }` which denotes a block of statements (however, an example of `{ ... };` will be seen later when we examine classes)

The **scope resolution operator** `::` denotes the **namespace** where the entity exists; in particular, `std::` (i.e., the **standard namespace**) is used to identify features from the Standard Library (e.g., `std::cout`, `std::cin`, and `std::endl` via `<iostream>`; `std::string` via `<string>`; etc.)

N.B. The statement `using namespace std;` can be included to prevent repetitive typing of `std::`, however, this is considered a bad practice due to potential "scope pollution" (particularly across many source files)

The **stream insertion operator** `<<` outputs to the console

The **stream extraction operator** `>>` receives input from the user (e.g., via keyboard)

A **string literal** can be defined using double quotes (e.g., `"Type your name"`)

### **DEMO: Creating a Project**

cf. video for this topic
  * N.B. The video covers Visual Studio project initialization and configurations

## Summary

You can use a variety of tools for C++
  * C++ is a cross-platform language
  * C++ is widely used and supported

To develop C++ applications, you must:
  * Edit your code
  * Build (compile and link)
  * Run (with or without debugging)

Console applications are the simplest to get started with
  * This course will focus exclusively on developing console applications accordingly

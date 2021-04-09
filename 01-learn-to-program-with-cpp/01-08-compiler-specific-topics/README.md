# Section 8 - Compiler-Specific Topics

## IDEs Can Make Starter Files

Recall that C++ applications can be written using a variety of tools; in particular, **Integrated Development Environments (IDEs)** (e.g., Microsoft Visual Studio) are commonly used in practice today

Visual Studio provides a *Create New Project* command, which can be used to create a console application

IDEs may create files you do not need (e.g., `readme.txt`)

However, IDEs also create files that *are* valuable, including important configurations; therefore, it is ill-advised to delete everything except for `.cpp` and `.h` files in a IDE-based project
  * If you do not know the specific purpose of a given file(s), it is best to leave it alone, in order to prevent later time expenditure to resolve potential issues related to this

IDEs may also put content in files that you do not need
  * Oftentimes instructions are added as comments; these *can* often be removed without adverse consequences on program development and execution

## Command-Line Arguments

The following is a variant of the `main` function, which takes two arguments:
```cpp
int main(int argc, char* argv[])
{
  // statements

  return 0;
}
```

N.B. `argc` is the *arguments count*, and `argv[]` is the *arguments vector* comprised of an array of old C-style character arrays (C's equivalent of strings), i.e., a collection of `char*` strings

This variant stems from older programs which would often be executed from the command line, designed to take parameters from the command prompt (`$`), e.g.,:
```
$ Small.exe -g Hello 12
$ g++ a.cpp b.cpp
```

N.B. Observe that the command-line compilation (i.e., `g++ ...`) is an illustrative example of this type of command-line application

If an IDE creates a boilerplate project having this variant of `main`, it is generally fine to remove the arguments, unless they are specifically required for the application in question

N.B. This course will not further discuss the topic of writing applications which take command-line arguments, as these applications are not common in the modern landscape; this topic was introduced here for cursory exposure, in case such legacy programs are encountered

## `#pragma once`

`#pragma once` is a preprocessor directive which prevents a file (e.g., header file) from being included multiple times
  * Including the same header file multiple times across various other files can result in multiple includes of the same header-file code, which generates a compiler error

While `#pragma once` is not officially in the Standard, as `#pragma` directives are compiler-specific and their implementation is at the discretion of the respective vendors, however, in practice `#pragma once` is a de facto standard preprocessor directive supported by major compilers

N.B. THe same effect can be achieved via **header guards**, however, these are highly error-prone and confusing to newcomers; `#pragma once` is the recommended alternative approach

## Setting the Warning Level

"*All our defaults are wrong*" is a common "trope" in the C++ community, and in truth it is not completely removed from reality

However, one critical consideration is the importance of **warning levels**: compilers can warn on every tiny thing, or they can be more tolerant

Most default warning levels are *too tolerant* (i.e., they do *not* provide sufficent warnings)

Fortunately, the warning level can be changed rather easily, as follows:
  * Visual Studio: project options
  * Command Line compiler flags: `-Wall -Wextra -Wpedantic`

Furthermore, warnings can be treated as errors (i.e., the build fails if there are warnings, as if they were errors), as follows:
* Visual Studio: project options
* Command Line compiler flag: `-Werror`

As a corollary to the previous "trope": *The compiler is your friend!*

### **DEMO: Visual Studio Tweaks**

N.B. cf. video for demonstration of compiler project settings (e.g., warning level) in Visual Studio

## Make Files

### Using Make

If you are not using an IDE-based build system (e.g., Visual Studio), then you are most likely compiling from the command line

If you compile at the command line, you will probably use **Make**

Make is a separate tool that calls the compiler via pre-configured command-line arguments

Make is controlled by **makefiles**, which contain two important pieces of information:
  1. Describes which files depend on each other
  2. Sets the compiler options

### Simplest Makefile

The simplest makefile is as follows:
```makefile
# `all` is the default target
all:
  g++ -std=c++11 -Wall -Wextra -Wpedantic -Werror Account.cpp Transaction.cpp SimpleClasses.cpp -o Simple
```

N.B. Simply calling this makefile `makefile` (without a file extension) will render it directly callable as the default makefile, by issuing command `make` from the directory containing this makefile (however, this name is not compulsory)
  * It is recommended to define a default makefile named `makefile`, as it can exist along with other makefiles in the same directory

N.B. In makefiles, indentations **must** be tabs (i.e., tabstop character) in order to parse correctly as command-line arguments by the terminal, ***not*** spaces

## Building with Multiple Files

With multiple headers and source files, the build process can become complex (e.g., inter-dependencies via `#include`s); oftentimes, it is only necessary to re-compile a subset of the files upon making changes, rather than re-compiling all of the files in the application
  * Re-compiling a large project consisting of many files can be potentially cumbersome and disruptive to the development process
  * Any object files unaffected by changes do not require re-compilation, and can be re-linked with the re-compiled object files of the changed files instead

In general, a **best practice** is to develop incrementally and compile often (i.e., only the pertinent files), rather than developing and compiling "in bulk"; this development pattern is more time-efficient and less error-prone

### Shorten Build Times

IDEs can track dependencies

Make can also be used for the same experience at the command line

## Makefiles for Multiple Files

Consider a more complicated example of a makefile named `changesonly` as follows:
```makefile
all: Simple

Simple: Account.o Transaction.o SimpleClasses.o
  g++ Account.o Transaction.o SimpleClasses.o -o Simple

Account.o: Account.cpp Account.h Transaction.h
  g++ -c -std=c++11 -Wall -Wextra -Wpedantic -Werror Account.cpp

Transaction.o: Transaction.cpp Transaction.h
  g++ -c -std=c++11 -Wall -Wextra -Wpedantic -Werror Transaction.cpp

SimpleClasses.o: SimpleClasses.cpp Account.h
  g++ -c -std=c++11 -Wall -Wextra -Wpedantic -Werror SimpleClasses.cpp
```

In the example above, if anything after `:` is newer than the entity before `:` (i.e., changed relatively more recently), then the command on the next line is executed

N.B. The command-line flag `-c` indicates compile only (i.e., do *not* link)

N.B. To avoid repetition, it is possible to add environment variables, patterns, and other general configurations to makefiles, however, this topic is beyond the present scope; furthermore, it is arguable that repetition in the manner shown above promotes readability/comprehension of the makefile
  * IDEs are also capable of generating makefiles

### **DEMO: Makefiles**

cf. `/SimpleClasses`

N.B. Issue terminal command `$ make` to run the makefile `makefile`, or issue terminal command `$ make -f changesonly` to run the makefile `changesonly` (where the command-line flag `-f` indicates "file")

## Summary

Tools that do things for you may not do exactly what you want; but it is *your* code in the end

You can shorten build times by using a tool that only re-compiles files that changed, or depend only on a *changed* file

Learning to use Make will save you time and tedium at the command line

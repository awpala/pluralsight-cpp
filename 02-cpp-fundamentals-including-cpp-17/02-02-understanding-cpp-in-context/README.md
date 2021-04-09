# Section 2 - Understanding C++ in Context

## Why C++?

C++ is a **general-purpose propgramming language**

C++ emphasizes power and performance

C++ is a popular language

## Modern C++ Is *Not* Too Hard for Beginners

You do not need to learn C first; in fact, it might even make things harder

If you already know C# or Java, you can learn C++ quickly

If you know old school C++ (i.e., ca. early 2000s or earlier), learning modern C++ may be harder (may require "unlearning" old habits)

If you are familiar with programming in general (e.g., what is a loop, why might you want to test a condition, what is an object, etc.), you can learn C++
  * The main difference with C++ is simply different syntax

Even if you do *not* know any programming languages yet, you can learn C++ as a first language

## The Standard Library: Built-In Capabilities

As with many modern programming languages, C++ provides a **Standard Library**, which is included with virtually any C++ compiler implementation
  * Furthermore, there are many vendors producing high-quality compilers today, so the landscape is robust, as are the feature sets

Among other things, the C++ Standard Library includes:
  * A useful `string` class
  * Many collections
  * Smart pointers for memory management
  * File and screen I/O
  * And much more!

## Modern C++

Managing memory manually is considered "old school"; so is pointer arithmetic for working with strings and arrays
  * These are vestiges from C++'s C lineage

Modern C++ looks a lot like C# or Java--but it is faster!
  * For example, in C# and Java generics are resolved at *run-time*, but in C++ templates (which implement genericity) are resolved at *compile-time*
  * Similar advantages appear throughout C++, making it advantageous if execution speed is of principal concern

## Standardization

C++ as a language does not belong to a single person or company; rather, there is a **standard** that defines the language, as managed by the **Standards Committee**

Compiler vendors implement a lot of features in advance, with many of their representative belonging to the Committee (i.e., they are knowledgeable around the features and cutting edge of the language)
  * Different compilers acheive 100% standard compliance at different paces

N.B. This course's videos will use Microsoft Visual Studio 17, which uses Microsoft's MSVC C++ compiler
  * However, the code examples in this companion repository will be created using the g++ compiler running on Linux Ubuntu, with makefiles added where necessary

### **DEMO: Standardization**

cf. https://isocpp.org/ and https://isocpp.org/std/status

cf. https://en.cppreference.com/w/cpp/compiler_support

## Summary

C++ is a powerful language used by millions of developers today

C++ has a reputation for being difficult, but it does not have to be; in fact, modern C++ is clean and simple

In modern C++, the Standard Library does a lot of the work for you already

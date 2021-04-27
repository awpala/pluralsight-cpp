# Section 2 - What Target Are You Trying to Reach?

## What Is Legacy Code?

So, what is legacy code exactly? Is it...
  * Code without tests?
  * Code more than 10 years old? 20? 30? More??
  * Code you did not write?
  * Code using a framework or library that is no longer maintained?
  * Ugly code that does not use current style?
  * Code that is slower than it could be?
  * Code that is hard to read or understand?

There is no corect answer to this question, however, a "typical" definition of "legacy code" may consist of some or all of these characteristics

For purposes of this course, **legacy code** is *any code you want to change, but are afraid to do so*

Reasons to change/update the code may include:
  * Fixing a bug
  * Change in modern rules and conventions
  * The code cannot be understood and/or maintained effectively in its current state
  * The code is lacking tests
  * There is no source control
  * There is an inadequate and/or poorly documented build system

A common theme among these reasons is "tensions" (i.e,. there is a presing need to change the code beyond a mere "nice to have")

## You Wish This Code Were Modern

Use new language capabilities

Avoid bug-prone constructs

Write code that is as fast as possible
  * Both systems (e.g., copmilers and hardwards) and performance improve over time

Use the C++ Standard Library more often and more effectively

### Pointer Arithmetic and Manual Memory Management

As a representative example, a lot of lcegacy C++ code involves the use of raw pointers and pointer arithmetic to perform manual memory management, which is tedious and error-prone
  * Some developers get pointer arithmetic wrong, despite it "looking right"
  * Some developers write memory leaks, memory overwrites, and other intermittent bugs with pointers

Modern C++ provides collections and iterators to operate more safely, as well as smart pointers to handle memory management without explicit use of raw pointers
  * These modern constructs in turn reduce vulnerability of applications to attacks from bad actors

### The C++ Core Guidelines

One place to look for a concrete definition of "modern C++" is the **C++ Core Guidelines**, available at https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines.html
  * Many of these guidelines encourage the adoption of a more modern style (i.e., C++11 and later, rather than "C-like" C++)
  * Many also additionally make code more maintainable and expressive
  * Some "violations" can be found by automated checkers and tools built by the growing community of enthusiasts around these guidelines

## You Wish This Code Were Maintainable

*Expressive* code tells what it does and is often "self-documenting"

*Simple* code is generally more maintainable than complex, convoluted code (which may include premature optimzizations via obfuscated code)

*Transparent* code is more maintainable, as its use is more immediately obvious (e.g., use of parantheses for sensible grouping, effective application architecture, etc.)

## Why Would You Change Working Code?

First things first: are you *sure* that it *is* indeed working?
  * Intermittent, indeterminate bugs can become problematic in an otherwise "functioning" application

It is often necessary to change otherwise working code so that it can be maintained as its use becomes more complex over time

There are many contemporary factors (e.g., better optimizers, larger caches, etc.) which can accentuate performance via code refactors

Most importantly, a programmer's time is valuable: it is often necessary to change working code so that it can be effectively understood and read under normal working/development conditions
  * A "readability polish" additionally can often uncover bugs in the process

## Course Approach

There are many approaches that can be taken to update legacy code, and there is no particular "natural" order in which to perform these changes

For purposes of this course, however, the following topics will be covered:
  * ***Strategy***: What to change and how to be ready to make changes
  * ***Tactics***: Specific things you can do
    * Use the compiler
    * Use the language
    * Use new parts of the language
    * Use the Standard Library
    * Refactor and reorganize
  * ***Strategy***: What is better now? What is left to do?

## Begin with the End in Mind

This course is *not* about changing code for the sake of changing it; rather, the objective is to improve the code from its *current state* to a *better state*
  * Always keep this "better state" in mind when working on the code

This "better state" of the code is...
  * ***Modern***
  * ***Expressive*** -- readable, obvious, transparent, understandable
  * ***Fast***
  * ***Safe (even easy!) to change***
  * ***Simple***

Most importantly, make code that you are no longer afraid to change!

## Summary

"Legacy code" needs to change, but it scares you to do so

Modernizing that code can make it maintanable, but can also do much more

You want to create code that explains itself and makes sense to a reader (i.e., without requiring excessive comments, a developer wiki, etc.)

It will likely get faster and/or more correct as you do so

But what parts should you change exactly? That is the topic of the following section of this course...

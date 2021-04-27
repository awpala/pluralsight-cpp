# Section 4 - The Compiler Is Your Friend

## Compiling Really Old Code

If your legacy code is compiled regularly, then this is not a particular concern

However, if you are attempting to compile a project composed of legacy code which has not been recently compiled, several issues may arise, including:
  * String functions
  * Loop scope rules changes
  * New keywords

### Secure String Functions

The Standard Library class `std::string` will be discussed later, however, legacy code often involves C-style strings comprised of an array of `char`s, along with corresponding library functions `str...`

`strcpy` and a number of other functions can leave code vulnerable to buffer overflow attacks

`strncpy` is intended to be a safer alternative, but it is not a perfect substitute
  * Does not check for null parameters, etc.

Some compilers will warn (or error) if you attempt to use `strcpy`
  * As a first pass, you can suppress this and refactor later with a safer alternative (e.g., for MSVC++ users, `strcpy_s` is a good substitute)

### **DEMO: String Warnings**

cf. `Strings.cpp`

## Loop Scope

A long time ago, the C++ language changed the rules for the **scope** of loop variables, e.g.,:
```cpp
for(int i = 0; i < 10; i++)
{
  // ...
}

if (i < 10) // `i` still in scope per "old rule"
{
  // loop must have terminated prematurely
}

for (i = 0; i < 10; i++) // `i` still in scope per "old rule"
{
  // ...
}
```

In the example above:
  * In the "old rule," `i` is still in scope after the first loop terminates
  * However, in the "new rule," `i` is out of scope after the first loop terminates

To reproduce the "old rule" behavior in a "new-rule"-enforcing compiler, the first loop can be refactored as follows:
```cpp
int i; // declare `i` outside of the loop construct
for (i = 0; i < 10; i++)
{
  // ...
}

// ...
```

## New Keywords

Over the years, C++ has added new keywords to the language; if any of these keywords have been used previously as variable names, this can yield compiler errors

In practice, the C++ specification developers have generally avoided keyword names which could conflict with names that developers would have potentially used previously (e.g., `nullptr`, `noexcept`, etc.)

Furthermore, for potentially conflicting keywords, these are typically context-sensitive (e.g., `final`, `override`, etc.) which will not necessarily conflict with declarations outside of these specific contexts

N.B. cf. https://en.cppreference.com/w/cpp/keyword for an up-to-date list of C++ keywords and naming rules for identifiers

## Turn Up the Warning Level

At this point, it is assumed that the code can be compiled with a relatively new C++ compiler (i.e., C++11 or later)

Ideally, your code will compile with *no* warnings

Additionally, warnings should not be simply ignored (these are often either bugs or potential bugs); along with this, use the highest warning level you can while still keeping it "clean"
  * This is probably not the highest level that the compiler offers
  * Change warning levels file-by-file as you are working on them, rather than across the entire codebase at once

### **DEMO: Warning Level**

cf. `Warnings.cpp`

## You Might Find Bugs

Consider the following examples:
```cpp
if (f = j) // warning -- should this be `==`? (better approach: if `f = j` is intended, do this outside of the `if` condition)

if (f > j)
  f++;
  return i; // warning -- always performs this step, resulting in unreachable code downstream (to fix this, either correct the indentation or use `{...}`, depending which is intended)

int foo(int a, int b) // warning -- unused parameter (if `b` is not used, removed this parameter)
{
  return a*a;
}
```

### You Can Clean Things Away

Unreachable code

Unused local variables

Unused function parameters
  * If you cannot remove them completely, remove the parameter variable name (leaving the type intact, for a valid function signature) to communicate this

Less to keep track of as you try to understand the code

N.B. Oftentimes in legacy code, old code is "kept around" due to poor source control, bad habits, etc.

## The Preprocessor

Before the code is compiled, it goes through the **preprocessor**, which processes the preprocessor directives denoted by `#` (e.g., definitions and macros)

Macros are nothing more than simple text substitution of one string for another
  * Type safety is disregarded
  * Can conflict with variable names, etc.
  * Are very difficult to debug (e.g., cannot be "stepped into" with the debugger)
  * Not all IDEs help to understand what you see (e.g., via macro expansion)

### Most Motivations for Macros Are Obsolete

| Macro Use Case | Modern Alternative |
|:---:|:---:|
| A function would be too expensive | Modern C++ compilers have inline functions |
| I want to give this number a name | Use a `const` variable, an `enum`, or an `enum class` |
 | I need different versions of this function | Use polymorphism (i.e., via class inheritance hierarchy with virtual-function implementations) or templates |
 | I need to wrap something around arbitrary code (e.g., timing, logging, etc.) | Use a lambda |

## Is This Macro Really a Function?

Clue: lots of parentheses

If the macro is really a function, then make it a function (additionally, the compiler can inline it if performance is a concern)
  * As a function, you get parameter evaluation, can step through via debugger, etc.

### But It Needs to Work for Different Types

Write the function so that it works for all of them

Additionally, use polymorphism if the types are more complicated than simple primitives

If the types are unrelated, then make it a template instead

### But It Needs a Different Name Sometimes

Write a common templated function instead, then write one-line wrappers with the different names; now, all versions of the function are available

## Names for Numbers

Most legacy code is rife with magic numbers; furthermore, macros only *name* them, but they do not provide type safety

### I Want to Give These Numbers Names

Use a `const` `static` class member
  * Accessing them via the class name is additionally a form of documentation
  * This also provides type safety

For a group of related numbers, use `enum` or `enum class` instead
  * `enum class` additionally provides type safety, and does not require unique names

### **DEMO: Macros**

cf. `Macros.cpp`

## Wrap Arbitrary Code in Housekeeping

Oftentimes, the last type of macro to be "let go" is the kind which automates some type of behavior (e.g., a `LOG` macro wrapping a block of code, timing macros, and security/permissions checks)

These use cases can all be addressed using lambdas, which are more readable and more debuggable; furthermore, there is no performance hit associated with using lambdas in this manner (compilers are optimized to inline when necessary)

For example:
```cpp
/* templated function definition */
template <typename Func>
long long TimeFunc(Func f) // takes a function or lambda as a parmaeter
{
  auto begin = steady_clock::now(); // N.B. `now()` is from the `std::chrono` namespace
  f(); // works for either functions or lambdas
  auto end = steady_clock::now();

  return duration_cast<seconds>(end - begin).count();
}

/* using the templated function */

// ...

auto seconds = TimeFunc(
  [&](){ fib40 = fibonacci(40); } // lambda captures `fib40` by reference
);
```

### **DEMO: Timing with Lambdas**

cf. `Timing.cpp`

## Summary

Let the compiler warn you about oddities in the code
  * Stop ignoring warnings

Replace macros with `const` members, `enum class`es, and/or functions
  * Do not be afraid of templates

Code with macros is hard to read, debug, and maintain
  * Functions can be inlined and are easier to debug
  * Constants can have scope and type

N.B. There was a time when they were necessary (e.g., when `const` was not available yet, when compilers did not optimize to perform inlining, when lambads were not available yet, etc.), but that is no longer the case in the modern C++ landscape

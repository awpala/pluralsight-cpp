# Section 6 - Strings and Collections

## Objects and Classes

So far, applications written have consisted of lines of sequential code and calls to functions

In C++, applications are not just made of functions, but of classes and objects too; therefore, C++ is an **object-oriented language**

A **class** defines the notion of an **object**, i.e.,:
  * What data it holds
  * What functions it can be asked to perform

Example: a `Date` class

An **object** is an instance of a class (e.g., `May 1st, 1990` or `Dec 3rd, 2017`)

Functions inside a class are called **member functions**
  * cf. The kind of functions shown earlier are called **free functions** or **nonmember functions**

N.B. Typical C++ applications are comprised of both free functions and member functions

## Strings

Many applications require working with text (e.g., representing a message, user input, etc.)

The Standard Library contains the header file `string` (i.e., `#include <string>`), which provides a very useful class `string` in the namespace `std`

The class `string` can compare, combine, and manipulate text strings, as well as search for substrings, make replacements, etc.

The class `string` resembles/"feels like" a built-in type

N.B. For Unicode characters, use `wstring` (wide strings) -- the principles described with respect to `string` generalize to `wstring`, so the latter will not be described in depth in this course

### String Operators

To combine two strings: `+`, `+=`

To compare two strings (lexicographically): `==`, `<`, `>`, `!=`

The operators `cout <<` and `cin >>` are both directly compatible with strings

### Reuse Your Knowledge

You already know how to...
* compare two integers with `<` and similar operators; comparison of strings is performed analogously
* add two integers with `+`; addition (concatenation) of strings is performed analogously
* print an integer to the console with `cout >>`; printing of strings is performed analogously

Therefore, the more you know how to do, the easier new things are to learn

## String Member Functions

Although strings perform many familiar operations (i.e., analgously to integers), they are indeed objects with corresponding specialized/idiosyncratic member functions, e.g.,:
```cpp
string greeting = "Hello, ";
int len = greeting.length(); // 7 -- call to member function length()
string s2 = greeting.substr(2, 3); // "llo" -- N.B. indexing in C++ is zero-based
int pos = greeting.find("He"); // 0
```

N.B. cf. https://en.cppreference.com/w/cpp/string/basic_string for full reference of `string` member functions

### **Demo: Strings**

cf. `Strings.cpp`

## Exercise

Write a program that asks the user for two words and tells them which is longer

Hints:
  * Use the code from `GuessMyNumber` as a starting point
  * This app can run until the user says to stop, or just once: your choice

Once it is working, try entering a phrase and see what happens
  * N.B. When `cin` reads the input stream, whitespace is not parsed (e.g., `hello world` will be read as two distinct/separate strings, `"hello"` and `"world"`)

cf. solution `Longer.cpp`

## Collections

Many programs need to work with a number of similar items (i.e., instances of the same class), e.g.,:
  * The people in a department
  * The items in an order
  * The transactions in an account

The Standard Library provides many classes that are ready to use

The simplest and best first choice of Standard Library container is `vector`
  * Holds an arbitrary number of values, all of the same type
  * Size does not need to be known in advance
  * Easy to access a specific item or all of them

For example:
```cpp
#include <vector>
using std::vector;

#include <iostream>
using std::cout;

vector<int> nums; // when declaring, specify the type of the vector's elements via <type>
nums.push_back(3); // call to vector member function `push_back`

for (auto item : nums) // range-based for loop -- iterates over all elements of the vector container
{
  cout << item << " ";
}

nums[0] = 7; // access a specific vector element via operator [...] (i.e., at index 0)
```

When working with Standard Library collections, many expected functions are implemented as free functions in the header `algorithm` rather than as member functions
  * These free functions are generalized to perform generic actions across different collections, thereby reducing potentially redundant member functions within similar containers

For example:
```cpp
#include <algorithm>
using std::sort;
using std::count;

#include <vector>
using std::vector;
using std::begin;
using std::end;

#include <string>
using std::string;

vector<string> words;
// ...
sort(begin(words), end(words));

vector<int> nums;
// ...
int threes = count(begin(nums), end(nums), 3);
```

### **DEMO: Collections**

cf. `Collections.cpp`

## Operator Overloading

**Operators** are simply functions, with a specialized syntax (i.e., "strange" names, no `(...)`, etc.)

You have seen many operators throughout this course already (e.g., `+`, `+=`, `==` for strings and integers)

Recall function overloading; similarly, operators can be **overloaded** as member functions of a class to provide idiosyncratic behavior (e.g., vector uses operator `[...]` for element access; `cout` and `cin` use `>>` and `<<`, respectively, to interact with the IO stream; etc.)

Therefore, operator overloading provides an mechanism to design types in a way that is intuitive and resembling the behavior of built-in types
  * Accordingly, many of the objects provided by the Standard Library have overloaded operators to provide expected behavior

## Templates

**Templates** are a powerful way to write a library
  * They work on any type, without compromising type safety
  * They work on both built-in types and user-defined types
    * This is facilitated by operator overloading

While writing templates is an advanced topic, *using* templates is not difficult; in fact, they have already been used in this course (cf. `std::vector` container, which is a templated class; simlarly, `std::sort` is a templated function, which operates on the iterators `std::begin` and `std::end`, which in turn are templated functions)

Templates are a very powerful feature of C++ which promotes reusability and **generic programming**

## Summary

THe class `string` is powerful and useful
  * Intuitive operator overloads
  * Useful nember functions for string processing
  * Works with some free functions in the Standard Library as well (e.g., `std::count`)

The Standard Library includes classes to represent a collection of anything (even user-defined types)
  * `std::vector` is the most generally useful collection, and is recommended as a first resort
  * There are free functions to work with `std::vector` and other collections

The C++ template mechanism allows us to generalize over types (both built-in types and user-defined types) without compromising type safety

Operator overloading is extremely powerful

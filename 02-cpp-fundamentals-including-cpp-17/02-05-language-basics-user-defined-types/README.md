# Section 5 - Language Basics: User-Defined Types

## Building

When defining your own types (i.e., via classes, discussed shortly) it is customary to use multiple different files to organize the program
  * One file may describe the type, while another may use it
  * You can make a promise (i.e., declare) to the compiler in the calling code that a definition exists somewhere else; the linker will "fulfill" this promise

Unlike other languages, C++ does not use reflection or metadata; instead, the compiler must be informed accordingly
  * The preprocessor directive `#include` can be used for this purpose (i.e., "pasting in" the code from one file into another), and it is only a convenience

N.B. Conventionally, **header files** (`.h`) are used to ***declare*** classes, and the corresponding **implementation files** (`.cpp`) ***define*** them
  * These user-defined header files can be used via `#include`, similarly to the definitions in the Standard Library

Once the linker combines all of the object, the resulting **executable file** constitutes the application

## Classes and Objects

A class is declared using the keyword `class`

A class also has the **access specifiers** `private` and `public` to designate its **members** (data/variables and functions) accordingly
  * In a class, members are `private` by default
  * In general, `public` member variables should be avoided

Classes are **declared**, just like built-in types

Class members are accessed using the operator `.` (i.e., `ClassName.classMember`)

For example, consider the following **class declaration** and its corresponding **implementation**:
```cpp
/*
  class declaration (in file `Person.h`)
*/
class Person
{
  private:
    std::string firstname;
    std::string lastname;
    int arbitrarynumber;

  public:
    std::string getName(); // N.B. this is a function declaration (discussed later)
}; // the terminating ; is required for a class declaration


/* 
  definition/implementation of member function (in file `Person.cpp`)
*/
#include "Person.h"

std::string Person::getName() // use fully qualified name of function (via Person::) to implement
{
  return firstname + " " + lastname; // member function has direct access to `private` member variables
}
```

N.B. Member functions of a class are generally `public` (e.g., getters and setters)

### **DEMO: Classes and Objects**

Simple example using the class `Person`:
```cpp
#include "Person.h"

int main()
{
  Person p1;
  Person p2;
  std::string name = p1.getName();

  //int i = p1.arbitrarynumber; // error -- cannot access a `private` member variable outside of the class

  return 0;
}
```

N.B. Implementation of the class `Person` will be discussed throughout this section

## Constructors

### Objects

An **object** is an instance of a class, which has its own copy of member variables having their own values (i.e., independent of other object instances)

**Member functions** operate on **member variables** (and arguments)

An object is **initialized** using a special function called a **constructor**
  * A constructor can take parameters to set initial values (e.g., for member variables), or a **default constructor** can also be defined

Consider the following example of a constructor declaration and its implementation:
```cpp
/* declaration */
class Person
{
  // ...
  Person(std::string first, std::string last, int arbitrary);
  // ...
};


/* definition/implementation */
Person::Person(std::string first, std::string last, int arbitrary)
  : firstname(first), lastname(last), arbitrarynumber(arbitrary) // special initializer list syntax (these initialize the values of the respective member variables)
{
  // N.B. when using initializer syntax, function body can be empty
}
```

N.B. The constructor always has the same name as the class, and can take any number of **parameters** which have a type and a name (e.g., `std::string first`)
  * A constructor can also not take any arguments (e.g., `Person()`), called the **default constructor**

N.B. Constructors do *not* return a value

N.B. Initializer syntax is recommended as a **best practice** in modern C++

If no constructors are provided, the compiler creates a default constructor automatically (which simply initializes the object without any meaningful data); however, if any constructor is defined, this default constructor is *not* provided

### **DEMO: Constructors**

cf. `/Constructors`

N.B. Using Linux Ubuntu with g++, navigate to directory `/Constructors` and issue the following terminal commands to build the program and then run it from the terminal:
```
$ make
$ ./Constructors
```

## Scope

Thus far, objects have been created as **local variables**; when objects are created in this manner, they have a **lifetime**

As control reaches the line where the object is declared/created, the constructor is called and memory is allocated for it
  * N.B. This memory is created on the stack, and such objects are said to have **stack semantics**

An object has a **scope**, which lasts until the end of the block in which it is declared (i.e., up to the closing `}` of the block)

When an object goes out of scope, its **destructor** runs
  * The destructor is optional, however, it is particularly useful to perform cleanup

N.B. The existence of the constructor and destructor, and the fact that they are guaranteed run in pairs, underly the powerful C++ concept called **RAII (Resource Acquisition Is Initialization)**
  * In the RAII pattern, resources are acquired in the constructor (e.g., a file is opened, a database connection is made, etc.), and then subsequently the resources are released in the destructor (e.g., a file is closed, a database connection is closed, etc.)

### **DEMO: Scope**

cf. `/Scope`

## `struct`

In addition to classes, C++ provides the keyword `struct` for user-defined types

structs are typically used to group "plain old data" (e.g., business logic, semantically grouped data, etc.)

A struct can have member functions, constructors, and destructors, just like classes
  * The only difference from a class is that structs' members are `public` by default (cf. classes' members are `private` by default)

Regarding structs vs. classes...
  * structs are useful to group data
  * classes are more useful if there is additionally associated logic and functionality

## Namespaces

**Namespaces** are a feature of C++ which prevents name collisions

Namespaces are accessed using the scope resolution operator `::` (e.g., `std::string`, where `std::` denotes the Standard Library namespace)

N.B. The syntax `using` can be used to specify a particular namespace to avoid redundancy in the code
  * `using namespace std;` is generally ill-advised; instead, it is recommended to use `using` statements only with specific entities (e.g., `using std::string;`) to avoid potential "namespace pollution* across multiple files

### **DEMO: Namespaces**

cf. `/Namespaces`

## Inheritance

**Inheritance** is another important concept in C++ which is a key to object-oriented design

In C++, there are **base classes**, which are then used to extend **derived classes** (which add or override member variables and/or member functions)

For example:
```cpp
/* declaration of derived class */
class Tweeter : public Person // `:` indicates that `Tweeter` is derived from `Person`
{
  // member declarations -- list only additional member variables and functions (i.e., do not repeat base class members that are not otherwise overridden)
};


/* implementation/definition of derived class */
Tweeter::Tweeter(
    std::string first,
    std::string last,
    int arbitrary,
    std::string handle
  )
  : Person(first, last, arbitrary), // pass arguments to the base class in the initialization (via the corresponding base-class constructor)
    twitterhandle(handle)
{
}
```

### **DEMO: Inheritance**

cf. `/Inheritance`

## Enumerations

**Enumerations** give names to a set of constants, using the keyword `enum`

The principal constraint in old-style enumerations is that the names must be *unique*

For example:
```cpp
enum Status
{
  Pending, // by default, starts from `0`
  Approved,
  Cancelled
};
```

N.B. Enumerations simply alias integers (i.e., `0`, `1`, `2`, etc.)

## Scoped Enumerations

C++ added **scoped enumerations**, which allows underlying types other than `int`; furthermore, the names need not be unique, which can be referenced unambiguously via their **fully qualified names** using the operator `::`

Scoped enumerations are defined using the combined keywords `enum class`

For example:
```cpp
enum class FileError
{
  notfound,
  ok // FileError::ok
};

enum class NetworkError
{
  disconnected,
  ok // NetworkErrror::ok
};

FileError fe = FileError::notfound;
fe = FileError:ok;

NetworkError ne = NetworkError::disconnected;
ne = NetworkError::ok;
```

N.B. Scoped enumerations are generally recommended over old-style enumerations or "magic constants"

### **DEMO: Enumerations**

cf. `/Enumerations`

## The Preprocessor

The **preprocessor** (via its associated **preprocessor directives** beginning with `#`) comprises a distinct step prior to compilation

The preprocessor controls what is compiled

N.B. The preprocessor (a "vestige" of C++'s C lineage) should be used with care and in a limited capacity (primarly via appropriate `#include`s)

One particularly useful preprocessor directive is `#pragma once`, which prevents multiple inclusions (e.g., of header files)
  * It is generally a **best practice** to add a `#pragma once` directive at the start of all header files to prevent potential multiple inclusions across multiple flies (particulary in large, complex applications)

### **DEMO: `#pragma once`**

cf. `/Preprocessor`

## Summary

Declare instances of objects or built-in types on the stack

When the instance goes out of scope, the object is cleaned up

User-defined types and built-in types are equally real

Scoped enumerations make it simple to use named values instead of arbitrary constants

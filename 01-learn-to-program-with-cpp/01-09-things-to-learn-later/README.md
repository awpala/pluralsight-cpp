# Section 9 - Topics to Learn Later

## C++ Has A LOT of Syntax

C++ has many ways to perform tasks equivalently
  * Some are faster
  * Some are more convenient
  * Some are holdovers from C++98 or C

You do not need to know all of these features to write a C++ program effectively
  * Most of it will make more sense when you have written some programs
  * You will encounter problems to solve that the syntax deals with
  * You will eventually know how to try using the syntax
  * In addition to developing C++ programs, you will likely also read others' programs, documentation, tutorials, etc. and therefore encounter unfamiliar syntax there

## Casting

**Casting** instructs the compiler of an intentional change in the data type, e.g.,:
```cpp
double d = 4.9;
int i = d; // implicit cast -- compiler generates a warning
i = static_cast<int>(d); // explicit cast via `static_cast`
```

`static_cast` informs the compiler of an intentional cast, and also communicates this intention to other developers examining the code; it is therefore considered **best practice** (i.e., as opposed to using implicit casting)

N.B. C++ also provides other cast templates: `dynamic_cast<>`, `const_cast<>`, and `reinterpret_cast<>`
  * While discussion of these is beyond the present scope, they similarly are useful to make intent obvious/explicit

### **DEMO: Casting**

cf. `Casting.cpp`

## The Keyword `const`

The keyword `const` (i.e., constant) informs the compiler of non-changing values, e.g.,:
```cpp
int const amount = 90;
```

`const` promises the compiler that a variable's value will not change
  * Prevents logic errors
  * Enables optimizations

`const` can also be used to designate non-changing member functions, e.g.,:
```cpp
string Transaction::Report() const
{
  // ...
}
```

Designating a member function with `const` promises that a member function will not change the value of any member variables (i.e., "read-only")
  * This must be added to *both* the function declaration and the function defintion

### **DEMO: `const`**

cf. `/SimpleClasses`

### Passing Parameters to Functions

Consider the following code, which passes an object instance as an argument to a function:
```cpp
void display(Transaction t);
// ...
Transaction deposit(50, "Deposit");
display(deposit);
```

When passing an object as an argument, by default, what goes into the function (i.e., as the corresponding parameter) is a *copy*
  * Changes inside the function (e.g., `display()`) will be to the local variable, *not* to the parameter (e.g., `deposit`); therefore, any changes performed by the function will not be reflected by the (original) object once the function execution completes

Now, consider the following function declaration:
```cpp
void update(Transaction& t);
```

The operator `&` indicates that the parameter is taken **by reference**, whereby the original version of the argument is passed to the function (i.e., *not* a local copy)
  * Otherwise, the function is called similarly (i.e., `update(deposit);`, as before)

N.B. Passing by reference is much more efficient than passing a copy, particularly if the argument is a large object (for which copying is an expensive operation)

Additionally, to prevent modification of the object passed by reference inside of the function (i.e., "read-only"), `const` can be used to pass by `const` reference, e.g.,:
```cpp
void display(Transaction const& t);
```

### **DEMO: Passing Parameters**

cf. `/Parameters`

## The Standard Library

The Standard Library is very extensive, beyond the simple examples shown in this course involving `<iostream>`, `<string>`, and `<vector>`

The Standard Library provides many **collections**, which are specialized containers for different purposes

Furthermore, the `<algorithm>` header contains many useful functions (e.g., `find`, `sort`, etc.)

The Standard Library also provides complex numbers, random numbers, and regular expressions

N.B. cf. the extensive, up-to-date reference https://en.cppreference.com/w/ for comprehensive coverage of the Standard Library (among other things)

The Standards Committee is constantly working to add more features to the C++ language and the Standard Library
  * N.B. cf. https://isocpp.org/std/status

N.B. As a matter of habit, consult the Standard Library first if add a feature to an application (i.e., prior to building it from scratch)--more likely than not, a common feature or problem has already been solved by it

## Resource Management

### Classes That Manage Resources

Consider writing a `File` class
  * Keeps a **file handle** in a member variables
  * Has member functions to open, read, and write a file

Simlarly, consider writing a class to work with a database
  * Keep an open database connection in a member variable
  * Has member functions to perform queries

How can you ensure the resource is properly managed?
  * Do not leave the file hanging open
  * Be sure to close the connection
  * etc.

You could write a function to perform closing, disposal, cleanup, etc., however, class users could potentially forget to call these

C++ provides **destructors** to manage these types of processes (i.e., when object instances go out of scope)
  * Destructors guarantees that cleanup get a chance to occur
  * Destructors are designated via `~` (e.g., `~Account()`)

### Scope

**Scope** is a fundamental concept in resource management

Consider the following code:
```cpp
{ // start of the scope
  int i;
  Account a; // constructor of `a` runs here
  Transaction T(50, "Deposit"); // constructor of `T` runs here
} // end of the scope -- the destructors of `a` and `T` run here
```

Destructors run when objects go out of scope
  * The most common case is when flow of control reaches a closing brace `}`
  * Member variables go out of scope when the instance they belong to does

N.B. Standard Library objects are also robustly destgned to perform automatic cleanup upon exiting scope (e.g., `string` member variables are correspondingly cleaned up when `a` and `T` go out of scope in the example above)

### Things to Learn Elsewhere

### Exceptions

**Exceptions** are a mechanism for dealing with unexpected program behavior
 * Exceptions are an alternative to returning error codes
 * Exceptions can make neater and faster code when done correctly

## The Free Store

The **free store** (also called the **heap**) lets you create really large or long-lived objects

Objects on the free store are accessed through **pointers**

Pointers are used to perform memory management and resource management activities

N.B. The Standard Library provides **smart pointers** (e.g., `std::shared_ptr` and `std::unique_ptr`) to deal with objects on the free store, as an alternative to traditional **raw pointers**

N.B. When examining memory management, be sure to learn from *modern* material (i.e., C++11 or later)--older methods of memory management are much more dangerous and error-prone
  * cf. RAII, Rule of 3, Rule of 5, and Rule of 0

## Lambdas

**Lambdas** are a way to use a few lines of code as a parameter to a function, or to store something in a variable

## Debugging

Whatever compiler you use, there is a corresponding **debugger** available

Debugging is a vital skill for all developers

Debuggers are not just useful for finding bugs; they can also be used to...
  * Understand the flow of control
  * Watch values change
  * See when the compiler calls things for you (e.g., constructor calls)

Learning to use your debugger is the first step towards becoming a better developer

## Minor Details

Finally, consider a "laundry list" of additional topics that may be encountered in future study of C++

While traditional object-oriented programming is not as common in the present day, it involves many ubiquitous concepts that may be encountered, e.g.,:
  * inheritance
  * virtual functions
  * polymorphism
  * multiple inheritance

The keyword `enum` can be used to define semantic literals (which simply alias integers)

Boolean operators `&&` and `||` occur commonly
  * These operators are **short-circuiting**

C++ also provides the less commonly used bitwise operators `&`, `|`, `^`, `<<`, `>>`

The `switch` statement provides multi-way comparisons

More operators you have not seen yet in this course: `%`, `&`, `*`, `->`, `?:`

Functions can be defined with **default parameters**

## Advanced Details

Interacting with the operating system (e.g., calling a Windows API)

Writing templates

Writing your own operator overloads

## Summary

You now know enough C++ to write a real program

You will need to learn a lot more to write some kinds of applications
  * Windows application (i.e., desktop)
  * Phone apps (each platform is different)
  * Unix application
  * Web service
  * Service

As a next step, learn frameworks and libraries to support specific applications of interest (e.g., games)

C++ has a lot of syntax, however, you do not need to learn all of it to get started
  * Learn it when you need it
  * If something feels really difficult, remember there is more C++ you can learn that might include an easier way to do it (e.g., Standard Library features); consult modern references for this purpose (i.e., C++11 or later)

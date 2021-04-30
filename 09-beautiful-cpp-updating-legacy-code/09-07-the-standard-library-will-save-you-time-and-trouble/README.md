# Section 7 - The Standard Library Will Save You Time and Trouble

## `std::string`

### Working with Strings

Legacy code often works with C-style `char*` strings (i.e., C-style arrays of type `char`) and their corresponding functions prefixed by `str...` (e.g., `strlen()`, `strcat()`, etc.)

Working with C-style strings has its issues, e.g.,:
  * Managing memory manually, including correct allocation for the null terminator `\0`
  * Remembering the `str...` functions, including the order of their parameters and the meaning of their `return` values

### `std::string`

The C++ Standard Library provides `std::string` as an alternative to C-style strings, which is a self-contained object
  * Manages its own memory (i.e., via RAII), including dynamic resizing when necessary
  * Includes useful member functions (e.g., `std::string.size()`, `std::string.clear()`, etc.), including `std::string.c_str()` to convert a C-style string to a `std::string` object instance
  * Provides many useful operator overloads
  * Works with Standard Library algorithm functions via header `<algorithm>`
  * Provides useful conversions to `std::string` (e.g., from numeric types)
  * Compatible with move semantics (i.e., "move-aware") as of C++11

N.B. C++ also provides `std::wstring` to work with wide strings (i.e., based on `wchar_t`s)
  * `std::string` is actually implemented as a template to handle a variety of character types 

### **DEMO: `std::string`**

cf. `/String`

N.B. The demo code in this repository uses C versions of the `str...` functions (e.g., `strncpy()` and `sprintf()`) rather than the `..._s` "safe" versions (e.g., `strncpy_s()` and `sprintf_s()`), as the latter are not standard (in particular, are not supported/implemented by `g++`)
  * This is a deviation from the code demonstrated in the corresponding lecture video, which uses the "safe" versions via Visual Studio with MSVC++ compiler

## Arrays

### Working with Arrays

Legacy code often includes C-style arrays via `[]`, which have several issues
  * Manual memory management (e.g., allocating, resizing, etc.)
  * Raw loops, which can be performed via array index `[]` or pointer `*` and are error-prone (e.g., going out of bounds)
  * Passing to functions, which often requires an additional argument to indicate the array's size (i.e., the array is not "size-aware")
    * The size is often declared via (error-prone) macro

## `std::vector`

The Standard Library collection `std::vector` provides a much safer alterantive to C-style arrays
  * `std::vector` is "size-aware"
  * `std::vector` manages its own memory (including resizing and cleanup)
  * `std::vector` provides many useful member functions and operator overloads
  * `std::vector` works with the Standard Library algorithm functions via header `<algorithm>`
  * As with C-style arrays, `std::vector` stores its elements contiguously in memory to maintain fast performance (as stipulated by the corresponding Standard Library implementation requirement)
    * `std::vector` does perform many copy operations to maintain this property, however, `std::vector` is also "move aware" and will use move semantics where appropriate to minimize this cost
    * `std::vector` can also be initialized with a capacity, which if chosen judiciously will further minimize these copy operations

For an array-like collection with a fixed size at compile time, a suitable alternative to `std::vector` is `std::array`

### **DEMO: `std::vector`**

cf. `/Vector`

## Action Plan for `std::string` and `std::vector`

1. First, understand the (legacy) code to be updated; start where the `char*` or `[]` array is created

2. Change the type of the variable

3. Replace helper size variable (or calls to `strlen()`) with method `.size()`
    * Remove unneeded constants

4. Remove cleanup code
    * `std::vector` and `std::array` perform this automatically

5. Replace `str...` functions with corresponding member functions and or Standard Library algorithm functions

6. Replace hand-rolled/raw loops to a more appropriate modern collection-idiomatic approach (e.g., ranged `for` loop, Standard Library algorithm function, etc.)

7. Change function signatures to accept the new collection type
    * N.B. The function `std::string.c_str()` can be used in function signatures that take a (C-style) string parameter but otherwise do not modify it (e.g., do not write to the string)

## RAII Pointers

### Smart Pointers

RAII is great, as has been repeatedly shown in this course
  * Stack-allocated objects which automatically manage their own memory are generally better (i.e., safer) to use than corresponding raw pointers (i.e., via `new` and `delete`)

You *can* write it yourself if a suitable Standard Library feature (e.g., `std::vector`, `std::string`, etc.) is not available for a particular use case
  * Allocate/acquire in the constructor
  * Release/free in the destructor

For example:
```cpp
void Order::SetDiscount(int amt)
{
  if (discount) // guard condition to prevent memory leak in case `SetDiscount()` is called successively
    delete discount;
  discount = new Discount(amt);
}

bool Process(Order order) // takes `order` by value (i.e., creates a copy of the `Order` object)
{
  // ...
  return true;
} // `order` goes out of scope here

// ...
Order o;
// ...
Process(o); // `Process()` is called, with argument `o` passed by value (i.e., as a copy)
// `o` no longer points to a valid discount here
```

However, in the particular case of memory management, this work has already been done and is available in the Standard Library in the form of **smart pointers** (e.g., `std::unique_ptr` and `std::shared_ptr`)

### How Did We Deal with This?

Write a lot of code (e.g., copy constructor, copy assignment operator, etc.)

Make rules (e.g., never pass by value)

*Hope* it works!

## The Standard Smart Pointers

The C++ Standard Library provides smart pointers that implement RAII by design, taking care of proper initialization, copy, clean up, etc.

There is sometimes hesitation about adopting smart pointers, as they make you think about lifetime and ownership

However, they are indeed a powerful tool which communicates your choices clearly to readers (i.e., without requiring additional and/or excessive comments); furthermore, they do all the work for you
  * With smart pointers, the rule of three (copy constructor, copy assignment operator, and destructor) and subsequent rule of five (move constructor and move assignment operator) become the **rule of zero**: no need to implement these constructs from scratch, as they are already provided in the smart pointers' Standard Library implementations

### **DEMO: Smart Pointers**

cf. `/SmartPointers`

## Kinds of Pointers

### Smart Pointers `std::shared_ptr` and `std::unique_ptr`

| `std::shared_ptr` | `std::unique_ptr` |
|:---:|:---:|
| Copyable via reference count it maintains of the heap | Non-copyable, only movable |
| Destructor checks reference count and deletes if it reaches`0` | Destructor deletes the single resource in the heap memory |
| Low overhead, non-intrusive | Lowest overhead, non-intrusive |
| Polymorphic | Polymorphic |
| Just use it like a pointer | Just use it like a pointer |
| Initialize via `std::shared_ptr.make_shared()` | Initialize via `std::unique_ptr.make_unique()` |

### So, All Raw Pointers Should Go?

This is *not* correct--raw pointers in and of themselves are *great*; however, *owning* raw pointers are terrible!
  * Owning means manual memory management (i.e., *you* need to delete...eventually, but not too soon, and not twice, and even if there are exceptions or early returns, etc.)
  * Otherwise, using non-owning raw pointers (i.e., without managing memory/lifetime manually) has many common use cases in typical applications

## But Are You Sure You Need a Pointer?

Some functions take arguments by address, when taking by reference instead would be much neater
* Extra punctuation
* Checking for null
* Uncertainty about ownership

Therefore, consider taking by reference instead

Furthermore, some variables could just be local, e.g.,:
  * Instead of using a pointer member variable that is always `new` in the constructor, simply include it as a solid member in the first place
  * Instead of allocating a local variable inside of a function via `new` and then calling `delete` before the function returns, simply use stack semantics for the variable instead

## Algorithms

The Standard Library provides many useful functions via header `<algorithm>` (as well as header `<numeric>`)
  * Work on any Standard Library container (e.g., `std::vector`, `std::array`, etc.) and any appropriately designed user-defined container class, no matter what it contains
  * Work on ranges, including only a subset of the container's elements if necessary
  * Typically work through **iterators**, which provide signifnicant functionality and reduce redundancy (i.e., prevents unnecessary duplicate methods across containers)

## Write Output

### Does Your Code Write Output to a Console?

Perhaps with `printf()`?

Perhaps with `<<` and `std::cout`?

Is it just for debugging? Logging?

### Write Something That Returns a String

If the console (and/or file output) is only being used for debugging or logging, consider using `std::string`s instead in a corresponding function (e.g., `dump()`, `log()`, `details()`, `to_string()`, etc.)
  * With `std::string`, nobody has to manage the C-style `char[]` string's memory
  * Furthermore, the calling code can use the `std::string` in various ways

## Summary

Managing memory is a challenge
  * Arrays of `char`s might be better as `std::string` objects
  * Arrays of objects might be better as `std::vector` or `std::array` object
  * Owning pointers should be smart pointers

The header `<algorithm>` does *so* much!

Instead of writing to a file or to a stream, consider building a `std::string` instead

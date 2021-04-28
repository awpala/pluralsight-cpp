# Section 6 - Language Changes in C++11, 14, and 17

## Standards

### C++ Keeps Changing

There was no formal standard until 1998

C++03 was a minor revision to C++98

C++11 was a major revision to the language, which added many important features and capabilities to both the language and the Standard Library, and fundamentally changed the way C++ code can be written

C++14 and C++17 built on C++11 to fill in missing features and to add new capabilities to complement the modern C++ coding style

Consequently, you can make code that is *much simpler* using the newer features (i.e., C++11 and later)

## `auto`

C++11 added the keyword `auto`, which asks the compiler to deduce the type
  * The variable is still strongly typed

`auto` type deduction is particularly useful to avoid explicitly indicating "ugly" type declarations (e.g., verbose iterator types)

### Action Plan for `auto`

Use it when adding new code

Consider replacing long or complicated explicit declarations for improved readability

May force you to move declaration to where the variable is initialized
  * This is a feature, not a bug!

### **DEMO: `auto`**

cf. `Auto.cpp`

## Null Pointers

### `NULL`, `0`, and `nullptr`

A pointer that does not point to anything meaningful is said to be "**null**"; such a null pointer is represented with the numerical value of `0` (i.e., rather than an explicit address)

`NULL` is a macro that means `0`, which is a carry-over from C
  * Ocassionally, the macro `NULL` can cause some undesired behavior, particularly with function overloads of `int` being chosen

C++11 introduced the keyword `nullptr` to designate a null pointer, and this is the recommended **best practice** when working with pointers
  * `nullptr` is otherwise interchangeable with `0` and `NULL`

Consider the following example of the "function overload problem":
```cpp
// overload A
int f(int n) { return n-1; }

// overload B
int f(int* n)
{
  if (n) return *n;
  else return 2;
}

auto j = f(0); // returns `-1` via overload A
j = f(nullptr); // returns `2` via overload B
j = f(NULL); // returns `-1` via overload A, because `NULL` aliases the `int` value `0`

int* n = NULL;
j = f(n); // returns `2` via overload B, as intended
```

### **DEMO: Null Pointers**

cf. `Null.cpp`

## Lambdas

C++11 also introduced **lambdas**, which is a code segment (a function, often inline/anonymous) that can be used to replace equivalent older constructs, such as function pointers (e.g., `bool (*compare)(int, int);`)

Lambdas are typically more transparent--you can see the code at the calling site
  * Lambdas are one of the few places where naming does not otherwise help a lot; it is often more idiomatic to write the lambdas inline/anonymously

### **DEMO: Lambdas**

cf. `/Lambda`

## Range-Based `for` Loop

Consider a "raw" `for` loop (or equivalent `while` loop) performed on a collection which iterates through each element of the collection exactly once, e.g.,:
```cpp
std::vector<int> nums { 1, 2, 3, 4 };

int total = 0;
for (auto it = nums.begin(); it != nums.end(); it++) // accesses iterator-wise via `it`
{
  total += *it;
}
```

The equivalent construct can be expressed more compactly with a range-based `for` loop, e.g.,:
```cpp
total = 0;
for (auto num:nums) // accesses element-wise via `num`
{
  total += num;
}
```

N.B. Range-based `for` loops also work on C-style arrays in addition to Standard Library collections (e.g., `std::vector`), and they can also access element-wise both by value *and* by reference
  * Therefore, range-based `for` loops are a useful idiom for modernizing C++ code


### **DEMO: Range-Based `for` Loops**

cf. `RangedFor.cpp`

## Enumerations

Enumerations have many useful properties, e.g.,:
  * Give a name to a number
  * Better than using a literal or macro
  * But could be better still (with respect to a traditional/pre-C++11 enumeration)

### Enumerations Issues

Names must be unique (e.g., `E_Ok`, `F_Ok`, `S_Ok`, etc. in different enumerations)

Are *not* strongly typed (e.g., can pass a `FileStatus` enumeration value to a function expecting a `NetworkStatus` enumeration value, can pass value `F_Ok`/`3` which is taken as `N_PermissionDenied`/`3` in that particular function, etc.)

### Enumeration Classes (C++11 and Later)

Always use fully qualified name
  * No more need for uniqueness due to unambiguous scoping

More strongly typed
  * Can "opt in" to "weaker" typing via `static_cast<>`, if necessary

Less implicit conversions to/from `int`

## Constructors

### Private Constructors

In older code, some constructors (e.g., copy constructors and assignment operators) are marked `private` to keep other code from calling them

A common reason for doing this is because the compiler might otherwise generate these constructors (as `public`) if they are not included explicitly

### Why Prevent Calling a Constructor?

To make an object non-copyable (e.g., via `private` copy constructor)

So that an object cannot be instantiated
  * Typically, this would be a class composed exclusively of `static` members

To prevent inheritance (i.e., derived classes cannot construct the base class)

The singleton design pattern
  * This is the only bona fide use case (i.e., as compared to the previous cases) for preventing the calling of a constructor in modern C++

### How Do You Take a Constructor Away?

C++11 introduced a better mechanism for making constructors inacessible via keyword `delete`
  * To prevent a specific constructor overload, simply do not include it in the class
  * However, to prevent a specific type of constructor, rather than writing a `private` one, mark it with `= delete` instead

Furthermore, consider the particular reason for making a constructor inaccessible
  * To prevent inheritance, use keyword `final`
  * To prevent copying, use keyword `delete`

### Forcing Constructors to Be Generated

C++11 also provides the additional complementary feature of "forcing" a particular constructor to be generated by the compiler via `= default`
  * This can be used to create a default constructor, copy constructor, move constructor, and even the destructor

N.B. This explicit approach is a better practice (i.e., more expressive) than simply omitting these altogether

## Summary

Change long or complex declarations to `auto`
  * Especially if `const` or `&` are involved

Change `NULL` to `nullptr`

Small functions and function pointers are a good opportunity to refactor to a lambda

If a raw loop iterates through every element of a collection, make it a range-based `for` loop instead

Consider changing `enum` to `enum class`, if the changes are not too wide-ranging

Change `private` constructors to deleted constructors where appropriate

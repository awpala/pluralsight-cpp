# Section 2 - Arrays, Pointer Arithmetic, and Strings

## Legacy Code

### Code Never Really Goes Away

Legacy code is...
  * Released in open source libraries, that can spread across other codebases over time
  * Described in blogs, articles, Q&A, internet repositories, etc.
  * Printed in books and magazines

In fact, some old C++ reads like a *different* language than modern C++

### What Makes It "Legacy"?

C++11 is considered the first major revision constituting "modern" C++
  * Before C++11, there were no lambdas, no ranged `for` loops, etc.

Legacy code tends to avoid using templates (e.g., C-style arrays rather than `std::vector`, C-style casts rather than `static_cast`, etc.)

Developers using legacy C++ coding style also have different habits, e.g.,:
  * No `const`
  * Manual dynamic memory management via `new` and `delete`
  * Raw pointers
  * Little use of the Standard Library (e.g., `std::string`, `<algorithm>` header, etc.)

Essentially, legacy C++ code is "C being compiled as C++" (i.e., "C with Classes")
  * This course will focus on learning how to read this style of code

## Pointers

Many modern C++ developers rarely use raw pointers; instead modern C++ involves:
  * passing by value and by reference
  * using Standard Library types (e.g., `std::optional`) that are more intuitive than using the equivalent raw pointers
  * etc.

When working with raw pointers, punctuation to look for includes:
  * `*` in a declaration denotes a pointer (e.g., in `int* pi;` or equivalently `int *pi;`, `pi` is a pointer to `int`)
  * `&` preceding a variable denotes "address of" (e.g., given `int j = 4;`, `pi = &j;` stores a reference to `j` in `pi`)
  * `*` before a variable (i.e., subsequently to its declaration) denotes "content of" (e.g., `*pi = 3;` changes `j`'s value to `3`)
  * `->` succeeding a pointer-to-object variable is equivalent to `(*ptr).`
    * This can be used to call a member function

### Pointer Arithmetic

In addition to introducing extra syntax when using pointers (i.e., rather than values and references), they also introduce other differences:
  * Pointers can be "null" (i.e., pointing to "nowhere")
  * Pointers can be changed to point to somewhere else

*Incrementing* a pointer via `++` makes it point somewhere else, by advancing the pointer by the appropriate size of its stored type

Consequently, pointer arithmetic is a great source of bugs

## C-Style Arrays

In modern C++, it is common practice to use `std::vector` to store arbitrarily many elements of the same type in a single collection

Conversely, the "pre-modern" predecessor to this approach is the **C-style array**

To use a C-style array:
  * Declare with a type, and a size (i.e., number of elements) known at compile-time (e.g., `int numbers[4];`)
  * Can also initialize when declaring, which permits omission of the size for the compiler to deduce instead (e.g., `double morenumbers[] = {1.1, 2.2, 3.3, 4.4, 0};`, whose size the compiler deduces as `5`)
  * Access one element with `[...]`, as with `std::vector`
  * Can also access using pointers, which is done commonly

For example:
```cpp
double d[] = {1.1, 2.2, 3.3, 4.4, 0}; // includes "sentinel" value `0` to denote termination of array, a common (error-prone) idiom in legacy C++ (and C)

for (double* p = d; *p != 0; p++) // `for` iteration via pointer `p` -- N.B. `p` has type `double**` (i.e., pointer to an array of doubles), where `d` is points to the address of `d[0]`
{
  *p += 1.0;
}
```

### Array Limitations

C-style arrays do not know how many elements they hold (i.e., they do not provide the corresponding members to determine this); the compiler simply treats the variable name as a pointer to the beginning of the array
  * Therefore, staying inside the bounds of the array's elements must be managed by the developer (i.e., C-style arrays do *not* perform **bounds checking**)

Furthermore, C-style arrays cannot grow to accomodate a new element; their size is fixed at compile-time

### Dynamic Arrays

For **dynamic arrays**, the size is not known at compile-time, but rather is determined at run-time

Using C-style arrays, dynamic arrays are allocated using the operator `new[]` (which allocates the corresponding memory on the free store); otherwise, use of the array is identical to the stack-based array (i.e., fixed at compile-time), as demonstrated previously

To clean up a C-style dynamic array (i.e., deallocate its memory from the free store), use the operator `delete[]`

However, such C-style dynamic arrays cannot be **resized** automatically; rather, to accomplish this manually:
  * Create a larger array
  * Copy over the elements from the original array
  * Clean up the original array

### **DEMO: C-Style Arrays**

cf. `arrays.cpp`

## C-Style Strings

### Arrays of `char`

Strings are an old, ubiquitous concept in programming

Prior to `std::string`, a C-style string was used, which consists of an array of `char` elements (e.g., `char[] str = {'A', 'B', 'C', '\0'};`)
  * By convention, the last element is the **null character** `'\0'` (distinct from `nullptr`, `'0'`, and `"0"`), which denotes the end of the string (such C-style strings are therefore sometimes called **null-terminated strings**)

The Standard Library provides a large collection of functions with names that are prefixed with `str...` in the header `<cstring>` (e.g., `strlen()`, `strcpy()`, etc.)
  * A common error when using these function is forgetting to allocate sufficient memory to include room for the terminating null character (correspondingly, there are many `+1` adjusting idioms used with these functions)

When using the more modern `std::string` object, it provides a constructor to build a `std::string` object from a C-style string (i.e., array of `char`s)

Similarly, `std::string` objects provide the method `c_str()` to convert in the other direction (i.e., from `std::string` object to C-style string)

### **DEMO: C-Style Strings**

cf. `strings.cpp`

## Summary

Legacy C++ code can read like an entirely different language

C-style arrays have less power than `std::vector` or `std::array`
  * Do not know their length
  * Do not perform bounds checking or self-resizing

A C-style string consist of an array of `char`s, which by convention are null-terminated via terminal element `'\0'`
  * Use functions from header `<cstring>` for performing manipulations of C-style strings

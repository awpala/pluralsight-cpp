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








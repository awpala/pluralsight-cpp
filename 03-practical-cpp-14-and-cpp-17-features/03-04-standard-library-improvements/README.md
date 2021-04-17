# Section 4 - Standard Library Improvements

## What Is a Raw Pointer?

### (Raw) Pointers in Modern C++

In modern C++ (post-C++11), it is possible to write production-level C++ code without the use of raw pointers

However, when working with mature/legacy codebases or more complicated applications, you will likely encounter **raw pointers**

### Pointers and Addresses in Computer Memory

In a C++ program, objects live in memory, which is **addressable** (typically as a hexadecimal integer denoting its location in memory, e.g., `0x7ffca2e06bdc`)

### Variable: Where Do You Live?

A **pointer** contains the address of a variable, e.g.,:
```cpp
int n{64};

int * p = &n; // pointer `p` (of type `int*`) holds the address of `n` (via `&`)
```

N.B. The unary operator `*` (**dereferencing operator**) is used to declare a pointer variable and to access (i.e., derference) the value it points to, and the unary operator `&` (**address of operator**) returns the addess of its operand

### The Null Pointer Points to *Nothing*

C++11 provides the keyword `nullptr` to initialize or assign a pointer value to "nothing"

N.B. Prior to C++11, the equivalent to `nullptr` was `0` or macro `NULL`, however, using `nullptr` instead in modern C++ code is the recommended style and best practice

## Requesting Memory: Stack vs. Heap

### Variables Allocated on the Stack

Consider the following statements:
```cpp
int n{64};
double speed{10.0};
bool success{true};

// more code ...
```

In these statements, the memory for the variables `n`, `speed`, and `success` is allocated on the **stack**, a region of memory

### Stack: Pros and Cons

The stack performs very fast memory allocations
  * Allocating/deallocating memory on the stack simply involves moving a **stack pointer**, which is an O(1) operation

However, the allocatable memory on the stack is very limited, and "overflowing" the stack can cause fatal errors in the program
  * The stack is well suited for allocating built-in/primitive data types
  * However, the stack is *not* well suited for allocating complex objects 

### Larger Amount of Data: Allocate on the Heap

The **heap** (or **free store**) is a separate area of memory from the stack, which is designed for storing large memory allocations (e.g., complex objects)

### Heap: Pros and Cons

Allocating memory on the heap is comparatively much slower than on the stack
  * Requires a request to the operating system's memory manager, involving many operations and complex data structures

However, memory allocated on the heap can serve much *larger* chunks of memory, and much less limited in this regard than the stack

### Requesting Memory from the Heap

In C++, **dynamic memory allocation** on the heap is performed using the operator `new`, e.g.,:
```cpp
double * p = new double[1000000]; // allocates one million `double`s
```

The operator `new` returns a pointer to the (starting) address on the heap where the memory was allocated
  * N.B. The memory is allocated as a contiguous block of memory (i.e., sequential bytes)

### Memory Lifecycle

Consider the lifecycle of memory when dynamic memory allocation on the heap is performed:
  1. `new` allocates memory on the heap and returns a pointer to it
  2. The memory is used in the running program
  3. The memory must be released to prevent a **memory leak** 

When memory is allocated on the stack, release of memory is performed *automatically* by the compiler; however, when dynamically allocating memory on the heap, releasing this memory must be performed *manually*

### Memory Lifecycle with Raw Pointers

When using raw pointers, memory is released via operator `delete`, e.g.,:
```cpp
// 1. Allocate large chunk of memory using new[]

// 2. Use the memory

// 3. Release the memory
delete [] p;
p = nullptr; // as a best practice, assign `p` to `nullptr` to avoid dangling references
```

N.B. When `delete` is used, the memory on the heap is released/recycled, however, the pointer still subsequently points to that memory location on the heap; therefore, as a **best practice**,  such pointers should be reassigned to `nullptr` to prevent having so called "**dangling pointers**" in the application
  * Accessing an "un-reset" dangling-pointer reference on the heap in this manner can introduce pernicious bugs into the program which can be difficult to debug

## Smart Pointers

### Resource Managers

Starting in C++11, the compiler provides **resource managers** that *automatically* release their owned resource (e.g., memory)
  * N.B. For reference, recall https://bit.ly/CppAutoResMgm describing automatic resource cleanup with destructors

For example:
```cpp
{ // new scope entered
  ResourceManager x{/* ... */}; // new resource is allocated via its constructor

  // use `x`
  x.DoSomething();
  // more code ...
} // upon exiting this scope, `ResourceManager` is automatically released (e.g., via destructor `~ResourceManager`)
```

Using a resource manager in this manner allows for writing C++ code which is structurally incapable of leaking resources (e.g., memory)

### Raw vs. Smart Pointers

raw (owning) pointers must *explicitly* `delete`/release the owned memory
  * N.B. A non-owning raw pointer (i.e., one that does not allocate memory on the heap, but simply points to/"observes" a variable) does *not* require deallocation/release, as there was no corresponding allocation performed previously

Conversely, modern C++ (starting from C++11) introduced **smart pointers**, which wrap raw pointers and automatically perform the necessary deletion/release of heap-allocated memory

The simplest smart pointer, `std::unique_ptr`, does not require explicit management of the allocated memory; as soon as the `std::unique_ptr` goes out of scope, it releases its own heap-allocated memory
  * This promotes writing safe C++ code

### Creating `unique_ptr`s with `make_unique`

The Standard Library provides `std::make_...` functions to perform the analogous role of `new` for raw pointers, e.g.,:
```cpp
#include <memory> // provides `std::unique_ptr` and `std::make_unique` 

// create a `unique_ptr` object `p` to an array of one million `double`s
auto p = std::make_unique<double[]>(1000000);

// when `p` goes out of scope, it will automatically deallocate its elements (i.e., array of one million `double`s)
```

Therefore, in modern C++ code, in general there should be no need for explicit calls to `new` and `delete` (i.e., no need to use raw owning pointers)

### Some Applications of `unique_ptr`

Consider some examples of using `std::unique_ptr`, e.g.,:
```cpp
// A safe owning smart pointer to image pixels
class Image {
  // ...
  int mWidth;
  int mHeight;
  unique_ptr<byte[]> mPixels; // smart pointer member variables
};

// A safe owning smart pointer returned by a factory function
unique_ptr<SomeObject> MakeObject(/* settings... */) {
  // ...
}
```

### **DEMO: Raw Pointer vs. Smart Pointer via `unique_ptr`/`make_ptr`**

cf. `Pointers.cpp`

## Standard-Defined Literals and the `<chrono>` Library

### Units of Measurement

Consider the following code:
```cpp
sleep(20); // causes the calling thread to "sleep" for 20 ...?
```

While they are not significant to the compiler, **units of measurement** are important to the programmer, particularly in programs involving many calculations involving physical quantities/units

C++14 defines some standard **suffixes** to denote many useful quantities (e.g., time)

The Standard Library header `<chrono>` (with corresponding namespace `std::chrono`) was introduced in C++11 and further expanded in C++14, which includes the following useful time duration classes:
  * hours
  * minutes
  * seconds
  * milliseconds
  * microseconds
  * nanoseconds

Furthermore, the `<chrono>` library performs automatic unit conversions

### Time Duration Initialization

N.B. The following examples using `seconds` generalize to the other time duration classes as well

Time durations can be initialized as follows:
```cpp
seconds s{}; // zero-initialized via `{}`
seconds s; // no initialization (garbage value)

seconds s{10}; // `10` seconds
seconds s = 10; // will not compile
auto s = 10s; // `10` seconds -- this suffixed form is valid as of C++14 (furthmore, via `auto`, the compiler deduces the correct type of `chrono::seconds`)
```

N.B. Recall declaration and initialization of variables (cf. https://bit.ly/CppInitVar)

### Standard-Defined Literals

The following is a summary of the standard-defined literals in `chrono::duration`:
| Literal Suffix | `std::chrono::duration` |
| :---: | :---: |
| `h` | hours |
| `min` | minutes |
| `s` | seconds |
| `ms` | milliseconds |
| `us` | microseconds |
| `ns` | nanoseconds |

### Deducing Strings

When using `auto` with string literals, consider the following example:
```cpp
auto s = "Connie"; // `s` has type `const char*` (pointer to array of `char`s, initialized to the string literal) not `std::string`
```

With modern C++, to avoid this behavior (i.e., to use `std::string` rather than `const char*`), C++14 provides the suffix `s` for this purpose, e.g.,:
```cpp
auto s = "Connie"s; // `s` has type `std::string`
```

Furthermore, there is no ambiguity with respect to `std::chrono::seconds` (i.e., same suffix `s` for two different/unrelated types), e.g.,:
```cpp
auto s = "Connie"s; // compiler deduces `std::string`
auto y = 10s; // compiler deduces `std::chrono::seconds`
```

### **DEMO: Standard-Defined `<chrono>` Literals**

cf. `Chrono.cpp`

N.B. `std::chrono` performs automatic time unit conversions at *compile-time* (i.e., *not* at *run-time*!)

## Tuples and Fetching Elements by Type

### `std::tuple`

C++11 introduced the new class template `std::tuple` (via corresponding header `<tuple>`) to the Standard Library, which is a fixed-size collection of heterogeneous values (i.e., of different types), e.g.,:
```cpp
// example tuple `std::tuple<std::string firstName, std::string lastName, double gpa, char grade>`
auto student = std::make_tuple("John", "Doe", 3.5, 'A');
```

### `std::tuple` Is a Generalization of `std::pair`

While `std::pair` contains only two (heterogeneous) elements, `std::tuple` generalizes this to arbitrarily many elements

### Fetching Elements from `std::tuple`

Prior to C++14, elements of a tuple were fetched via `std::get<>()`, using a zero-based index, e.g.,:
```cpp
auto gpa = std::get<2>(student); // returns third element
```

C++14 extended this capability by enabling to use the element's type to fetch via `std::get<>()` (provided the target element's type is distinct within the tuple), e.g.,:
```cpp
auto gpa = std::get<double>(student);
auto firstName = std::get<std::string>(student); // error -- this is ambiguous (`student` has two elements of type `std::string`); therefore, must use index instead here
```

## Summary

`make_unique` and `unique_ptr` allow to safely perform dynamic memory allocation via the heap

Standard-defined literals are useful for avoiding bugs involving unit conversions

`std::tuple` elements can be fetched by type starting in C++14 rather than by index

# Section 5 - Safely Encapsulating Fixed-Size Arrays with `std::array`

## `std::array`: A Zero-Overhead Wrapper around Built-In Arrays

### Concrete Example: x-y Coordinates for a Quadrilateral

#### Using `std::vector`

Consider using `std::vector` (given 2 `float`s per x-y vertex and 4 vertices total), i.e.,:
```cpp
std::vector<float> quad(8);
```

Using this approach, allocating this memory on the heap rather than on the stack is inefficient, given that the size of the `std::vector` object will not change (i.e., the quadrilateral will always have four vertices)
  * This is particularly important if this code is part of a tight loop (e.g., a rendering engine with a high framerate)

#### Optimization: Stack-Allocated C-Style Array

A potentially better approach is to use a stack-allocated C-style array, i.e.,:
```cpp
float quad[8];
```

While this approach provides zero-overhead stack allocation, using this C-style array is not a modern C++ best practice; instead, the C++ Standard Library provides the container `std::array` for this purpose

### `std::array`

`std::array` is...
  * Zero-overhead (unlike `std::vector`, which uses the heap)
  * Useful for very small containers (e.g., `quad` from the previous example, small local buffers, etc.)
  * Fixed-size, which is known at compile-time

### `std::array` vs. `std::vector`

| Container | Memory Overhead | Resizing | Memory Bounds |
| :---: | :---: | :---: | :---: |
| `std::array` | zero-overhead via stack | fixed-size at compile-time | stack space is limited |
| `std::vector` | dynamic-allocation overhead via heap | resizable | heap is well suited for large memory allocations (e.g., complex objects) |

## Common Operations with `std::array`

### `std::array` Construction

`std::array` objects are created/constructed as follows (via Standard Library class template):
```cpp
std::array<int, 3> a = {11, 22, 33}; // store `3` elements of type `int`
std::array<int, 3> a{11, 22, 33}; // equivalent to previou statement
std::array a{11, 22, 33}; // equivalent to previous statements -- requires C++17 (deduces type and count automatically)
```

N.B. This C++17 feature is called **deduction guides**

### Method `std::array::size()`

The method `std::array::size()` returns the number of *elements* (*not* the total number of bytes) in the container, e.g.,:
```cpp
std::array<double, 4> a {10.0, 20.0, 30.0, 40.0};
std::cout << "Number of elements: " << a.size();
```

N.B. The operator `sizeof` returns the number of bytes of its operands, and is commonly use to determine the size of a C-style array in legacy C++ (and C), however, this approach is error-prone

N.B. Recall that `std::vector::size()` similarly returns the number of elements in a `std::vector` object instance; this demonstrates the genericity that is inherent in the C++ Standard Library

### Accessing `std::array`'s Elements

Once a `std::array` object instance is initialized, its elements can be accessed via operator `[]` (i.e., `a[i]` at index `i` via zero-based index)
  * This is fast O(1) random element access via integer-index offset (unless certain debug checks are enabled)

Additionally, as with `std::vector`, `std::array` provides bounds-checked element access via corresponding method `std::array::at()` (i.e., `a.at(i)`)

Furthermore, to access the underlying raw/C-style array wrapped by the `std::array` object instance, this can be done via method `std::array::data()` (i.e., `a.data()`)
  * N.B. There is a corresponding method `std::vector::data()` as well

### `std::array` Assignment

With C-style arrays, the following is not permissible:
```cpp
int a1[] = {10, 20, 30};
int a2[] = {11, 22, 33};

a2 = a1; // compiler error
```

Conversely, `std::array` supports the assignment operator, e.g.,:
```cpp
std::array a1 = {10, 20, 30};
std::array a2 = {11, 22, 33};

a2 = a1; // no error
```

### Iterators for `std::array`

When using `std::array` object instances, iterators can be accessed via free functions from the Standard Library (e.g., `std::begin(a)` and `std::end(a)`) or member functions (e.g., `a.begin()` and `a.end()`)
  * This is another demonstration of genericity--the same features were seen previously with `std::vector`

## Reusing Standard Library Algorithms with `std::array`

### Reusing Algorithms with Different Containers

A key design feature of the Standard Library algorithms is that they can be reused with many different Standard Library containers, which is facilitated by the underlying iterators (which access the containers' elements) that connect the algorithms to the containers
  * This in turn reduces the need for redundant method functions to perform common operations among the containers

### Searching for Elements in `std::array`

There is no member function `std::array::find()`; however, the previously seen (cf. `std::vector`) Standard Library algorith m function `std::find()` *can* be used with `std::array` as well

For example:
```cpp
// given `std::array` object instance `a`
auto result = std::find(begin(a), end(a), value);
```

### Sorting Elements in `std::array`

To sort the elements of a `std::array` object instance, use `std::sort()`, e.g.,:
```cpp
std::sort(begin(a), end(a));
```

### **DEMO: `std::array` in Action**

cf. `Array.cpp`

## Implementing Very Efficient, Fast Look-Up Tables with `std::array`

A very efficient, fast look-up table can be implemented using `std::array` to store read-only data, which can then be searched via binary search to look up items in the `std::array` object instance
  * The `std::array` object instance must be ***sorted*** in order to perform binary search

Rather than implementing the binary search algorithm from scratch, the C++ Standard Library provides the (obcurely named) algorithm function `std::lower_bound()` for this purpose

Furthermore, if the table is defined at the calling-function scope, use `static` `constexpr`, which avoids having the comiler generate unnecessary machine code (e.g., to push values onto the stack), i.e.,:
```cpp
{ // function scope

  // ...

  static constexpr std::array table = {
    // ...
  };
}
```

## Summary

Introduction to the container `std::array`
  * Performance and zero-overhead of a raw/C-style array is combined with the advantage of using a high-level C++ Standard Library container

When to use `std::array` vs. `std::vector`

Reuse Standard Library algorithm functions with `std::array`

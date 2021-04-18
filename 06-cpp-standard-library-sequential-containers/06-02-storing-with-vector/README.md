# Section 2 - Storing Sequences of Elements with the Standard Library Container `std::vector`

## Introduction

### Navigating the C++ Standard Library Containers

This course (and its follow-up companion) will "navigate" the C++ Standard Library containers, covering their fundamental operations and providing guidance on selecting appropriate containers based on their properties and trade-offs

### Different High-Quality Standard Containers

The C++ Standard Library provides many high-quality containers, having different properties that suit different needs

These containers are highly optimized and well tested

### C++ Standard *Library* (*Not* Framework)

Beware that the Standard Library is a library, not a framework; this means that the C++ Standard Library does not enforce any particular architecture or infrastructure for C++ projects that use it

In fact, most frameworks (e.g., Qt) are compatible with the Standard Library containers, and indeed it is even generally considered a **best practice** to use the Standard Library containers whenever possible
  * Using C++ Standard Library containers improves portability across different frameworks

## Introducing `std::vector`

### Sample Scenario: IoT Application

Consider an IoT application which reads a data stream from an external device (e.g., temperature logs); where should such data be stored (i.e., for later processing)?

One possibility is to use a raw C-style, fixed-size array, e.g.,:
```cpp
// data read from sensor
float temperatures[100];
```

However, using C-style arrays is ill-advised
  * The size is fixed, and therefore can only store a predefined amount of data points

To address the issue of fixed size, a dynamic, heap-allocated raw array could be used (which can be resized as necessary), e.g.,:
```cpp
// data read from sensor
float* temperatures = new float[100];
```

However, implementing a proper robust and bug-free raw array is complicated and cumbersome
  * Resizing the array requires several steps
    1. Allocate a new larger memory block
    2. Copy the data from the previous block to the new block
    3. Release the previous block
  * Additional code is also required to make the code safe in case of an exception occurring, etc.

### `std::vector`: A Dynamically Flexible Array

Fortunately, in the realm of modern C++, the Standard Library provides robust containers for storing a sequence of elements; in particular, the Standard Library container `std::vector` is well suited for this purpose

`std::vector` (via header `<vector>`) is a dynamic array which is *easily resizable* at run-time (i.e., during programm execution), e.g.,:
```cpp
// data read from sensor
std::vector<float> temperatures{}; // create an empty array
std::vector<float> temperatures; // equivalent to above
```

N.B. `std::vector` is a template, therefore the type is provided (e.g., `float`) when declaring the vector via `<...>`

Once a `std::vector` object/container is created, the method `push_back()` can be used to add new elements, e.g.,:
```cpp
temperatures.push_back(newTemperatureValue);
```

### `std::vector` Guarantees Efficient Growth

When using `push_back()`, the `std::vector` instance will automatically resize itself to accomodate the newly added element, if necessary

The cost to resize is amortized in a performant way (i.e., in constant time, O(1), on average) for typical use cases

### Using `std::vector`'s Method `push_back()`

The method `push_back()` is:
  * Simple
  * Safe
  * Efficient

### **DEMO: `std::vector` in Action**

cf. `ReadingFileToVector.cpp`

### **DEMO: Using `std::vector` with User-Defined Classes**

cf. `VecCustomClasses.cpp`

N.B. `std::vector` can contain elemnts of arbitrarily complex classes (e.g., `vector<ResourceManager>`, `vector<Image>`, `vector<Matrix>`, etc.); it is even highly composable (e.g., `vector<vector<T>>`)

## Basic Operations with `std::vector`

### Create an Empty Vector

Recall that an empty `std::vector` object can be initialized as follows:
```cpp
std::vector<int> v{};
std::vector<int> v; // equivalent to previous statement
```

### Create a Vector with Some Initial Values

A `std::vector` object can also be initialized with values, e.g.,:
```cpp
std::vector<int> v{67, 79, 78, 78, 73, 69};
```

### Create a Vector Containing `count` Copies of a Given Element

A `std::vector` object can be created with `count` copies of a given element, e.g.,:
```cpp
std::vector<string> v{3, "Connie"}; // initialized with `3` copies of the string `"Connie"`
```

### `size()` Returns the Number of Elements

Use the method `size()` to determine the number of elements currently in a vector object instance, e.g.,:
```cpp
cout << "vector `v` contains " << v.size() << " elements.";
```

### `empty()` Checks if the Vector Has No Elements

Use the method `empty()` to determine if a vector object instance is empty, e.g.,:
```cpp
if (v.empty()) {
  cout << "vector is empty.";
}
```

### `clear()` Erases All Elements from the Vector

Use the method `clear()` to remove all elements from a vector object instance, e.g.,:
```cpp
v.clear();
// vector `v` is now empty
```

### `std::vector` of RAII Objects

Now, consider a `std::vector` object containing a more complex type than simple built-ins/primitives, e.g.,:
```cpp
// given a `std::vector` object `images` containing elements of type `Image`
images.clear(); // `clear()` performs `~Image()` on each element automatically

// given a `std::vector` object `sockets` containing elements of type `Socket`
sockets.clear(); // `clear()` performs `~Socket()` on each element automatically
```

Therefore, observe the power and versatility of the `std::vector` container

Similarly, when a `std::vector` object goes out of scope, it performs automatic cleanup (including its RAII-object elements, if applicable), e.g.,:
```cpp
{ // begin scope
  std::vector<Something> v;
  // some code
} // the destructor of `v` is invoked automatically, as well as that of its `Something` elements (if applicable, e.g., RAII objects)
```

### Common Method Names

The names used for `std::vector`'s methods (e.g., `size()`, `empty()`, and `clear()`) are common across many Standard Library containers, thereby making code using these containers very generic
  * While the implementations will differ between the containers, the semantic purpose of the methods is consistent across the containers

## Safely Accessing `std::vector` Elements

`std::vector` stores its elements in contiguous memory locations, which optimizes performance

To (randomly) access a single element in the array, this can be done via overloaded operator `[]` (e.g., `v[i]`, at index `i` via zero-based index)
  * However, attempting to access an out-of-bounds index in this manner will result in undefined behavior

### Element Access with `vector::at()`

Alternatively, an element of a `std::vector` object can be (randomly) accessed by index via method `at()` (e.g., `v.at(i)` at index `i`), which additionally performs bounds checking
  * If the index is out of bounds, the `std::vector` object will throw `std::out_of_range` at run-time and prevent access of the requested memory

### `vector::at()` vs. `vector::operator[]`

`vector::at()` is more secure than `vector::operator[]` due to bounds-checking, however, in some applications (e.g., computationally intensive programs performing many iterations involving large matrices and arrays) using `vector::at()` may result in perceptibly slower element access

### **DEMO: Buffer Overflow and Safe Element Access in `std::vector`

cf. `VecAccessOutOfBounds.cpp`

N.B. Debugging tools (e.g., `AddressSanitizer`, macro `_LIBCPP_DEBUG`, etc.) can be used to identify suble bugs pertaining to memory access
  * cf. Video for demonstration of using these tools for analysis of `VecAccessOutOfBounds.cpp`

## Analyzing `std::vector` Growth Policy: Size vs. Capacity

### Simplified Model for `std::vector`

It is important to have even a simplified mental model of `std::vector`; without discussing the implementation details, consider `std::vector` as a resource manager that owns a dynamic (ie., heap-allocated) array

A **key property** of the `std::vector` object instance's elements is that they occupy contiguous memory

### Adding a New Element with `push_back()`

When using `push_back()`, to guarantee the contiguous-memory property of the `std::vector` object, one approach is to perform the following steps:
  1. Allocate a new, larger contiguous memory block on the heap to store the original vector elements as well as the additional element being added
  2. Copy the elements to the new memory block
  3. Release the old memory block back to the available pool on the heap

However, repeating this process for each invocation of `push_back()` would not be performant; in practice, `std::vector` objects actually pre-allocate a larger block of contiguous memory, allowing for fast addition of new elements

### `std::vector`'s Capacity vs. Size

The pre-allocated memory of a `std::vector` object is called its **capacity**, which can be accessed via method `vector::capacity()`

Conversely, `vector::size()` returns the number of elements currently inserted/allocated in the `std::vector` object, where in general `vector::capacity() >= vector::size()`

Once `vector::capacity() == vector::size()` is reached, the next call to `vector::push_back()` will automatically perform the necessary resizing

### Smart Capacity Growth Policy

The algorithm for calculating the new capacity makes re-allocations *rare* in practice
  * Given an initial `std::vector` object instance of capacity `N`, after reallocation (upon reaching a corresponding size of `N`) the capacity is increased to `k * N` (where `k > 1`, typically `k == 2` or `k == 1.5`)
  * Thanks to this geometric growth policy, the performance of `push_back()` is an amortized constant (i.e., O(1)) run-time
    * For a `std::vector` object instance containing many elements (e.g., millions), resizing is increasingly rare

### Comparing Different Growth Algorithms

`k * N` reallocation is much more performant than `k + N` reallocation, as these result in run-time performances of O(1) and O(N^2) (respectively)
  * In the case of `N == 1000`, this amounts to an order of `1000` vs. an order of `1000000` resizings (respectively)

## Tip: Reserving Capacity to Improve `push_back()`'s Run-Time Performance

Suppose you have an estimate of the element count that will be held by a `std::vector` object instance; rather than invoking many reallocations in conjunction with `push_back()` invocations, storage/capacity can be *pre-allocated* first via method `vector::reserve(capacity)`

Using this approach can significantly improve the performance of `std::vector`, particularly if the expected element count can be estimated accurately (i.e., to prevent unnecessary excessive/unused memory allocation) for the use case at hand

## Summary

`std::vector` is a powerful, flexible array-like (i.e., sequence) container, and is a "work horse" of the C++ Standard Library

`std::vector` provides safe and automatic memory/resource management

`std::vector` stores its elements in contiguous memory, providing safe and fast integer-index access

`std::vector` provides many important and useful operations
  * N.B. The generic iterator-based design of these operations allows for generalization of these operations to other Standard Library containers

`std::vector` has a smart growth policy, with a distinct size (its elements count) vs. capacity (the amount of pre-allocated storage at a given instance)
  * This allows for efficient run-time performance of the method `push_back()`

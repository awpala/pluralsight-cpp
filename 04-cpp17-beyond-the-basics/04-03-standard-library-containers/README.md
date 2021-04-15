# Section 3 - Standard Library Containers

## Standard Containers Save

Previously, it was common practice to use C-style arrays as containers for storing elements of the same type

However, with modern C++, it is a best practice to use the **containers** provided by the Standard Library
  * You do not have to write the container
  * The Standard Library provides many useful containers
  * The Standard Library containers work verl well with the Standard Library algorithms as well
  * The Standard Library containers are aware of their size, which they manage by themselves

N.B. The Standard Library containers are class-based objects, with corresponding member variables and member functions

### You Do Not Have to Manage Memory

A container is a solid object on the stack, or a member variable; when the container destructs, so do its contents
  * It will *not* call `delete` on raw pointers, however
  * But it will do the right thing for smart pointers

### You Do Not Have to Handle Special Cases

Containers resize themselves when you add elements

Containers throw exceptions when you attempt to access past the end or before the beginning

You never give up type safety (e.g., cannot push an integer onto a vector of strings)
  * This protects you from errors of thought
  
N.B. The Standard Library containers are templates

## Expressivity

### People Who Read Your Code Know What It Does

A key benefit of the Standard Library containers is that other C++ developers recognize them and know what they do, making code that uses them more readable and expressive
  * The Standard Library is meticuluously developed for optimization and is generally bug-free, and is therefore well vetted and trustworthy

## **DEMO: `Containers (vector)`**

cf. `/Containers`

N.B. As the demo shows, there is some overhead in the `std::vector` instance's management of its size (i.e., via its own automatic resizing); this is sometimes leveled as a criticism against the `std::vector` container, however, in practice this container is very performant

## `vector`

### If You Just Want One Rule

In general, `std::vector` should be the "go-to" container

`std::vector` has many useful properties
  * It grows itself when you add new items
  * It can be traversed with an **iterator** (`it`), or randomly accessed with operator `[]`
  * It cleans up after itself (i.e., when it goes out of scope, it destroys itself and its elements if they are also objects)

### Decent Performance

While resizing/copying can in principle adversely impact performance, in practice `std::vector` has excellent performance under typical-use circumstances
  * N.B. Part of the performance optimization is due to the move semantics introduced in C++11

`std::vector` keeps its elements consecutively in memory, thereby making `it++` (iterator traversal) a simple memory addition and allowing for fast random access

For example:
```cpp
vector<Employee> newHires; // declare a vector

vector numbers{ 0, 1, 2 }; // initialize a vector -- starting with C++17, the compiler can automatically deduce the type of the vector from the initializer
numbers.push_back(-2); // add an element to the end of the vector with method push_back() (the vector will automatically resize and copy if necessary)
numbers[0] = 3; // access an element (writing) with operator `[]` (0-based indexing)
int num = numbers[2]; // access an element (reading)

for (int i : number) // ranged `for` loop
{
  cout << i << '\n';
}
```

## `array`

### Vectors That Never Grow

While `std::vector`'s ability to resize itself is a useful feature, there is a small performance cost required to accomplish this
  * Additionally, the ability to resize adds a cost as well, because this requires the elements to be kept on the free store (also called the heap) rather than locally on the stack

Conversely, it is possible that resizing is not required for a particular use case (e.g., 12 elements, representing each month); the Standard Library collection `std::array` is particularly well suited for this purpose

`std::array` does not resize and lives on the stack, which therefore may improve performance

The main advantage of `std::array`, however, is to express clearly its purpose: a collection with a fixed size at compile-time, which will not grow or shrink at run-time

## `list`

Many different data structures are required for applications; one particularly useful data structure is a linked list, which is implemented by the Standard Library container `std::list`

In a linked list, each element knows where to find the next element in the list
  * This avoids copying when new items are added to the list; instead, a "pointer" is simply changed

A key advantage of using Standard Library containers is that changing the container is fairly simple
  * Much of the code will work unchanged, or perhaps with only minor modifications necessary

### `list` Can Be Faster or Slower

`std::list` requires less copying

However, `std::list` is more expensive to traverse, since `it++` is an indirection
  * If the list is kept sorted, then finding the place to insert a new element may require many traversals via `it++`

Therefore, never assume a `std::list` will be faster than `std::vector`; measure and see to determine this with greater certainty

### **DEMO: `list`**

cf. `/ListAndVector`

## Know Your Collections

`std::vector`, `std::list`, and `std::map` are the most common dynamic collections in the Standard Library

`std::array` can also be used if the collection never grows or shrinks and its size is known at compile-time

`std::map` is kept in sorted order, and its keys must be unique     
  * `std::multimap` allows for collections (i.e., non-unique keys)
  * `std::unordered_map` and `std::unordered_multimap` have quicker add operations

Additionally the Standard Library provides `std::stack`, `std::queue`, `std::dequeue`, and `std::priority_queue`

N.B. cf. https://en.cppreference.com/w/cpp/container for a comprehensive list of Standard Library containers

## Summary

The Standard Library provides many useful collections; for typical use cases, start with `std::vector`

If you think you need a list, go ahead and use `std::vector` first; then, measure with a real load, and try swapping in `std::list` (which is generally easy to do with Standard Library containers due to their genericity) to compare *real* performance

If you think you need a `std::map`, `std::stack`, `std::queue`, etc. then you probably do, so go ahead and use them instead
  * In these scenarios, do *not* invent your own implementation of these based on `std::vector`

Write your code in a manner that promotes easy switching between containers, e.g.,:
  * Use `auto` to declare iterators
  * Use `begin()` and `end()` to access the boundary elements of the container
    * N.B. These can even be used with C-style arrays, in addition to the Standard Library collections
  * Use algorithms from the Standard Library `<algorithm>` header as much as possible, since these are designed to work with the Standard Library containers in a generic manner
  * The key point is do *not* implement code from scratch that is already available in the Standard Library!

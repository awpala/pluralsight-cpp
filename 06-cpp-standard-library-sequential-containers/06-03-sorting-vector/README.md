# Section 3 - Breaking the Ice with Useful Standard Library Algorithms: Sorting `std::vector`

## Sorting `std::vector` with `std::sort()`

### Sorting `std::vector`

To sort the elements of a `std::vector` object instance, this *could* be done with a user-defined sorting function; however this introduces some drawbacks:
  * Designing a performant sorting algorithm could be difficult and time-consuming
  * This process is bug-prone/error-prone

However, in the particular case of sorting, this is unnecessary, as the Standard Library already provides an algorithm `std::sort()` for this purpose
  * The implementation of `std::sort()` is high-quality, performant, and well-tested

### Use the Standard Library's algorithm `std::sort()`

`std::sort()` (via header `<algorithm>`) can be called with a single statement, e.g.,:
```cpp
std::sort(/* arguments */);
```

`std::sort()` can be used in several ways, however, its simplest form has two parameters:
```cpp
// `v` is a `std::vector` object
auto first = begin(v); // the beginning of `v` (first element)
auto last = end(v); // the end of `v` (one index past the last element)
sort(first, last);
```

N.B. It is idiomatic to consolidate the statements in the example above (i.e., used as simply `sort(begin(v), end(v));`)

N.B. `begin(v)` and `end(v)` are iterators (discussed next)

## What Are Iterators and Why Should You Care?

### What Are Iterators?

An **iterator** is essentially a *generalized pointer*, which points to an element inside of a container (e.g., `std::vector`)

The iterator `begin()` points to the first element in the container, while the iterator `end()` points to one index/element *past* the last element of the container

Given an iterator `it` pointing to an arbitrary element within the container, it can be advanced to the next element via `++it`

Furthermore, iterator `it` can be dereferenced via `*it` to return the value of the element at the position to which `it` points

### Iterators Abstract Away Containers

A very powerful aspect of iterators is their *generalized* nature; they essentially "abstract away" a particular container, making iterators generalized across containers

### What Is the Type of an Iterator?

The type of an iterator is typically cumbersome and "noisy" (e.g., `vector<int>::iterator`, `vector<string>::iterator`, `vector<string>::const_iterator`, etc.)
  * N.B. `const_iterator`s are available for read-only element access to containers

However, in modern C++, a more idiomatic (and better) alternative is to simply use `auto` to let the compiler deduce the type of iterators instead

### Algorithms, Iterators, and Containers

The C++ Standard Library uses the genericity of iterators to generically apply Standard Library algorithms to various Standard Library containers, using the same syntax (e.g., `it++` to advance the iterator, `*it` to dereference the iterator, etc.)
  * Algorithms use iterators to access elements inside containers

### Reusing Algorithms with Different Containers

Genericity is a key feature of the Standard Library algorithms (e.g., the algorithm `std::sort()` can be used on `std::vector`, other Standard Library containers, and even appropriately designed user-defined/custom containers via custom iterators)

Therefore, decoupling algorithms from containers provides an elegant and extensible design (e.g., reducing the need for redundant member functions duplicated across containers)

## **DEMO: `std::sort()` in Action`

cf. `Sort.cpp`

## Sorting Using Custom Comparison

`std::sort()` provides an additional form accepting a third parameter, which specifies how to perform sorting, i.e.,:
```cpp
// `v` is a `std::vector` object
sort(begin(v), end(v), /* custom comparison */);
```

There are several ways to specify the custom comparison; a particularly useful way is to use a **lambda**, which is essentially an anonymous function

For example:
```cpp
// `names` is a `std::vector<std::string>` object
sort(begin(names), end(names),
  [](auto const& a, auto const& b) { // inline lambda -- specifies comparison
    return a.length() < b.length(); // compare string by length (i.e., shorter strings first)
  }
);
```

## Summary

Sorting `std::vector` with `std::sort()`

Iterators

Algorithms, iterators, and containers

Custom sorting via lambdas

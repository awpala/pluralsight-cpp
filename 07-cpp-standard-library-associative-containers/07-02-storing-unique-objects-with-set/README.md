# Section 2 - Storing Unique Objects with `std::set`

## Introduction

This course will introduce some useful associative containers implemented in the C++ Standard Library

This course is a follow-up companion course to the previous one entitled *C++ Standard Library: Sequential Containers*, which is a prerequisite for this course
  * Must be familiar with iterators

## Introducing `std::set`

### Storing Unique Objects with `std::set`

The Standard Library container `std::set` is particularly useful for storing *unique* elements/objects

`std::set` can be thought of as a mathematical set, in which similarly each element is unique (i.e., duplicate elements are *not* allowed)

### Sample Usages

For example:
```cpp
set<string> uniqueFilenames;
set<string> airportCodes;
```

### Important Features of `std::set`

`std::set` is characterized by...
  * Unique elements
  * Elements are automatically stored in *sorted* order
  * Both element insertion and look-up are very performant, with a guaranteed O(logN) run-time for these operations

N.B. To use the corresponding features (e.g., storing unique elements and sorted insertion) of `std::set` in other more general-purpose containers (e.g., `std::vector`), this requires custom code implementation for the latter
  * Therefore, `std::set` was designed specifically with these features in mind

## Creating `std::set` and Querying Common Attributes

### Using `std::set` in Your Code

To use `std::set` containers, they are accessed via Standard Library header `<set>`

### Creating and Initializing `std::set`

To create an empty `std::set` object instance:
```cpp
// create a set of strings that is initially empty
std::set<std::string> colors:
std::set<std::string> colors{}; // equivalent to previous statement
```

To create a `std::set` object instance with initial elements:
```cpp
// the Pluralsight color palette
set<string> colors{"orange", "blue", "plum", "green", "purple"};
```

### Common Operations with `std::set`

`std::set` provides many familiar methods (cf. `std::vector`), e.g.,:
  * `std::set::size()` returns the number of elements
  * `std::set::clear()` removes the elements
  * `std::set::empty()` indicates whether the container is empty

N.B. The genericity of the Standard Library makes reusing containers and learning new ones relatively simple

## Inserting New Elements in `std::set`

To insert a new element into a `std::set` object instance, use the method `std::set::insert()`, e.g.,:
```cpp
// given `std::set` object instance `colors` containing `std::string` elements;
colors.insert("yellow");
```

`std::set::insert()` returns an object of type `std::pair<iterator, bool>`
  * `iterator` points to the inserted element upon successful insertion, or to the existing element that prevented the insertion (i.e., if attempting to insert a duplicate element)
  * `bool` is `true` if the insertion occurred, or `false` otherwise

If using a C++ compiler that supports C++17 or later, structured binding can be used to work with the return value from `std::set::insert()` idiomatically, e.g.,:
```cpp
auto [it, inserted] = colors.insert("yellow"); // N.B. `inserted` is more descriptive than `second` (via `std::pair`)

if (inserted) {
  // insertion occurred
} else {
  // there was no insertion
}
```

### Elements Are Stored in Sorted Order in `std::set`

For example:
```cpp
set<int> numbers;

numbers.insert(64);
numbers.insert(500);
numbers.insert(80);
numbers.insert(2);

// `numbers` contains 2, 64, 80, 500 (in order)
```

N.B. The elements of a `std::set` object instance are stored in sorted order regardless of the insertion order of the elements

## Iterating Through `std::set`'s Elements

### Ranged `for` Loop Syntax

For example:
```cpp
// given `std::set` object instance `numbers` containing `int`s

// Print the elements stored in the set
for (auto n : numbers) {
  cout << n << ' ';
}
```

When iterating through elements that are *not* cheap to copy (e.g., complex objects), use `const&`, e.g.,:
```cpp
// given `std::set` object instance `filenames` containing `std::string`s

// Print the filenames in the set
for (auto const& f : filenames) {
  cout << f << '\n';
}
```

`std::set` does *not* allow in-place modification of its elements, e.g.,:
```cpp
for (auto & f : filenames) { // error -- cannot pass by reference
  // ...
}
```

## Removing Elements from `std::set`

To remove elements from a `std::set` object instnace, use the method `std::set::erase()`, e.g.,:
```cpp
set<string> computers{"C64", "Amiga 500", "Amiga 2000", "ZX Spectrum"};

// remove the non-Commodore computer
computers.erase("ZX Spectrum");
```

`std::set::erase()` returns the number of removed elements (i.e., `0` if no element was removed or `1` if the element was removed)

### Erasing All Elements That Satisfy a Condition

This can be done explicitly via `for` loop, e.g.,:
```cpp
// given `std::set` object instance `s`

for (auto it = s.begin(), last = s.end(); it != last; ) {
  if (predicate(*it)) {
    it = s.erase(it); // using `std::set::erase()` overload which takes an iterator as a parameter and returns a new iterator to the subsequent element
  } else {
    ++it; // do not erase current element, but instead proceed to the next
  }
}
```

However, such an approach is cumbersome and bug-prone; instead, the equivalent logic is wrapped via Standard Library algorithm function `std::erase_if()` (which is provided in C++20 or later), having the following general syntax:
```cpp
std::erase_if(container, predicate); // requires C++20 or later
```

## Looking Up Elements in `std::set`

To search for an element in a `std::set` object instance, use the method `std::set::find()`, e.g.,:
```cpp
set<string> computer{"Amiga", "VIC-20", "C64", "ZX Spectrum"};
auto result = computers.find("C64");
```

`std::set::find()` returns an iterator to the element if found, otherwise it returns an iterator to the end, e.g.,:
```cpp
if (result != computers.end()) {
  // element found in the set `computers`
} else {
  // element not found
}
```

Furthermore, the returned iterator can be dereferenced to access the element returned (e.g., `*result`)

### `std::set::find()` Offers Great Look Up Performance

`std::set::find()` has O(logN) run-time performance with respect to N elements, which is very fast/performant for practical purposes

Conversely, invoking `std::find()` on an unsorted container results in O(N) performance, which is particularly slow for large containers

### Write Simpler Code Using `std::set::contains()`

In addition to using `std::set::find()` (which uses iterators), C++20 provides additional simplification via new (as of C++20 or later) method `std::set::contains()`, e.g.,:
```cpp
if (computers.contains("C64")) {
  // element found in the set `computers`
} else {
  // element not found
}
```

N.B. `std::set::contains()` is a simpler alterantive to `std::set::find()` if the iterator is not otherwise needed

## **DEMO: `std::set` in Action**

cf. `Set.cpp`

## **DEMO: Storing User-Defined Objects in `std::set`**

cf. `PointSet.cpp`

## Summary

`std::set` provides easy storage of unique objects

Inserting new elements with `std::set::insert()`

Removing elements with `std::set::erase()` or (with C++20 or later) `std::erase_if()`

Searching elements with `std::set::find()`

`std::set` provides great run-time performance with respect to element insertion and look up

Elements are stored in *sorted* order
  * User-defined classes must overload comparison operators (e.g., `<`) to be able to insert into `std::set` correctly (i.e., in sorted order)

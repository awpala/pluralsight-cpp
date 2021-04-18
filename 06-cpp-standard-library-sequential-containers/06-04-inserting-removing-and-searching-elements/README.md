# Section 4 - Inserting, Removing, and Searching Elements

## Inserting Elements with `std::vector::insert()`

The method `insert()` inserts `count` copies of `value` immediately before `pos`, i.e.,:
```cpp
v.insert(pos, count, value);
```

Alternatively, multiple elements can be inserted immediately before `pos` via an **initializer list**, e.g.,:
```cpp
v.insert(pos, {100, 200, 300});
```

Additionally, multiple elements can be inserted via source element range [`first`, `last`) (including `first` but excluding `last`), i.e.,:
```cpp
v.insert(pos, first, last);
```

### **DEMO: `std::vector::insert()` in Action**

cf. `VecInsert.cpp`

## Removing Elements with Erase-Remove Idiom

### Removing Elements

Elements can be removed by exact value or by a matching condition

This removal can be performed via explicit iteration code, however, such an approach is cumbersome, potentially inefficient, and bug-prone

Alternatively, the C++ Standard Library provides functions for this purpose, which are implemented safely and efficiently

### Removing Elements with `std::remove_if()`

To remove elements conditionally, use `std::remove_if()` as follows:
```cpp
std::remove_if(first, last, predicate);
```

The `predicate` is a removing condition, for which matching elements are removed
  * More preciely, this is a unary predicate, which takes as input an element from the container and returns `true` if the elements should be removed from the container or `false` otherwise
  * The `predicate` can be written either as a free function (e.g., `bool isOdd(int x);`) or as a local/inline lambda

The result of calling `std::remove_if()` is that the `true`-evaluated elements are shifted to the beginning of the container (e.g., `std::vector`), while the `false`-evaluated elements are shifted to the end (there is no net reduction in the container's size, however); additionally, an iterator is returned pointing to the position immediately following the last `true`-evaluated element (i.e., pointing to the first `false`-evaluated element)

### Erase the Remaining Elements

Therefore, using the iterator returned from `std::remove_if()`, the remaining "garbage" elements can be removed from the vector via call to `std::vector::erase()`, which removes the elements from the vector (i.e., reduces the vector's size)

This pair of complementary actions via `std::remove_if()` followed by `std::vector::erase()` is called the **erase-remove idiom**
  * This idiom applies to both `std::vector` as well as other containers from the Standard Library

### Removing Elements: `remove_if()` vs. `remove()`

While `std::remove_if()` removes elements based on a `predicate`, `std::remove()` additionally provides the ability to remove all elements that are equal to a given `value`, i.e.,:
```cpp
std::remove(first, last, value);
```

### Convenient Wrappers for Erase-Remove Idiom

Starting with C++20, the erase-remove idiom has been wrapped in a single algorithm function in the Standard Library, i.e.,:
```cpp
void std::erase(container, value);
void std::erase_if(container, predicate);
```

N.B. C++20 Standard Library algorithm `std::erase()` is distinct from the method `std::vector::erase()` described previously

### **DEMO: The Erase-Remove Idiom in Action

cf. `EraseRemove.cpp`

## Searching for Elements with `std::find()` and `std::find_if()`

As with erase-remove, rather than performing element search via iteration code (which is cumbersome and bug-prone), the Standard Library provides algorithm functions for this purpose as well

### Searching with `std::find()`

The function `std::find()` has the following general form to search for `value` in container range [`first`, `last`):
```cpp
std::find(first, last, value);
```

`std::find()` returns an iterator to the first occurrence of the element containing `value`, or `last` if no value was found

For example:
```cpp
// given `vector<string> v{ ... }`
auto result = std::find(begin(v), end(v), "Connie");

if (result != end(v)) {
  // `"Connie"` is in the vector
} else {
  // not found
}
```

### Conditional Search with `std::find_if()`

An additional variation is provided via `std::find_if()`, which allows for searching by `predicate`, i.e.,:
```cpp
std::find_if(first, last, predicate);
```

`std::find_if()` returns an iterator similarly to `std::find()`

For example:
```cpp
vector<string> v{ "Galileo", "C64", "Connie", "Amiga", "C++" };
auto it = find_if(begin(v), end(v), CaseInsensitiveCompare);
```

### **DEMO: Searching in Action**

cf. `VecSearch.cpp`

### **DEMO: Case-Insensitive String Search with `std::find_if()`

cf. `VecSearchCaseInsensitive.cpp`

## Summary

Inserting elements with `std::vector::insert()`
  * Facilitated by iterators

Removing elements via erase-remove idiom

Searching with `std::find()` and `std::find_if()`

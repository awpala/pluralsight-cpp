# Section 4 - Efficient Key-Value Associations with `std::unordered_map`

## Introducing `std::unordered_map`

### `std::map` vs. `std::unordered_map` Interface

`std::unordered_map` shares a common basic public interface with that seen previously for `std::map`

For example, the following code will work equivalently for both containers:
```cpp
map<int, string> m{}; // `std::map`
unordered_map<int, string> m{}; // `std::unordered_map`

// these statements work equivalently for both containers
m[1] = "one";

cout << " 1 is pronounced " << m[1];

auto it = m.find(3);

if (m.contains(10)) { // method `contains()` available in C++20 or later
  // ...
}
```

### Common Operations with `std::unordered_map`

Insert a new element (i.e., key-value association) via `std::unordered_map::operator[]` (e.g., `m[key] = value`)

Retrieve an existing element via `std::unordered_map::operator[]` (e.g., `value = m[key]`)

Search for an element by key via `std::unordered_map::find()` (e.g., `m.find(key)`)

Determine if a key is present via `std::unordered_map::contains()` (e.g., `m.contains(key)`)

Remove an element by key via `std::unordered_map::erase()` (e.g., `m.erase(key)`) or (for C++20 or later) via `std::erase_if()` (e.g., `erase_if(m, predicate)`)

### `std::unordered_map` vs. `std::map`

While `std::unordered_map` shares a common basic public interface with `std::map`, there are some difference, as will be discussed in shortly

## `unordered_map` vs. `map`: Element Sorting

An important difference between `std::unordered_map` and `std::map` is the way in which elements are stored
  * Recall that `std::map` *automatically* sorts its elements by keys; therefore, belongs to the category of **ordered associative containers**
  * Conversely, `std::unordered_map` does *not* automatically sort its elements; therefore, it belongs to the category of **unordered associative containers**

## `unordered_map` vs. `map` Under the Hood: Performance Differences

### `std::map` Under the Hood

`std::map` is typically implemented using a balanced binary search tree, with each tree node containing a single key-value association (i.e., essentially `std::pair<const Key, Value>`)
  * N.B. There are additional implementation-specific details, which are beyond the scope of this course

An essential outcome of this implementation is guarantted O(log(N)) run-time performance for common `std::map` operations (e.g., inserting, searching, and erasing elements)

### `std::unordered_map` Under the Hood

`std::unordered_map` is implemented using hash tables with buckets

A hash table takes an input key and converts it (via **hash function**) to an integer which is used as the index (similarly to an array index) in the hash table

With this implementation, element access performance approaches O(1) (simlarly to element access via index in an array)

However, if two keys yield the same hashed index (i.e., a **collision** occurs), then these keys/elements are stored in the same location/"bucket" within the hash table, in which case an additional linear search must be performed within the location/"bucket" to retrieve the particular key

### `std:unordered_map` Performance

Due to collisions, in practice, `std::ordered_map` provides *average* constant-time (i.e., O(1)) run-time performance for its operations (e.g., inserting, searching, and removing elements)

### The Quality of the Hash Function Is Important

An key takeaway from the aforementioned discussion is that the quality of the hash function (i.e., its ability to produce indices in a manner that minimizes collisions) is consequential to the performance of `std::unordered_map`
  * N.B. Additionally, hash functions can be maliciously crafted to purposely cause collisions to degenerate performance of the hash table

In general, designing and implementing good, robust custom hash functions is very difficult; fortunately, the C++ Standard Library provides these by default, and it is therefore a best practice to use these instead of implementing them from scratch

### `unordered_map` vs `map` Performance

| Container | Implementation | Run-Time Performance for Insertion, Search, and Removal of Elements |
| :---: | :---: | :---: |
| `std::unordered_map` | hash table with buckets | O(1) on average |
| `std::map` | balanced binary search tree | O(log(N)) |

`std::unordered_map` can be *slower* than `std::map` (e.g., if implemented with bad hash functions that yield many collisions)

### **DEMO: `unordered_map` vs. `map` Performance in Action: Counting Words**

cf. `/WordCount`

N.B. Including `using ...;` and `using namespace std;` statements in header files is considered a bad practice (due to namespace collisions introduced by multiple inclusions), however, this guideline is violated in this particular (small) program without issue

N.B. This program requires the third-party library `boost` to run

## A Brief Touch on Using Custom Classes as Keys

To use a custom class as a key to `std::map`, this simply requires an overload of the operator `<` to enable comparisons for insertion (i.e., in sorted order)

Conversely, to use a custom class as a key to `std::unordered_map`, this is much more complicated, as this requires providing a custom hash function for the class, as well as an overload of the operator `=` to determine if two keys generate the same hashed index (i.e., in case of collisions)
  * Implementing a good hash function that minimizes collisions is a complicated task

Therefore, the potential use of custom classes as keys is another important consideration when deciding between `std::map` and `std::unordered_map`

## Summary

`std::unordered_map` and `std::map` share a *common* basic interface

`std::unordered_map` offers *great performance* (on average)
  * O(1) *on average* for insertion, search, and removal of elements

`std::unordered_map` does *not* store its elements in sorted order

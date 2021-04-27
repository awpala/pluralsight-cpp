# Section 8 - Unexpectedly Userful Operations

## Remember `std::partial_sort_copy()`?

Recall that `std::partial_sort()` performs a partial sort of a container, with the first `n` elements specified being in sorted order and the remaining subsequent elements being unordered; additionally, `std::partial_sort_copy()` can be used to copy this sorted subset of elements to a new container

Perhaps a more descriptive name for this function would be `std::top_n()`

In this same vein, this section will survey several useful Standard Library algorithm functions whose names somewhat "obscure" their intended purpose, but are nevertheless useful to be aware of due to their utility in common use cases

## Swapping

While Standard Library algorithm functions typically work via iterators, the function `std::swap()` is a notable exception: instead, it works on any two references to the same type of value (which can be completely unrelated to the collections)

N.B. `std::swap()` was originally part of the header `<algorithm>`, however, it was subsequently moved to the header `<utility>` as of C++11

`std::swap()` is fast and has many specialized use cases (e.g., smart pointers, strings, and collections); therefore, it is the preferred approach over creating swapping routines from scratch (`std::swap()` is comparatively more expressive and also more performant)

Additionally, when working with iterators (e.g., reverse iterators), `std::iter_swap()` is provided to perform swapping of iterators

`std::swap_ranges()` is also available to swap several elements simultaneously

N.B. The aforementioned swapping functions can be generally used within or between collections
  * This generality covers many diverse use cases and obviates the need for from-scratch swapping routines

### **DEMO: Swapping**

cf. `Swapping.cpp`

## `std::rotate()`

### Reordering Elements by Hand

Consider the problem of moving an element at an arbitrary position within a collection to a new position within the collection

To perform this task manually, this will require some complicated logic (e.g., swapping, reordering, cleanup, etc.)

### `std::rotate()`

The (ambiguously named) Standard Library algorithm function `std::rotate()` performs the functionality described regarding repositioning of an element within a collection

`std::rotate()` accepts an arbitrary range within the collection (which need not be the entire collection), and shifts (i.e., rotates) the elements' position about this range, effectively moving the element(s) to some other position within the collection

### Rotate Part of a Collection

To address the original problem of moving a *single* element to a new position within the collection, this simply involves the invocation of `std::rotate()` with respect to that element and the appropriate range-shifted repositioning

N.B. `std::rotate()` performs shifting in-place, and is often more performant than the equivalent (and generally more complicated) from-scratch routine

### **DEMO: `std::rotate()`**

cf. `Rotate.cpp`

N.B. While many of the algorithm functions seen thus far accept arguments `(firstIterator, lastIterator, ...)`, `std::rotate()` accepts arguments as follows (where `middleIterator` is the element to be positioned at the *start* of the post-rotated range):
```cpp
std::rotate(firstIterator, middleIterator, lastIterator);` // where `lastIterator` is not inclusive, i.e., immediately outside of the "rotated range"
```

N.B. Effectively, the distance between `firstIterator` and `middleIterator` is the number of element positions "rotated up," and correspondingly the distance between `lastIterator` and `middleIterator` is the number of element positions "rotated down"

## Advantages of Algorithms

There are many notable advantages of using Standard Library algorithm functions, including:
  * quicker to write
  * quicker for everyone else to read for the rest of the code's use
  * probably faster-performing
  * better tested (e.g., against edge cases)

## `std::partition()`

`std::partion()` is yet another Standard Library algorithm function whose name is not immediately indicative of its purpose, but which solves a useful problem nevertheless

`std::partition()` allows to divide (i.e., partition) a collection based on a predicate (e.g., lambda) such that the resulting initial elements meet this predicate condition while all of the other subsequent remaining elements do not

Additionally, `std::stable_partition()` can be applied to enforce more controlled/deterministic processing (e.g., ordering) of the two partitions
  * N.B. cf. Recall `std::stable_sort()`, used to enforce a deterministic sort order

### Partition and Rotate

`std::rotate()` and `std::partition()` can be combined to perform complex reorganizations of the collection's elements (e.g., moving a disjoint/non-contiguous set of elements in the collection to a specific position in the collection)

### **DEMO: Partition and Rotate**

cf. `PartitionRotate.cpp`

## Summary

Some functions in the Standard Library header `<algorithm>` are not intuitively/descriptively named with respect to their most common use case
  * They indicate "what they do," but not necessarily "what they are for"

Think of...
  * `std::partial_sort_copy()` as "`std::top_n()`"
  * `std::rotate()` as "`std::move_within_collection()`"
  * `std::stable_partition()` as "`std::gather()`", which is particularly useful/powerful when combined with `std::rotate()`

Knowing that these functions exist makes the difference in effective C++ programming

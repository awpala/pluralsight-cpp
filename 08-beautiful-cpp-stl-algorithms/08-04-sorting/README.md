# Section 4 - Sorting

## Sorting

To sort a collection of objects, use the Standard Library algorithm function `std::sort()`

`std::sort()` has the following general form (where `it1` and `it2` are iterators):
```cpp
sort(it1, it2);
```

By default, `std::sort()` uses the overloaded operator `<` to perform comparisons (i.e., coparing adjacent elements to determine the sort order)

Additionally, a third argument `predicate` can be provided to perform sorting, i.e,.:
```cpp
sort(it1, it2, predicate);
```

N.B. Typically, it is idiomatic to use a a lambda to express `predicate`

### **DEMO: Sorting**

cf. `/Sorting`

## Stable Sort

Consider a situation in which it is necessary to first sort by a specified property (i.e., predicate), and then sort again by another property

Should "ties" on the second sort be in their original order?
  * The tie-breaking behavior is non-deterministic in the Standard Library `std::sort()` function

To programmatically define the tie-breaking behavior of the second sort, use `std::stable_sort()`, which is computationally more expensive (with respect to both run-time and memory)
  * Therefore, the more expensive operation is not performed "by default," but rather when specified by the programmer for a particular need (e.g., tie breaking)

### **DEMO: Stable Sort**

cf. `/StableSort`

## Is It Sorted?

To determine whether a collection is already sorted, it is not necessary to invoke `std::sort()` on it; rather, use the Standard Library algorithm function `std::is_sorted()`

`std::is_sorted()` has the following general form:
```cpp
std::is_sorted(it1, it2);
```

As with `std::sort()`, the default sorting behavior expected by `std::is_sorted()` is via the overloaded operator `<`

Additionally, as with `std::sort()`, sort-order comparison can be provided via additional argument `predicate`, i.e.,:
```cpp
std::is_sorted(it1, it2, predicate);
```

### **DEMO: Is It Sorted?**

cf. `/IsSorted`

## Find the Largest, or Smallest, or ...

To find the largest or smallest element in a collection, the procedure to accomplish this depends on whether or not the collection is already sorted
  * In an *unsorted* collection, it is necessary to check every element
  * In a *sorted* collection, it is not necessary to check every element; the smallest element is first, and the largest element is last

Furthermore, to search for an arbitrary value in the collection, this also depends on whether or not the colelction is sorted
  * In an *unsorted* collection, it is necessary to check every element
  * In a *sorted* collection, a **binary search** can be performed

The aforementioned operations can be summarized as follows:

| Operation | Unsorted Collection | Sorted Collection |
|:---:|:---:|:---:|
| Minimum element | `std::min_element()` | first element in collection |
| Maximum element | `std::max_element()` | last element in collection |
| Find an element | `std::find()` | `std::upper_bound()`, `std::lower_bound()` |

N.B. `std::upper_bound()` and `std::lower_bound()` expect a sorted collection, and otherwise yield undefined behavior on an unsorted collection
  * `std::upper_bound()` finds the first-occurring element having a value greater than that provided as the argument
  * `std::lower_bound()` finds the first-occurring element having a value not less than that provided as the argument
  * Both `std::upper_bound()` and `std::lower_bound()` can also accept a `predicate` as an argument

### **DEMO: Find the Largest, or Smallest, or ...**

cf. `/MinMaxFind`

## Shuffle

The opposite of sorting is **shuffling**

To perform shuffling in C++ via `std::shuffle()`, use the following:
```cpp
#include <random>

// ... create collection

// create a random device and a Mersenne Twister to use as a `generator`
random_device randomdevice;
mt19937 generator(randomdevice());

// pass the `generator` to `std::shuffle()`
std::shuffle(it1, it2, generator);
```

N.B. The Mersenne Twister is a **pseudorandom number generator** (**PRNG**), and is one of the most widely used PRNGs
  * Its name derives from the fact that its period length is chosen to be a Mersenne prime (encoded with `19937` bits)

N.B. C++17 additionally provides the Standard Library algorithm function `std::sample()` to randomly select an element from a collection without requiring to shuffle first 

### **DEMO: Shuffle**

cf. `Shuffle.cpp`

## Partial Sorting

Given a very large collection, it may not be necessary to sort it *entirely*

The Standard Library algorithm function `std::partial_sort()` is useful for this purpose (e.g., pagination, with sorting of only the currently visible elements)

`std::partial_sort()` sorts the *n* smallest elements and places them at the beginning of the collection, and the subsequent (unordered) elements are larger than these

`std::partial_sort()` has the following general sort (where `itBeginUnsorted` defines where the unsorted list begins):
```cpp
std::partial_sort(it1, itBeginUnsorted, it2);
```

The corresponding check can be performed via `std::is_sorted_until()`, which determines how far into the collection the elements are sorted

Additionally, `std::partial_sort_copy()` copies the sorted portion into another collection

N.B. There is no stable version of `std::partial_sort()` provided in C++; all of the subsequent unsorted elements occur in a non-deterministic order

### **DEMO: Partial Sorting**

cf. `PartialSorting.cpp`

## *n*th Element

The Standard Library algorithm function `std::nth_element()` performs a **partitioning**, whereby the specified "pivot" position `n` will contain the element at that position in its sorted-order position with respect to the collection, and subsequently elements *before* position `n` will be *smaller* than this element (not in sorted order) and elements *after* will be *larger* than this element (not in sorted order)

`std::nth_element()` has the following general form (where `itNthElement` is an iterator to the element in the collection to be placed in position `n`):
```cpp
std::nth_element(it1, itNthElement, it2)
```

### **DEMO: *n*th Element**

cf. `NthElement.cpp`

## What Are You Trying to Do?

As indicated at the beginning of this section, the critical question to ask when developing a program is: *What are you trying to do?*

To this end, many useful features are provided via the Standard Library algorithm functions--the more familiar these become, the more productive your C++ development will correspondingly become as well

## Summary

Sorting is trivial to perform in C++ for elements with an overloaded operator `<`

Provide a lambda predicate for complete control

When sorting multiple times (i.e., with respect to multiple attributes), consider using `std::stable_sort()` (e.g., for tie-breaking)

Use `std::is_sorted()` to determine if the collection is already sorted (i.e., without requiring to explicitly sort it first)

In a *sorted* collection, *faster* searches are possible

Shuffling ("unsorting") can also be performed via `std::shuffle()`

`std::partial_sort()` provides the ability to perform partitioning into groups without fully sorting the collection

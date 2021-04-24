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

### **DEMO: Sorting`

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








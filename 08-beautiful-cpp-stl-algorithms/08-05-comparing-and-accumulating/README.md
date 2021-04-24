# Section 5 - Comparing and Accumulating

## Comparing Collections

### Are These Collections the Same?

Consider two collections from a given type (e.g., `std::vector<Employee>`, `std::array<int>`, `std::queue<PurchaseOrder>`, etc.)

To determine whether these two collections are the same, this comparison could be done via `for` loop, however, it is much more idiomatic to call a function (e.g., `std::equal()`) for this purpose instead; this latter approach is:
  * More readable/expressive
  * More performant
  * Less error-prone (e.g., edge cases are handled)

Similarly, `std::mismatch()` can indicate where the collections diverge

These kinds of functions are the topic of this section
  * Additionally, note that these functions return a `std::pair` object instance

## `std::pair`

### Holding a Pair of Values

It is commonly necessary to group two related values in a single entity (i.e., object); the Standard Library class `std::pair` provides this particular feature

`std::pair` works with any arbitrary combination of types (i.e., as a heterogeneous pair of types)
  * `std::pair` is used in the implementation of `std::map` to hold its key-value pair

Being a Standard Library template class, `std::pair` is strongly typed (i.e., only holds the types specified during declaration of the `std::pair` object instance)

`std::pair()` provides the properties `.first` and `.second` to (generically) access its respective constituent elements

## **DEMO: Comparing**

cf. `Comparing.cpp`

## Total the Elements of a Collection

A common operation is to total/accumulate the elements of a collection (e.g., addition of all integer elements, accumulating a target property across all object elements, etc.); this feature is provided by Standard Library algorithm function `std::accumulate()`

In its simplest form, `std::accumulate()` uses the overloaded operator `+` to iteratively accumulate the elements of the collection

Additionally, `std::accumulate()` can accept a custom `predicate` (e.g., via lambda) to prescribe the accumulation

When invoking `std::accumulate()` on a collection, in general the resulting total value can be of a different than the elements of the collection

N.B. `std::accumulate()` is provided in header `<numeric>` (i.e., *not* `<algorithm>`)

### **Demo: Total the Elements of a Collection**

cf. `Total.cpp`

## A Loop in Disguise

While it may be tempting to dismiss the advice to avoid raw loops whenever possible, the Standard Library algorithm function `std::for_each()`additionally provides the equivalent behavior or a ranged `for` loop over a collection

`std::for_each()` takes a lambda as an argument, and iterates through each element of the collection exactly once
  * Additionally, the range of the collection traversed can be controlled by the iterators passed as arguments (i.e., it is not strictly necessary to iterate over the *entire* collection)

### **DEMO: `std::for_each()`**

cf. `ForEach.cpp`

## Summary

Comparing two collections is easy via `std::equal()` and `std::mismatch()`

The Standard Library class `std::pair` is very useful, in addition to performing comparisons (cf. header `<pair>`)

Adding up or combining all of the elements of a collection can be performed in one line using the Standard Library

If you are certain that you need to use a loop, consider `std::for_each()` instead of a raw `for` loop

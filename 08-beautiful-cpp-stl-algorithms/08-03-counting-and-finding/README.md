# Section 3 - Counting and Finding

## What Are You Trying to Do?

Asking this question is the first step to approaching any code-based problem solving, including when using the Standard Library

## `count()`

Consider the following loop-based code:
```cpp
// count how many entries have the target value (2)
int twos = 0;
int const target = 2;

for (size_t i = 0; i < v.size(); i++)
{
  if (v[i] == target) { twos++; }
}
```

This code can be equivalently represented via the Standard Library algorithm function `std::count()` as follows:
```cpp
int const target = 2;

// first form -- iterators via member functions
int simple = count(v.begin(), v.end(), target);

// second form -- iterators via free/non-member functions
int simple = count(begin(v), end(v), target);
```

### **DEMO: `count()`**

cf. `Count.cpp`

## Member or Non-Member `begin()` and `end()`

The iterators `begin()` and `end()` are provided in two forms:
  1. As **member functions**
  2. As **non-member functions**

| Characteristic | Member Functions | Non-Member Functions |
|:---:|:---:|:---:|
| Syntax Example | `v.begin()`, `v.end()` | `begin(v)`, `end(v)` |
| Availability | Available for all collections in the Standard Library, including `vector`, `string`, and `map` | Calls `.begin()` or `.end()` if it exists (otherwise calls as a free/non-member function); also works for C-style arrays

Both forms return the same iterators

Additionally, if the member functions are missing for a given collection, a non-member/free function can be written to provide these iterators (the equivalent extension via member functions, such as by using inheritance to a new collection class, is much more difficult to implement)

Consequently, it is ***recommended*** to use the non-member functions as the safest choice and a good habit in general

## `count_if()`

Rather than counting *all* elements (i.e., using `std::count()`), it is also possible to count according to a specific *condition*/*predicate* via `std::count_if()`

Consider the following example:
```cpp
// count how many entries are odd
int odds = 0;

for (autom elem : v)
{
  if (elem % 2 != 0) { odds++; } // predicate/condition
}
```

The equivalent code can be expressed via `std::count_if()` as follows:
```cpp
auto odds = count_if(
  begin(v), end(v),
  [](auto elem) { return elem % 2 != 0; } // predicate/condition via lambda
);
```

### **DEMO: `count_if()`**

cf. `CountIf.cpp`


## Why Count Anyway?

There are additional ways to count elements in a collection in addition to a target value of predicate/condition, e.g.,:
  * Are *all* of these elements ...?
  * Are *any* of these elements ...?
  * Are *none* of these elements ...?

While these types of tests can be performed via `std::count()` with additional logic on the resulting value, the Standard Library provides algorithms functions specifically for these types of questions via `std::all_of()`, `std::any_of()`, and `std::none_of()` (respectively)

### **DEMO: Aggregate Counts**

cf. `AggregateCounts.cpp`

## Finding

Another common operation on collections is to search for an element having either a particular value or meeting a particular condition

The function `std::find()` returns the first element found having the specified value in the specified range

Additionally, `std::find_if()` returns the first element found meeting a condition/predicate in the specified range

Both functions return an iterator, including `end()` if the element is not found
  * This is a more general approach than returning indices, and additionally allows to performed "daisy-chained" operations (i.e., using the returned iterator in a subsequent call)

### **DEMO: Finding**

cf. `Find.cpp`

## Variations on Finding

The Standard Library additionally provides variations of `std::find()` which are idiomatic for common use cases, e.g.,:
  * `std::find_if_not()` -- tests for the *opposite* of the predicate
  * `std::find_first_of()` -- finds the first-occuring of the two provided elements to be searched
  * `std;:search()` -- finds a sequence of elements (rather than a single value), returning an iterator to the first element of the found subsequence
  * `std::find_end()` -- returns an iterator to the *last* occurrence of the searched subsequence
  * `std::search_n()` -- finds consecutive instances
  * `std::adjacent_find()` -- finds any occurrences of two consecutive elements having the same value

### **DEMO: Variations on Finding**

cf. `FindVariations.cpp`

## Summary

A well-named function says far more than a comment

Standard Library algorithm functions work with any collection that provides the appropriate iterators
  * Or part of a collection

Prefer non-member function (e.g., `begin(v)`) to member function (e.g., `v.begin()`) for iterators
  * This pattern is more generalized across collections, and there is no penalty for using the former (the compiler will optimize to use the corresponding member function as necessary); however, the reverse is not true with respect to the latter

Iterators can be incremented, decremented, dereferenced, and passed to other functions

The Standard Library provides many variations on finding and counting--this means you do not need to build your own, but rather use what is already there
  * cf. https://en.cppreference.com/ for specific details when necessary

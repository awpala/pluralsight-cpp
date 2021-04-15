# Section 5 - Standard Library Algorithms

## Discoverability

When using Standard Library containers, not everything is a member function (i.e., will not always be identifiable via IDE helper/auto-completion)

However, this does not mean that a particular feature must be coded from scratch; on the contrary, it is very likely that the Standard Library already provides the feature in question

## Collections, Algorithms, and Iterators

The Standard Library has a particular approach to providing the ability to work with collections in a generic way

The Standard Library provides the following three broad categories of features:
  * **Collections** consisting of templatized data structures
  * **Algorithms** consisting of templatized functions
  * **Iterators** are pointer-like entities which connect the algorithms to the collections, allowing the algorithms to "traverse" the elements of the collections

N.B. By using this implementation of "connecting" collections to algorithms via iterators, it reduces a lot of redundancy (e.g., repeated/duplicated member functions across the collections)

## Say What You Mean

The key advantage of using algorithms from the Standard Library is the resulting readability and expressiveness (i.e., "self-explanatory" nature of the code)
  * Why make someone puzzle out your code? (e.g, all `for` loops look similar, etc.)

### Algorithms Have Names That Are Clues

The Standard Library algorithms have descriptive names that indicate their functionality
  * `std::sort` performs sorting of the collection's elements
  * `std::find` finds an element in the collection
  * `std::generate` generates elements in the collection
  * etc.

### **DEMO: Where Are They?**

cf. https://en.cppreference.com/w/cpp/algorithm for a comprehensive list and description of the Standard Library algorithms

N.B. Both headers `<algorithm>` and `<numeric>` contain Standard Library algorithms (be sure to consult references for both to find a particular feature)

N.B. Many of the Standard Library functions are templated with respect ot `It`, the iterator
  * cf. https://en.cppreference.com/w/cpp/iterator for more information regarding iterators

## Less Fuss Over Style

In addition to their inherent expressiveness, using the Standard Library algorithms functions help prevent ambiguities and conflicts with respect to programming style
  * increment statement: i++ vs ++i vs. inside the `for` statement vs. in the loop body?
  * iteration: iterators vs. random access via `[]`?
  * naming conventions for: indices, iterators, etc.
  * etc.

### **DEMO: Expressivity**

cf. `Expressivity.cpp`

### **DEMO: Errors**

cf. `Errors.cpp`

N.B. In addition to expressivity, the Standard Library algorithms are also useful for avoiding errors

## Errors

As seen in the previous demo, the Standard Library is very useful for avoiding errors

For example:
```cpp
vector <int> v;
for (int i = 0; i < 5; i++)
  v.push_back(i++); // semantic error: double incrementing


for (auto it = begin(v3); it ~!= end(v3); it++)
{
  if (*it == 3)
    v3.erase(it); // invalidates the iterator (i.e., can no longer be incremented), which can case a run-time error if using `v3` later in the code
}


// ... and plenty more!
```

Therefore, **do not** write raw loops; instead, use the corresponding Standard Library algorithm function
  * Learn to recognize these functions; their names are generally descriptive, though some may require some further investigation to identify them properly

## "Standard" Often Means "Interchangeable"

Another key benefit of using the Standard Library algorithms functions is that they are commonly interchangeable
  * The algorithms work with iterators
  * Most containers support most iterators
  * Therefore, it is typically easy to change containers without otherwise changing the other code logic

### **DEMO: Swap Container**

cf. `SwapContainer.cpp`

N.B. This code is otherwise similar to `Expressivity.cpp` (which uses `std::vector`), but only changing the container to `std::list`

## **DEMO: Things to Learn More About**

cf. `LearnMore.cpp`

N.B. This demo shows the power of the Standard Library to perform many diverse tasks

## Beauitful C++: STL Algorithms

There is an additional course which covers the Standard Library algorithms in more detail, including:
  * counting and finding
  * sorting
  * comparing and accumulating
  * generating and manipulating collections
  * using the power of iterators
  * unexpectedly useful operations
  * an explanation of conventions (e.g., parameter names, structure, etc.) used in the Standard Library

## Summary

Calling named functions from Standard Library algorithms makes your code expressive and readable; not having to write them also saves you work
  * They handle edge cases
  * They may be faster than what you would otherwise write

It is pretty easy to change the container and still use the same algorithms; the only tough part is finding and learning them

# Section 6 - Managing Linked-Lists with `std::list`

## Introducing `std::list`: Pros and Cons

### Linked List Data Structure

The Standard Library container `std::list` is typically implemented with a **linked list** data structure
  * A linked list si a linear sequnce of nodes, which in general are *not* in contiguous memory

### Doubly-Linked List

More precisely, `std::list` is typically implemented using a doubly-linked list, whose node elements are comprised of the following:
  * the data
  * pointer to the *next* node
  * pointer to the *previous* node

With this doubly-linked-list implementation, `std::list` supports iterators that can traverse the container in both directions (i.e., forward and reverse); such iterators are called **bidirectional iterators**

### `std::list`'s Features

`std::list` supports fast constant-time (i.e., O(1)) insertion and removal of elements at any arbitrary position within the container
  * cf. Inserting into an arbitrary position (e.g., in the middle) of a `std::vector` container is relatively slow, as this requires shifting all of the "donwstream" elements over to accomodate the newly added element, as well as a potential resizing

With respect to **iterator stability**, inserting/removing an element 
into/from a `std::list` container does not invalidate the other iterators of the container
  * cf. Insertion/removal of an element into/from a `std::vector` container changes the position of the other elements within the container, thereby invalidating the iterator to some or all of the other elements in the container

However, with respect to memory layout, the elements (i.e., nodes) of a `std::list` container are scattered/non-contiguous on the heap, making element access less efficient (requiring a traversal of *all previous* nodes, with worst case O(N) with respect to N nodes) and less cache-friendly
  * cf. `std::vector` stores its elements in contiguous memory, which provides fast (i.e., O(1)) element access due to this extremely efficient memory layout (which works particularly well with modern CPUs)

### `std::list` vs. `std::vector`

Unless `std::list`'s typical features are needed (e.g., iterator stability and/or constant-time insertion/deletion of elements), `std::vector` is a better "default" container to use in general
  * However, when in doubt, perform empirical measurements to be sure

## Creating `std::list`, and Creating and Removing Elements

### Creating a `std::list`

The following syntax can be used to initialized a `std::list` object instance:
```cpp
// initialize `std::list` with given values
std::list<int> l{11, 22, 33, 44, 55, 66};

// create an empty list
std::list<int> l{};
std::list<int> l; // equivalent to previous statement
```

### Common Operations with `std::list`

The previously seen methods (cf. `std::vector`) also apply to `std::list`, i.e.,:
  * `std::list::size()` returns the number of elements in the container
  * `std::list::clear()` removes the elements from the container
  * `std::list::empty()` checks if there are any elements in the container

### Inserting a New Element at the Beginning

To prepend an element to the beginning (i.e., the head) of a `std::list` object instance, use the method `std::list::push_front()` 
  * This is a fast constant-time (i.e., O(1)) operation
  * Furthermore, this operation does not invalidate any of the other iterators in the container

### Removing the First Element

To remove the first element of the a `std::list` object instance, use method `std::list::pop_front()`
  * This is a fast constant-time (i.e., O(1)) operation
  * Furthermore, this operation does not invalidate any of the other iterators in the container

### List Operations Under the Hood

The aforementioned list operations are *not* as trivial to implement under the hood as they may imply
  * Insertion requires proper node re-pointing
  * Deletion requires both node-repointing as well as corresponding removal/deletion of the removed node to avoid memory and resource leaks

### Access the First Element

To access the first element of a `std::list` instance object (i.e., to read or to modify it), use method `std::list::front()`

### Operations on the Last Element

There are analogous methods provided for managing the last (i.e., tail) element of the `std::list` object instance, i.e.,:
  * `std::list::push_back()` adds a new element
  * `std::list::pop_back()` removes the element
  * `std::list::back()` accesses the element

### Inserting an Element at Arbitrary Position

To insert element `value` before position `pos` in a `std::list` object instance (e.g., `myList`), use method `std::list::insert()`, e.g.,:
```cpp
myList.insert(pos, value);
```

N.B. This is the same public interface as for `std::vector()` (cf. `std::vector::insert()`)
  * Of course, the implementation details are different between the two

### Removing Elements from `std::list`

To remove *all* elements `value` from a `std::list` object instance, use method `std::list::remove()`, e.g.,:
```cpp
myList.remove(value);
```

To conditionally remove all elements that satisfy `condition` (a unary predicate), use method `std::list::remove_if()`, e.g.,:
```cpp
myList.remove_if(condition);
```

## Accessing Elements in `std::list`

There is no operator `[]` available to randomly access elements (i.e., nodes) in a `std::list` container

However, the following can be performed to access elements at arbitrary positions within a `std::list` object instance:
```cpp
auto it = myList.begin();
std::advance(it, steps); // advances iterator `it` by `steps` nodes -- O(N) operation with respect to N `steps`
```

## Bidirectional vs. Forward-Only Iteration, and `std::forward_list`

### `std::list` Provides Bidirectional Iterators

Given an iterator `it` to an element/node of a `std::list` container, it can be traversed in both directions, or bidirectionally (i.e,. advanced forwards via `++it` or moved backwards via `--it`)

### `std::forward_list` Is a Singly-Linked List

Additionally, the C++ Standard Library provides the container `std::forward_list`, which is implemented as a singly-linked list (i.e., does *not* contain a pointer to the previous node, only to the next node)

### `forward_list` Supports Forward-Only Iteration

`std::forward_list` is more memory efficient (each element stores less information, i.e., no previous-node pointer), however, consequently it only supports forward iteration (i.e., `++it` but *not* `--it`)

Therefore, `std::list` generally recommended for its greater flexibility, however, use `std::forward_list` if that is more appropriate for a given particular use case

### **DEMO: `std::list` in Action**

cf. `List.cpp`

## Analyzing and Fixing The `std::list` Sorting Bug

### Bug: Sorting `std::list`

There are different types/categories of iterators; `std::sort()` expects a **random access iterator** (e.g., such as those provided by `std::vector`)

Conversely, `std::list` provides bidirectional iterators (which do not overload the operator `-`), which are not general enough to be used by `std::sort()`; therefore, the following statement generates a compiler error:
```cpp
// `planets` is a `std::list` container containing `std::string` elements
sort(begin(planets), end(planets));
```

### Correctly Sorting `std::list`

To sort a `std::list` object instance, use the method `std::list::sort()`, e.g.,:
```cpp
planets.sort(); // N.B. sorts `std::string` elements lexicographically by default
```

### **DEMO: Sorting `std::list` in Action**

cf. `ListSort.cpp`

## Summary

Introduction to `std::list` container

Pros and cons of `std::list`

Important operations (insertion, removal, and element access)

Reusing Standard Library algorithm functions (e.g., `std::find()`)

Subtle sorting bug, and how to fix it

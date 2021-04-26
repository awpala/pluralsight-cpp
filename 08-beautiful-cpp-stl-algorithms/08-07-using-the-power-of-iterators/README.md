# Section 7 - Using the Power of Iterators

## Pre-Allocating

### Pre-Allocating Vectors Is No Fun

Thus far in the course, it was necessary to **pre-allocate** `std::vector` containers, e.g.,:
```cpp
vector<int> v1(10);

fill(begin(v1), end(v1), 1);
fill_n(begin(v1), 6, 2); // does not grow the vector if `v1.size() < 6`
iota(begin(v1), end(v1), 1);
```

However, this approach is limited; for example:
  * What if the size of the `std::vector` container is not known in advance?
  * What if there is no default constructor for the elements?
  * Or, if there is a default constructor, what if it is expensive to run?

## Use a Different Iterator

To use the previously learned Standard Library algorithm functions on a container (e.g., `std::vector`) which is of an improper size, use a different iterator

An **inserting iterator** inserts an element at the indicated location in the container; this is provided by the following:
  * `std::back_inserter()` inserts the element at the back/end of the container
  * `std::front_inserter()` inserts the element at the front/beginning of the container, with the original elements shifted over to accomodate the newly inserted element

N.B. The inserting iterators are supported in various combinations for the Standard Library containers (e.g., `std::vector` supports `std::back_inserter()` but not `std::front_inserter()`, whereas `std::deque` only supports `std::front_inserter()`)

N.B. The inserting iterators are provided via header `<iterator>`

### **DEMO: Different Iterators**

cf. `InsertingIterators.cpp`

## Almost Any Algorithm

### Changing Values with Iterators

A **key principle** regarding iterators is the following: *Different iterators can change the behavior of the algorithm*

For example, consider (cf. previous demos) the difference of applying `std::fill_n()` (or similarly `std::generate_n()`) to a `std::vector` container object instance `v` using iterator `std::begin()` ("overwrite" *existing* elements) vs. using iterator `std::back_inserter()` (adds *new* elements to the end)

Therefore, this relationship between algorithms, containers, and iterators is important to understand in order to use the Standard Library effectively

## Use Them with (Almost) Any Algorithm

Inserting iterators can be used with almost any Standard Library algorithm function; the key here is that the algorithm function in question *cannot* rely on receiving two iterators whose distance in the container is used to drive the algorithm function's behavior

Therefore, suitable candidates for use with inserting iterators include:
  * `std::fill_n()` (but *not* `std::fill()`)
  * `std::generate_n()` (but *not* `std::generate()` or `std::iota()`)
  * `std::transform()` with respect to the *target* container
  * `std::copy()`,`std::copy_if()`, `std::unique_copy()`, and `std::reverse_copy()` all with respect to the *target* container

### **Demo: Changing Values**

cf. `ChangingValues.cpp`

## Reverse Iterators

In addition to inserting iterators, the C++ Standard Library also provides **reverse iterators**

The reverse iterators `std::rend()` and `std::rbegin()` provide analogous features to the iterators `std::begin()` and `std::end()` (respectively), but are used for traversing the collection in the *reverse* direction
  * `std::rbegin()` points to the last element of the collection (i.e., *not* one position *past* the end)
  * `std::rend()` points to one position *before* the first element of the collection

Correspondingly, incrementing the reverse iterators via operator `++` moves iteration in the *reverse*/*backward* direction (i.e., from `std::rbegin()` toward `std::rend()`)
  * This implementation scheme allows using similar Standard Library algorithm function idioms for a reverse iteration as for a normal/forward iteration

### **DEMO: Reverse Iterators**

cf. `ReverseIterators.cpp`

## Iterator Arithmetic

While pointer arithmetic is challenging and error-prone, the corresponding iterator arithmetic is much safer

As a best practice, declare iterators using `auto` to let the compiler perform the corresponding type deduction, as typical iterator type declarations tend to be long and unwieldy (this was a large motivation for introducing `auto` in the first place!)

The operator `++` moves the iterator to the next elements in the collection (i.e., typically forwards, but otherwise backwards for a reverse iterator); the opposite behavior is observed with the corresponding operator `--`


The augmented assignment operators `+=` and `-=` can also be used with iterators, with the second operand being an integer indicating the corresponding element-position offset

Simlarly the binary operator `+` can be used to increase the iterator position by an integer-specified amount

Additionally, the corresponding binary operator `-` can be used to decrease the iterator position by an  integer-specified amount; furthermore, the binary operator `-` can also be used with another iterator of compatible type to compute the distance/offset (i.e., number of elements) between the iterators

### **DEMO: Iterator Arithmetic**

cf. `IteratorArithmetic.cpp`

## Iterators to `const` Elements

Not all Standard Library collections can hold `const` objects/elements
  * This is typically *not* allowed for a self-resizing container (e.g., `std::vector`) which must copy elements to the resized container, however, this is a possible scenario when working with fixed-size containers (e.g., `std::array`)

Iterators do *not* circumvent the `const` property of elements in a container (i.e., `const`-correctness is enforced)

Furthermore, it may be desirable to prevent changing of elements of the container by design; in this case, `std::cbegin()` can be used, which returns a `std::const_iterator`, whose pointed-to value cannot be changed
  * The corresponding iterators `std::cend()`, `std::crbegin()`, and `std::crend()` are also available for this purpose

N.B. Besides ensuring `const`-correctness, these `const` iterators are equally useful for expressing intent

### **DEMO: Iterators to `const` Elements**

cf. `ConstIterators.cpp`

## Summary

Use the Standard Library algorithm functions you already know with different iterators

Inserting iterators prevent unnecessary pre-allocation of containers

Reverse iterators expand the feature set of the existing Standard Library algorithm functions, obviating the need for redundant functions (e.g., `std::reverse_find()`)

`const` iterators enforce `const`-correctness

Iterator arithmetic is safe (unlike pointer arithmetic), and oftentimes offers convenience (always deals with number of elements in the collection, rather than byte offsets, data types, etc.)

Having many kinds of iterators yields a net reduction in the total amount of algorithms that must be provided in the Standard Library (e.g., no need for `std::find()` vs. `std::reverse_find()` vs. `std::const_find()`, etc., but rather use the provided `std::find()` with corresponding iterators)
  * Therefore, less algorithm functions to learn and remember

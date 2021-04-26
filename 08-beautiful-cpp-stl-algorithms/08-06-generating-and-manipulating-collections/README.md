# Section 6 - Generating and Manipulating Collections

## Copying

The overloaded operator `=` can be used to copy the elements from one container object instance to another

Additionally, to copy only a subset of the elements, this could be done via `for` loop or via Standard Library algorithm function `std::copy()` (better approach)

There is also a corresponding function `std::copy_if()` to perform copying via user-defined `predicate` (e.g., lambda function)

The function `std::copy_n()` can be used to copy the first `n` elements in the collection

The function `std::copy_backward()` performs copying operations in a reverse fashion, with the last copied-to operation occurring first (i.e., as opposed to the general first copied-to operation occurring first, as in the aforementioned functions)
  * This function is typically only necessary if copying within the same collection in a manner requiring this reverse-order operation, otherwise when copying across two separate collections this can be handled via appropriate arguments ordering

### **DEMO: Copying**

cf. `Copying.cpp`

N.B. In general, if dealing with copying *within* a collection (i.e., rather than from a source to a target), when "copying to the left" then it is safer to use `std::copy()`, otherwise when "copying to the right" then it is safer to use `std::copy_backward()`
  * This is generally dictated by the third parameter: if it falls within the range of the first two parameters, then use `std::copy_backward()` (otherwise, use `std::copy()`)

## Collections of Non-Copyable Types

Given a collection of non-copyable objects as its constituent elements, it is necessary to use `std::move()` to "transfer" these elements between containers (or within the same container)

`std::move()` takes the same iterator parameters as `std::copy()`, and there is also a corresponding `std::move_backward()` function provided by the Standard Library (taking the same parameters as `std::copy_backward()`)

N.B. There are *no* analogous functions `std::move_if()` or `std::move_n()` provided by the Standard Library
  * In practice, it is rare to use `std::move()` for any purpose other than to transfer *all* of the elements, so this is not particularly limiting

## Removing Elements

To remove an elment(s) from a collection at an arbitrary position, use `std::remove()`

Additionally, use `std::remove_if()` to remove elements via predicate (e.g., lambda)

After calling `std::remove()` on a container (e.g., `std::vector`), the container's size does not contract, nor does it change the values past the new end; rather, it places the post-removal elements in the contracted range, and returns an iterator to the new end

This iterator can then be used for further processing (e.g., calling `std::erase()` to remove these elements from the collection)
  * By design, the C++ Standard Library does not impose a performance cost (e.g., element removal), but rather leaves these decisions to the user's discretion

### **DEMO: Removing Elements**

cf. `/Removing`

## Creating and Filling Collections

Every Standard Library collection includes member functions to add elements to the collection, often with corresponding resizing performed automatically (e.g., `std::vector`)

Furthermore, non-empty Standard Library collections initialize elements by default (e.g., `vector<int> nums(100);` creates a collection object instance `nums` containing `100` `int`s initialized to the default value `0`; `vector<MyObject>` would similarly call the default constructor for `MyObject` elements; and so on)

Once a container object instance is created, the Standard Library algorithm functions `std::fill()` (all elements) and `std::fill_n()` (first `n` elements) can be used to assign values to the (default-initialized) elements of the container

Additionally, `std::iota()` can be used to assign values incrementally (e.g., `1`, `2`, `3`, etc.)
  * N.B. `std::iota()` is provided in the header `<numeric>`

The Standard Library algorithm functions `std::generate()` and `std::generate_n()` additionally accept a predicate (e.g., lambda) to specify how the  element's value is generated/created

### **DEMO: Creating and Filling Elements**

cf. `Generating.cpp`

## Replacing Values

To replace a specific value(s) in a collection, rather than using complex loop-based logic, the Standard Library algorithm function `std::replace()` can be used for this purpose instead

Additionally, the corresponding function `std::replace_if()` is also available, which performs replacement via predicate (e.g., lambda)

### **DEMO: Replacing Values**

cf. `Replacing.cpp`

## `std::transform()`

If it is necessary to perform a transformation to a collection (i.e., perform an action on every element in a range) and then put the result back either into the same collection or into a different collection, use the Standard Library algorithm function `std::transform()`
  * Another variation of this function also works with elements in a pair-wise manner

### **DEMO: `std::transform()`**

cf. `Transform.cpp`

## Eliminating Duplicates

Consider the issue of removing consecutively occurring duplicates from a collection

One approach would be to perform the following sequence: `std::sort()`, `std::adjacent_find()`, and `std::remove()` (and additional cleanup via `std::erase()`, if necessarY)

Alternatively, the equivalent result can be acheived via `std::sort()` followed by the Standard Library algorithm function `std::unique()`

Similarly, this can be done conditionally via predicate (e.g., lambda) using `std::sort()` followed by `std::unique_copy()`
  * This is equivalent to the sequence `std::sort()`, `std::copy_if()` or `std::transform()`, and cleanup

### **DEMO: Eliminating Duplicates**

cf. `Duplicates.cpp`

## Reversing and Swapping

To perform in-place reversal of elements in the container, use the Standard Library algorithm function `std::reverse()`
  * This approach is better and less error-prone than performing complicated pointer arithmetic

The function `std::iter_swap()` swaps the elements of its iterator arguments

The function `std::reverse_copy()` performs the same action as `std::reverse()`, but rather than performing in-place reversal (i.e., modifying the original collection) it instead copies the reversed collection into a new collection

### **DEMO: Reversing and Swapping**

cf. `ReversingAndSwapping.cpp`

## Summary

As before, you should not be writing raw loops if not necessary to do so (i.e., if there is a corresponding Standard Library algorithm function available)
  * This includes copying, removing, or generating entire collections

Replace any value with another

Transform is incredibly powerful

Removing duplicates, reversing in-place, swapping elements
  * Having named functions available to perform these actions helps to express intent
  * Edge cases (e.g., empty collections, overlapping ranges, etc.) are handled and tested already

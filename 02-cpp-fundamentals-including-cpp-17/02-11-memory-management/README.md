# Section 11 - Memory Management

## The Free Store

So far, all of the variables seen in this course have been **local variables**, which go out of scope when function execution ends
  * This included member variables of an object within the scope of the object's member functions; when execution of the member functions end, the variables go out of scope

However, it is sometimes desired for variables to have a lifetime (i.e., scope) beyond the execution of a function; C++ provides a construct called the **free store** for this purpose (i.e., longer-lived variables)

N.B. Local variables are often described as being "on the **stack**" (or, equivalently, having **stack semantics**), while longer-lived variables are described as being "on the **heap**" (an alternative name for the free store)
  * The "heap" nomenclature is a carry-over from C

To retrieve allocated memory from the free store, C++ provides the operator `new`, which returns a pointer to the object or instance and runs the constructor to initialize the object

To subsequently tear down, C++ provides the corresponding operator `delete`, which releases the free-store memory for subsequent re-use and runs the destructor to perform cleanup of the object

N.B. There is slightly different syntax for "raw arrays" using `[]`, however, modern C++ generally avoids using "raw arrays" (instead, data structures from the Standard Library are used)
  * This course (which is focused on modern C++ best practices) will not discuss "raw arrays" for this reason

### **DEMO: The Free Store**

cf. `/FreeStore`

## Manual Memory Management

**Manual memory management** describes the notion that if you receive a pointer to memory on the free store via operator `new` then you have to keep track of it throughout the lifetime of the program (i.e., the scope of the pointer)
  * At some point, you must correspondingly call `delete`

There are certain things which make manual memory management difficult, e.g.,:
  * What happens if someone copies the pointer?
  * What happens if the local variable (the pointer) goes out of scope early (i.e., prior to calling `delete`)?
  * etc.

Manual memory management is difficult, exposing a variety of potential mistakes to be made, e.g.,:
  * Delete too soon
  * Delete twice
  * Never delete
  * etc.

### Rule of Three

One of the original manual memory management strategies developed in C++ is the so-called **rule of three**, which suggests that a pointer to the free store should be managed via an object having special member functions for this purpose
  * The **destructor** deletes what may have been created with `new` (i.e., when the object goes out of scope)
  * The **copy constructor** uses `new` to initialize from the existing value, and is used when the object is copied (which in turn manages its deletion as its own independent copy)
  * The **copy assignment operator** deletes first and then uses `new` to initialize when the object is assigned (while performing the corresponding cleanup on the deleted original object)
    * N.B. This introduces certain design decisions, such as whether to perform *deep* vs. *shallow* copying of the object

### Rule of Five

The original rule of three eventually evolved to become the **rule of five**, with the addition of two features (via C++11, which introduced **move semantics**):
  * The **move constructor**
  * The **move assignment operator**

N.B. Move semantics (which prevent an object from going out of scope by instead "moving" it into another object rather than creating a new object from scratch) were introduced to address the fact that copying is expensive for large, complex resources

### Rule of Zero

With the rule of five, it may be (perhaps correctly) perceived that adding five "boilerplate" features adds a level of tedium to class design

Therefore, the corresponding **rule of zero** reflects the notion of designing your class *not* to need any of these, but rather rely primarily on stack semantics instead
  * This can be done very effectively in coordination with the Standard Library, which provides many useful objects that *do* perform the neccessary rule-of-five memory management without requiring you to implement all of these features

### **DEMO: Manual Memory Management**

cf. `/Memory`

## Easy Memory Management

Imagine a template class with just one member variable, a `T*` that you received from `new`...
  * The constructor saves the `T*` in a member variable
  * The destructor will `delete` that `T*`, which prevents a memory leak
  * Use full rule of five implementation to handle copy and move
    * Previously, copying could be *prevented* by making the copy constructor `private`; however, modern C++ allows to mark the copy constructor and copy assignment constructors as "deleted" to prevent copying
    * A **deep copy** can be implemented
    * A **shallow copy** can be implemented with **reference counting**: copy increments, destructor decrements, and `delete` at count of `0`

Operator overloading provides the key to facilitating memory management
  * With an overload of `*`, attempting to dereference a stack-based object (which is *not* a pointer itself) will simply return `T*`, making the behavior resemble that of a pointer
  * Furthermore, with an overload of `->`, if `T` is an object, its members will be accessible

C++11 introduced **smart pointers** to implement this memory management solution
  * One to prevent copying
  * Another that provides shallow copying with a reference count

## Standard Library Smart Pointers

`unique_ptr` is very low-overhead, with the one downside that it is non-copyable; instead, `std::move` must be used (e.g., moving a `unique_ptr` from a variable to a collection and vice versa)
  * When the object goes out of scope, the `unique_ptr` performs cleanup of the free store automatically

`shared_ptr` is used less commonly, however it is particularly useful in the scenario where many objects requires access to the same resource on the free store
  * It uses reference counting to manage memory (i.e, the last object will "turn off the lights on the way out")
  * As the `shared_ptr` (a stack-based object) is copied, the objects simply update the mutual reference count to keep track of it

`weak_ptr` is a companion to `shared_ptr` which allows to "peek" at a `shared_ptr` without affecting the reference count
  * N.B. `weak_ptr` must be used with caution to ensure that the resource still exists when it is used/accessed

WIth `unique_ptr` and `shared_ptr`, as long as the object remains in scope, the destructor has not been called and the object can still be accessed (this is not necessarily true for the `weak_ptr`)

### **DEMO: Standard Library Smart Pointers**

cf. `/MemoryWithSmartPointer`

N.B. Using smart pointers as class members simplifies the code drastically by enabling a rule-of-zero programming style, if it is appropriate to do so in the context/semantics of the class in question

## Summary

The free store (also historically called the heap) gives objects a lifetime longer than local scope

The free store also allows to use pointers to represent optional things (i.e., initialize with `nullptr`, and then subsequently allocate memory on the free store when it is needed in the program)

Manual memory management is difficult and rather old-fashioned by modern C++ standards

Smart pointers make life a lot simpler (i.e., avoiding the rule of three and the rule of five, but rather designing with the rule of zero)
  * `unique_ptr` is generally a suitable choice for many use cases, which requires using move semantics to perform assignment operations
  * Smart pointers obviate the need for raw pointers (and their corresponding error-prone operators `new` and `delete`) as a means to use the free store effectively

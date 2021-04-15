# Section 6 - Move Semantics

## Move Semantics

It is common in C++ for objects to have a pointer (or "pointer-like" entity) to data somewhere else; when such objects must be copied, there are two possibilities:
  1. **shallow copy** simply copies the pointer, with the new pointer pointing to the same object
  2. **deep copy** creates a new, independent object with a corresponding separate/independent pointer

When performing a deep copy, copying the data to another object takes time

However, in many cases, the original object is no longer required; so then, why bother to copy it in the first place?

### Temporaries

Consider the following example:
```cpp
string s = s1 + s2 + s3 + s4;
```

In the example above, temporaries such as `s3 + s4` have no purpose later in the application; in such a scenario, **moving** (i.e., rather than copying) is a huge speedup
  * The same line of reasoning applies to resizing a vector, for example

### Moving

Now, consider the following example:
```cpp
string s = s1 + s2;
```

In the example above, `s1` and `s2` are two separate objects on the stack each containing data on the free store (i.e., the element `char`s forming the respective strings)
  * During concatenation, an anonymous `string` object called `temp` (for purposes of illustration) is created to hold the copied contents of `s1` and `s2`
  * `temp` is then passed to the constructor of `s`, and then finally `temp` is destroyed after `s` is built, whose building in turn involves creating another object to copy the data from `temp` during construction
  * alternatively, a better approach is not to create another object during the construction of `s`, but rather have `s` point to the object pointed to by `temp` directly that was already created in order to "keep it alive" after `temp` goes out of scope

### **DEMO: Move Semantics**

cf. `/ListAndVector`

## Rvalue References

If you need to write a move constructor, a move assignment operator, and/or any other function that is being optimized for "stealing" a temporary (i.e., rather than copying it), then you need to be familiar with the appropriate function signature to accomplish this

If you write a class called `Resource`, a function can take a `Resource` parameter in many ways:
  * `Resource x` is a solid instance of `Resource`, for which copying will occur
  * `Resource * px` is a pointer to some solid instance of `Resource`
  * `Resource & rx` is a reference to some solid instance of `Resource`
  * `Resource && rrx` is an **rvalue reference** to some disappearing instance of `Resource`

### What Is an Rvalue?

Consider the following statements:
```cpp
x = 3;
x = a + b;

y = x; // valid
3 = x; // invalid
a + b = x; // invalid
```

Per the example statements above, the literal `3` and the expression `a + b` can only occur on the right-hand side of the assignment operator `=`; such values are called **rvalues**
  * Conversely, in the example above, `x` and `y` are correspondingly called **lvalues** (i.e., they can have values assigned to them via `=`)

While the name "rvalue reference" refers to the right-hand side of `=`, the actual definition is more subtle than this; however, in practice, the following help to gain a better intuition for an rvalue:
  * It is something ephemeral/temporary (as opposed to an lvalue, which is something whose address can be easily read, e.g., `x`, `a[i]`, etc.)
  * It is something that is well suited to be "stolen from" (e.g., a sequence of work that is about to go out of scope)

## Move Constructor, Move Assignment Operator

It is not your job as a developer to know when a particular value is about to go away; that is the compiler's job

But if you write a function that takes an ordinary (i.e., lvalue) reference and another that takes an rvalue reference, when your function is called with something that is about to go away, the compiler will call your overload that takes an rvalue reference

For the case of constructor and the assignment operator, these overloads are called the **move constructor** and the **move assignment operator** (respectively), and they are remeniscent of their respective counterparts
  * However, they are faster: they "steal" (i.e., move) elements from the reference they are passed, rather than making copies (e.g., make a pointer point to the same place as the reference's pointer)

Be sure to leave the passed reference (i.e., the entity which you are "stealing from") in a valid state (e.g., an empty state *is* valid, however, it should *not* be pointing to memory that is not supposed to be cleaned up yet--therefore, thoughtfulness is required in designing these functions)
  * Empty, `nullptr`, etc. are valid

Fortunately, these functions are already implemented for standard library classes (e.g., `std::string` and `std::vector`)
  * If your type is movable, `std::vector` resizing (and much more) will be much faster/optimized
  * The best way to make your types movable is to restrict their members to movable objects (e.g., `std::string`), thereby avoiding the need to write any of the special constructor functions

However, if it *is* necessary to implement these functions, they can be done as follows:
```cpp
Resource(Resource&& r); // move constructor
Resource& operator=(Resource&& r); // move assignment operator

Resource::Resource(Resource&& r)
  : name(std::move(r.name)) // `std::move()` is used on the "steal from" member (i.e., `name`)
{}

Resource::operator(Resource && r)
{
  if (this != &r) // guard against "self move" -- do not want to "lose" `name` when `this` == `&r`
  {
    name = std::move(r.name);
    r.name.clear();
  }
  return *this;
}
```

## New Rules

### The Rules You Think You Know Might Be Wrong

In modern C++, the additional interesting speedups/optimizations also make for more complicated rules

It was once taught in C++ that...
  * Pass by value is dangerous -- it comes with an associated copy, which may be very expensive; use pass by reference instead wherever possible
    * However, if a temporary is passed to the function, it might actualy be moved, not copied
  * Return by value also incurs a potential cost-to-copy penalty, with many compilers performing "return value optimization" to address this (whereby it creates a return-value object in the *calling scope* in order to avoid "throwing it away" when the function goes out of scope)
    * However, modern C++ compilers now provide **guaranteed copy elision**, which ensures that returning by value is guaranteed to be quicker than any other way -- since that local variable is about to go out of scope, the compiler will simply move it
  * `std::vector` is slow
    * However, when copying becomes moving, the heuristics change considerably -- it depends if the `std::vector` consists of copy-only objects or if it consists of movable objects
  * It is inefficient to build a string from many smaller pieces
    * However, this is not true if you perform this by moving the pieces as you go rather than copying (furthermore, using move semantics here also improves readability/expressiveness)

Therefore, in the modern C++ landscape which includes move semantics, many of the previous inefficiences introduced by copying no longer apply

## `std::move()` Is Just a Cast

`std::move()` is in fact a bit of a misnomer, as it does not actually "move" anything; rather, it is simply a *cast*

For example:
```cpp
name = std::move(r.name); // std::move() casts `r.name` from an lvalue to an rvalue reference
```

`std::move()` causes the compiler to choose overloads for move constructors or move assignment operators, rather than their respective copy counterparts; those then subsequently might move something

## Rule of ...

Recall the **rule of 3**: if you write any one of a destructor, a copy constructor, or an assignment operator, then write all three

With the addition of move semantics, this expanded to the **rule of 5**: additionally, add a move constructor and a move assignment operator to the rule of 3

With the Standard Library available (and the potential tedium of implementing these five features reflexively), consider simply using the **rule of 0**: use member variables that manage themselves (e.g., `std::vector`, `std::unique_pointer`, etc.) and consequently write nothing
  * The compiler will automatically handle the move semantics of your member variables where appropriate

## Summary

Move semantics dramatically boost performance by avoiding expensive copying
  * This may require you to write your own move constructor and move assignment operator, but it is better to simply use member variables that are movable by design (e.g., Standard Library containers, for which the compiler automatically generates these)

If you do need to move something:
  * Use `std::move()`, which casts a regular (i.e., lvalue) reference to an rvalue reference so that the correct overload is used
  * Comon use case: move a `std::unique_ptr` into and out of a collection
    * N.B. Anything that cannot be copied (e.g.,`std::unique_ptr`) generally *can* be moved

The Standard Library uses move semantics
  * All of the collections
  * `std::string`

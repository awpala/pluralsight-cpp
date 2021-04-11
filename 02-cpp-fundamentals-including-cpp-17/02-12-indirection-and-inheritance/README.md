# Section 12 - Indirection and Inheritance

## References and Inheritance

Consider a function that takes a parameter by reference (e.g., `&Person`); this "base class reference" can actually refer to an instance of the derived class
  * Such a function respects the **"is-a" relationship** (i.e., inheritance) between the base class and its derived class
  * This is vital to adhere to the principle of **Liskov substitutability**

In C++, any base class function can be called through a base reference to a derived instance
  * If the function has been marked `virtual` (correspodingly called a **virtual function**), then the *derived class* function executes; this principle is called **polymorphism** (literally "many forms")
    * N.B. Many other languages provide this behavior by default
  * Otherwise, if the function is non-virtual, then the *base class* function executes

N.B. Unlike many other languages, C++ gives you the ability to decide whether to use virtual vs. non-virtual functions according to the appropriate need

Calling a virtual function has a run-time cost because there is a memory cost due to management of the virtual table (which enables direction of the call to the appropriate function)

It is often the case that virtual functions are more desirable to use

With virtual functions, functions of the derived class cannot be called, because the compiler only knows about the base class reference
  * If you make an override in the derived class and it is a virtual function, then the derived class *will* run (however, the function must exist in the base class)

It is not permissible to go in the other direction: you cannot create a "derived class reference" that refers to a base class instance
  * Some of the derived class's member variables would be missing

## Pointers and Inheritance

The situation is exactly the same with pointers as with references: a "pointer to a base class" can actually point to a derived class instance

Any base class function can then be called via the pointer
  * For a virtual function, the derived class function executes
  * For a non-virtual function, the base class function executes

As before, C++ gives you the ability to choose (i.e., virtual function vs. non-virtual function)

Furthermore, it is not permissible to point a "pointer to a derived class" at a base class intance
  * As before, some derived class member variables would be missing, making this an undefined operation

### Smart Pointers and Inheritance

The same rules apply when using smart pointers; smart pointers behave simiarly to raw pointers, and this includes polymorphism

### **DEMO: Pointers and Inheritance**

cf. `/PointersAndInheritance`

N.B. The access modifier `protected` can be used provide access of the base class's members to its derived class(es), however, this can create a tighter coupling between the implementations of the base class and its derived class(es)
  * It is often better to maintain the base class's encapsulation in tact and simply use getters and setters to access the base class's `private` members

N.B. As a **rule of thumb**, if there is at least one `virtual` function declared in the class, make the destructor `virtual` as well
  * This ensures proper cleanup of derived class instances pointed to by base class pointers when the derived class instances go out of scope
  * Otherwise, do not necessarily include a `virtual` destructor "by default" or "out of habit," because this does incur a run-time penalty (i.e., memory overhead for the virtual table)

## Slicing

Using inheritance and polymorphism (i.e., using virtual functions) provides a great deal of benefits, particularly being able to write generic code 

However, one pitfall of using an inheritance hierarchy is **slicing**, which occurs when you copy objects around
  * Copying a derived class object into a base class object causes the extra member variables to "fall away" (i.e,. they are *sliced*)
  * It is not permissible to copy a base class object into a derived class object, because the base class does not have a way to initialize the additional member variables in the derived class 

These rules have implications when passing to a function by value: a copy is made, and slicing will occur (i.e., data will be lost)

For this reason, use references or pointers to avoid slicing when calling functions (e.g., member functions) polymrophically on an object that is passed in
  * References use the same syntax as solid objects (i.e., references are simpler to use than pointers)

### **DEMO: Slicing**

cf. `/Slicing`

N.B. This demo also shows how shared pointers work with inheritance via virtual functions

N.B. When functions take object parameters by value, if those objects are in an inheritance hierarchy, slicing may occur resulting in a disruption of the expected polymorphic behavior (i.e., base class will be used instead of the intended derived class); conversely, taking object parameters by reference will exhibit the expected polymorphic behavior with respect to the derived class
  * This is why it is very common for object parameters to functions to be taken by reference when there is an inheritance hierarchy involved, despite the added run-time cost of copying, performance, etc.--indirection opens the door to polymorphism

## Casting and Indirection

### Casting Pointers

A common occurrence in C++ with respect to polymorphism is having a base class pointer that you know is actually pointing to a derived class instance; in this situation, it is possible to **cast** the base class pointer to a derived class pointer

Casting to the derived class pointer allows to call derived class methods with it

However, caution must be exercised when casting pointers up and down the inheritance hierarchy to avoid performing unintended actions (particularly when casting to more specialized derived classes)

### C-Style Cast

In older C++, a C-style cast was performed to cast pointers via the syntax `(type)` (e.g., `Tweeter* pt = (Tweeter*)p;`)

C-style casting can be very dangerous if not performed correctly

Furthermore, C-style casting is not particularly informative (i.e., does not clearly convey the intention of the cast)

### Templated Casts

Modern C++ provides several templated casts

`static_cast<type>` performs casting at compile-time; therefore, this is a design decision made deliberately during development
  * Therefore, `static_cast` conveys the intention of the cast more clearly/explicitly
  * It is the developer's responsibility that the cast is safe

If a `static_cast` cannot be guaranteed, then `dynamic_cast<type>` can be used, which provides the following features:
  * Performs a run-time check
  * Works only when casting a pointer to a class with a virtual table (which is generated if the class contains at least one virtual function)
  * Returns `nullptr` if the cast fails
  * Is slower than `static_cast` due to the added run-time overhead/checks, but is consequently safer

C++ also provides additional templated casts:
  * `const_cast` is used for casting away `const` (not considered modern C++ style and therefore not recommended for general use)
  * `reinterpret_cast` is used to perform bit twiddling (this is an advanced technique beyond the scope of beginners)

### **DEMO: Casting and Indirection**

cf. `/Casting`

## Summary

Combining an inheritance hierarchy with indirection gives rise to polymorphism, which lets you write generic code that relies on specific implementations
  * For example, update all the accounts, ship all the orders, pay all the employees, etc. using the derived class's version of the pertinent member function(s) irrespectively of the base class pointer or reference
  * With this scheme, adding additional derived classes does not require an update to the otherwise "general" logic

Raw pointers, smart pointers, and references all support polymorphism
  * References are particularly easy to work with due to their relatively simple syntax compared to pointers

Copying solid objects from derived class to base class can cause slicing (i.e., loss of polymorphism)
  * This is why pointers and references are used to maintain polymorphic behavior and to prevent slicing

Cast templates provide safety and expressiveness when converting between base class pointers and derived class pointers
  * Do *not* use C-style casts for this purpose; instead, use `static_cast` (checked at compile-time) when possible, otherwise use `dynamic_cast` (checked at run-time)
  * If using `dynamic_cast`, test for `nullptr` to ensure a successful cast occurred



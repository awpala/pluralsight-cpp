# Section 3 - Standard Library Containers

## Standard Containers Save

Previously, it was common practice to use C-style arrays as containers for storing elements of the same type

However, with modern C++, it is a best practice to use the **containers** provided by the Standard Library
  * You do not have to write the container
  * The Standard Library provides many useful containers
  * The Standard Library containers work verl well with the Standard Library algorithms as well
  * The Standard Library containers are aware of their size, which they manage by themselves

N.B. The Standard Library containers are class-based objects, with corresponding member variables and member functions

### You Do Not Have to Manage Memory

A container is a solid object on the stack, or a member variable; when the container destructs, so do its contents
  * It will *not* call `delete` on raw pointers, however
  * But it will do the right thing for smart pointers

### You Do Not Have to Handle Special Cases

Containers resize themselves when you add elements

Containers throw exceptions when you attempt to access past the end or before the beginning

You never give up type safety (e.g., cannot push an integer onto a vector of strings)
  * This protects you from errors of thought
  
N.B. The Standard Library containers are templates

## Expressivity

### People Who Read Your Code Know What It Does

A key benefit of the Standard Library containers is that other C++ developers recognize them and know what they do, making code that uses them more readable and expressive
  * The Standard Library is meticuluously developed for optimization and is generally bug-free, and is therefore well vetted and trustworthy

## **DEMO: `Containers (vector)`**

cf. `/Containers`

N.B. As the demo shows, there is some overhead in the `std::vector` instance's management of its size (i.e., via its own automatic resizing); this is sometimes leveled as a criticism against the `std::vector` container, however, in practice this container is very performant

## `vector`

### If You Just Want One Rule









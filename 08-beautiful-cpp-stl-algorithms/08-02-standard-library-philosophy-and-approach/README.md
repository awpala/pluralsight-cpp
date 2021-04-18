# Section 2 - Standard Library Philosophy and Approach

## C++ and Libraries

The C++ Standard Library is not the largest (cf. Java and .NET, which are comparatively larger)
  * "Smaller" does not mean non-existent, however

The C++ Standard Library is under active development and is continually growing

The C++ Standard Library is indeed poewrful--do not ignore what is already there!

## Other People's Code

Learning and using the C++ Standard Library will generally yield more performant code while increasing readability/expressivity--many common problems have already been solved by features provided by the C++ Standard Library

## Discoverability

While IDE auto-completion can be helpful for discovering features, when using the C++ Standard Library, not everything is a member function

In fact, in the C++ Standard Library, there is a preference for free functions over member functions, as this reduces a lot of redundancy

## Collections, Algorithms, Iterators

The C++ Standard Library is comprised of three major categories:
  1. **collections** are class templates which store elements
  2. **algorithms** are function templates which provide free functions to perform common tasks (e.g., searching, sorting, etc.) on the collections
  3. **iterators** are pointer-like entities which allow the algorithms to perform actions on the containers (the algorithms work with iterators rather than directly with containers)

N.B. This implementation scheme using iterators as intermediaries between collections and algothms reduces the need for including redundant member functions across the containers
  * Understanding iterators is fundamental to understanding the way that the Standard Library works and to leverage it effectively

## Algorithms

The Standard Library algorithms...
  * Work on any container, irrespective of what it contains
  * Work on ranges (e.g., subsets of a container)
  * Typically work with collections via iterators
    * Iterators are analogous to pointers, however, the provide significant functionality
  * Live in their own header file, `<algorithm>`
    * It may be difficult to find these features (e.g., via IDE) if this header is not included, as the algorithms are *not* member functions of the containers

## Headers You Should Know

For the foreseeable future, being a C++ developer involves knowing which header(s) to include to obtain the required functionality

Key headers to be aware of (in decreasing order of priority) include:
  * `<algorithm>`
  * collections: `<vector>`, `<array>`, `<list>`, `<stack>`, `<map>`, `<queue>` (and more)
  * `<string>`
  * `<iterator>`
    * May need to include to gain additional functionality, as will be discussed later in the course
  * `<utility>` (provides `std::pair`) and `<tuple>`
  * `<numeric>`
  * math: `<complex>` and `<cmath>`
  * utilities: `<regex>` and `<chrono>`
    * These will not be covered in this course, but are included here for reference/exposure
  * smart pointers: `<memory>`
  * working with lambdas: `<functional>`

N.B. Additional headers will be introduced as needed in the course

## Do Not Write Raw Loops

Raw loops generally decrease the readability/comprehensibility of code, particularly if they include complex logic

It is therefore recommended to use C++ Standard Library features that abstract/wrap raw loops whenever possible; to do this, it is necessary to learn to recognize standard algorithms (the function names are descriptive for this purpose, e.g., `count()`, `count_if()`, `find()`, `find_if()`, `copy_if()`, etc.)
  * A particular advantage of using standard algorithms is that they are designed for efficiency and correctness, including robust testing against extensive edge cases

## Algorithms in This Course

This course will explore the Standard Library algorithms by general categories:
  * counting and finding
  * sorting
  * comparing and accumulating
  * generating and manipulating collections
  * using the power of iterators
  * unexpectedly useful operations

The course will wrap up with a "big picture" view of the header `<algorithm>`, and in particular exploring common conventions (e.g., naming, order of parameters, etc.) used by it
  * This facilitates with both comprehension and use/"muscle memory" of the Standard Library algorithms

## Summary

C++ has a smaller library than some languages, but "smaller" does not mean "small"

The header `<algorithm>` is packed with great code that you can use
  * You may never write a raw loop again!
  * The real effort is in learning which algorithms *exist* in this header, what they are for, and how they can replace otherwise written-from-scratch code (e.g., raw loops)

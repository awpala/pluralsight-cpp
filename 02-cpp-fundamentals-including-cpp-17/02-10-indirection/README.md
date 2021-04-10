# Section 10 - Indirection

## Pointers and References

### References

A **reference** is an alias for something else (i.e., a target type)
  * The target can only be set when the reference is declared
  * All other actions occur through the reference
  * References cannot be made to refer to something else

### Pointers

A **pointer** is also an alias for something else, however, pointers have additional capabilities that references do not
  * Pointers can point to something that already exists
  * Pointers can point to a special value indicating "nowhere"
   * Pointers can be made to point to something else

With the added features, pointers give rise to flexible syntax, e.g.,:
```cpp
int* pA = &A; // `pA` is a point to an integer `A` (via reference to `A` with operator `&`) -- N.B. this style is more common among modern C++ developers
int *pA = &A; // equivalent to above -- spaces around `*` are not significant

*pA = 5; // assign a new value to target `A` via its pointer `pA`
```

N.B. `*` is called the **dereferencing operator**, and `&` is called the **address of operator**

When working with pointers to objects, there is additional syntax available, e.g.,:
```cpp
Person Kate("Kate", "Gregory", 234);
Person* pKate = &Kate;
name = (*pKate).GetName(); // access member via `.` (N.B. parentheses are necessary due to operator precedence of `*` vs. `.`)
name = pKate->GetName(); // equiavalent to previous line via operator `->` (which is equivalent to `(*...).`)
```

N.B.`->` is called the **"points-to" operator**

### Null Pointer

It is possible for a pointer to point to "nowhere" (i.e., initialized to a non-significant value)
  * In C (and early C++), this is accomplished by assigning a pointer to the (`int`) value `0`, which is commonly aliased via the macro value `NULL`
    * This gives rise to some strange behavior in certain edge cases
  * Modern C++ provides the keyword `nullptr` for this purpose, and it is recommended as a **best practice** to use this keyword exclusively

### **DEMO: Pointers and References**

cf. `/PointersAndReferences`

N.B. Since a reference must be initialized with its declaration, if a value is not intended to be empty/null, then it is better to simply use a reference in the first place rather than a pointer (i.e., references are a valid solution to indirection, it is not always a given that pointers are necessary)
  * This has the added benefit that the syntax for references is less complicated than that of pointers

## `const`

Recall that `const` is a commitment to the compiler that you will not change the entity in question, e.g.,:
  * When declaring a local variable (e.g., `int const zero = 0;`)
  * As a function parameter (e.g., `int foo(int const i);`, `int something(Person const& p);`, etc.)
  * A a modifier on a member function to indicate it will not change the class's member variables (e.g., `int GetName() const;`)

Ensuring `const` correctness *after* a program is developed and built can be difficult--therefore, it should be done *from the beginning* instead!
  * It is easier to change away from `const` to non-`const` later when necessary than to go back and determine where `const` is more appropriate to use throughout the current state of the application
  * `const` also adds the benefit of compiler optimization

## `const`: Before or After?

Regarding style with respect to placement of `const`, this has evolved over time, e.g.,:
```cpp
// style 1 (modern) -- `const` after, or `const` on the right
int const ci = 3;
// style 2 (older) -- `const` before, or `const` on the left
const int ci = 3;
```

While these styles are equivalent from the compiler's perspective, when mixing indirection (i.e., pointers and references) with `const`, the `const` before style becomes more cumbersome to use
  * `const` before style requires reading "inside out"

Conversely, with the `const` after style, you simply look at what the `const` is after and that is what is constant
  * Accordingly, this course will use `const` after style exclusively

N.B. Regarding style, the compiler does not care--but humans do (i.e., readability counts)!

### **DEMO: `const`**

cf. `/Const`

## `const` with Indirection

Working with references is simple since they cannot re-target; therefore, marking with `const` (e.g., `int const & rI`) means the value cannot be changed (otherwise, there are no other possible variations)

Conversely, pointers are more complex, however `const` after style helps with disambiguating the different possibilities
  * The pointer can be declared `const` (e.g., `int * const cpI`), which means that the *pointer* cannot be changed to point to somewhere else (e.g., `cpI = &something;` will generate an error)
  * The pointer can point at something constant (e.g., `int const * cpI`), which means that the value of the *target* cannot be changed (e.g., `*cpI = 2;` will generate an error)
  * Furthermore, a `const` pointer to a `const` value can also be declared (e.g., `int const * const crazy`), which means that neither the *pointer* (i.e., where it points to) nor the value of the *target* can be changed

### **DEMO: `const` with Indirection**

cf. `/ConstWithIndirection`

N.B. C++ provides type safety with respect to pointers: they must point to a specific type

N.B. In C++, pointers store a reference (i.e., memory address) of its target as its own value (i.e., non-dereferenced); the type of this stored value depends on what the pointer targets (e.g., `int*` pointer stores `int**`, which is an address of an `int` value, etc.)

## Summary

Pointers and references provide another way to access memory
  * References have a simpler syntax via only `&`
  * Pointers have more complex syntax than references, since they perform additional actions

`const` keeps your programs *correct*
  * Functions that take literal values need to be aware of `const` (i.e., must be `const`-correct)
    * For example, attempting to pass a literal as a non-`const` reference will cause an error
  * `const`-correctness spreas throughout your code, and should be a design consideration *during* the development process, *not* after
  * If you take a reference for speed, you should take a `const` reference
  * Many operator overloads, constructors, and other "canonical" functions take `const` references

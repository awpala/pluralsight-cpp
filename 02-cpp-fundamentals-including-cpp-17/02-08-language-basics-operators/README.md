# Section 8 - Language Basics: Operators

## Arithmetic

C++ provides **arithmetic operators**: `+`, `-`, `*`, `/`
  * `/` is an interger division (i.e., truncation may occur if used on a floating-point number, or on integers with a fractional result)

C++ provides corresponding shortcuts (**augmented assignment operators**): `+=`, `-=`, `*=`, `/=`

C++ provides the increment `++` and decrement `--` operators, in both prefix and postfix forms (e.g., `i++`, `++i`, `i--`, `--i`)
  * Generally, these operators change the value by `1` (however, **iterators** overload these operators to traverse collections)
  * Postfix vs. prefix are equivalent for standalone statements, however, in other statements (e.g., assignments) the postfix operators perform the effect *after* (e.g., after assignment) wherease the prefix operators perform the effect *before* (e.g., before assignment)

C++ provides the modulo operator `%`, which returns the remainder after dividing

N.B. C++ does *not* provide an exponentiation operator

### **DEMO**: Arithmetic**

cf. `/Arithmetic`

## Comparisons

C++ provides the following **comparison operators**: `<` ,`>`, `<=`, `>=`

C++ provides the following equality/inequality operators: `==`, `!=`
  * N.B. `==` (equality) should ***not*** be confused with `=` (assignment)

C++ provides the following **Boolean operators**: `&&`, `||`
  * These operators are **short-circuiting**:
    * in `expr1 && expr2`, if `expr1` is `false` then the entire expression is `false` by default and `expr2` is not evaluated
    * In `expr1 || expr2`, if `expr1` is `true` then the entire expression is `true` by default and `expr2` is not evaluated

C++ provides the not operator `!`, which simply inverts the value of an expression from `true` to `false` or vice versa (e.g., `!0` evaluates to `true`)

The aforementioned operators all return `true` or `false`, including when used with arbitrarily complex expressions

### **DEMO: Comparisons**

cf. `/Comparison`

## Bitwise Operators

The previously seen Boolean operators (`&&`, `||`, `!`) operate on `true` or `false` valuse
  * If a number is used, it is first converted to a Boolean value, where `0` is `false` and any non-zero number is `true`

Conversely, the analogous **bitwise operators** (`&`, `|`, `^`) operate on a bit-by-bit (i.e. *bitwise*) basis

Bitwise operators can be used to test the individual bits of an integer value (e.g., a bit pattern containing flags)

C++ also provides the **bit-shift operators** `<<` and `>>`, which shift the bits by the specified number of positions
  * N.B. These operators are *overloaded*, as will be discussed shortly (cf. `cin >> ...` and ` cin >> ...`)

N.B. Using bitwise and bit-shift operators is a more advanced concept, and typically beginners will find the Boolean operators to be more useful for their applications

## Operator Overloading

**Operator overloading** is a central aspect of C++, which promotes generic coding (i.e., creating user-defined classes that are idiomatic/remeniscent of built-in types)

For example:
```cpp
int i = j + 3; // `+` with built-in type
Order newOrder = oldOrder + newItem; // overloaded `+` with user-defined type `Order` 
```

In C++, operator overloading is performed via the keyword `operator` in the corresponding function to define the operator
  * Typically, this is a member function of a class
  * However, occassionally this can also be a free function

### The Standard Library Has Plenty of Useful Overloads

The Standard Library's operator overloads are so useful, they are "invisible" in practice, e.g.,:
  * `+` in `std::string` objects, which concatenates strings
  * `<<` and `>>` in stream I/O
  * `++` for iterators

### When to Overload Operators

What operators can be overloaded? All of them!
  * Ultimately, this is a decision decision (e.g., which to include, how to overload idiomatically for the class in question, etc.)

## Writing an Overload

Consider writing the following operator overloads:
```cpp
MyObject < Something // case 1
Something < MyObject // case 2
```

The corresponding operator overloads can be written as follows:
```cpp
// case 1 -- use a member function
bool MyClass::operator<(OtherType something)
{
  // implementation
}

// case 2 -- use a free function
bool operator<(OtherType something, MyClass mc)
{
  // implementation -- use `public` functions of `MyClass`,
  // or declare `operator<()` with keyword `friend` to access 
  // `private` members of `MyClass` 
}
```

N.B. In case 1 of this example (and similar), this function can be designed to operator on two objects of the same type (e.g., `MyClass`) or of two different types

### **DEMO: Writing an Overload**

cf. `/Overload`

N.B. Whether or not to use `friend` functions is largely a matter of preference and style
  * If there is no need to access the class's member variables directly then it is better to simply use the class's `public` methods to access the member variables and overload the operator as a free function instead (i.e, *not* using `friend`)
  * Conversely, `friend` functions are useful when `public` functions cannot be used (e.g., to avoid breaking encapsulation by adding the corresponding necessary `public` function to the class)

## Summary

C++ has *a lot* of operators

Not all of the operators behave the way you think
  * `&&` and `||` are short-circuiting
  * `&`, `|`, and `^` are bitwise operators
  * `==` vs. `=`
  * Certain seemingly strange styles/idioms are done conventionally around this idea

It is possible to write *very* concise code -- there often can be an inherent tradeoff against readability, however

Operator overloading is a very powerful technique that sets C++ apart from other languages
  * User-defined classes can be designed to behave idiomatically/remeniscient of built-in types

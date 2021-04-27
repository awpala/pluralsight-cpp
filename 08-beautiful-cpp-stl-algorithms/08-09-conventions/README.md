# Section 9 - Conventions

## Remembering

### How Do You Remember All That?

While the Standard Library algorithm functions seem numerous and daunting to "memorize," in fact there are many conventions and patterns/consistency within it, particulary with respect to ordering of parameters

### Reduce Mental Effort

The parameters are consistent (i.e, in their ordering)

Integer parameters are rare, and are well-named when they do occur

Prefixes (e.g., `stable_...`) and suffixes (e.g., `..._n`, `..._if`, etc.) are consistent

If all else fails, good documentation exists (as well as corresponding IDE tools, e.g., auto-completion, highlighting, etc.)

## Iterator Parameters

The vast majority of Standard Library algorithm functions take two iterators as their first two arguments, representing the range [`first`, `last`) (i.e., exclusive of `last`)

Functions with suffix `_n` accept two arguments:
  * The start-position iterator
  * The number (i.e., `n`) of elements to be processed (e.g., generated, filled, etc.)

Functions which target a destination (an iterator) accept three iterators as arguments, with the third argument designating the destination/target iterator; these three iterator arguments will occur first in the arguments list, prior to any subsequent predicates or values
  * Typically, these three iterator arguments are (in the order)`startSource`, `endSource`, and `startDestination`

Occassionally, functions accept four iterators as arguments (e.g., subsequences)
  * There is still consistency here, where typically the begin-end `source` pair are listed before the begin-end `destination` pair

### Exceptions

There are some exceptions to the heuristics indicated above, e.g.,:
  * `std::rotate(firstIterator, newFirstIterator, lastIterator)`
  * `std::rotate_copy(firstIterator, newFirstIterator, lastIterator, destinationFirstIterator)`
  * `std::partial_sort(firstIterator, middleIterator, lastIterator)` (N.B. there is also an overload available with the `predicate` as the fourth parameter)
  * `std::nth_element(firstIterator, nthIterator, lastIterator)` (N.B. there is also an overload available with the `predicate` as the fourth parameter)
  * `std::inplace_merge(firstIterator, middleIterator, lastIterator)`

N.B. These five functions are the main exceptions to the (otherwise consistent) aforementioned heuristics

## Integer Parameters

In the C++ Core Guidelines, one of the guidelines is to avoid multilpe, consecutive parameters of the same type (e.g., a rectangle function taking four vertex-coordinate parameters would not provide intuitive/unambiguous use of its four arguments)

The Standard Library algorithm functions are particularly well designed in accordance with this guideline, with rare occurrence of integer parameters

Functions containing `..._n` in their names accept an integer parameter in the second position to indicate the size (i.e., number of elements)

When working with a collection of type `T` (e.g., `int`), many of the Standard Library algorithm functions take type `T` as an argument; however, there is rarely an ambiguity in practice (e.g., typically an integer parameter denoting size is the last argument in the parameters list)
  * Similarly, integer arguments for initial values (e.g., lambdas, `std::iota()`, `std::accumulate()`, etc.) are disambiguated by their position in practice

## Predicates

Many Standard Library algorithm functions accept predicates as an argument, which contributes greatly to their flexiblity and power

### Predicate Last

A typical **pattern** in the Standard Library algorithm functions is to provide overloads with and without a predicate, otherwise sharing (i.e., consistent ordering of) the same leading parameters (i.e., preceding the lambda in the with-predicate overload)
  * A representative example of such an overloaded function is `std::sort()`

N.B. A predicate need not be a lambda (i.e., a function pointer or functor is equally valid), however, in practice lambdas are a very useful and less error-prone idiom in modern C++ and are consequently the recommended best-practice approach
  * The lambda need not be written inline (i.e., can be defined as a separate, reusable function), however, this is a common idiom in modern C++

Additionally, many Standard Library algorithm functions provide an overload replacing a predicate with a value instead, which is also generally the last-occurring parameter; in this case, as before, the leading/preceding parameters are still consistent (i.e., with respect to their order in the parameters list)

The only **exception** to the predicate-last convention is as follows: both `std::replace_if()` and `std::replace_copy_if()` have the predicate/value as the third parameter, and the new value as the fourth parameter

## Modifiers in Names

One of the key advantages of using the Standard Library algorithm functions is their expressive names, which are often "self-documenting" (e.g., `std::count()`, `std::find()`, etc.)

Additionally, many of the function names include **modifiers** to provide additional description
  * ends with `_if`: add a predicate parameter, or--if original takes a value parameter--replace with predicate parameter
  * ends with `_n`: replace `first, last` with `first, size` (where `size` always refers to the number of elements)
  * starts with `is_`:
    * returns a `bool`
    * exception to this for `is_X_until`, which returns an iterator (to the element position *immediately following* the action performed by the function, which can be the one-past-the-end position)
  * starts with `stable_`: elements retain their relative order from the original-collection positions if the function otherwise has no reason to modify (e.g., swap, sort, etc.) their position

Furthermore, there is no distinct/separate function to perform "from the end" vs. "from last to first"--rather, this is handled by the corresponding iterators (e.g., forward vs reverse iterators, etc.)

## Cannot Remember

While there are consistent conventions and patterns in the Standard Library algorithm functions, you still have to memorize some of it, right?

While there is some truth to this, in practice, modern tools (e.g., IDEs) assist here as well, e.g.,:
  1. `#include <algorithm>`
  2. Try typing a name (e.g., `sort`, `find`, `count`, `copy`, etc.)
  3. Auto-complete may assist
  4. From there, follow the aforementioned heuristics for the parameters (further assisted by the IDE tooltips)

Beyond that, if still "no luck," there are resources/references readily available, e.g., https://en.cppreference.com/

## Summary

There are nearly 100 functions in `<algorithm>`--however, nobody memorizes them all in practice

The names and parameters are consistent, which effectively greatly reduces the need to "memorize" things

Use https://en.cppreference.com/ if you need to

Be sure to use the powerful Standard Library algorithm functions--people are often (unnecessarily) intimdated away from using them, but they constitute a very language useful feature for idiomatic, expressive, and performant modern C++ programming

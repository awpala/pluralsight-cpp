# Section 7 - Exceptions

## Not Every Action Succeeds

In typical applications, errors and failures happen
  * Some are predictable
  * However, some are not (e.g., memory runs out during run-time, user attempts to input a value which overflows the target data type, etc.)

Different errors can be handled in different ways

## Expected Errors

The simplest way to handle expected errors is to test for them in advance in the program itself (e.g., `if` guards)
  * Deal with them right when they are discovered
  * Provide some type of immediate feedback (e.g., prompt user for better input)

However, is a problem with this approach: sometimes the code that finds the problem cannot deal with it (e.g., error originates from the user interface but generates in the business-logic layer)

One approach to solve this is have the function return an indication of trouble (e.g., `UpdateTimesheet()` returns `true` or `false` to the caller)

### Expected Errors: What If?

What if the function already returns something? (e.g., `sqrt()` returns a number, `FindEmployee()` returns an `Employee`, etc.)

What if the function cannot return a value (e.g., constructors)?

What if the developer who calls the function forgets to check the return value?
  * It may be easier (i.e., more predictable) to design for user input validation, but what if the network connection drops during a process (a relatively rare but nonetheless disruptive event)?

## Exceptions

While checking for bad conditions is the premier way to handle errors, it is not an exhaustive error-mitigating strategy

Additionally, **exceptions** can be used to provide more robust error handling

When an exception is **thrown**, it transfers the flow of execution to an **error handler** rather than executing the statement(s) that are subsequent to the offending line of code

When using exceptions, the developer cannot "forget" to check the return value -- once an exception is thrown, it is thrown regardless of whether or not it was expected

Furthermore, when using exceptions, it is ideal to handle the error as close to where it occurs (i.e., within the call stack) as possible
  * A related concept to this is **stack unwinding** (discussed later in this section)

To use an exception in your code:
  * Wrap the code that might throw an error in a `try` block
    * The `try` block should be as small as possible to:
      1. Be able to undo actions performed immediately prior to executing the code that threw the error
      2. Reduce the amount of code subsequent to the error that will be "skipped" when the error is thrown
  * Add one or more `catch` blocks after the `try`
    * Catch the more specific exceptions *first*, and then more general ones *later*
    * Catch exceptions *by reference* to avoid slicing (thrown derived exception classes may be more specific than the base exception class)
  * C++ does *not* provide a `finally` clause (used in other languages for cleanup code) -- in C++, the corresponding cleanup code is performed by the **destructor** instead
    * Destructors run no matter how control leaves the block (i.e., either normally or via thrown/caught exception)

For example:
```cpp
try
{
  // risky stuff
}
catch (out_of_range& oor) // the caught exception `oor` is a local variable in the `catch` block
{
  // reacting code
}
catch (exception& e)
{
  // reacting code
}
```

N.B. The compiler tests the `catch` blocks in turn until a suitable exception class is encountered
  * In the example above, `out_of_range` (more specific) is placed before `exception` (more general), because they both can handle the thrown exception but the former is a more specific error handler

### **DEMO: Exceptions**

cf. `Exceptions.cpp`

## What to Throw and Catch

While in principle you simple throw an exception and then catch that exception, in practice, C++ allows you to throw and catch *anything* (e.g., `int`, `std::string`, instance of a class, etc.); this puts quite a burden on the developer
  * The documentation may be helpful here -- but that presumes it exists in the first place (and, if so, it mentions the exception)!

Despite the compiler's flexibilty with exceptions, the conventional practice is to use the class `std::exception` provided by the Standard Library
  * `std::exception` is a base class to a hierarchy of more specific exception classes
  * The Standard Library uses classes derived from `std::exception` when it is necessary to throw an exception (i.e., catch `std::exception` by reference but throw the derived classes)

It is advisable to use the Standard Library exception classes hierarchy, or otherwise derive exceptions from them if necessary

## `std::exception`

`std::exception` is in the header `<exception>`
  * N.B. It may be unnecessary to include it, however, because the Standard Library headers often include it already (e.g., `std::vector` throws `std::exception` under certain circumstances), although there is no harm in including it even in this scenario

`std::exception` has a member function `what()` which returns a string that describes the error in a human-readable/loggable format

`std::exception` has a number of derived classes, e.g.:
  * `logic_error`
  * `runtime_error`

N.B. `logic_error` and `run_time` errors are called **marker classes** because they do not add any member variables or member functions, but rather simply provide the member function `what()`
  * They are distinguished primarily by their name as a means to specify (i.e., "mark") the specific error in question, inasmuch as these different errors will typically require specific error-handling strategies

### **DEMO: Throwing an Exception**

cf. `/Throwing`

## Unwinding the Stack

When an exception is thrown, control is transferred immediately to the appropriate catch (skipping any code that would have normally been evaluated subsequently to the offending code in the caller)

Additionally, a process called **stack unwinding** occurs when an exception is thrown
  * If in a `try` block, everything local to the `try` block goes out of scope
    * Destructors execute
    * Control transfer to the `catch`
  * If not in a `try` block, everything local to the executing function goes out of scope, and control returns to where that function was called from
    * This process occurs recursively to find a caller with a `try` block

If the preceding sequence gets all the way out to `main()`, then the user receives a dialog
  * The process is more interesting if the code does end up in a `catch` block

### **DEMO: Unwinding the Stack**

cf. `/StackUnwinding`

## RAII Revisited

Stack unwinding prior to transferring control to a `catch` block is an example of what makes RAII such a powerful concept

Consider the following examples:
```cpp
/* No RAII */
try
{
  auto x = new X(Stuff);
  // risky stuff -- throws an exception
  delete x; // this statement is not reached
} // `x` goes out of scope, but still has memory allocated on the free store -- memory leak (bad)!
catch (exception& e)
{
  // react
}

/* With RAII */
try
{
  auto x = make_unique<X>(Stuff);
  // risky stuff -- throws an exception
} // `x` gets destroyed automatically here prior to transferring control to the `catch` block
catch (exception& e)
{
  // react
}
```

Therefore, without RAII, it is much more complicated to manage exception handling when working with objects -- but with RAII, the process is much more simpler and streamlined (i.e., "exception-safe")

## Exceptions Have a Cost

While useful, exceptions are not a first-resort measure (e.g., validating user input with code logic is generally a better alterantive to using exceptions for this purpose)

There is little or no cost to set up `try`/`catch` blocks if the exception is *not* thrown (i.e., application proceeds along the "happy path")

However, if an exception *is* thrown, this requires a time expenditure (much more so than a simple guarding `if`)

There is generally a tradeoff between correctness and performance
  * If correctness is of little concern, error handling can be largely excluded to the benefit of fast execution
  * Conversely, a serious error that can impact the user experience may be worth the expenditure of time to conduct appropriate error handling (e.g., via exceptions)

Exceptions are most useful with a deep calling hierarchy (e.g., `a` calls `b` calls `c` calls `d` calls `e` etc.)
  * Each caller must test a return value, preventing further calculations if something went wrong; this can take time too

Using exceptions makes neater code that runs faster when everything goes well
  * On the happy path, this generally requires less testing (e.g., extensive/exhaustive `if` guards)

Exceptions are best for *rare occurrences* (e.g., disk is full, network went down, etc.)

## `noexcept`

### You Can Mark a Function as `noexcept`

While there is an associated performance cost with setting up code that may throw an exception, the keyword `noexcept` can be used to annotate code that is not expected to throw an exception
  * While `noexcept` appears to mean "will not throw an exception," it really means "will not throw an exception worth catching*

N.B. The opposite semantics can also be achieved via `noexcept(false)` (used in template metaprogramming)

`noexcept` provides ceratin advantages:
  * expressivity
  * performance

### `noexcept` Functions That Throw?

If a function marked `noexcept` *does* throw an exception...
  * The app terminates/crashes
  * No stack unwinding occurs
  * No exceptions are caught (e.g., no opportunity to produce error logs)

This situation is practical in certain cases (e.g., attempting to allocate memory when none is available)

N.B. In general, `noexcept` is used to designate functions that reflect the appropriate semantics, rather than code that may still potentially throw an error

## Enabling Moves with `noexcept`

Most of the performance issues associated with exceptions occurring on the happy path are small (e.g., setting up a `try`/`catch`, using `noexcept`, etc.)

However, there is one key scenario where using exceptions can be expensive: if a move operation throws, the enclosing operation cannot be rolled back
  * For example, if resizing a vector, while moving elements from the smaller vector to the larger vector, if one of the move operations throws an exception, the vector code will undo what it did, however, it canont guarantee that all of the operations will be undone

Consequently, many of the operations in the Standard Library that use move semantics will only call `noexcept` functions
  * These operations generally use move constructors, move assignment operators, swap, etc. which are `noexcept`

If your move operations (or things they call) are *not* `noexcept`, you will get a *copy* instead (which is much slower); therefore, it is imperative to mark these `noexcept` whenever possible to do so in order to use these semantics

## Summary

Exceptions handle unusual (i.e., exceptional) errors
  * `try` sets up a context in which an exception might occur
  * `throw` captures information about the problem and transfers control to a location where it can be resolved
  * `catch` accepts the information from the thrown error and uses it

Between the `throw` and the `catch`, locally scoped objects are cleaned up
  * Destructors run

While the compiler allows to `throw` and `catch` any arbitrary type, the best practice is to use the `std::exception` class (or something derived from it) instead
  * Most Standard Library code throws objects derived from `std::exception`

Exceptions should be caught in order from most specific to most general; furthermore, exceptions should be caught by reference (i.e., rather than by value) to avoid slicing

Mark functions `noexcept` if they do not throw exceptions (especially if it is a move constructor, move assignment operator, or swap function, in order to ensure that move semantics are used rather than copying)

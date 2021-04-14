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






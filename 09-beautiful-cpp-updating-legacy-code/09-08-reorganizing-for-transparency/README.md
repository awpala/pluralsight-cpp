# Section 8 - Reorganizing for Transparency

## Ripping Things Apart

Source control is available when changes go awry

Tests also ensure proper functionality is maintained

However, extra caution is still required when making changes to existing code

### Extra Caution

Does the code have side effects or just a `return`?
  * Be particularly careful if globals are changed

Do you have tests for everything it can do?
  * A fully automated test suite is ideal, but manual testing is useful here as well

Do one small step at a time and keep testing with each incremental change

## Arrow Code

Consider the following example:
```cpp
bool Order::Calculate(double x, double y)
{
  if (x < limit) {
    if (y >= 0) {
      if (shipping) {
        // ...actual calculation setting some member variable
        return true;
      } else {
        error = Errors::NotShipping;
        return false;
      }
    } else {
      error = Errors::YNegative;
      return false;
    }
  } else {
    error = Errors::XTooLarge;
    return false;
  }
}
```

This function body has an "arrow-like" shape, with deeply nested `if` constructs; such so-called **arrow code** is problematic for several reasons:
  * Introduces tedious horizontal scrolling to view in its entirety
  * The "key calculations" are often difficult to identify within the code
  * Brittle (e.g., if another condition is added)
  * Obscures patterns or errors

In general, such arrow code should be refactored to a "flatter" structure, e.g.,:
```cpp
bool Order::Calculate(double x, double y)
{
  if (x >= limit) { // "flipped" condition, but otherwise equivalent to previous
    error = Errors::XTooLarge; // `error` is grouped with corresponding `if`
    return false; // placing `return` statement here eliminates unnecessary `else` clause 
  }
  if (y < 0) {
    error = Errors::YNegaive;
    return false;
  }
  if (!shipping) {
    error = Errors:NotShipping;
    return false;
  }
  // easy to add additional condition(s) later if necessary

  // ...other logic
  return true;
}
```

## Wall of Declarations

Older code can sometimes include dozens (or more) of variables declared at the top of a function
  * This is a habit left over from C
  * The variable names used are often non-descript/non-memorable; additionally, some may not even be used at all

### Is This EVer Right?

Required instead of declaring inside an `if` statement, whose scope is too small
  * In this case, declare immediately prior to the `if` statement, rather than at the top of the function

Required instead of declaring inside a `switch` statement, which does not permit declarations inside
  * In this case, declare immediately prior to the `switch` statement, rather than at the top of the function

Required in "old-style" `for` loops for correct behavior
  * This is not necessary for "new-style" `for` loops, which are generally better to write with scoped index variables
  * Furthermore, avoid raw loops wherever possible (i.e., wherever modern C++ constructs provide a better alternative)

It is generally acceptable to declare variables at the beginning of a fuction, however, it is a best practice to declare variables as close to their use in the code as possible (ideally, with simultaneous declaration and initialization)
  * The compiler can additionally detect unused variables, which are prime candidates for elimination altogether 

## When You Declare Where You Use

You may be able to make it `const`

It may show you its real name (i.e., based on its behavior in the code)

Readers do not need to remember the variable name for so long

For example:
```cpp
/* original -- less clear */
double d3; // total revenue
// ...
d3 = getGrossReceipts(/* ... */);
// ...
if (something)
  d3 *= 0.95;
// ...
if (d3 > d7) {
  // ...
}


/* refactor -- more clear */
double totalRevenue;
// ...
totalRevenue = getGrossReceipts(/* ... */);
// ...
if (something)
  totalRevenue *= 0.95;
// ...
if (totalRevenue > oldRevenue) {
  // ...
}
```

## Refactor into Smaller Functions

1. Identify a block of code that performs a distinct task (e.g., a loop, an `if`/`else`, a `switch`, a long calculation, etc.)

2. Give the new function a (descriptive) name
    * If the original code is already a member function of the class, the extracted block should likely be a `private` member of the same class
    * A descriptive name should indicate *behavior* rather than *implementation* (e.g., `setReviewDates()` rather than `loopThroughEmployeesAndUpdate()`) 

3. If possible, replace the logic with a call to the corresponding Standard Library algorithm function if such logic is already provided there

For example:
```cpp
/* original -- N.B. comments are not appropriate substitutes for descriptive names! */
// total the numbers in the vector
int i = 0;
for (auto n : v) {
  i += n;
}

/* refactor -- use Standard Library algorithm function instead */
int total = accumulate(begin(v), end(v), 0);
```

## Function Parameters

Does the function change this variable?
  * If so, then pass by reference
  * Otherwise, if not, then pass by value

N.B. Oftentimes the compiler's optimizer can pass by value very efficiently (even for seemingly "expensive-to-copy" types); if performance becomes an issue (and is attributable to pass by value, i.e., as determined from measurements), then passing by `const` reference is an appropriate alternative
  * cf. https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines.html#Rf-in

Are you returning something large?
  * Return by value anyways
  
N.B. modern C++ compilers are highly optimized (e.g., return value optimization, guaranteed copy elision, etc.); optimizers can often eliminate copy operations altogether by creating the object in the calling stack rather than in the called function stack itself
  * cf. https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines.html#Rf-out

You may need an abstraction to return multiple semantically related values (e.g., a `class`, a `struct`, a `std::tuple`, etc.), rather than using out parameters to store return values

## Add More `const`

Going even beyond `const` correctness, consider starting off marking everything `const` (e.g., function parameters, local variables, member functions, etc.)
  * This approach reduces moving parts, and lowers the barrier to readability/comprehension

For example:
```cpp
/* original */
int i;
// ...1000 lines of code
i = 0;
// `i` never changes again


/* refactor */
const i = 0;
```

### Almost `const` Variables

Some variables are "almost" `const`, e.g.,:
```cpp
/* original */
int control = 0;
if (overlimits) {
  control = limit;
}
// issue: `control` should be `const` from here on


/* solution 1: use a ternary operator */
int const control = overlimits ? limit : 0;

/* solution 2: call a function */
int const control = initcontrol(overlimits, limit);

/* solution 3: "immediately invoked" initializing lambda expression (IIILE) */
int const control = 
  [=]() { if (overlimits) { return limit; } return 0; }
();
```

N.B. The IIILE idiom is particularly effective with relatively short lambdas with clear logic (otherwise, extracting the logic to a function may be a better approach)

## Tidy Up

Remove commented out code

Remove `#ifdef`ed out code

Remove unused variables, uncalled functions, and unused types

N.B. You have source control and tests as a precautionary measure, so making these types of removal should be done without much heasitation

## Error Codes

A common design/architectural idiom is to use `bool` return values from functions (e.g., to signal success vs. failure)
  * This can hide the true purpose of a function

Some common solutions to this issue include:
  * Storing the value in a member variable of an object passed in as an argument
  * Using output parameters to store these values

However, these solutions are not ideal; consider:
  * Do you really need these values? (e.g., always returning `true` is redundant)
  * Could exceptions work better? (e.g., when error states are not regular/predictable)
  * Could a wrapper type for the return value work better?

### Where `NULL` Means Fail

A common idiom is to return a pointer from a function, with a `NULL` return value indicating a "failure" state (e.g., not found); however, this approach typically involves memory management (e.g., ensuring to delete appropriately if a heap-allocated resource is returned from the function)

For this use case, the Standard Library provides `std::optional` via header `<optional>`, which is a stack object that has value semantics, e.g.,:
```cpp
auto opt = returnOpt();

if (opt) {
  // `*opt` can be accessed here
} else {
  // `opt` is null
}
```

N.B. `std::optional` provides the useful member functions `std::optional.value()` and `std::optional.value_or()` to work with the contained value
  * cf. https://en.cppreference.com/w/cpp/utility/optional

### When Return Type Varies

Consider a function that calculates a `double` but might fail and has a reason; a common approach for this situation involves the following:
  * Return a `bool`
  * Out parameter for the `double` (i.e., `double&`)
  * Another out parameter for an error code or a string (e.g., failure reason)

However, as a more modern idiom, consider returning these values as a `std::tuple` instead
  * These values can be subsequently used via `std::tie` or (in C++17 or later) via structured bindings

N.B. The class template `std::expected` is a pattern/feature that is currently underdevelopment to provide this kind of error handling
  * cf. https://isocpp.org/blog/2018/01/introduction-to-proposed-stdexpected

## Summary

Reorganize "arrow code" with early returns

Move declarations closer to where things are used

As you understand things, name them
  * Variables
  * Functions you extract as you go

Use `const` to help you explain the code to yourself

Get rid of unused code

Consider replacing error codes with exceptions or by returning compound values

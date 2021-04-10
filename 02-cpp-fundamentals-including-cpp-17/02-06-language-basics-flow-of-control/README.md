# Section 6 - Language Basics: Flow of Control

## Flow of Control

Typically, an application executes in order from one line to the next

### Standard Constructs in Almost Every Language

Most languages (including C++) provide mechanisms to alter the regular "top-to-bottom" flow of control in a program

C++ provides the following **constructs** to control the flow:
  * `if`
  * `while`
  * calling a function
  * `return` from a function

N.B. The next section will cover functions

### Different in C++

Additionally, C++ provides the following (which are not present in some languages):
  * `for`
  * `break` (used in all loops)
  * `continue`
  * `switch`
  * immediate `if`
  * `goto`

N.B. `goto` will not be covered in this course, and is rarely used in practice

## `if`

The `if` statement allows to conditionally evaluate an expression, and has the following general syntax:
```cpp
if (condition) actionExpression;

// equivalent to above
if (condition)
  actionExpression;
```

N.B. `(...)` is required to identify the `condition`, where `condition` is either a bool or an expression that evaluates to a bool

Additionally, `{...}` can be used to group multiple statements in the action:
```cpp
if (condition)
{
  // statements
}
```

N.B. Using `{...}` *always* (i.e., including when there is only one statement to execute) is considered a **best practice**

The `else` clause can also be added to provide multi-way selection:
```cpp
if (condition)
{
  // these statements execute if condition == true
}
else
{
  // these statements execute if condition == false
}
```

`else` is optional, and each `else` pairs with its most immediately preceding `if`

### **DEMO: `if`**

cf. `If.cpp`

## `while`

The `while` loop provides the ability to perform repeated actions, and has the following general syntax:
```cpp
while (condition) actionExpression;

// equivalent to above
while (condition)
  actionExpression;
```

N.B. `while` checks the `condition` *before* the first iteration of execution, therefore the `actionExpression` may never evaluate (i.e., if `condition` is initiallly `false`)

Regarding `(...)` and `{...}`, the same general rules apply for `while` as for `if` seen previously

A `while` loop can be exited prematurely via keyword `break`

### **DEMO: `while`**

cf. `While.cpp`

## `for`

The `for` loop construct is similar to the `while` (i.e., performing actions repeatedly), however, it has a different general syntax:
```cpp
for (initializerExpr; conditionExpr; loopChangeExpr)
{
  // action statements
}
```

For example:
```cpp
for (int i = 0; i < 10; i++)
{
  cout << i << endl;
}
```

As with `while`, `break` can be used to exit a `for` loop construct prematurely

Furthermore, `continue` can be used to skip to the subsequent loop iteration 

N.B. The ranged `for` loop will be discussed later in the context of C++ collections

### **DEMO: `if`**

cf. `If.cpp`

N.B. This program is equivalent to that in `While.cpp`; indeed, oftentimes these two loop constructs can express equivalent logic

## `switch`

The `switch` statement is a useful alternative construct to `if`-`else` when there are many related conditions to evaluate, and generally reduces otherwise excessive nesting

`switch` requires that the condition must be either an integral type (e.g., `int`, `unsigned short`, `char`, etc.) or an enumeration (which is essentially an integer)

`switch` has the following general syntax:
```cpp
switch(conditionExpr)
{
  case value1:
    // action
    break;
  // additional case(s)
  default:
    // action
}
```

If a `break` is omitted from a particular `case`, that case "falls through" to the next `case`

Scope in `switch` statements is peculiar; consider the following example:
```cpp
int x = someFunction(stuff);
switch(x)
{
  case value1:
    // action
    break;
  default:
    // action
} // `x` (an int) is still in scope here

Thing t = someFunction(stuff);
switch(t.getStatus())
{
  case value1:
    // action
    break;
  default:
    // action
} // `t` (an object) is still in scope here -- no destruction/cleanup is performed here
```

However, as of C++17, it is possible to scope an object exclusively to the `switch`, for example:
```cpp
switch(Thing t = someFunction(stuff); t.getStatus()) // `t` is declared and initialized inside of (...), thereby being scoped to `switch`
{
  case value1:
    // action
    break;
  default:
    // action
} // `t` goes out of scope here
```

### **DEMO: `switch`**

cf. `Switch.cpp`

## Ternary Operator

The **ternary operator** `?:` (sometimes called the **immediate `if`**) can be used to consolidate an `if`-`else` construct if their respective statements assign to the same variable

The ternary operator has the following general syntax:
```cpp
condition ? isTrueExpr : isFalseExpr
```

For example:
```cpp
if (something)
  result = 7;
else
  result = 302;

// equilvalent to above
result = something ? 7 : 302;
```

N.B. `?:` supports arbitrarily complex expressions (provided they evaluate to the appropriate compatible type), however, expressions including **side effects** should be avoided in general

### **DEMO: Ternary Operator**

cf. `Ternary.cpp`

## Summary

C++ has the usual flow-of-control constructs, plus some that may not be available in other languages

Use these constructs according to the appropriate idiom
  * `for` vs. `while`
    * if the numbers of iterations are known in advance, use `for`
    * otherwise, use `while` (e.g., read user input until a certain condition is met)
  * `switch` vs. series of `if`s
    * as a rule of thumb, with 3 or more related conditions use a `switch`
  * ternary operator
    * if all three parts are short enough to fit on a single line, use `?:`
    * otherwise, use `if`-`else`

N.B. The compiler has a sophisticated "understanding" of the code, therefore, the choide of construct is ultimately a matter of readability and comprehension by the programmer

# Section 4 - Flow of Control

## Flow of Control

"*Flow of control*" refers to the way in which code executes
  * Normally, code is executed from top to bottom (as has been demonstrated thus far)
  * A number of keywords can change this top-to-bottom flow, however:
    * branching: `if`, `else`
    * repetition: `while`, `for`

These keywords work with **logical expressions** (e.g., `(x > 0)`, `(y-2 < b)`, etc.), which evaluate to `true` or `false`

**Comparison operators** compare two operands and return either `true` or `false`: `>`, `>=`, `<`, `<=`, `==`, `!=`
  * N.B. `==` (equality comparison) is *distinct* from `=` (assignment), and should not be confused (but often are among novices)!

## `if`

In an `if` construct, the condition must always have `(...)`, e.g.,:
```cpp
if (i<j)
{
  // statements -- only run if i<j is true
}
```

N.B. `{...}` is optional if there is only one statement inside the `if` construct (e.g., `if (i<j) ...;` is valid if `...` respresents a single statement), but they are recommended regardless to promote readability

An `else` clause can also be added to a preceding `if` clause, e.g.,:
```cpp
if (i<j)
{
  // statements -- only run if i<j is true
}
else
{
  // statements -- only run if i<j is false
}
```

N.B. An `else` clause cannot be standalone, it must have an associated `if` clause (the `else` clause associates to its immediately preceding `if`)

## `while`

The `while` loop construct executes its statement(s) while the test condition is `true`, e.g.,:
```cpp
while(keepgoing)
{
  // statements -- execute while `keepgoing` is true
}
```

N.B. As with `if`, `{...}` is optional for a `while` loop containing a single-line statement (i.e., `while(keepgoing) ...;`), however, including it *always* is a best practice

In a `while` loop, the loop body must change something about the test condition (otherwise, the loop will run indefinitely, i.e., an **infinite loop** results), e.g.,:
```cpp
while(keepgoing)
{
  // ...
  if (answer == 0)
  {
    keepgoing = false; // terminates the while loop
  }
}
```

## `for`

The traditional `for` loop construct has three distinct parts:
  1. initializer
      * Typically either declares and initializes a variable, or assigns a value to a previously declared variable
  2. continue condition
      * Similar to the test condition in a `while` loop, i.e., the loop continues to execute while this condition is true
  3. incrementer
      * Changes the loop variable value in each iteration of the loop

For example:
```cpp
for (int loop = 0; loop < 10; loop++)
{
  // statements -- execute while loop < 10 is true
}
```

N.B. The **increment operator** `++` is equivalent to `+= 1`

In a `for` loop, the body of the loop does not have to change anything about the condition if the incrementer does

N.B. As with `if` and `while`, `{...}` is not necessary in a `for` loop construct if there is only a single statement, but it is still recommended to include it as a best practice

## **DEMO: Flow of Control**

cf. `Flow.cpp`

## Exercise

Write a "guess my number" game
  * For simplicity, hard-code the answer in your code (e.g., `int answer = 7;`)
    * You can change the number, and then build and run again
  * Ask the user to enter a guess
  * Let them know if they guessed too high, too low, or got it
  * Keep going until they get it
  * Do not perform error checking (this will be discussed later in the course)
    * When you test it, use reasonable inputs

cf. solution `GuessTheNumber.cpp`

## More Flow of Control

### Other Keywords Exist

The keywords described below are included here for the sake of completeness, but will be encountered later in the lesson and/or in subsequent practice; the aforementioned `if`, `else`, `for`, and `while` are adequately sufficient for present purposes

`switch` statements can be used to perform multi-way testing similarly to sequential `if`-`else` statements

range-based `for` loops can be used to iterate over collections (discussed later)

`break` can be used to exit a loop prematurely

`continue` can be used to proceed to the next loop iteration

`do`-`while` loops are similar to `while` loops, but always perform at least one initial loop iteration before testing the condition

`goto` statements are used to jump to a labeled code section
  * `goto` is rarely used in practice and is highly error-prone and can otherwise obscure the code's flow of control

N.B. `return` statements are also a form of flow of control; these will be examined in more detail in the next section

## Summary

The keywords `if`, `else`, `while`, and `for` control the lines that execute in your program

Logical conditions are how an application makes decisions

These fundamental building blocks can build a real application

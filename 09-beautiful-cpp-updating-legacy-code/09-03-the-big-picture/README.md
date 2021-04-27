# Section 3 - The Big Picture

## What *Not* to Do First

Global search-and-replace or rename

Mechanical "let's replace all the macros with..."

Massive re-architecting of the entire system in one pass

Run a tool that...
  * Tells you what to change
  * Makes the changes for you

### Why Not?

There is a chance that even small changes can break otherwise working code

Furthermore, these types of changes take time to implement, especially if they are extensive; therefore, these costs should not be incurred unless there is a benefit to do so

So, where is the benefit?
  * Maybe nobody ever reads or changes that particular code
  * Maybe that code was already perfectly understandable
  * Maybe that code should actually be deleted altogether

## What Parts Need Attention?

Rather than making extensive changes across the codebase, start incrementally with smaller, local changes
  * Areas that change a lot (e.g., a particular function or class)
  * Code that does not work well currently
  * Areas that new people are told to read
  * Areas that need new capabilities now

## Leaving a Breadcrumb

While sometimes it is obvious where the "hot paths" requiring changes are present, but other times it may take a while to find these areas for improvement

One suggestion is to leave "breadcrumb" comments during development, e.g.,:
```cpp
// SIMP Took 10 minutes to understand Nov 17 1998 ABC

// SIMP Took 30 minutes to understand Feb 3 2007 DEF

// SIMP Took 20 minutes to understand July 20 2018 KMG
```

N.B. `SIMP` is a shorthand denoting "need to *simp*lify"

## Tidy as You Go

It is helpful to modernize code as it is developed and reviewed (e.g., during bug fixes, feature development, etc.)

When you finally understand code, fix it (e.g., rename variables, extract logic into a new function, etc.)
  * Do not just leave a comment explaining it

N.B. Refactoring tools (discussed later in the course) are useful for this process

## Being Less Worried about Changes

"But wait, I am scared to change this code, remember?"

### Get Right with Tests

Before fixing the codebase, it is important to fix the tests *first*

Tests make it less scary to change the code

If there are *no* tests currently, add them incrementally as you tidy the codebase

When you understand something, add a test that records your understanding

Over time, as tests accumulate in the codebase (typically concentrating around the "hot" parts), this inherently protects those sections of the codebase

Not all testing is automated; manual testing can also provide some confidence

## Know the Risks

Some changes are safer to perform than others

| Safer changes | More dangerous changes |
|:---:|:---:|
| Rename something that is used only in this class | Rename something that outside code depends on |
| Refactor some code in a long function into a smaller function at the same or smaller scope | Replace a long function that tests status, type, etc., with several similar functions and chnage calling code |
| Gather local variables into an abstraction and reduce parameter counts in local function calls | Change the signatures of functions called throughout the application |
You have test coverage for all the code affected by the change | You are missing some tests, or the change may affect a global calculation so the effects can be felt far away |

## I Do Not Have Time to Clean This Up!

### How Code Gets Hard to Read

A common misconception is that legacy code was written by people who simply "did not care" about writing simple, understandable code; this is not necessarily true, however
  * They wrote the code with the available tools and practices of the time
  * Additionally, the code may have started off as simple and understandable, but became more complex and unwieldy over time (e.g., addition of "special cases" and variations)

Coming into a codebase containing this type of legacy code can often elicit the sentiment "I do not have time to clean it up, I am just here to add another report"

However, this attitude can be ultimately counter-productive, particularly if the offending code is impeding effective routine use of the code

In such scenarios, here are some suggestions:
  * "Timebox" your cleanup, with a suggested time limit of half the estimated task time
  * Stop when "time is up," then evaluate if you have made the code better or worse
    * If worse, then roll it all back and note any lessons learned
    * Otherwise if better, then do the task the new way

N.B. Following this "timebox" approach, over time you will typically net enough added productivity to justify the upfront "cleanup cost"

## Let Tools Help You

It is important to use tooling to facilitate the legacy code updating process

### Source or Version Control

Can always roll back changes

Nothing is really lost

Discrete commits show others what you did and why
  * The size of commits are discretionary and up to the team to decide, but in general do not mix changes that are not supposed to change behavior (e.g., tidying up, refactoring, modernizing, etc.) with those changes that are; establish some conventions to designate these commits appropriately

### Other Tools

Something to perform refactoring (e.g., IDE, plugin, etc.)

Something to perform reformatting (e.g., linter)
  * Old code may have particularly inconsistent indentation, for example
  * If a broad-sweeping reformatting is performed, do this as a single, discrete commit to communicate this to the team and to avoid mixing this with other code changes
  * Follow conventions established by the team (e.g., brace placement)

Core Guidelines checkers developed by the community are also available
  * Do not change the entire codebase in broad sweeps, but such a tool is useful to identify areas of the codebase that are particularly "non-modern" to target for updating

## Specific Changes to Make

The following changes can be performed in any order and/or combination at any particular time (i.e., based on the specific needs of the particular codebase in question):
  * Use the power of the compiler (e.g., off-loading burden from the preprocessor, which is less powerful than the compiler)
  * Write idiomatic C++ (e.g., classes, type safety, `const`-correctness, etc.)
  * Take advantages of language features added this century (i.e., C++11 and later)
  * Use the C++ Standard Library for performance and expressiveness
  * Clean up, refactor, throw away "junk," and reorganize

N.B. These changes are the topics of the next several sections of this course

## Do You Need to Freeze?

A certain saying goes as follows: "Coding to a specification is like walking on water; it is easy, as long as it is frozen"

In practice, it is probably not necessary to enact a **code freeze** in order to perform updates effectively; rather, the code should stay *usable* while you are working on it

Try not to be more than a few minutes away from checking in and moving on
  * When you do check in, it should not just be "working code," but also should be "better code"
  * You can make drastic improvements to a codebase over time in this manner, without resorting to freezing it altogether

## Do You Need to Change Your Ways?

This is almost certainly the case

In large codebases, many changes are copy-paste-edit
  * You are changing what people copy
  * But you cannot stay ahead of them

Ensure that everyone knows the target
  * In particular, they should not be performing counter-productive actions that deviate away from the target

Ensure that everyone has the tools they need

Most importantly, embrace a culture of change toward modern, idiomatic C++ code

## Summary

Do *not* wade in and start changing *everything*; rather, change the parts that *need* the change (i.e., the "hotspots")

Do not start with the dangerous changes, but rather work incrementally starting from the safer changes to establish a "rhythm"

Have your tools in place

Do not waste the time that went into reading and understanding the code
  * Put that understanding into the code and/or the tests

Ensure that others know what you are doing and what the ***target*** is (e.g., cleaner code that everyone can read and understand, and can change without fear)

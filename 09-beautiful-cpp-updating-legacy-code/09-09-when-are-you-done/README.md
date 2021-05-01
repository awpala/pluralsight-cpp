# Section 9 - When Are You Done?

## Evaluate Your Changes

In some ways, reading legacy code is like exploring a new place:
  1. You are working in a small area
  2. When you started, you did not understand it
  3. As you explored, you cleaned up
  4. What is different now from when you started?

### Is It Shorter Than Before?

Many of the suggested tactics in this course made the code shorter, e.g.,:
  * Replace hand-rolled/raw code with the Standard Library
  * Combine declaration and initialization
  * Delete all the unused code
  * Good abstractions (e.g., polymorphism, RAII, etc.)

### Is It More Obvious Than Before?

More importantly, the refactored code is much more obvious (i.e., readable and expressive) than before, e.g.,:
  * Uses good names
  * Is organized to be readable
  * Uses good abstractions
  * The code is self-explanatory

## Legacy Code

Recall the definition provided at the outset of this course: *legacy code is any code you want to change, but are afraid to*

Therefore, a short-term achievement in the process of updating/refactoring legacy code is the following realization: "*I know what it does, and I was able to make my changes*"

However, the longer term goal of refactoring a legacy codebase is as follows: "*Now it is clear what it does; nobody has to learn all that next time. Nobody will be afraid to change it.*"
  * In other words, leave it better than you found it

## Did You Find a Bug?

In the process of refactoring legacy code, this often reveals many bugs (including subtle or intermittent ones), e.g.,:
  * RAII fixed a missed cleanup
  * Polymorphism fixed a misesed "check the type of `X`"
  * Removing housekeeping code revealed where a pattern faltered
  * Using the Standard Library collections or algorithm functions handled an edge case

## So, What Is Next?

Perhaps nothing

Do you have another change you are scared to make?

Did you spot a larger pattern?
  * Do not lose sight of the "bigger picture" while refactoring legacy code
  * Dedicate a separate task to implementing the change across the codebase

Is there more knowledge to record in the code (e.g., marking `const`, renaming variables, etc.)?
  * Even if this amounts to adding extra documentation beyond the codebase (e.g., separate document file), make to sure to record this knowledge rather than to "hoard" it (thereby perpetuating the original problem)

## Think about Wrappers and Facades

Consider the following example of "big picture" thinking:
```cpp
/* a function signature which "cannot" be changed */
int f(int i1, int i2, int i3, int i4);


/* refactor to a wrapper -- original function signature is not changed */
int f(int i1, int i2, int i3, int i4) {
  // implementation
  Point p1(i1, i2);
  Point p2(i3, i4);
  f(p1, p2);

  // alternative implementation (equivalent to above)
  f({i1, i2}, {i3, i4});
}

int f(Point p1, Point p2);
```

## Other Places for Wrappers

Separate exception-using code from error-returning code

Separate `std::string` areas from `char*` areas

Hide your abstractions and polymorphism from parts of the application not yet exposed to them

N.B. The *boundary* between the changed parts and the old parts is an **adapter**
  * This isolates changes to a particular section

### Expanding the Updated Area

Over time, the "update boundary" can expand into more areas of the codebase, e.g.,:
  1. You started by cleaning hotspots
  2. You spread certain proven patterns through a larger area
  3. All the hottest spots are good now
  4. Can removing adapters be useful?
    * This depends on the specifics of the codebase, however, in general, as the boundary expands, the "inner regions" become more "de-coupled" from it

#3 When Do We Rip It *All* Apart and Rebuild All of It?

Never! Always keep changed *contained*
  * Build adapters and/or facades and/or wrappers
  * Be able to roll back when necessary (e.g., via source control)
  * Be able to prove it is safe (e.g., via tests)
  * ***Understanding*** always comes *before* changing

## Summary

Stop and evaluate after each time you clean up
  * Have you left it better? How and why?
  * Have you built a boundary between old and new (e.g., via wrapper or adapter)?
    * Should you move it?
  * Decide what to clean up next

Keep understanding and changing until your code is modern enough
  * Some old cold spots will not be hurt by deprioritizing their changes initially (or, it may not even be necessary to do so)
  * Remember *who* is reading the code (e.g., newcomers, consultants, experienced veterans, etc.)

"Done" is always a matter of opinion, which can be better informed by your improvements

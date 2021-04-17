# Section 5 - Better Lambdas

## What Is a Lambda?

### Lambda: Unnamed Function

C++11 introduced **lambdas**, which are essentially unnamed functions, e.g.,:
```cpp
// inline lambda implementation
[](int a, double b) {
  // do something ...
}
```

### Custom Comparison Function

Consider an example of sorting a vector of string elements:
```cpp
vector<string> names {
  "Mike", "John", "Beth", "Austin",
  "Bob", "cindy", "Elizabeth", "Connie"
};

// sort lexicographically (default behavior of `std::sort()`)
sort(begin(names), end(names));

// perform custom sorting by string length (i.e., shorter strings first)
// via custom comparison function to compare two (string) elements
bool compare(string const& a, string const& b) {
  return a.length() < b.length();
}
sort(begin(names), end(names), compare);

// perform the same custom sorting, but with an inline/in-place lambda instead
sort(begin(names), end(names),
  [](string const& a, string const& b) { // the compiler automatically deduces the return type `bool`
    return a.length() < b.length();
  }
);
```

N.B. cf. https://bit.ly/VecSort for discussion of sorting with iterators

N.B. cf. https://bit.ly/ObParam for using `const&` for "observing" parameters (i.e., read-only [and without copying for objects], without otherwise modifying the passed argument's value)

N.B. Anonymous inline/in-place lambdas (i.e., as opposed to separate named functions) are idiomatic in such cases as `std::sort()`, where the purpose of the inline lambda function is particular to the calling function (i.e., `std::sort()`)

## Generic Lambdas

C++14 introduced **generic lambdas** (also called **polymorphic lambdas**), which allows for parameter list type declarations with `auto`

For example, compare the following inline lambdas:
```cpp
// C++11
[](string const& a, string const& b) {
  return a.length() < b.length();
}

// C++14
[](auto const& a, auto const& b) {
  return a.length() < b.length();
}
```

N.B. Generic lambdas are particularly useful for complex parameter type declarations; for example, consider a more complex parameter type than simply `string` (e.g., `vector<unique_ptr<MyCoolCLass>> const& a`) -- this could quickly become cumbersome!

### **DEMO: Generic Lambdas**

cf. `ReadLines.cpp` for sorted output (lexicographically by default via `std::sort()`) of text lines in `data.txt`, and corresponding `ReadLinesLambdaSort.cpp` with *custom-sorted* output (shortest to longest) of text lines in `data.txt` using an inline lambda

N.B. `ReadLines.cpp` was previously introduced in the course *C++11 from Scratch* (cf. https://bit.ly/CppDemoSort)

## Init-Captures in Lambdas

### Anatomy of a Lambda

Recall the inline lambda seen previously in this section:
```cpp
[](auto const& a, auto const& b) {
  return a.length() < b.length();
}
```

The C++ lambda has the **general syntax** `[...](...){...}`, where:
  * `[...]` is the lambda **capture list**
  * `(...)` is the **parameters list**
  * `{...}` is the lambda **function body**

#### Capture List

The **capture list** can contain variables declared outside of the lamba, which it imports (i.e., "captures") inside of the lambda, e.g.,:
```cpp
int x{/* ... */};
double y{/* ... */};

[x, y](auto a, auto b) {
  // do something -- `x` and `y` are captured and available inside this lambda
}
```

In the example above, `x` and `y` are captured *by value* (i.e., copied into the lambda)
  * N.B. cf. https://bit.ly/CppParamRules for basic rules for parameter passing in C++

Additionally, variables can be captured *by reference* via operator `&`, e.g.,:
```cpp
[x, &y](auto a, auto b) {
  // do something -- `y` is passed by reference, with access to `y` in the original/calling scope (i.e., not a copy)
}
```

### Init-Capture

C++14 additionally provides the **init-captures** feature, which allows to initialize values inside the capture list, e.g.,:
```cpp
[x, y, value = 64](auto a, auto b) { // `value` is an init-capture
  // do something
}
```
#### Capture *by move*

init-captures are particularly useful when it is necessary to ***move*** something into the lambda (i.e., rather than copying), particularly when moving otherwise non-copyable entities, e.g.,:
```cpp
/* moving `std::unique_ptr` object */
unique_ptr<X> p1 /* initialized to something */;
unique_ptr<X> p2; // uninitialized

p2 = p1; // eror -- `std::unique_ptr` objects are non-copyable

p2 = std::move(p1); // valid -- moves from source `p1` to destination `p2`, with `p1` automatically destroying itself


/* using `std::unique_ptr` object in an init-capture */
unique_ptr<X> p{/* ... */};

[ u{move(p)} ]( /* parameters */ ) { // `p` is moved into the lambda as `u`
  // do something
}
```

Similarly, consider an example using the user-defined class `Image` (which is movable but non-copyable via its member variable `m_data`):
```cpp
class Image {
  // ...
  unique_ptr<Pixel> m_data; // conatins image pixesl (R, G, B)
};

// init-capture `Image` instances via `std::move()` (omitted here for brevity)
```

N.B. **move semantics** involve the transfer of ownership of the constituent data

### **DEMO: Init-Captures with `std::move()`**

cf. `LambdaInitCapture.cpp`

## Summary

Quick lambda introduction/refresher via comparison function

Generic lambdas via `auto`

Init-capture is available as of C++14, and is particularly useful for moving (otherwise non-copyable) objects into the lambda's scope

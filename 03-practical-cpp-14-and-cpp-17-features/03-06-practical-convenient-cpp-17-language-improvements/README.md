# Section 6 - Practical Convenient C++17 Language Improvements

## Writing Less Code with Nested Namespaces

### Namespaces

When working with codebases of medium-to-large complexity, **namespaces** are a useful tool for organizing and structure the code (e.g., combining/grouping semantically related classes and functions)

For example:
```cpp
namespace PluralsightEngine {
  // engine classes

  // ...

} // PluralsightEngine
```

### Nested Namespaces

C++ allows for namespaces to be **nested**, e.g.,:
```cpp
namespace PluralsightEngine {
  namespace Graphics {
    namespace Rendering {
      class OpenGLRender {
        // ...
      };

      // ...
      
    } // Rendering

    // ...

  } // Graphics

  // ...

} // PluralsightEngine
```

### C++17 Nested Namespaces

However, this syntax is cumbersome; C++17 provides **nested namespaces** to address this issue, e.g.,:
```cpp
namespace PluralsightEngine::Graphics::Rendering {
  class OpenGLRender {
    // ...
  };
}
```

Nested namespaces provide cleaner code which is less error-prone due to avoiding deeply nested `{ ... }` pairs

## Variable Declarations in `if` and `switch` Statements

### Find and Replace Strings

Consider the following example:
```cpp
vector<string> names{ /* some names ... */ };

// Find and replace `"Connie"` with `"***"`
const auto it = find(begin(names), end(names), "Connie");
if (it != end(names)) { // guard condition -- N.B. `std::find()` returns an iterator to the `end` value as a sentinel if no value is found
  *it = "***";
}

// Find and replace `"C64"` with `"**"`
const auto it = find(begin(names), end(names), "C64"); // error -- cannot re-declare `it`
if (it != end(names)) {
  *it = "**";
} 
```

N.B. cf. https://bit.ly/VecSort for an explanation of iterators (in the context of sorting a vector)

The error in the latter example (i.e., redeclaring `it`) can be resolved as follows:
  * Create a new variable (e.g., `it2`)
  * Enclose the `if` statement within a new scope via `{...}`

However, these are not particularly elegant or scalable solutions...

### C++17 Variable Declarations in `if` Statements

C++17 provides **variable declarations** to address the issue from the previous example

Consider an analogy via `for` loop with index `i`, e.g.,:
```cpp
for (int i = 0; i < n; i++) {
  // `i` is scoped locally to this `for` loop
}

for (int i = 0; i < n; i++) {
  // `i` is scoped locally to this `for` loop, independently of the previous `for` loop's `i`
}
```

Similarly, C++17 provides the ability to declare local variables inside of an `if` statement, e.g.,:
```cpp
// Find and replace `"Connie"` with `"***"`
if (const auto it = find( /* ... */ ); it = != end(names)) {
  *it = "***";
}

// Find and replace `"C64"` with `"**"` -- no error here, since `it` is scoped locally
if (const auto it = find( /* ... */ ); it = != end(names)) {
  *it = "**";
}
```

An `else` clause can also be used, e.g.,:
```cpp
if (const auto it = find( /* ... */ ); it != end(names)) {
  *it = "***";
} else {
  // target string not found -- N.B. `it` is still accessible here
}
```

### C++17 Variable Declarations in `switch`

The ability to declare local variables was also extended to `switch` statements in C++17, e.g.,:
```cpp
switch (auto val = GetSomeValue(); /* expression for `switch` */) {
  // various cases... -- `val` is accessible here
}
```

### **DEMO**: Variable Declarations in `if` Statements

cf. `VariableDeclarationsIf.cpp`

## Compile-Time Evaluations with `if` `constexpr`

### C++17 `if` `constexpr`

Consider an ordinary `if` statement, e.g.,:
```cpp
if (condition) { // `condition` is evaluated at run-time
  // executed if `condition == true` 
} else {
  // executed if `condition == false`
}
```

C++17 provides a powerful feature called `if` `constexpr`, which is particularly useful when writing template-based C++ code

`if` `constexpr` provides compile-time evaluation of the condition, e.g.,:
```cpp
if constexpr (condition) { // `condition` is evaluated at compile-time
  // executed if `condition == true` 
} else {
  // executed if `condition == false`
}
```

### Using `if` `constexpr` with Template Code

Consider the following example:
```cpp
template <typename T>
auto DoSomething(T const& value) {
  if constexpr (/* `T` is an `int` */) {
    // do something with `int`s -- only this block is compiled
  } else {
    // do something else -- this block is ignored by the compiler, but may be accessed during run-time
  }
}
```

### **DEMO: `if` `constexpr` in Action**

cf. `IfConstexpr.cpp`

## Writing Clearer Code with Structured Bindings

C++17 introduced the feature of **structure bindings**, which allows for single-statement, multiple-variable declarations from a `std::pair`, `std::tuple`, or `struct`, e.g.,:
```cpp
auto [var1, var2, /* ... */] = GetSomeData();
```

### Building an Italian-to-English Dictionary

For example:
```cpp
map<string, string> italianDictionary {
  {"casa", "home"},
  {"gatto", "cat"},
  {"pasta", "pasta"},
  // ...
};

auto result = italianDictionary.insert({"sedia", "chair"}); // N.B. the method `insert()` returns `std::pair`, as deduced via `auto`
```

N.B. `std::map` is an associative container that maps from a `key` to a `value`, which can be of different types (e.g., `std::map<string, string>`, `std::map<string, int>`, etc.)

N.B. The `std::pair` returned by method `std::map.insert()` consists of two elements: (1) the first is an iterator to key element, and (2) the second is a `bool` indicating whether insertion was performed
  * If the key is *not* already present in the map, then a new element is inserted and `insert()` returns an iterator to that element and a value of `true` (respectively)
  * Otherwise, if the key *is* already present in the map, then `insert()` returns an itetator to the existing key and a value of `false` (respectively)

To check the insertion of the `result`:
```cpp
/* pre-C++17 */
auto result = italianDictionary.insert({"sedia", "chair"}); // N.B. repeated statement from before for reference
if (result.second == true) {
  // insertion was successful
} else {
  // use `result.first` to locate the existing item
}

/* using C++17's structured binding */
auto [position, success] = italianDictionary.insert({"sedia", "chair"});
if (success) {
  // insertion was successful
} else {
  // use `position` to locate the existing item
}
```

N.B. This principle generalizes to `std::tuple` and custom `struct`s as well

### **DEMO: Structured Bindings in Action**

cf. `StructuredBindingMap.cpp`

## Summary

Nested namespaces simplify complex namespace hierarchies

Variable declarations can be used in `if` and `switch` statements starting from C++17

`if` `constexpr` is particularly useful for writing template code in C++

C++17 structured bindings perform simultaneously declaration and initialization of multiple variables, using more meaningful variable names

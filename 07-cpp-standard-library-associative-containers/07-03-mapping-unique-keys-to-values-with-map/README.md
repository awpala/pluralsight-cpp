# Section 3 - Mapping Unique Keys to Values with `std::map`

## Why `std::map`?

As with `std::set`, `std::map` stores unique elements, which are commonly called **keys**

Additionally, `std::map` associates (i.e., maps) a key to a **value**

THese associations can generally be of different types, e.g.,:
```cpp
std::map<int, string>; // key `int` to value `string`
std::map<string, ShapePtr>; // key `string` to value `ShapePtr`
std::map<SymbolName, LineOfCode>; // key `SymbolName` to value `LineOfCode`
```

## Creating and Initializing `std::map`

### Using `std::map` in Your Code

`std::map` is provided in the Standard Library header `<map>`

### Creating an Empty `std::map`

To create an empty `std::map` object instance:
```cpp
std::map<KeyType, ValueType> m{};
std::map<KeyType, ValueType> m; // equivalent to previous statement

m.empty(); // returns `true`
```

### Initializing `std::map` with Key-Value Pairs

To initialize a `std::map` object instance with key-value pairs:
```cpp
map<int, string> m{
  {1, "one"},
  {2, "two"},
  {64, "sixty-four"}
};
```

### Counting Associations with `map::size()`

The method `std::map::size()` can be used to determine the number of key-value pairs (i.e., elements) present in a `std::map` object instance, e.g.,:
```cpp
m.size(); // returns `3`
```

## Inserting and Looking Up Associations

### Inserting Associations with `map::operator[]`

To insert new elements into a `std::map` object instance, use overloaded operator `std::map::operator[]`, e.g.,:
```cpp
map<int, string> m{};
m[1] = "one";
m[2] = "two";
m[64] = "sixty-four";
```

### Looking Up Associations with `map::operator[]`

to look up elements in a `std::map` object instance, use overloaded operator `std::map::operator[]`, e.g.,:
```cpp
cout << "64 is pronounced " << m[64] << '\n';
```

### Several Uses of `map::operator[]`

In addition to insertion and look up, `std::operator[]` is also used to update an existing element/association, e.g.,:
```cpp
m[64] = "SIXTY-FOUR";
```

### `map::operator[]` vs. `vector::operator[]`

Unlike `std::map::operator[]`, which inserts a new element if it does not exist in the container, `std::vector::operator[]` can produce an error (e.g., out-of-bounds index access, buffer overrun, etc.) if attempting to access a non-existent element in the container

## Iterating through `std::map` Associations

To iterate through the elements of a `std::map` object instance, a ranged `for` loop can be used, e.g.,:
```cpp
// given `std::map<int, strng>` object instance `m`

for (auto [num, pronunciation] : m) { // via structured bindings (available in C++17 or later)
  cout << "The number " << num
    << " is pronounced " << pronunciation << '\n';
}

for (auto const& [num, pronunciation] : m) { // use `const&` as a best practice for read-only access (and to avoid copying unnecessarily) 
  cout << "The number " << num
    << " is pronounced " << pronunciation << '\n';
}
```

N.B. C++17 introduced structured bindings, which can be used to access the key and value in an idiomatic way for each association/element

As with `std::set`, `std::map` stores its elements/associations in *sorted* order with respect to the key

### How `std::map` Stores Key-Value Pairs

`std::map` stores its key-value associations using the class template `std::pair<Type1, Type2>` (implemented in the C++ Standard Library)
  * `std::pair` allows to pair two (possibly heterogeneous) elements into a single object/element

For `std::map`, the stored element/association has the following correspondences to `std::pair`:
  * `std::pair::first` holds `const Key`
  * `std::pair::second` holds `Value`

Thanks to structured bindings (available in C++17 or later), it is possible to use clearer, more descriptive names for the underlying element/association (i.e., as opposed to `std::pair::first` and `std::pair::second`)

## **DEMO: `std::map` in Action with Number Pronunciations**

cf. `NumberPronunciation.cpp`

## Searching Associations with the Method `map::find()`

To search for an element in a `std::map` object instance, in addition to using the operator `std::map::operator[]`, the method `std::map::find()` can also be used (e.g., `m.find(key)`)

`std::map::find()` returns an iterator pointing to the element if found, otherwise it returns the iterator `std::map::end` if not found
  * This pattern is analogous to that of `std::set` seen previously (as well as with other containers in the Standard Library)

N.B. The returned iterator points to a `std::pair<const Key, Value>` object, which provides access to both `Key` and `Value` as necessary

### `map::find()` vs. `map::operator[]`

| Method | Attempt to access `const(&) map` | When `key` is not found | Run-Time Performance |
| :---: | :---: | :---: | :---: |
| `map::find()` | *no* compiler error (`const` overload avalable) | returns iterator `map::end` | O(log(N)) |
| `map::operator[]` | compiler error (no `const` overload available) | creates/inserts a *new* element | O(log(N)) |

N.B. O(log(N)) run-time element look up is a key feature of `std::map`

### **DEMO: Looking Up Elements in `const std::map`**

cf. `MapElementAccess.cpp`

## **DEMO: Implementing a Simple English-Italian Dictionary with `std::map`**

cf. `ItalianDictionary.cpp`

## **DEMO: Implementing a Simple Airport Database with `std::map`**

cf. `AirportDB.cpp`

## Removing Associations from `std::map`

The method `std::map::erase()` (e.g., `m.erase(key)`) can be used to remove an element/association
  * There are several overloads available for this method

If a matching key is found, `std::map::erase()` removes the corresponding association/element (i.e., key-value pair) from the `std::map` object instance

Additionally, the method `std::map::clear()` erases *all* elements from the `std::map` object instance (e.g., `m.clear()`)
  * N.B. Recall, this is a common method for Standard Library containers (cf. `std::vector::clear()`, `std::array::clear()`, `std::set::clear()`, etc.)

### Erasing All Elements That Satisfy a Condition

To remove elements of a `std::map` instance object matching a custom criterion (i.e., `predicate`), this could be done via iteration through the elements and then calling `std::map::erase()` to remove the elements iteratively

For example:
```cpp
// given a `std::map` object instance `m`

for (auto it = m.begin(), last = m.end(); it != last; ) {
  if (predicate(*it)) {
    it = m.erase(it); // overload of `std::map::erase()` which takes an iterator as its argument (the found element) and returns an iterator to the next element in the container
  } else {
    ++it;
  }
}
```

Additionally, starting with C++20, this equivalent logic can be performed via added Standard Library algorithm function `std::erase_if()`, i.e.,:
```
std::erase_if(container, predicate);
```

## Summary

Storing key-value pairs/associations with `std::map`

Elements are stored in *sorted* order with respect to *key* (independently or insertion order)

Using `map::operator[key]` for inserting, updating, and looking up associations
  * Limitations of `map::operator[key]`

Searching elements with `map::find()`

`std::map` guarantees O(log(N)) for insertion and look up operations

Removing elements with `map::erase()` and (for C++20 or later) `std::erase_if(map, predicate)`

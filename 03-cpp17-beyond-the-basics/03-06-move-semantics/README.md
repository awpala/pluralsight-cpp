# Section 6 - Move Semantics

## Move Semantics

It is common in C++ for objects to have a pointer (or "pointer-like" entity) to data somewhere else; when such objects must be copied, there are two possibilities:
  1. **shallow copy** simply copies the pointer, with the new pointer pointing to the same object
  2. **deep copy** creates a new, independent object with a corresponding separate/independent pointer

When performing a deep copy, copying the data to another object takes time

However, in many cases, the original object is no longer required; so then, why bother to copy it in the first place?

### Temporaries

Consider the following example:
```cpp
string s = s1 + s2 + s3 + s4;
```

In the example above, temporaries such as `s3 + s4` have no purpose later in the application; in such a scenario, **moving** (i.e., rather than copying) is a huge speedup
  * The same line of reasoning applies to resizing a vector, for example

### Moving

Now, consider the following example:
```cpp
string s = s1 + s2;
```

In the example above, `s1` and `s2` are two separate objects on the stack each containing data on the free store (i.e., the element `char`s forming the respective strings)
  * During concatenation, an anonymous `string` object called `temp` (for purposes of illustration) is created to hold the copied contents of `s1` and `s2`
  * `temp` is then passed to the constructor of `s`, and then finally `temp` is destroyed after `s` is built, whose building in turn involves creating another object to copy the data from `temp` during construction
  * alternatively, a better approach is not to create another object during the construction of `s`, but rather have `s` point to the object pointed to by `temp` directly that was already created in order to "keep it alive" after `temp` goes out of scope

### **DEMO: Move Semantics**



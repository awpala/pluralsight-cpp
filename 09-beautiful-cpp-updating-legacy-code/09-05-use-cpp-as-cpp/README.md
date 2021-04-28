# Section 5 - Use C++ as C++

## What Makes C++ C++?

User-defined types
  * `class`es and `struct`s
  * encapsulation

Deterministic destruction (i.e., rather than garbage collection) via RAII

Polymorphism
  * inheritance hierarchy
  * virtual functions

Genericity via templates

`const`-correctness

For example:
```cpp
/* non-idiomatic C-like approach */
bool UpdateMainStorage(
  bool includeCommission,
  bool triggerReports,
  bool backupRequired,
  bool USonly,
  bool override
) {
// ... using `includeCommission`, etc.
}

bool success = UpdateMainStorage(
  true,
  ReportsNeeded(),
  false,
  false,
  true
);


/* C++ idiomatic approach via `struct` */
struct MainStorageOptions {
  bool includeCOmmission=false; // using default initializers (a useful C++ feature)
  bool triggerReports=false;
  bool backupRequired=false;
  bool USonly=false;
  bool override=false;
};

bool UpdateMainStorage(MainStorateOptions opt) {
  // ... using `opt.includeCommision`, etc.
}

MainStorageOptions mso;
mso.includeCommission = true;
mso.triggerReports = ReportsNeeded();
mso.override = true;

bool success = UpdateMainStorage(mso);
```

## While You Are Looking at That Function

Is it called from multiple places?

Does it hard-code the parameters?

Does all of the calling code pass the *same* value for one of the parameters?
  * You can make the function smaller by elminiating this paramter altogether

## Spotting Classes

### Another Common Pattern

Consider the following example:
```cpp
char empName[100];
int NameLength;
int empSalary;
int empStartYear;
bool emplsExempt;
// ...
if (!emplsExempt)
{
  empSalary *= 1.05;
}

if ((CURRENT_YEAR - empStartYear) % 5 == 0)
{
  // ...
}
```

### Thousands of Lines

Furthermore, consider the following example:
```cpp
// ...
char* fname = strtok(empName, " ");
char* lname = strtok(NULL, " ");
char revName[100];
strcpy(revName, lname);
strcat(revName, ", ");
strcat(revName, fname);
// ...
```

### Make a Class

What the previous examples demonstrate is a failure to encapsulate

Therefore, to make a class, do the following:
  1. Make the "related variables" member variables
    * Do not change their names at first
    * Make them `public` at first
  2. Add `public` methods for each semantic unit of logic that you observe
  3. Then, make the variables `private`
  * Add getters and setters only if needed
  4. Lastly, fix the variable names once the variables and logic/methods are encapsulated in a class

### **DEMO: Creating Classes**

cf. `/Strings`

## Cleanup and Housekeeping Code

If the file was opened, then close it

If the mutex (or lock, or exclusive access, etc.) was acquired, then release it

If the connection is open, then close it

If memory was allocated, then free it

This type of housekeeping code is often repeated, e.g.,:
  * At the end of the happy path
  * In a catch block(s) if an exception occurs, in conditional `if`/`else` paths, etc.
  * Before each return in a long function

N.B. These types of tasks are typically the job of the **destructor**

### Scope

Objects are created on the stack via their **constructor**, and have a lifetime in the local scope of the function

The objects' lifetime is subsequently the scope of the function

Once the function execution terminates, the objects go out of scope and their **destructor** is called

In C++, this scope/lifetime paradigm is encompassed by the idiom **Resource Acquisition Is Initialization (RAII)**, which indicates that if there is a resource present (e.g., an open file, a connection, a lock, etc.) then it can be acquired in the constructor and then subsequently released in the destructor

### Resource Acquisition Is Initialization (RAII)

If there is housekeeping code present, it can be encapsulated via RAII as follows:
  1. Make a class
  2. Find all the code that initializes the member variable(s)
    * Move them to the constructor
  3. Change the calling code so that it uses the constructor
  4. Find all the code that performs cleanup
    * Move it to the destructor
  5. Change the calling to code to remove the cleanup (which has instead been moved to the destructor)
  6. Try to test all of the paths if you have deleted a lot to ensure proper resource management has been maintained

### **DEMO: RAII**

cf. `/RAII`

N.B. This simple example uses basic heap-based file constructs and arrays for purposes of demonstrating refactoring a file resource to an RAII-encapsulating class; in practice, use the file I/O features provided by the Standard Library (along with more robust collections, e.g., `std::vector`) for even better performance and resource management
  * This example is better suited for simple demonstration than a more complicated use case (e.g., mutexes, database connections, etc.)

N.B. On Linux, once compiled, the program can be run on companion file `/RAII/numbers.txt` from the shell/terminal as follows (run from directory `/RAII`):
```
$ ./RAII

Enter full path to file: numbers.txt

...
```

## Make It Noncopyable

An important consideration for any class which includes a destructor is **copies**

If two (or more) object instances (e.g., created via copying) hold references to the same common/mutual resource and if one of the objects goes out of scope (and cleans up the common resource in the process), then the resource is invalidated for the remaining object(s)

### Deep Copies

One solution to this problem is to add a copy constructor and an assignment operator, and design them in such a manner in which they perform a **deep copy** (whereby each copy of the object instance creates its *own* independent copy of the common resource)
  * This is called the **rule of three**: when designing a class with a destructor, it should always be accompanied by the corresponding copy constructor and assignment operator overload (or, more generally, including any one of these three should always be accompanied by the other two)

N.B. Additionally, when including move semantics, this is expanded to the **rule of five** to additionally include the move constructor and the move assignment operator

### Reference Counting

However, it is not always sensible to perform deep copying (e.g., an open file handle should be a singleton, dealing with an expensive resource, etc.)

Therefore, an alterantive is to use a resource management scheme for handling the common resource, such as **reference counting** among the object instances (all referencing the same common/mutual resource)
  * With a reference counter, the resource is only destroyed if the the reference count reaches zero (i.e., no more objects exist)

N.B. The Standard Library provides `std::shared_ptr` for this purpose

### Make It Non-Copyable

An even simpler approach (if appropriate) is to simply disallow copying altogether
  * This would be most appropriate if it is not anticipated for the resource to go out of scope prematurely

In C++11 or later, this can be done as follows:
```cpp
Resource(Resource const& other) = delete;
Resource& operator=(Resource const& other) = delete;
```

N.B. This idiom is used in the previous demo `/RAII`

## RAII Benefits

When RAII is encapsulated (e.g., via class), the main-line code becomes much more apparent (i.e., less cluttered)
  * Additionally, this encapsulation process can reveal existing bugs in the code

You might not have to write the wrapper from scratch
  * The Standard Library provides `std::shared_ptr` (reference counting) and `std::unique_ptr` (non-copyable), which are very powerful and useful for implementing RAII
  * There are also additional RAII-wrapper solutions (e.g., COM pointers for Windows, file wrappers, etc.) -- this approach is called "other people's code"

## Similar Functions or Checks

Oftentimes, when reviewing code, many recurring patterns may exist in the code, e.g.,:
```cpp
if (type == special) // occurs in 5 different places
// ...
```

C++ provides polymorphism via inheritance
  * The performance of C++ polymorphism is sometimes criticized (e.g., due to extra indirection), however this is not typically an issue in practical use cases; furthermore, compile-time polymorphism (via templates), which relies on duck typing, can be additionally used to increase performance

Additionally, similarly named functions may be encountered when reviewing code, e.g.,:
```cpp
UpdateRegularOrders()
UpdateRushOrders()
UpdateBackOrders()
```

These functions could be similarly grouped via polymorphism into an `Order` base class, which is extended to derived classes `RushOrder` and `BackOrder` containing the virtual function `update()`

The common theme in the aforemntioned examples is nearly identical blocks of code; inheritance and polymorphism can be used effectively to address this issue

Otherwise, if the objects or functions are not semantically related but have similar behavior, templates are another powerful technique which can be used to reduce redundancy and improve genericity

## `const` Correctness

The keyword `const` is very useful in C++; it is a great way to articulate application design in the code itself

`const` is also useful as an exploratory tool
  1. Mark everyting `const` initially (e.g., function parameters, member functions, and local variables)
  2. Remove `const` gradually, starting with resolving initial compiler errors

As a side effect, this exploratory process adds a lot of information to the code

For example:
```cpp
x = order.getTotal(); // if a compiler error occurs, examine `getTotal()` to determine if `const` is appropriate

Whatever GetWhatever(/* ... */) const // obviously does not change anything
{
  // ...
}

void Update(/* ... */) // obviously does change things
{
  // ...
}

void Clear(/* ... */) // also obvious
{
  // ...
}

void Print(/* ... */) // not so obvious
{
  // ...
}

void Archive(/* ... */) // also not obvious
{
  // ...
}

bool chkDBO(/* ... */) // no idea!
{
  // ...
}

int ULL(/* ... */) // also no idea!
{
  // ...
}

// etc.
```

N.B. As a first step, start locally and do what you can
  * `const` can always be added later if necessary; however, as a corrollary to this, it is easiest to start from "everyting `const`" and "unrestrict" incrementally from there 

## Do Not `typedef` Structs

Legacy C++ code can often contain similar to the following:
```cpp
typedef struct sTwoInts
{
  int one;
  int two;
} TwoInts;

TwoInts n; // can now simply write `TwoInts n;` instead of `struct sTwoInts n;`
```

This is a common C idiom, however, this is unnecssary in modern C++; in modern C++, this behavior is already provided without requiring the designation `typedef`, e.g.,:
```cpp
struct ThreeInts
{
  int one;
  int two;
  int three;
};

ThreeInts n;
```

## Proper Casts

Another difference in old vs. modern C++ is casting style

Older C++ uses C-style casts via `(...)`, e.g.,:
```cpp
int nLimit = (int) fLimit;
```

A key issue with C-style casts is that they do not carry any information

Modern C++ provides templated casts to express intent more clearly
  * `static_cast<>` is used to explicitly indicate a permissible cast (e.g., `float` to `int`, upcasting from a derived-class pointer to a base-class pointer, etc.)
  * `dynamic_cast<>` is used to explicitly indicate a cast which may cause run-time issues (e.g., downcasting a pointer)
    * Returns `nullptr` for an unsuccessful pointer cast, which can be checked conditionally at run-time
  * `reinterpret_cast<>` is used to explicitly indicate a cast which is bit-twiddling or otherwise changes the meaning of the variable
  * `const_cast<>` is used to explicitly indicate a cast which removes `const`
    * N.B. Casting away `const` can be problematic, particularly in applications involving threading

N.B. These templated casts are effective documentation tools to express *intent*

## Summary

Use the language to help you

Create abstractions
  * To hold related variables
  * To hold related functions
  * Everyting gets a name

Embrace RAII

Use virtual functions and/or templates to eliminate unnecessary code duplication

Mark constant things as `const`

Cast properly via templated casts (i.e., rather than C-style casts)

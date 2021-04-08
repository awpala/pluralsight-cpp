# Section 7 - Writing Classes

## A Class of Your Own

A class pulls together semantically related **data**, e.g.,:
  * A customer's first name, last name, address, and phone number
  * An account's number, balance, and list of transactions

A class also adds **functions** that (generally) operate on the data, e.g.,:
  * Get a customer's full name
  * Post a transaction to an account, including updating the balance

Member functions of a class can include operator overloads, if it is sensible to do so for the particular class in question

By combining related data and functions together in a class, this makes the code easier to change and use

## Simple Class System: Design

Consider the design of a simple class pertaining to a bank account

N.B. Classes typically are named with nouns (e.g., `Account`)

Consider the class `Account`...
  * Keeps track of a balance
  * Holds a vector of `Transaction` objects
  * Member functions: `Deposit` and `Withdraw`
  * `Report` function, which is a collection of strings that the calling code can print

Now, consider the class `Transaction`...
  * Should have a date, but we will ignore this for now
  * Holds an amount and a transaction type (for now, simply a string)
  * A `Report` function, which is a string describing the amount and type

Consider the member functions of `Account` in more detail:
  * `Deposit`
    * Create a `Transaction` object
    * Add it to the vector
    * Update the balance
  * `Withdraw`
    * Ensure that you cannot take out more than you have
    * Create a `Transaction` object
    * Add it to the vector
    * Update the balance

## Coding a Class

### Translating Design into Code

It is considered a **best practice** to design a class (e.g., via pseudocode, natural language description, etc.) prior to implementation

In C++, a key design decision is to determine the **access** of each class member
  * Generally, member variables are `private`, which is C++'s enforcement of the principle of **encapsulation**
  * Generally, functions you think of early in the design process are usually `public`; these are typically **services** that the class offers
    * As a corrollary, any helper functions that are designed to facilitate implementation but are otherwise unneccessary to expose should be designated as `private`

### Constructors

**Constructors** are used to initialize objects

Some classes require constructors to initialize variables via parameters
  * Use special **initializing syntax** to initialize member variables (as will be seen shortly)

N.B. Not every class requires a constructor, and not every member variable has to be connected to a parameter in a constructor

The name of the constructor function is the name of the class itself; furthermore, with overloading, it is permissible to create multiple constructors with distinct parameter lists

Constructors do *not* have a return type
  * N.B. This is a distinct situation from a function which returns `void` (i.e., a constructor simply has no return type, it does *not* return `void`)

Like any other function, a constructor can take **parameters**
  * Use them to initialize variables (e.g., member variables)

Like any other function, constructors can be **overloaded**

## Structuring The Code

While it is permissible to define all classes in one, monolithic file, this is not a typical practice

Generally, a class is designed with *one* **header file** (`.h`) per class containing just the declarations of the class's contents

Furthermore, there is *one* **source file** (`.cpp`) per class to implement all the functions

With this implementation strategy, any code that uses the class simply includes the header for the class; so does the source file that implements the class
 * The linker will then handle linking the class implementation to the user code

## Class Syntax

### Keywords to Know

A class is **declared** as follows (i.e., in the header file):
```cpp
class ClassName
{
  private:
    // declarations of private class members
  public:
    // declarations of public class members
}; // N.B. This is a rare instance where a terminating `;` after `}` is required
```

In the corresponding implementation, functions are defined using the scope resolution operator `::`,i.e.:
```cpp
ClassName::MemberFunction(...) { 
  // function implementation statements
} // N.B. no terminating `;` required here
```

For example:
```cpp
// class declaration (in header file)
class Account
{
  private: // `private` variables are only accessible from inside member functions
    int balance;
    std::vector<Transaction> log;
  public:
    Account(); // constructor (N.B. called the "default constructor" if no parameters are taken)
    std::vector<std::string> Report();
    bool Deposit(int amount);
    bool Withdraw(int amount);
    int GetBalance() { return balance; } // `GetBalance` is implemented as an "inline function"
};
```

### Inline Functions

Some functions are really obvious, and are often added to keep the data private; in these cases, it is sensible to show the code together with the function declaration, rather than implementing it separately

Such functions are often colloquially referred to as **inline functions**
  * N.B. This is distinct from the C++ concept of a function declared with keyword `inline`, which is a separate topic involving some compiler optimizations, which is outside of the present topical scope

Now, consider, the implementation of the `Account` member functions:
```cpp
Account::Account(): balance(0) {} // constructor with initializer syntax via `:` (N.B. `log` has a default initialization via `std::vector`)

vector<string> Account::Report()
{
  vector<string> report;

  report.push_back("Balance is " + to_string(balance));
  report.push_back("Transactions: ");

  for (auto t:log) // ranged for loop
  {
    report.push_back(t.Report()); // using `t`s member `Report()` is a common object-oriented programming idiom (i.e., delgation of features)
  }
  report.push_back("-----------------");
}

bool Account::Deposit(int amount)
{
  if (amount <= 0) // guarding `if` pre-condition
  {
    return false;
  }

  balance += amount;

  log.push_back(Transaction(amount, "Deposit")); // create an anonymous `Transaction` object to perform action
  return true;
}

bool Account::Withdraw(int amount)
{
  if (amount <= 0)
  {
    return false;
  }

  if (balance >= amount)
  {
    balance -= amount;
    log.push_back(Transaction(amount, "Withdraw"));
    return true;
  }

  return false;
```

## Creating Instances

A constructor that takes no arguments is called a **default constructor**

Objects can be declared with default constructors similarly to built-in types, e.g.:
```cpp
Account acct;
```

Furthermore, objects with parameter-taking constructors are declared using `(...)` or `{...}`, e.g.,:
```cpp
Transaction t(amount, type);
Transaction t{amount, type}; // this version is recommended as it avoids certain potential errors in more complex classes
```

N.B. `Account acct();` does not initialize an object, but rather declares a function (conversely, `Account acct{};` is equivalent to `Account acct;`)

N.B. Do not use `=` when declaring and initializing an object of a user-defined class to avoid unncessary confusion

## Encapsulation

A well written class is *changeable*, in accordance with the dynamic nature of applications programming

Making all member variables `private` ensures that the code outside of the class cannot count on their names or types
* This allows for the name and/or type of the member variables to be changed without breaking the code outside of the class
* Furthermore, the code outside the class does not need to know the rules or implementation details of the class (e.g., you cannot withdraw more than the present amount)

To interact with the class's `private` member variables, you can add `public` member functions as "gatekeepers" (e.g., `GetBalance()` to determine an account's present balance)

N.B. Not all member variables will have getters, and it is not always necessary to add setters for all member variables either (e.g., `SetBalance()` would not be a useful function to include)

This notion of creating a "*contract*" or "*interface*" between the class and its users is called **encapsulation**

The best `public` functions are things the class itself does, *not* ways to manipulate some of the data in the class (the latter is a more counterintuitive way to approach class design)

Some general **design guidelines** are as follows:
  * Add as few `public` member functions as you can
  * Use `private` functions if you just want to avoid repeating code or to give something a name
  * The more that is encapsulated, the better: changes in one part of the code do not affect other places, and this makes it easier for the developer and less likely to cause bugs elsewhere

## **DEMO** Simple Classes with Encapsulation

cf. `/SimpleClasses`

## Lifetime Management

The concept of **lifetime management** will be revisited later, but consider an introduction of it here

Some classes work with rea-lworld things, e.g.,:
  * Open a file, and then need to close it
  * Open a database connection, and then need to close it

When an object goes out of **scope**, you cannot ask it to close or clean up the data that it held; however, C++ has great **mechanisms** to manage this process
  * A class can have a **destructor** that is called automatically when the object instance goes out of scope
  * **RAII** (Resource Acquisition Is Initialization) makes life simple: "open" things in the constructor, and then "close" them in the destructor
  * However, you also need to deal with copying (e.g., if two classes have a copy of a handle and one thinks it is done, should it close the file?)

Simple classes that just have local variables in them are not generally concerned with lifetime management

## Summary

Writing user-defined classes starts with design

A well-designed class can be used just like a built-in type

A weell-designed class hides its implementation details (i.e., exhibits **encapsulation**)
  * This leaves the developer free to change the implementation details wtihout breaking other code
  * This saves those who use the class from having to remember to do things particular to the class

Using one header file (`.h`) and one source file (`.cpp`) per class is a good practice

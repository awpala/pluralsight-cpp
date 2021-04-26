# Section 7 - Using the Power of Iterators

## Pre-Allocating

### Pre-Allocating Vectors Is No Fun

Thus far in the course, it was necessary to **pre-allocate** `std::vector` containers, e.g.,:
```cpp
vector<int> v1(10);

fill(begin(v1), end(v1), 1);
fill_n(begin(v1), 6, 2); // does not grow the vector if `v1.size() < 6`
iota(begin(v1), end(v1), 1);
```

However, this approach is limited; for example:
  * What if the size of the `std::vector` container is not known in advance?
  * What if there is no default constructor for the elements?
  * Or, if there is a default constructor, what if it is expensive to run?

## Use a Different Iterator





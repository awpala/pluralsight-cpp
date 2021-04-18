// Shows std::set containing objects of a custom class

#include <iostream>
using std::cout;
#include <ostream>
using std::ostream;
#include <set>
using std::set;
#include <cmath>
using std::hypot;


// Custom class representing a 2D point
class Point2D {
public:
  Point2D() = default;

  Point2D(double x, double y) : mX{ x }, mY{ y } {}

  double X() const { return mX; }
  double Y() const { return mY; }

  double Length() const {
    return std::hypot(mX, mY);
  }

  void SetXY(double x, double y) {
    mX = x;
    mY = y;
  }

private:
  double mX = 0.0;
  double mY = 0.0;
};

// To store a `Point2D` object in std::set, operator `<` must be overloaded to provide comparisons for insertion (i.e., in sorted order)
inline bool operator<(const Point2D& p1, const Point2D& p2) {
  // Compare points based on their distance from the origin O(0, 0)
  return p1.Length() < p2.Length();
}

// Print point in the form (X, Y)
inline std::ostream& operator<<(std::ostream& os, const Point2D& point) {
  os << '(' << point.X() << ", " << point.Y() << ')';
  return os;
}

// Print std::set<Point2D> content in the form: {p1, p2, ..., pn}
std::ostream& operator<<(std::ostream& os, const std::set<Point2D>& points) {
  os << '{';

  bool isFirst = true;
  for (const auto& p : points) {
    if (isFirst) {
      os << p;
      isFirst = false;
    }
    else {
      os << ", " << p;
    }
  }

  os << '}';
  return os;
}

// Demonstrate std::set<Point2D> operations
int main() {
  using std::cout;

  std::set<Point2D> points{ {20, 30}, {22, 33}, {2, 3} };
  cout << " Initial set of points: \n";
  cout << "  " << points << "\n\n";

  points.insert(Point2D{10, 20});
  cout << " Inserting new point (10, 20): \n";
  cout << "  " << points << "\n\n";

  return 0;
}

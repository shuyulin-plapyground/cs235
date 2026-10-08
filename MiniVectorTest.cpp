//File name: MiniVectorTest.cpp, template version
//name:
//email:

// command to compile:
// g++ -std=c++17 -Wall -Wextra -pedantic MiniVectorTest.cpp Rectangle.cpp -o MiniVectorTest
#include <iostream>
#include <cassert>
#include <stdexcept>
#include <string>
#include "MiniVector.hpp"
#include "Rectangle.hpp"

int main() {
  MiniVector<int> v;

  v.push_back(3);
  v.push_back(2);
  v.push_back(1);
  v.push_back(-1);
  v.push_back(6);
  std::cout << v.size() << '\n';
  std::cout << v.capacity() << '\n';
  //std::cout << v[0] << '\n';

  v[0] = 1; // call int& operator[](size_t pos) method
  std::cout << v.at(0) << '\n';
  v.at(0) = 7;

  v.clear();
  std::cout << "\nCall v.clear(); capacity and size of v are as follows.\n";
  std::cout << "capacity: " << v.capacity() << '\n';
  std::cout << "size: " << v.size() << '\n';

  v.reserve(20);
  v.push_back(3);
  std::cout << "\nThen call v.reserve(20); capacity and size of v are as follows.\n";
  std::cout << "capacity: " << v.capacity() << '\n';
  std::cout << "size: " << v.size() << '\n';

  MiniVector<int> v2(10);
  MiniVector<int> v3 = v2;
  std::cout << "\nRun MiniVector v2(10); Set v3 to be v2. Then change ith element of v3 to be i + 1, where i >= 0\n";

  for (std::size_t i = 0; i < v3.size(); ++i) {
    v3[i] = static_cast<int>(i + 1);
    std::cout << v3[i] << " ";
  }
  std::cout << "\n\n";

  std::cout << "Contents of v2 are not changed:\n";
  for (std::size_t i = 0; i < v2.size(); ++i) {
    std::cout << v2[i] << " ";
  }
  std::cout << "\n\n";

  v2.clear();
  std::cout << "Call clear method for v2.\n";
  MiniVector<int> v4 = v2;

  std::cout << "After v4 = v2, is v4 an empty vector? " << std::boolalpha << v4.empty() << '\n';

  MiniVector<int> v5(3);
  v5[0] = 10;
  v5[1] = 20;
  v5[2] = 30;
  v5.push_back(40);

  MiniVector<int> v6(1);

  v6 = v5;
  v6.push_back(999);
  assert(v6.size() == v5.size() + 1);
  assert(v6.capacity() == v5.capacity());
  assert(v6[0] == 10);
  assert(v6[1] == 20);
  assert(v6[2] == 30);

  v6[0] = 100;

  std::cout << v5[0] << '\n';  // 10
  std::cout << v6[0] << '\n';  // 100

  v6 = v6;                     // self-assignment
  std::cout << v6[0] << '\n';  // 100

  MiniVector<int> empty;
  v6 = empty;

  std::cout << v6.empty() << '\n';     // true
  std::cout << v6.size() << '\n';      // 0
  std::cout << v6.capacity() << '\n';  // 2

  MiniVector<int> large(10);
  large = v5;

  assert(large.size() == v5.size());
  assert(large.capacity() == v5.capacity());
  assert(large[0] == 10);
  assert(large[1] == 20);
  assert(large[2] == 30);
  assert(large[3] == 40);

  const MiniVector<int> constVector(v5);

  assert(constVector.size() == v5.size());
  assert(!constVector.empty());
  assert(constVector[0] == 10);
  assert(constVector.at(1) == 20);

  bool caught = false;

  try {
    v5.at(v5.size());
  }
  catch (const std::out_of_range&) {
    caught = true;
  }

  assert(caught);

  MiniVector<int> popTest;
  popTest.push_back(10);
  popTest.push_back(20);

  std::size_t oldCapacity = popTest.capacity();

  popTest.pop_back();
  assert(popTest.size() == 1);
  assert(popTest.capacity() == oldCapacity);

  popTest.pop_back();
  assert(popTest.empty());
  assert(popTest.capacity() == oldCapacity);

  MiniVector<double> decimals;
  decimals.push_back(1.5);
  decimals.push_back(2.75);
  assert(decimals[0] == 1.5);
  assert(decimals[1] == 2.75);

  MiniVector<std::string> words;
  words.push_back("tree");
  words.push_back("string");
  assert(words.size() == 2);
  assert(words[0] == "tree");
  assert(words[1] == "string");

  MiniVector<Rectangle> defaultRectangles(3);

  assert(defaultRectangles.size() == 3);
  assert(defaultRectangles.capacity() == 3);
  assert(defaultRectangles[0].length() == 2.0);
  assert(defaultRectangles[0].width() == 1.0);

  MiniVector<Rectangle> rectangles;

  rectangles.push_back(Rectangle(3.0, 4.0));
  rectangles.push_back(Rectangle(5.0, 6.0));
  rectangles.push_back(Rectangle(7.0, 8.0));

  assert(rectangles.size() == 3);
  assert(rectangles.capacity() == 4);
  assert(rectangles[0].length() == 3.0);
  assert(rectangles[1].width() == 6.0);
  assert(rectangles.at(2).area() == 56.0);  // 7.0 * 8.0

  MiniVector<Rectangle> rectangleCopy(rectangles);
  rectangleCopy[0] = Rectangle(10.0, 2.0);

  assert(rectangleCopy[0].length() == 10.0);
  assert(rectangleCopy[0].width() == 2.0);
  assert(rectangles[0].length() == 3.0);
  assert(rectangles[0].width() == 4.0);

  rectangleCopy.push_back(Rectangle(9.0, 10.0));

  assert(rectangleCopy.size() == 4);
  assert(rectangleCopy.capacity() == rectangles.capacity());
  assert(rectangleCopy[3].length() == 9.0);
  assert(rectangleCopy[3].width() == 10.0);

  return 0;
}

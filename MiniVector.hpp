// File name: MiniVector.hpp, template version
//
// MiniVector: a simplified template vector.
//
// The point of this class (as with std::vector) is to give clients an
// array that can grow. Internally we keep three pieces of state:
//
//   data_      - pointer to a dynamically allocated array of type T on the heap
//   size_      - how many elements are actually "in use" (logical length)
//   capacity_  - how many elements the current allocation can hold
//                before we must reallocate
//
// size_ <= capacity_ always. The gap between them is spare room that lets
// push_back() be fast most of the time (amortized O(1)) instead of
// reallocating on every single insertion.
//
#ifndef MINIVECTOR_HPP
#define MINIVECTOR_HPP

#include <cstddef>//  for size_t // to allow using nonegative integer 

// delcear T, T reprent type and we don't know which type yet~ 
template <typename T>
class MiniVector {
public:
  // Creates an empty vector with an allocated array of capacity 2.
  // size() == 0 and capacity() == 2.
  MiniVector();

  // If count > 0, creates a vector containing count value-initialized
  // elements, with size() == capacity() == count.
  // If count == 0, behaves like the default constructor:
  // size() == 0 and capacity() == 2.
  // Marked explicit so that an integer count cannot implicitly convert
  // into a MiniVector<T>.
  explicit MiniVector(std::size_t count);

  // Deep copy: `other`'s elements are duplicated into freshly allocated
  // storage. Modifying one vector must never affect the other.
  MiniVector(const MiniVector& other);

  // Deep-copy assignment. Must correctly handle self-assignment
  // (v = v;) and release any storage this vector previously owned.
  MiniVector& operator=(const MiniVector& other);

  // Releases the heap array owned by this vector.
  ~MiniVector();

  // Bounds-checked element access: throws std::out_of_range if
  // pos >= size(). Prefer this over operator[] when you're not sure
  // the index is valid.
  // MiniVector.tpp includes <stdexcept> for std::out_of_range.
  T& at(std::size_t pos);
  const T& at(std::size_t pos) const;

  // Unchecked element access (like std::vector::operator[]).
  // Passing an out-of-range position results in undefined behavior.
  T& operator[](std::size_t pos);
  const T& operator[](std::size_t pos) const;

  bool empty() const;
  std::size_t size() const;
  std::size_t capacity() const;

  // Ensures capacity() >= newCapacity, reallocating if necessary.
  // Existing elements and size() are preserved.
  // Does nothing if newCapacity <= capacity().
  void reserve(std::size_t newCapacity);

  // Removes all elements. size() becomes 0, but capacity() and the
  // underlying allocation remain unchanged.
  void clear();

  // Appends element to the end. If size() == capacity(),
  // doubles the capacity before inserting.
  void push_back(T element);

  // Precondition: !empty(). Like std::vector::pop_back(), calling this
  // on an empty MiniVector is undefined behavior -- do not add a check,
  // and do not throw. Must not change capacity().
  void pop_back();

private:
  T* data_;
  std::size_t size_;
  std::size_t capacity_;
};

// The template definitions must be visible to every file that uses MiniVector.
#include "MiniVector.tpp"

#endif
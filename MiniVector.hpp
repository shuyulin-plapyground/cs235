// File name: MiniVector.hpp
//
// CSCI 235 -- Project 1A: MiniVector (int)
// Hunter College, CUNY | Fall 2026
//
// MiniVector is a simplified, int-only stand-in for std::vector<int>.
// This header is the complete specification for MiniVector.cpp, which you
// write yourself: implement every function declared below. Do not modify
// this file -- the interface below is exactly what the autograder expects.
//
// Internally, MiniVector keeps three pieces of state:
//
//   data_      - pointer to a dynamically allocated int array on the heap
//   size_      - how many elements are actually "in use" (logical length)
//   capacity_  - how many elements the current allocation can hold before
//                we must reallocate
//
// size_ <= capacity_ always. The default constructor starts capacity_ at 2
// (never 0), so data_ is never null and push_back() never needs a special
// case for "growing from an empty allocation."
//
#ifndef MINIVECTOR_HPP
#define MINIVECTOR_HPP

#include <cstddef>

class MiniVector {
public:
    // TODO (Task A): Default constructor.
    // Allocate an array of capacity 2. size() == 0, capacity() == 2.
    MiniVector();

    // TODO (Task A): Count constructor.
    // If count > 0: allocate an array of capacity == count, and
    // value-initialize every element to 0. size() == capacity() == count.
    // If count == 0: behave exactly like the default constructor
    // (capacity() == 2), so MiniVector(0) and MiniVector() are
    // indistinguishable.
    explicit MiniVector(std::size_t count);

    // TODO (Task A): Destructor.
    // Release the heap array owned by this vector. Nothing else is needed.
    ~MiniVector();

    // TODO (Task D): Copy constructor.
    // Deep copy: allocate a new array of other.capacity(), and copy
    // other.size() elements into it. Modifying one vector must never
    // affect the other.
    MiniVector(const MiniVector& other);

    // TODO (Task D): Copy-assignment operator.
    // Deep-copy assignment. Must correctly handle self-assignment
    // (v = v;) and must not lose *this's original data if allocation
    // of the new array were to fail (allocate the replacement before
    // releasing what you currently own).
    MiniVector& operator=(const MiniVector& other);

    // Unchecked element access (like std::vector::operator[]). Passing an
    // out-of-range idx is undefined behavior. Each overload is a one-line
    // return statement in terms of data_ -- not separately graded, but
    // needed by every task below. Study both overloads: why does the const
    // one return const int& instead of int&?
    int& operator[](std::size_t idx);
    const int& operator[](std::size_t idx) const;

    // TODO (Task C): Bounds-checked element access.
    // Throw std::out_of_range if idx >= size(). Otherwise behaves like
    // operator[].
    int& at(std::size_t idx);
    const int& at(std::size_t idx) const;

    // TODO (Task B): Ensure capacity for at least newCapacity elements.
    // If newCapacity > capacity(), allocate a new array of exactly
    // newCapacity elements, copy the existing size() elements into it, and
    // free the old array. If newCapacity <= capacity(), do nothing:
    // reserve() never shrinks the vector, and never changes size().
    void reserve(std::size_t newCapacity);

    // TODO (Task B): Append value at the end.
    // If size() == capacity(), first call reserve(2 * capacity()) to make
    // room -- reserve() already contains the allocate/copy/free logic, so
    // push_back() should not duplicate it. Then store value at the end and
    // increase size() by one.
    void push_back(int value);

    // TODO (Task C): Remove the last element.
    // Precondition: !empty(). Like std::vector::pop_back(), calling this
    // on an empty MiniVector is undefined behavior -- do not add a check,
    // and do not throw. Must not change capacity().
    void pop_back();

    // TODO (Task C): Remove all elements.
    // Set size() to 0. Unlike pop_back(), clear() has no precondition --
    // calling it on an already-empty MiniVector is perfectly safe. The
    // allocated storage remains available for reuse: clear() changes only
    // size(), and must not modify capacity() or the underlying array.
    void clear();

    // One-line implementations in terms of size_ and capacity_. Not
    // separately graded, but needed by every task below.
    bool empty() const;
    std::size_t size() const;
    std::size_t capacity() const;

private:
    int* data_;
    std::size_t size_;
    std::size_t capacity_;
};

#endif
// PointerPractice.hpp
// CSCI 235 -- Exercise 2: Pointer Practice
// Provided file -- do not modify. Gradescope compiles your submission
// against the original version of this file.

#ifndef POINTER_PRACTICE_HPP
#define POINTER_PRACTICE_HPP

#include <cstddef>

// ---------------------------------------------------------------------
// Task A -- Pointer expressions
//
// No loops, no algorithms here -- work out the result of each
// expression from the table on the handout. arr is a 4-element array;
// p is a plain int* that has been set equal to arr.
// ---------------------------------------------------------------------
struct TaskAAnswers {
    int starArr;                          // *arr
    int arrBracket0;                       // arr[0]
    int starArrPlus1;                       // *(arr + 1)
    int arrBracket1;                         // arr[1]
    int* arrPlus1;                            // arr + 1
    int* addrArrBracket1;                      // &arr[1]
    int starP;                                  // *p
    int pBracket0;                               // p[0]
    int starPPlus2;                               // *(p + 2)
    int pBracket2;                                 // p[2]
    bool arrPlus1EqualsAddrArrBracket1;             // arr + 1 == &arr[1]
    bool starArrPlus2EqualsArrBracket2;              // *(arr + 2) == arr[2]
};

TaskAAnswers taskA_pointerExpressions(int arr[]);

// ---------------------------------------------------------------------
// Task B -- Dynamic allocation
//
// Return a dynamically allocated array of `size` ints, every element
// value-initialized to 0. The caller is responsible for deleting it
// with delete[].
// ---------------------------------------------------------------------
int* allocate(std::size_t size);

// ---------------------------------------------------------------------
// Task C -- Pointer to the last occurrence of the minimum
//
// Return a pointer to the LAST occurrence of the smallest value in
// arr (not the value itself). If size == 0, return nullptr.
// ---------------------------------------------------------------------
int* lastMinimum(int* arr, std::size_t size);

// ---------------------------------------------------------------------
// Task D -- Reverse in place, using pointer arithmetic
//
// Reverse the elements of arr in place. You must implement this with
// two pointers that walk toward each other (e.g. int* left = arr;
// int* right = arr + size - 1;) -- not with integer indices.
// ---------------------------------------------------------------------
void reverse(int* arr, std::size_t size);

// ---------------------------------------------------------------------
// Task E -- Two kinds of "swap"
//
// swapValues swaps the two ints that a and b point to.
// swapPointers swaps what the two pointers *a and *b point to.
// ---------------------------------------------------------------------
void swapValues(int* a, int* b);
void swapPointers(int** a, int** b);

// ---------------------------------------------------------------------
// Task F (OPTIONAL PRACTICE -- not graded, not required)
//
// Two-pointer palindrome check. arr is read-only.
// ---------------------------------------------------------------------
bool isPalindrome(const int* arr, std::size_t size);

#endif
// Stack.hpp
// CSCI 235 -- Exercise 5: Stacks and Queues
// Provided file -- do not modify. Gradescope compiles your submission
// against the original version of this file.

#ifndef STACK_HPP
#define STACK_HPP

#include <string>

// A link-based stack of ints -- the LinkedStack from Class 9.
//
// The top of the stack is the FRONT of the chain, so push() is Class 8's
// prepend() and pop() is Class 8's removeFront(). That is what makes every
// operation O(1): you never walk the list.
//
// head_ points at the top node; the bottom node's next is nullptr;
// head_ == nullptr is the empty stack.
class Stack {
public:
    Stack();       // provided -- head_ = nullptr, size_ = 0
    ~Stack();      // provided -- deletes every remaining node

    // Copying is disabled, for the same reason as in Exercise 4: without a
    // deep copy, two stacks would share one chain and both destructors would
    // delete each node. A compile error is better than a double free.
    Stack(const Stack& other) = delete;
    Stack& operator=(const Stack& other) = delete;

    // ---- Implement these in Stack.cpp ----
    bool push(int value);   // Task A -- always returns true for a linked stack
    bool pop();             // Task B -- false if the stack is empty
    int  top() const;       // Task B -- PRECONDITION: !empty()

    // ---- Provided observers ----
    bool empty() const;            // head_ == nullptr
    int  size() const;             // O(1): the stored count
    std::string toString() const;  // "30 -> 20 -> 10" (top first), or "(empty)"

private:
    struct Node {
        int   data;
        Node* next;
    };

    Node* head_;
    int   size_;
};

// ---- Task E: implement this in Stack.cpp ----
//
// Returns true when every opening bracket in `text` is closed by the matching
// closing bracket, in the correct order. Characters that are not one of
// ( ) [ ] { } are ignored entirely.
//
//   balanced("a(b)[c]")   -> true
//   balanced("{[()]}")    -> true
//   balanced("([)]")      -> false   (closed in the wrong order)
//   balanced("(()")       -> false   (an opening bracket never closed)
//   balanced(")(")        -> false   (a closing bracket, nothing open)
//   balanced("")          -> true    (nothing to mismatch)
//
// Use a Stack. Counting brackets is not enough -- order is what matters.
bool balanced(const std::string& text);

#endif
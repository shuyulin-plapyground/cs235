// Queue.hpp
// CSCI 235 -- Exercise 5: Stacks and Queues
// Provided file -- do not modify. Gradescope compiles your submission
// against the original version of this file.

#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <string>

// A link-based queue of ints -- the LinkedQueue from Class 10.
//
// Items join at the BACK and leave from the FRONT, so the class keeps two
// pointers. front_ is where dequeue() removes; back_ is where enqueue() adds.
// Both are nullptr when the queue is empty, and both point at the SAME node
// when the queue holds exactly one item.
//
// That one-item case is where this class is usually gotten wrong. Read the
// comments on enqueue() and dequeue() carefully.
class Queue {
public:
    Queue();       // provided -- front_ = back_ = nullptr, size_ = 0
    ~Queue();      // provided -- deletes every remaining node

    Queue(const Queue& other) = delete;
    Queue& operator=(const Queue& other) = delete;

    // ---- Implement these in Queue.cpp ----

    // Task C. Adds `value` at the back. Always returns true.
    //
    // Two cases:
    //   - the queue is empty: the new node is BOTH the front and the back.
    //   - otherwise: hook it onto the current back, THEN advance back_.
    //     (Advance first and back_->next = newNode becomes
    //      newNode->next = newNode -- the new node points at itself and
    //      is never connected to the queue.)
    bool enqueue(int value);

    // Task D. Removes the item at the front. Returns false if empty.
    //
    // This is Class 8's removeFront() plus ONE extra line: when the queue
    // becomes empty, back_ must be reset to nullptr as well. Otherwise back_
    // is left pointing at memory you just freed, and the next enqueue()
    // writes into it.
    bool dequeue();

    // Task D. Reads the front item. PRECONDITION: !empty()
    int front() const;

    // ---- Provided observers ----
    bool empty() const;            // front_ == nullptr
    int  size() const;             // O(1): the stored count
    std::string toString() const;  // "10 -> 20 -> 30" (front first), or "(empty)"

private:
    struct Node {
        int   data;
        Node* next;
    };

    Node* front_;
    Node* back_;
    int   size_;
};

// ---- Task F (OPTIONAL PRACTICE -- not graded) ----
//
// Reverses `q` in place, so that the item that was at the back ends up at the
// front. Use a Stack: dequeue everything into it, then pop everything back
// into the queue. It comes out in reverse order because of the stack's LIFO behavior.
//
// This is the Class 9 backup slide ("Reversing With a Stack") applied to a
// queue -- and it is a good way to check you understood both structures.
void reverseQueue(Queue& q);

#endif
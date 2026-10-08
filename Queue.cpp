// Queue.cpp
// CSCI 235 -- Exercise 5: Stacks and Queues
//
// SUBMIT THIS FILE (together with Stack.cpp).
// Implement Task C and Task D below. Task F is optional. Do not modify
// Queue.hpp.

#include "Queue.hpp"
#include "Stack.hpp"   // only needed for Task F

#include <sstream>

// ---------------------------------------------------------------- provided
Queue::Queue() : front_(nullptr), back_(nullptr), size_(0) {}

Queue::~Queue() {
    while (front_ != nullptr) {
        Node* toDelete = front_;
        front_ = front_->next;
        delete toDelete;
    }
    back_ = nullptr;
    size_ = 0;
}

bool Queue::empty() const {
    return front_ == nullptr;
}

int Queue::size() const {
    return size_;
}

std::string Queue::toString() const {
    if (front_ == nullptr) {
        return "(empty)";
    }
    std::ostringstream out;
    for (Node* curr = front_; curr != nullptr; curr = curr->next) {
        out << curr->data;
        if (curr->next != nullptr) {
            out << " -> ";
        }
    }
    return out.str();
}

// ================================================================== Task C
// enqueue(value): add `value` at the back. Always returns true.
//
// The new node always goes at the end, so its next is nullptr.
//
// Then two cases:
//   empty queue     -> the new node is both front_ and back_
//   otherwise       -> (1) back_->next = newNode;   hook it on
//                      (2) back_ = newNode;         then advance
//
// Order matters in case 2. If you advance back_ first, then
// back_->next = newNode is really newNode->next = newNode: the new node
// points at itself. The old queue is still reachable from front_, but it
// is no longer connected to back_.
bool Queue::enqueue(int value) {
    Node* addback = new Node{value,nullptr};
    if(size_==0){
        front_ = addback;
        back_ = addback;
    }else{
        back_->next = addback;
        back_ = addback;
        
    }
    size_++;
    return true;
}

// ================================================================== Task D
// dequeue(): remove the front item. Returns false if the queue is empty.
//
// Start from removeFront(): save front_, advance front_, delete the saved
// address. Then add the line this class needs:
//
//   if the queue has just become empty, back_ must be set to nullptr too.
//
// Skip that line and back_ still points at the node you just deleted.
// empty() will look correct -- it checks front_ -- and the next enqueue()
// will write through back_ into freed memory. Valgrind catches it here.
bool Queue::dequeue() {
    if(size_==0){
        return false;
    }
    Node* todelete = front_;
        front_=front_->next;
        delete todelete;
        size_--;
    if(size_==0){
        back_=nullptr;
        front_=nullptr;
    }
    
    return true;

}

// front(): return the front item WITHOUT removing it.
//
// PRECONDITION: the queue is not empty.
int Queue::front() const {
    
    return front_->data;
}

// ================================================================== Task F
// OPTIONAL PRACTICE -- 
// queue q = 10,20,30,40,50
//we storage in to stack from front --> end 
//stack = 50,40,30,20,10 frist in last out 
// push it back to queue = 50->40->30->20->10 first in first out
// since we are not created an new pointer . we just creat a local object , since we finish the function the temp will get destory.
void reverseQueue(Queue& q) {
    Stack temp;
    while(!q.empty()){
       temp.push(q.front());// this concept is not correct since stack is an structure 
       q.dequeue();
    }
    while(!temp.empty()){
        q.enqueue(temp.top());
        temp.pop();
    }
} 
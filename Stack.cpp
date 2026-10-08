// Stack.cpphttps://orange-space-pancake-4jw964xrq55jc5564.github.dev/
// CSCI 235 -- Exercise 5: Stacks and Queues
//
// SUBMIT THIS FILE (together with Queue.cpp).
// Implement Task A, Task B and Task E below. Do not modify Stack.hpp.

#include "Stack.hpp"
#include<iostream>

#include <sstream>

// ---------------------------------------------------------------- provided
Stack::Stack() : head_(nullptr), size_(0) {}

Stack::~Stack() {
    while (head_ != nullptr) {
        Node* toDelete = head_;
        head_ = head_->next;
        delete toDelete;
    }
    size_ = 0;
}

bool Stack::empty() const {
    return head_ == nullptr;
}

int Stack::size() const {
    return size_;
}

std::string Stack::toString() const {
    if (head_ == nullptr) {
        return "(empty)";
    }
    std::ostringstream out;
    for (Node* curr = head_; curr != nullptr; curr = curr->next) {
        out << curr->data;
        if (curr->next != nullptr) {
            out << " -> ";
        }
    }
    return out.str();
}

// ================================================================== Task A
// push(value): put `value` on top of the stack.
//
// The top is the front of the chain, so this is prepend(): make a new node
// whose next is the current head_, then move head_ to it. Remember size_.
//
// Always returns true. (A linked stack cannot be full; push returns bool only
// so that this class and an array-based stack share one interface.)
bool Stack::push(int value) {
    Node* newData = new Node{value,head_};
    head_ = newData;
    // TODO: your code here
    size_++;
    return true;
}

// ================================================================== Task B
// pop(): remove the top item. Returns false if the stack is empty.
//
// This is removeFront(). Save the node you are about to remove, move head_
// past it, and only THEN delete the saved address -- reading head_->next
// after the delete is reading freed memory.
bool Stack::pop() {
    if(size_==0){
        return false;
    }
    Node* toDelete = head_;
    head_= head_->next;
    
    delete toDelete;
    toDelete = nullptr;
    size_--;
    return true;
}

// top(): return the top item WITHOUT removing it.
//
// PRECONDITION: the stack is not empty. The caller checks empty() first; the
// tests never call top() on an empty stack.
int Stack::top() const {
    return head_->data;       
}

// ================================================================== Task E
// balanced(text): see the comment in Stack.hpp for the exact rules.
// creat an stack for contain the text[i] by the loop
// storage the close prenthesis into stack (infor from our side: how many close prentesis from text)

// check the string (if close > open ){size!=0 return false}
//                  (if close <open ){if(!s.empty())and still get into the check open prenthesis loop , return false}
// else they are equal  then return true.
bool balanced(const std::string& text) {
    Stack s;
    for(std::size_t i=0; i<text.size();++i){
        if(text[i]== '('|| text[i]=='{'||text[i]=='['){
            s.push(text[i]); 
        }
        
        if(text[i]==')'||text[i]=='}'||text[i]==']'){
            if(s.empty()){
                return false;
            }
            if(s.top() == '('&& text[i] == ')'){
                s.pop();
            }
            else if(s.top() == '['&& text[i] == ']'){
                s.pop();
            }
            else if(s.top() == '{'&& text[i] == '}'){
                s.pop();
            }
        }
        
        
    }
    if(s.size()==0){
        return true;
    }else{
        return false;
    }

}
// LinkedList.cpp
// CSCI 235 -- Exercise 4: Linked List Operations
// Complete the TODO sections below and submit this file.

#include "LinkedList.hpp" 

#include <iostream>
#include <stdexcept>
#include <string>

// ==============================================================
// PROVIDED -- you do not need to change anything above the line
// marked "TODO" further down.
// ==============================================================

LinkedList::LinkedList() : head_(nullptr) {
}

LinkedList::~LinkedList() {
    while (head_ != nullptr) {
        Node* toDelete = head_;   // remember the node to free
        head_ = head_->next;      // advance FIRST, while we still can
        delete toDelete;          // now it is safe to free it
    }
}

bool LinkedList::empty() const {
    return head_ == nullptr;
}

// Note: this walks the chain rather than returning a stored counter, so it
// always reports what the pointers actually say. A production list would
// cache the length in a data member and keep it up to date in every
// insert and remove -- one more invariant to maintain.
int LinkedList::size() const {
    int count = 0;
    for (Node* curr = head_; curr != nullptr; curr = curr->next) {
        ++count;
    }
    return count;
}

int LinkedList::getEntry(int pos) const {
    if (pos < 0) {
        throw std::out_of_range("getEntry: position must not be negative");
    }
    Node* curr = head_;
    for (int i = 0; i < pos && curr != nullptr; ++i) {
        curr = curr->next;
    }
    if (curr == nullptr) {
        throw std::out_of_range("getEntry: position past the end of the list");
    }
    return curr->data;
}

std::string LinkedList::toString() const {
    if (head_ == nullptr) {
        return "(empty)";
    }
    std::string out;
    for (Node* curr = head_; curr != nullptr; curr = curr->next) {
        out += std::to_string(curr->data);
        if (curr->next != nullptr) {
            out += " -> ";
        }
    }
    return out;
}

// --------------------------------------------------------------
// TODO -- Task A: void LinkedList::prepend(int value)
// Insert value at the FRONT of the list, in O(1).
//0(1) one time, no need to work thorugh the list 
// we get the value connet to the head 
void LinkedList::prepend(int value) {
    Node* newNode= new Node{value,head_};
    // the sturct of node int data , Node*next// when we assign * means for stores memory address
    // this is connect value with next through (address of next node)
    head_= newNode;



}

// TODO -- Task B: void LinkedList::append(int value)
// Insert value at the BACK of the list. Remember the empty list.
void LinkedList::append(int value) {
    // if the head == empty then head == new Node 
    //else we connect value at the end of the head 
    Node* newNode = new Node{value,nullptr};

    if(head_==nullptr){
        head_= newNode;
        return;
    }
    Node* curr = head_;
    while(curr->next != nullptr){
        curr= curr->next;
        //update it want it loop to the end of the value 
    }
    
    curr->next=newNode;
    
}

// TODO -- Task C: bool LinkedList::insertAt(int pos, int value)
// Insert value so that it ends up at index pos (0-based). Inserting at
// pos == size() appends. Return false and change nothing if pos is
// negative or greater than size().
bool LinkedList::insertAt(int pos, int value) {
    if(pos<0 ||pos>size()){
        return false;
    }
    Node* newNode = new Node{value,head_};
    if(pos==0){
       
        head_=newNode;
        return true;
    }

    Node* newNode2 = new Node{value,nullptr};
    if(pos==size()){
        
        Node* curr = head_;
        while(curr->next != nullptr){
        curr= curr->next;
        //update it want it loop to the end of the value 
        }
        curr->next=newNode2;
        return true;
    }
    Node* curr =head_;
    int index= 0;
    Node* newNode3 = new Node{value,nullptr};
    if(pos>0 && pos<size()){
        while(index<pos-1){
            curr= curr->next;
            index++;
    }
        newNode3->next = curr->next;
// connect the newNode->next with rest of the currt 
        curr->next = newNode3;
// now assign the 

        return true;
    }
    return false;
    


}

// TODO -- Task D: bool LinkedList::removeValue(int target)
// Remove the FIRST node whose data equals target and free it. Return
// false if the value is not in the list.
bool LinkedList::removeValue(int target) {
    Node*curr = head_;
    Node*prev = nullptr; 
    while(curr!=nullptr ){
        if(curr->data ==target){
            // remove the first node whoese data equals to target 
            if(prev==nullptr){
                head_= curr->next;
                delete curr;
                return true;
            }
            else{
            // curr is not the first node 
                prev->next = curr->next;
                delete curr;
                return true;
            }
        }
        prev=curr;
        curr = curr->next;
    }
    return false;  
    // since there have no target value from the head_ , return false 

}

// TODO -- Task E: void LinkedList::reverse()
// Reverse the list IN PLACE -- no new nodes, no deleted nodes.
void LinkedList::reverse() {
    Node* prev= nullptr;
    Node* curr= head_
    while(curr!=nullptr){
        Node*  succ= curr->next;
        curr -> next = prev;
        prev = curr;
        curr= succ;
    }
    head= prev;
}


bool LinkedList::removeAt(int pos){
// Remove the node at index pos. Return false if pos is out of range.
// --------------------------------------------------------------
}
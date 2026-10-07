// File name: MiniVector.tpp  (submit this file, renamed if needed, to Gradescope)
// Name: shuyu lin
// Email:ShuYu.Lin64@login.cuny.edu
//
// CSCI 235 -- Project 1B: MiniVector (template)
// Hunter College, CUNY | Fall 2026

//
// This file is a .tpp, not a .cpp, because MiniVector is now a template:
// the compiler needs to see a template function's full body at the point
// where it is used, for whatever type T that use asks for. MiniVector.hpp
// already #includes this file at the bottom, so you never #include
// MiniVector.tpp yourself, and you never compile it directly -- just
// implement the TODOs here exactly as you would in a .cpp file.
//
// Compile (with MiniVectorTest.cpp, which is provided and already runs a
// battery of self-checks):
//   g++ -std=c++17 -Wall -Wextra -pedantic MiniVectorTest.cpp Rectangle.cpp -o MiniVectorTest
// Tests may fail or terminate with a runtime memory error until the
// corresponding and prerequisite TODO sections are completed. Complete the
// tasks in order:
//   Task A, then Task B, then Task C, then Task D.

#include <stdexcept>
#include <string>   // std::to_string, for at()'s exception message

// ============================================================
// Task A -- Construction and destruction
// ============================================================

// TODO (Task A): Default constructor.
// Allocate data_ as a new array of capacity 2, with every element
// value-initialized. Use `new T[2]{}` so built-in types such as int
// are initialized to zero; class types invoke their default constructor.
// size_ = 0, capacity_ = 2.
template <typename T>
MiniVector<T>::MiniVector() {
  data_ = new T[2]{}; 
  // creat 2 new memory with defalt type T on the heap and initialize them 
  //{}the memory may exit but no indeteminate value 
  size_ = 0;
  capacity_ = 2;          // placeholder -- replace with 2
}

// TODO (Task A): Count constructor.
// from defalt constructor is for count 
template <typename T>
MiniVector<T>::MiniVector(std::size_t count) {
    data_= new T[count]{};
   // initializing it and allocate how many count for the room size?
   if(count==0){
    size_ = 0;
    capacity_ = 2; //<- follow by defalt constructor
   }else{
    size_=count;
    capacity_=count;
   }
   // if the count == 0 then we don't allocate the space else we allocate the space as count
}

// TODO (Task A): Destructor.
// free the allocated memory ~ 
template <typename T>
MiniVector<T>::~MiniVector() {
  delete[] data_;
}

// ============================================================
// PROVIDED -- study these, you do not need to change them.
// ============================================================

// Unchecked element access. Out-of-range pos is undefined behavior,
// exactly like std::vector::operator[].
template <typename T>
T& MiniVector<T>::operator[](std::size_t pos) {
  return data_[pos];
}

template <typename T>
const T& MiniVector<T>::operator[](std::size_t pos) const {
  return data_[pos];
}

template <typename T>
bool MiniVector<T>::empty() const {
  return size_ == 0;
}

template <typename T>
std::size_t MiniVector<T>::size() const {
  return size_;
}

template <typename T>
std::size_t MiniVector<T>::capacity() const {
  return capacity_;
}

// ============================================================
// Task B -- Growth and capacity
// ============================================================

// TODO (Task B): Ensure capacity for at least newCapacity elements.
/*
if(old capacity is smaller than new then we grow)
allocate a new array 
copy the old to the new 
delet[] the old
assign the data_to new , also update the capacity since the space grown
*/

template <typename T>
void MiniVector<T>::reserve(std::size_t newCapacity) {

    if(newCapacity>capacity_){
        T*temp= new T[newCapacity];
        for(std::size_t i=0; i<size_; i++){
             temp[i] = data_[i]; 
        }
        delete[] data_; 
        data_=temp;
        capacity_=newCapacity;
    }    
}

// TODO (Task B): Append element at the end.
/*
we need to check the space first, if space size == space -> grow space
else push back the data

*/
template <typename T>
void MiniVector<T>::push_back(T element) {
    if(size_==capacity_){
        reserve(2*capacity_);
        //double capacity everytime we push when there is not enought space
    }
    data_[size_] = element;
    size_++;

  // TODO
}

// ============================================================
// Task C -- Removal and checked access
// ============================================================

// TODO (Task C): Bounds-checked element access.
// If pos >= size_, throw std::out_of_range with a helpful message.
// Otherwise, behave exactly like operator[].
template <typename T>
T& MiniVector<T>::at(std::size_t pos) {
  if(pos>=size_){
    throw std::out_of_range("index out of range");
    // throw-> stop excution
    // out_of_ range // reason and readable string 
  }
  return data_[pos];  
}

template <typename T>
// what we do here is for read~
const T& MiniVector<T>::at(std::size_t pos) const {
    if(pos>=size_){
        throw std::out_of_range("index out of range");
    }
    return data_[pos];
}

// TODO (Task C): Remove the last element.
// pop_ back just remove last element, and this function we just decrement 1;
// why we don't delect[] the last element? since it's a pointer , and it points to whole dynamic allocated array

template <typename T>
void MiniVector<T>::pop_back() {
    size_--;
}
// after we call pop_back, if minivector have 10 20 30, i=decrement 1 make 30 invalide
// even 30 still there but we won't reach that 


// TODO (Task C): Remove all elements.
template <typename T>
void MiniVector<T>::clear() {
  size_=0;
}
// size_=0 make all the element inactive 

// ============================================================
// Task D -- Rule of Three (copy constructor & copy assignment)
// ============================================================

// TODO (Task D): Copy constructor.


template <typename T>
// destination MiniVector
MiniVector<T>::MiniVector(const MiniVector& other) {
    T* temp = new T [other.capacity_]; // creat new memory 
    // other source
    // this,  desination 
    // when we put data_, size_ , capacity _ it's from new 
    std::size_t index = 0;
    while(other.size_>index){
        temp[index] = other.data_[index];
        index++;
    }
    data_ = temp;
    // we don't need to delect temp here since we copy from other and and temp is this 
    // we just assign the temp pointing to the data we don't need to delect anything here
    size_ = index;
    capacity_ = other.capacity_;
}
        
    
    


// TODO (Task D): Copy-assignment operator.
template <typename T>
MiniVector<T>& MiniVector<T>::operator=(const MiniVector& other){
    std::size_t index = 0;
    // we created destination other from last function
    // here , deep copy 
    // free the destination
    // this address of current object
    //*this onject itself
    if(this == & other){// address compare with the adress 
        return *this; // make sure that this is not pothing to another //
        // if it dose return it immedialy  *this is dereferrence
    }
    T* temp= new T [other.capacity_];
    while(other.size_>index){
        temp[index]=other.data_[index];// other is an minivector we need to point to it's vector
        index++;
    }
    delete[]this->data_;// delect destination memory
    this-> data_ = temp; // update
    size_=index;
    capacity_=other.capacity_;
    return *this;
    // no matter what we have to return this vector objecy ~
}
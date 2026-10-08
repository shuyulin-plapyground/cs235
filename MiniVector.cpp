#include "MiniVector.hpp"

#include <stdexcept>
MiniVector::MiniVector(){
    size_= 0;
    capacity_=2;
// constructor , when set capacity have two room and the begining and size is 0 means the array is fresh 
}
MiniVector:: MiniVector(std::size_t count){
    capacity_= (count>0?count:2); // set capacity before using the arr
    size_=(count);
    data_=(new int [capacity_]{});
    // since here we use [] when we free the arr we need to delete[]
    

}
MiniVector::~MiniVector(){
    // realse the heap array owned by it's vector . nothing else is needed
    delete[] data_;

}
MiniVector:: MiniVector(const MiniVector& other):
data_(new int[other.capacity()]),// allocate capacity as data with in type int to make sure we have enought space to copy into it
size_(other.size()),
capacity_(other.capacity())
{  
    for(std::size_t i=0; i<size_;i++){
        data_[i]=other.data_[i];
        // copy element 
    }

}
MiniVector & MiniVector::operator=(const MiniVector& other){
    // gard .
    if(this == &other){
        return *this;
        //assigning to myself
        //For efficiency. Without the guard, self-assignment is still correct, but it
        //performs an unnecessary O(n) allocate/copy/free operation.
    }
    // allocate . copy
    data_=new int[other.capacity_];
    for(std:: size_t i=0; i<other.size_;i++){
        data_[i]=other.data_[i];
    }

    size_=other.size_;
    capacity_=other.capacity_;
    //free the old , point the update
    delete[] data_;
    return *this;

}
int& MiniVector::operator[](std::size_t idx){
    return data_[idx];
}
const int& MiniVector:: operator[](std::size_t idx) const{
    return data_[idx];
}

    // TODO (Task C): Bounds-checked element access.
    // Throw std::out_of_range if idx >= size(). Otherwise behaves like
    // operator[].
    int& MiniVector::at(std::size_t idx){
        if(idx>=size_){
            throw std::out_of_range("index too big");
        }
        return data_[idx];
    }
    const int& MiniVector::at(std::size_t idx) const{
        if(idx>=size_){
            throw std::out_of_range("index too big");
        }
        return data_[idx];
    }

    // TODO (Task B): Ensure capacity for at least newCapacity elements.
    // If newCapacity > capacity(), allocate a new array of exactly
    // newCapacity elements, copy the existing size() elements into it, and
    // free the old array. If newCapacity <= capacity(), do nothing:
    // reserve() never shrinks the vector, and never changes size().
void MiniVector::reserve(std::size_t newCapacity){
    if(newCapacity<=capacity_){
        return;
    }
        int* newData =new int [newCapacity];
        for(std::size_t i=0;i<size_;i++){
            newData[i]=data_[i];
        }
        delete[] data_;
        data_ = newData;
        capacity_=newCapacity;
    

        
    }


    // TODO (Task B): Append value at the end.
    // If size() == capacity(), first call reserve(2 * capacity()) to make
    // room -- reserve() already contains the allocate/copy/free logic, so
    // push_back() should not duplicate it. Then store value at the end and
    // increase size() by one.
    void MiniVector::push_back(int value){
        if(size_==capacity_){
            reserve(2*capacity_);
        }
        data_[size_] = data_[value];
        size_++;
    }
    // TODO (Task C): Remove the last element.
    // Precondition: !empty(). Like std::vector::pop_back(), calling this
    // on an empty MiniVector is undefined behavior -- do not add a check,
    // and do not throw. Must not change capacity().
    void MiniVector::pop_back(){
        size_--;
    }

    // TODO (Task C): Remove all elements.
    // Set size() to 0. Unlike pop_back(), clear() has no precondition --
    // calling it on an already-empty MiniVector is perfectly safe. The
    // allocated storage remains available for reuse: clear() changes only
    // size(), and must not modify capacity() or the underlying array.
    void MiniVector::clear(){
        size_=0;
    }

    // One-line implementations in terms of size_ and capacity_. Not
    // separately graded, but needed by every task below.
    bool MiniVector::empty() const{
        return size_==0;
    }
    std::size_t MiniVector::size() const{
        return size_;
    }
    std::size_t MiniVector:: capacity() const{
        return capacity_;
    }
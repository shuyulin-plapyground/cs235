#include "MiniVector.hpp"
MiniVector::MiniVector(){
    size_= 0;
    capacity_=2;
// constructor , when set capacity have two room and the begining and size is 0 means the array is fresh 
}
MiniVector:: MiniVector(std::size_t count){
    capacity_= (count>0?count:2); // set capacity before using the arr
    size_=(count);
    data_=(new int [capacity]{});
    // since here we use [] when we free the arr we need to delete[]
    

}
MiniVector::~MiniVector(){
    // realse the heap array owned by it's vector . nothing else is needed
    delete[] data_;

}
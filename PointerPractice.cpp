#include "PointerPractice.hpp"
#include <cstddef>
TaskAAnswers taskA_pointerExpressions(int arr[]){
    int *p =arr;
    // p recieves the address stored by arr 
    TaskAAnswers answer{};
    //both expression in each pair access the same integer
    answer.starArr = *arr;
    // follow arr to it's first elememt 
    // retrieve the value 10 
    // store 10 in the box name starArr
    answer.arrBracket0 = arr[0];
    // storage {10,20,30}, 10 into the bucket 0
    answer.starArrPlus1 = *(arr+1);
    // storage value 20
    answer.arrBracket1 =arr[1];
    // storage value of 20
    answer.arrPlus1 = arr+1;
    // storage as address of value 20;
    answer.addrArrBracket1 = &arr[1];
    answer.starP = *p;
    answer.pBracket0 = p[0];
    answer.starPPlus2 = *(p+2);
    answer.pBracket2 = p[2];

    answer.arrPlus1EqualsAddrArrBracket1 = (arr+1 == &arr[1]);
    // arr+ 1 is an address
    answer.starArrPlus2EqualsArrBracket2= (*(arr+2) == arr[2]);
    // *(...) is an value



    
    return answer;
}
int* allocate(std::size_t size){
    // return type is int* so the function should return a pointer not a value 
    int* data = new int[size]{};
    // data store an address
    // new int[size] creates an array of size integers
    //{}initialized every integer to zero
    // int* data storage adress of  what we creat from the right side to the left side;
    return data;
// the caller will free the dynamic arr after using it/

}
// test c 
int* lastMinimum(int* arr, std::size_t size){
    if(size==0){
        return nullptr;
    }
    int* lastMin = arr;
    int* current = arr+1;
    int* end = arr+size;
// it containing the address
    while(current<end){// we always loop by the location 
        
        if(*current<= *lastMin){
        // now access the value throught the ponter's address and comparing them 
            lastMin = current;
        }
        current++;
    }
    return lastMin;
}
// task D 
void reverse(int* arr,std::size_t size){
    if(size<2){
        return;
        // since it's void function. this return just stop the function

    }
    int* left = arr;
    int* right = arr +size-1;
    while(left < right){
        int temporary = *left;
        *left = *right;
        *right = temporary;
        left++;
        right--;
    }

}
//task E
void swapValues(int* a, int* b){
    // storage address of the integer 
    int temporary = *a;
    //* get the value of the address of int
    *a = *b;
    *b=temporary;
    
}
void swapPointers(int**a ,int**b){
// int** storage address of the pointer that storage the address
    int * temporary = *a;
    // address template ,  *a right now is a address 
    *a=*b;
    *b= temporary;

}
bool isPalindrome(const int* arr, std::size_t size) {
    // arr promises that integer will be read only const int* not able to modify 
    
    const int* left =0;
    const int* right =arr+size -1;
    while(left<right){
        if(arr[*left]!=arr[*right]){
            return false;
        }    
        left++;
        right--;
    }
    return true;
}
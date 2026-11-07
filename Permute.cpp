// Permute.cpp
// CSCI 235 -- Exercise 7: Permutations
// Complete the four functions below by finishing the TODO sections.
// Submit this file (and only this file) to Gradescope.

#include "Permute.hpp"

#include <utility>   // std::swap

// Task A
long long factorial(int n) {

    if(!(n>=0 && n<=20)){
        throw std:: out_of_range ("must between 0 and 20");
        // or -1 as false 
        
    }
    // 0! = 1
    if(n == 0){
        return 1;
    }
    
    return n * factorial(n-1);
    
}

// Task B
void permute(std::vector<int>& v, std::size_t k,
             std::vector<std::vector<int>>& out) {
// the k pass by 0 everytime after the recursion k+1
// set the base case k!=v,size
    if(k==v.size()){
        out.push_back(v);
        return;
    }
    for(std::size_t i=k ; i<v.size();++i){

        std::swap(v[i],v[k]);//choose
        permute(v,k+1,out);//recurse 
        std::swap(v[i],v[k]);//undo
    }
}

// Task C
std::vector<std::vector<int>> allPermutations(std::vector<int> v) {
    std::vector<std::vector<int>> result;
    permute(v,0,result);
    return result;

}

// Task D
int countDerangements(std::vector<int>& v, const std::vector<int>& original,
                      std::size_t k) {
    // pruning means stopping a branch as soon as it won't have valid answer
    int count =0;
    if(k==v.size()){
        return 1;
    }
    for(std::size_t i=k; i<v.size();++i){
        std::swap(v[i],v[k]);
        if(v[k]!=original[k]){
        // swap change the position k , when i = 1, k= 0 , it swap v[k]!= orginal [k] . enter the recuersive loop 
            count = count + countDerangements(v,original,k+1);
            
        }
        std::swap(v[i],v[k]);
    }
    return count;
}

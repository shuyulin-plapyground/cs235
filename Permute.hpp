// Permute.hpp
// CSCI 235 -- Exercise 7: Permutations
// Provided file -- do not modify. Gradescope compiles your submission
// against the original version of this file.

#ifndef PERMUTE_HPP
#define PERMUTE_HPP

#include <cstddef>
#include <vector>


long long factorial(int n);


void permute(std::vector<int>& v, std::size_t k,
             std::vector<std::vector<int>>& out);

std::vector<std::vector<int>> allPermutations(std::vector<int> v);


int countDerangements(std::vector<int>& v, const std::vector<int>& original,
                      std::size_t k);

#endif
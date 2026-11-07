// Ex7Demo.cpp
// CSCI 235 -- Exercise 7: Permutations
//
// Provided file -- do not submit this. Build it with:
//
//     g++ -std=c++17 -g Permute.cpp Ex7Demo.cpp -o ex7demo
//     ./ex7demo
//
// The expected output is in demo_output.txt. Your output should match it
// exactly once all four tasks are done.

#include "Permute.hpp"

#include <iostream>
#include <vector>

static void print(const std::vector<int>& v) {
    std::cout << "(";
    for (std::size_t i = 0; i < v.size(); ++i) {
        std::cout << (i ? " " : "") << v[i];
    }
    std::cout << ")";
}

int main() {
    std::cout << "=== Task A: factorial ===\n";
    for (int n : {0, 1, 2, 3, 4, 5, 10}) {
        std::cout << "  " << n << "! = " << factorial(n) << "\n";
    }

    std::cout << "\n=== Task B: permute ===\n";
    std::vector<int> v{1, 2, 3};
    std::vector<std::vector<int>> out;
    permute(v, 0, out);
    for (const auto& p : out) {
        std::cout << "  ";
        print(p);
        std::cout << "\n";
    }
    std::cout << "  v afterwards: ";
    print(v);
    std::cout << "   (must equal the original)\n";

    std::cout << "\n=== Task C: allPermutations ===\n";
    std::vector<int> w{5, 6, 7, 8};
    auto all = allPermutations(w);
    std::cout << "  " << all.size() << " permutations of ";
    print(w);
    std::cout << "\n  first: ";
    print(all.front());
    std::cout << "\n  last:  ";
    print(all.back());
    std::cout << "\n  w unchanged: ";
    print(w);
    std::cout << "\n";

    std::cout << "\n=== Task D: countDerangements ===\n";
    for (int n = 0; n <= 5; ++n) {
        std::vector<int> base;
        for (int i = 0; i < n; ++i) {
            base.push_back(10 * (i + 1));
        }
        std::vector<int> work = base;
        std::cout << "  " << n << " values: "
                  << countDerangements(work, base, 0) << "\n";
    }
    return 0;
}
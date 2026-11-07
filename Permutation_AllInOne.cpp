// Permutation_AllInOne.cpp
// Convenience copy combining Permute.hpp, Permute.cpp, and Ex7Demo.cpp.
// The Exercise 7 handout says to submit Permute.cpp only; keep the original
// assignment files separate for Gradescope.

#include <cstddef>
#include <iostream>
#include <stdexcept>
#include <utility>
#include <vector>

// Declarations from Permute.hpp
long long factorial(int n);

void permute(std::vector<int>& v, std::size_t k,
             std::vector<std::vector<int>>& out);

std::vector<std::vector<int>> allPermutations(std::vector<int> v);

int countDerangements(std::vector<int>& v, const std::vector<int>& original,
                      std::size_t k);

// Implementations from Permute.cpp

// Task A
long long factorial(int n) {
    if (!(n >= 0 && n <= 20)) {
        throw std::out_of_range("must between 0 and 20");
    }
    // 0! = 1
    if (n == 0) {
        return 1;
    }
    return n * factorial(n - 1);
}

// Task B
void permute(std::vector<int>& v, std::size_t k,
             std::vector<std::vector<int>>& out) {
    if (k == v.size()) {
        out.push_back(v);
        return;
    }
    for (std::size_t i = k; i < v.size(); ++i) {
        std::swap(v[i], v[k]); // choose
        permute(v, k + 1, out); // recurse
        std::swap(v[i], v[k]); // undo
    }
}

// Task C
std::vector<std::vector<int>> allPermutations(std::vector<int> v) {
    std::vector<std::vector<int>> result;
    permute(v, 0, result);
    return result;
}

// Task D
int countDerangements(std::vector<int>& v, const std::vector<int>& original,
                      std::size_t k) {
    int count = 0;
    if (k == v.size()) {
        return 1;
    }
    for (std::size_t i = k; i < v.size(); ++i) {
        std::swap(v[i], v[k]);
        if (v[k] != original[k]) {
            count = count + countDerangements(v, original, k + 1);
        }
        std::swap(v[i], v[k]);
    }
    return count;
}

// Demo code from Ex7Demo.cpp
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
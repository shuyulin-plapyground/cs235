// PointerPracticeDemo.cpp
// CSCI 235 -- Exercise 2: Pointer Practice
//
// A small driver so you can compile and run your PointerPractice.cpp
// locally and see it in action before submitting. This file is
// PROVIDED for your own testing -- you do NOT submit it, and Gradescope
// does not use it; Gradescope has its own, more thorough checks.
//
// Compile and run with:
//   g++ -std=c++17 PointerPractice.cpp PointerPracticeDemo.cpp -o demo
//   ./demo

#include <iostream>

#include "PointerPractice.hpp"

int main() {
    std::cout << "=== Task A: pointer expressions ===\n";
    int arr[] = {10, 20, 30, 40};
    TaskAAnswers ans = taskA_pointerExpressions(arr);
    std::cout << "*arr = " << ans.starArr << "   (expect 10)\n";
    std::cout << "arr[0] = " << ans.arrBracket0 << "   (expect 10)\n";
    std::cout << "*(arr + 1) = " << ans.starArrPlus1 << "   (expect 20)\n";
    std::cout << "arr[1] = " << ans.arrBracket1 << "   (expect 20)\n";
    std::cout << "arr + 1 == &arr[1]? " << (ans.arrPlus1EqualsAddrArrBracket1 ? "true" : "false")
              << "   (expect true)\n";
    std::cout << "*p = " << ans.starP << "   (expect 10)\n";
    std::cout << "p[2] = " << ans.pBracket2 << "   (expect 30)\n";
    std::cout << "*(arr + 2) == arr[2]? "
              << (ans.starArrPlus2EqualsArrBracket2 ? "true" : "false") << "   (expect true)\n";

    std::cout << "\n=== Task B: allocate ===\n";
    int* dyn = allocate(5);
    std::cout << "dyn == nullptr? " << (dyn == nullptr ? "true" : "false")
              << "   (expect false)\n";
    if (dyn != nullptr) {
        std::cout << "dyn[0..4] = ";
        for (int i = 0; i < 5; ++i) std::cout << dyn[i] << " ";
        std::cout << "  (expect 0 0 0 0 0)\n";
    }
    delete[] dyn;

    std::cout << "\n=== Task C: lastMinimum ===\n";
    int c[] = {4, 2, 7, 2, 5};
    int* m = lastMinimum(c, 5);
    std::cout << "min value = " << (m != nullptr ? *m : -1) << "   (expect 2)\n";
    std::cout << "index of that pointer into c = "
              << (m != nullptr ? (m - c) : -1) << "   (expect 3, the LAST 2)\n";

    std::cout << "\n=== Task D: reverse ===\n";
    int d[] = {1, 2, 3, 4, 5};
    reverse(d, 5);
    std::cout << "reversed: ";
    for (int i = 0; i < 5; ++i) std::cout << d[i] << " ";
    std::cout << "  (expect 5 4 3 2 1)\n";

    std::cout << "\n=== Task E: swapValues vs. swapPointers ===\n";
    int x = 10, y = 20;
    int* p = &x;
    int* q = &y;
    swapValues(p, q);
    std::cout << "after swapValues: x = " << x << ", y = " << y << "   (expect x=20, y=10)\n";

    int x2 = 10, y2 = 20;
    int* p2 = &x2;
    int* q2 = &y2;
    swapPointers(&p2, &q2);
    std::cout << "after swapPointers: *p2 = " << *p2 << ", *q2 = " << *q2
              << "   (expect *p2=20, *q2=10 -- p2 and q2 traded places)\n";

    std::cout << "\n=== Task F (optional): isPalindrome ===\n";
    int f1[] = {1, 2, 3, 2, 1};
    int f2[] = {1, 2, 3};
    std::cout << "isPalindrome({1,2,3,2,1}) = " << (isPalindrome(f1, 5) ? "true" : "false")
              << "   (expect true)\n";
    std::cout << "isPalindrome({1,2,3}) = " << (isPalindrome(f2, 3) ? "true" : "false")
              << "   (expect false)\n";

    return 0;
}

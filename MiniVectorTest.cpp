// File name: MiniVectorTest.cpp  (PROVIDED -- do not modify, do not submit)
//
// CSCI 235 -- Project 1A: MiniVector (int)
// Hunter College, CUNY | Fall 2026
//
// A self-check harness covering Tasks A-D, one task per run. Passing every
// test in a task group is necessary but not sufficient for full credit --
// the Gradescope autograder checks additional cases (different numbers,
// more edge cases) that you have not seen.
//
// Tests may fail or terminate with a runtime memory error until the
// corresponding and prerequisite functions in your MiniVector.cpp are
// implemented -- that is expected, not a bug in this file. Run only the
// task group you are currently implementing, and complete the tasks in
// order.
//
// Compile:
//   g++ -std=c++17 -Wall -Wextra -o MiniVectorTest MiniVectorTest.cpp MiniVector.cpp
// Run one task at a time:
//   ./MiniVectorTest A   # constructors and destructor
//   ./MiniVectorTest B   # push_back, reserve, and growth
//   ./MiniVectorTest C   # pop_back, clear, and at
//   ./MiniVectorTest D   # Rule of Three

#include "MiniVector.hpp"
#include <iostream>
#include <string>
#include <stdexcept>

static int g_pass = 0;
static int g_total = 0;

template <typename T>
static void chk(const std::string& label, T actual, T expected) {
    ++g_total;
    if (actual == expected) { ++g_pass; return; }
    std::cout << "FAIL: " << label << " -- expected " << expected
              << ", got " << actual << "\n";
}

template <typename F>
static void chk_throws_out_of_range(const std::string& label, F&& fn) {
    ++g_total;
    try {
        fn();
        std::cout << "FAIL: " << label
                  << " -- expected std::out_of_range, but nothing was thrown\n";
    } catch (const std::out_of_range&) {
        ++g_pass;
    } catch (...) {
        std::cout << "FAIL: " << label
                  << " -- threw, but not std::out_of_range\n";
    }
}

static void print_result(const std::string& taskLabel) {
    if (g_pass == g_total)
        std::cout << "Task " << taskLabel << ": all " << g_total << " tests passed.\n";
    else
        std::cout << "Task " << taskLabel << ": " << g_pass << "/" << g_total
                  << " tests passed.\n";
}

// ── Task A: Construction and destruction (9 tests) ───────────────────────────────
static void testTaskA() {
    MiniVector v;
    chk<std::size_t>("default ctor: size()", v.size(), 0);
    chk<std::size_t>("default ctor: capacity()", v.capacity(), 2);
    chk<bool>("default ctor: empty()", v.empty(), true);

    MiniVector w(5);
    chk<std::size_t>("count ctor(5): size()", w.size(), 5);
    chk<std::size_t>("count ctor(5): capacity()", w.capacity(), 5);
    chk<int>("count ctor(5): w[0] == 0", w[0], 0);
    chk<int>("count ctor(5): w[4] == 0", w[4], 0);

    MiniVector z(0);
    chk<std::size_t>("count ctor(0): capacity() == 2", z.capacity(), 2);
    chk<bool>("count ctor(0): empty()", z.empty(), true);

    print_result("A");
}

// ── Task B: Growth and capacity (30 tests) ──────────────────────────────────
static void testTaskB() {
    MiniVector v;
    std::size_t expectedCapacities[] = {2, 2, 4, 4, 8, 8, 8, 8};
    for (int i = 0; i < 8; ++i) {
        v.push_back((i + 1) * 10);
        chk<std::size_t>("push_back #" + std::to_string(i + 1) + ": size()",
                    v.size(), static_cast<std::size_t>(i + 1));
        chk<std::size_t>("push_back #" + std::to_string(i + 1) + ": capacity()",
                    v.capacity(), expectedCapacities[i]);
    }
    for (int i = 0; i < 8; ++i) {
        chk<int>("push_back: v[" + std::to_string(i) + "] preserved",
                 v[i], (i + 1) * 10);
    }

    // reserve(): growing capacity manually, elements preserved (4)
    MiniVector r;
    r.push_back(1);
    r.push_back(2);
    r.reserve(10);
    chk<std::size_t>("reserve(10): capacity() becomes 10", r.capacity(), 10);
    chk<std::size_t>("reserve(10): size() unchanged", r.size(), 2);
    chk<int>("reserve(10): r[0] preserved", r[0], 1);
    chk<int>("reserve(10): r[1] preserved", r[1], 2);

    // reserve() never shrinks capacity (1)
    r.reserve(1);
    chk<std::size_t>("reserve(1) < capacity(): capacity() unchanged", r.capacity(), 10);

    // reserve() requesting less than the starting capacity is a no-op (1)
    MiniVector s;
    s.reserve(0);
    chk<std::size_t>("reserve(0): capacity() unchanged (still 2)", s.capacity(), 2);

    print_result("B");
}

// ── Task C: Removal and checked access (15 tests) ───────────────────────────
static void testTaskC() {
    MiniVector v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    chk<int>("at(1) valid index", v.at(1), 20);
    chk_throws_out_of_range("at(3) == size(), out of range", [&]() { v.at(3); });
    chk_throws_out_of_range("at(100) far out of range", [&]() { v.at(100); });

    MiniVector empty;
    chk_throws_out_of_range("at(0) on empty vector", [&]() { empty.at(0); });

    const MiniVector cv(3);
    chk<int>("const at(1)", cv.at(1), 0);

    std::size_t capBefore = v.capacity();
    v.pop_back();
    chk<std::size_t>("pop_back: size() decreases by 1", v.size(), 2);
    chk<std::size_t>("pop_back: capacity() unchanged", v.capacity(), capBefore);
    chk<int>("pop_back: v[0] unchanged", v[0], 10);
    chk<int>("pop_back: v[1] unchanged", v[1], 20);

    // clear(): removes all elements without touching capacity (3)
    MiniVector c;
    c.push_back(1); c.push_back(2); c.push_back(3);
    std::size_t capBeforeClear = c.capacity();
    c.clear();
    chk<std::size_t>("clear(): size() becomes 0", c.size(), 0);
    chk<std::size_t>("clear(): capacity() unchanged", c.capacity(), capBeforeClear);
    chk<bool>("clear(): empty() becomes true", c.empty(), true);

    // clear() on an already-empty vector is a safe no-op (1)
    MiniVector d;
    d.clear();
    chk<bool>("clear() on empty vector: still empty()", d.empty(), true);

    // Previously occupied storage can be reused correctly after clear() (2)
    c.push_back(99);
    chk<int>("clear() then push_back: c[0] reused", c[0], 99);
    chk<std::size_t>("clear() then push_back: size() == 1", c.size(), 1);

    print_result("C");
}

// ── Task D: Rule of Three (29 tests) ────────────────────────────────────────
static void testTaskD() {
    MiniVector a;
    a.push_back(10);
    a.push_back(20);
    a.push_back(30);

    // Copy constructor: size, capacity, elements 0-2, allocated storage (6)
    MiniVector b(a);
    chk<std::size_t>("copy ctor: size()", b.size(), 3);
    chk<std::size_t>("copy ctor: capacity()", b.capacity(), a.capacity());
    chk<int>("copy ctor: b[0]", b[0], 10);
    chk<int>("copy ctor: b[1]", b[1], 20);
    chk<int>("copy ctor: b[2]", b[2], 30);
    b.push_back(40);
    chk<int>("copy ctor: allocated storage matches copied capacity", b[3], 40);

    // Copy-constructor independence, both directions (2)
    b[0] = 999;
    chk<int>("copy ctor: independence, a[0] unaffected", a[0], 10);
    a[1] = 888;
    chk<int>("copy ctor: independence, b[1] unaffected", b[1], 20);
    a[1] = 20;  // restore for the assignment tests below

    // Assignment: size, capacity, elements 0-2, allocated storage (6)
    MiniVector destination;
    destination = a;
    chk<std::size_t>("assign: size copied", destination.size(), 3);
    chk<std::size_t>("assign: capacity copied", destination.capacity(), a.capacity());
    chk<int>("assign: element 0 copied", destination[0], 10);
    chk<int>("assign: element 1 copied", destination[1], 20);
    chk<int>("assign: element 2 copied", destination[2], 30);
    destination.push_back(40);
    chk<int>("assignment: allocated storage matches copied capacity", destination[3], 40);

    // Assignment independence, both directions (2)
    destination[1] = 999;
    chk<int>("assign: deep-copy independence (dest -> source)", a[1], 20);
    a[2] = 888;
    chk<int>("assign: deep-copy independence (source -> dest)", destination[2], 30);
    a[2] = 30;  // restore

    // Assignment into a larger destination: size, capacity, elements 0-2 (5)
    MiniVector large;
    for (int i = 0; i < 9; ++i) large.push_back(i);
    large = a;
    chk<std::size_t>("assign into larger destination: size()", large.size(), 3);
    chk<std::size_t>("assign into larger destination: capacity()", large.capacity(), a.capacity());
    chk<int>("assign into larger destination: large[0]", large[0], 10);
    chk<int>("assign into larger destination: large[1]", large[1], 20);
    chk<int>("assign into larger destination: large[2]", large[2], 30);

    // Assigning an empty source with capacity 2 into a destination with
    // capacity 10: empty, size, capacity actually replaced (3)
    MiniVector fromEmptySource;
    fromEmptySource.reserve(10);
    fromEmptySource.push_back(1);
    MiniVector emptySrc;
    fromEmptySource = emptySrc;
    chk<bool>("assign from empty: empty()", fromEmptySource.empty(), true);
    chk<std::size_t>("assign from empty: size()", fromEmptySource.size(), 0);
    chk<std::size_t>("assign from empty: capacity() == 2", fromEmptySource.capacity(), 2);

    // Self-assignment: size, capacity, elements unchanged (5)
    MiniVector self;
    self.push_back(10); self.push_back(20); self.push_back(30);
    std::size_t selfCapBefore = self.capacity();
    self = self;
    chk<std::size_t>("self-assignment: size() unchanged", self.size(), 3);
    chk<std::size_t>("self-assignment: capacity() unchanged", self.capacity(), selfCapBefore);
    chk<int>("self-assignment: self[0] unchanged", self[0], 10);
    chk<int>("self-assignment: self[1] unchanged", self[1], 20);
    chk<int>("self-assignment: self[2] unchanged", self[2], 30);

    print_result("D");
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " [A|B|C|D]\n";
        return 1;
    }
    const std::string task(argv[1]);

    if (task == "A") testTaskA();
    else if (task == "B") testTaskB();
    else if (task == "C") testTaskC();
    else if (task == "D") testTaskD();
    else {
        std::cerr << "Task must be A, B, C, or D.\n";
        return 1;
    }
    return 0;
}

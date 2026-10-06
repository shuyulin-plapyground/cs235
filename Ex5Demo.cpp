// Ex5Demo.cpp
// CSCI 235 -- Exercise 5: Stacks and Queues
//
// Provided file -- do not submit this. It is here so you can run your own
// code and see what it does. Build it with:
//
//     g++ -std=c++17 -g Stack.cpp Queue.cpp Ex5Demo.cpp -o ex5demo
//     ./ex5demo
//
// The expected output is in demo_output.txt. Your output should match it
// exactly once all five graded tasks are done.

#include "Stack.hpp"
#include "Queue.hpp"

#include <iomanip>
#include <iostream>
#include <string>

// every label is printed in the same 14-character column
static void label(const std::string& text) {
    std::cout << "  " << std::left << std::setw(14) << text << " : ";
}

static void show(const std::string& text, const Stack& s) {
    label(text);
    std::cout << s.toString() << "   (size " << s.size() << ")\n";
}

static void show(const std::string& text, const Queue& q) {
    label(text);
    std::cout << q.toString() << "   (size " << q.size() << ")\n";
}

int main() {
    std::cout << "=== Task A: push ===\n";
    Stack s;
    show("new stack", s);
    s.push(10);
    s.push(20);
    s.push(30);
    show("push 10,20,30", s);
    std::cout << "  note the top is printed FIRST -- push() adds at the front\n";

    std::cout << "\n=== Task B: pop and top ===\n";
    label("top()");
    std::cout << s.top() << "\n";
    s.pop();
    show("after one pop", s);
    label("pop order");
    while (!s.empty()) {
        std::cout << s.top() << " ";
        s.pop();
    }
    std::cout << "\n";
    show("now", s);
    label("pop() on empty");
    std::cout << (s.pop() ? "true" : "false") << "\n";

    std::cout << "\n=== Task C: enqueue ===\n";
    Queue q;
    show("new queue", q);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    show("enq 10,20,30", q);
    std::cout << "  note the OLDEST is printed first -- enqueue() adds at the back\n";

    std::cout << "\n=== Task D: dequeue and front ===\n";
    label("front()");
    std::cout << q.front() << "\n";
    q.dequeue();
    show("after one deq", q);
    label("dequeue order");
    while (!q.empty()) {
        std::cout << q.front() << " ";
        q.dequeue();
    }
    std::cout << "\n";
    show("now", q);

    std::cout << "\n  -- the case Task D is really about --\n";
    q.enqueue(77);
    q.enqueue(88);
    show("refilled", q);
    std::cout << "  if this line is wrong, dequeue() did not reset back_\n";

    std::cout << "\n=== Task E: balanced ===\n";
    const std::string cases[] = {
        "", "()", "{[()]}", "()[]{}", "a(b)[c]",
        "([)]", "(()", "())", ")(", "{[}]",
        "int f(int a[]) { return a[0]; }"
    };
    for (const std::string& c : cases) {
        std::cout << "  " << (balanced(c) ? "balanced    " : "NOT balanced")
                  << "  \"" << c << "\"\n";
    }

    std::cout << "\n=== Task F (optional, not graded) ===\n";
    Queue r;
    for (int i = 1; i <= 5; ++i) {
        r.enqueue(i * 10);
    }
    show("before reverse", r);
    reverseQueue(r);
    show("after reverse", r);
    std::cout << "  (unchanged above means Task F is still empty -- that is fine)\n";

    return 0;
}
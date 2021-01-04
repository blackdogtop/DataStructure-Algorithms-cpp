#include <iostream>
#include <stack>
using namespace std;


class MinStack {
public:
    stack<int> xstack;
    stack<int> minStack;

    /** initialize your data structure here.
     * Complexity:
     *      time: O(1)
     *      space: O(n) */
    MinStack() {
        minStack.push(INT_MAX);
    }

    void push(int x) {
        xstack.push(x);
        minStack.push(min(x, minStack.top()));
    }

    void pop() {
        xstack.pop();
        minStack.pop();
    }

    int top() {
        return xstack.top();
    }

    int getMin() {
        return minStack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
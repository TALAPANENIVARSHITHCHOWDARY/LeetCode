#include <stack>
#include <limits.h>

class MinStack {
    std::stack<int> st;     // Primary stack to store all values
    std::stack<int> minSt;  // Auxiliary stack to store the minimum values

public:
    /** initialize your data structure here. */
    MinStack() {
        // No initialization needed as std::stack handles it
    }
    
    void push(int val) {
        st.push(val);
        if (minSt.empty() || val <= minSt.top()) {
            minSt.push(val);
        }
    }
    
    void pop() {
        if (!st.empty()) {
            if (st.top() == minSt.top()) {
                minSt.pop();
            }
            st.pop();
        }
    }
    
    int top() {
        if (!st.empty()) {
            return st.top();
        }
        return -1; // or throw an exception if preferred
    }
    
    int getMin() {
        if (!minSt.empty()) {
            return minSt.top();
        }
        return INT_MAX; // or throw an exception if preferred
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

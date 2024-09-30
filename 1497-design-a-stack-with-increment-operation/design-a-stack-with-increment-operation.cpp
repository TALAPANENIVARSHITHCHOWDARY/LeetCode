class CustomStack {
private:
    vector<int> stack;   // Vector to store the stack elements
    int maxSize;         // Maximum allowed size of the stack

public:
    // Constructor to initialize the stack with a maxSize
    CustomStack(int maxSize) {
        this->maxSize = maxSize;
    }

    // Pushes an element onto the stack if it's not full
    void push(int x) {
        if (stack.size() < maxSize) {
            stack.push_back(x);  // Add element to the end of the vector
        }
    }

    // Pops the top element from the stack and returns it, or returns -1 if the stack is empty
    int pop() {
        if (stack.empty()) {
            return -1;  // Stack is empty
        }
        int topElement = stack.back();  // Get the top element
        stack.pop_back();               // Remove the top element
        return topElement;
    }

    // Increments the bottom k elements by val. If there are fewer than k elements, increment all elements
    void increment(int k, int val) {
        int limit = min(k, (int)stack.size());  // Determine how many elements to increment
        for (int i = 0; i < limit; ++i) {
            stack[i] += val;  // Increment the element at index i
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */

class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;  // Use stack<char> to store characters
        for (char ch : s) {
            if (!st.empty() && st.top() == '(' && ch == ')') {
                st.pop();  // Matching pair found, pop the opening '('
            } else {
                st.push(ch);  // Otherwise, push the character onto the stack
            }
        }
        // The size of the stack will be the number of unbalanced parentheses
        return st.size();
    }
};

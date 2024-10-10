class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        // Stack to store indices in a decreasing order of values
        stack<int> st;
        
        // Step 1: Build the stack
        for (int i = 0; i < nums.size(); ++i) {
            if (st.empty() || nums[st.top()] > nums[i]) {
                st.push(i);
            }
        }

        int maxWidth = 0;
        
        // Step 2: Traverse from the end and calculate the max width ramp
        for (int j = nums.size() - 1; j >= 0; --j) {
            // Check if we can form a ramp with the current `j` and the top of the stack
            while (!st.empty() && nums[st.top()] <= nums[j]) {
                // Compute the width and update the maximum width
                maxWidth = max(maxWidth, j - st.top());
                st.pop();  // Remove the index from the stack as it's no longer useful
            }
        }
        
        return maxWidth;
    }
};

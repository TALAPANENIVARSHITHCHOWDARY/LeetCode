class Solution {
public:
    int minSwaps(string s) {
        int balance = 0, maxBalance = 0;
        
        // Traverse the string to calculate the imbalance
        for (char ch : s) {
            if (ch == '[') {
                // A matched opening bracket decreases imbalance
                balance++;
            } else {
                // A closing bracket without an opening bracket increases imbalance
                balance--;
            }
            
            // Track the maximum imbalance
            maxBalance = min(maxBalance, balance);
        }
        
        // The number of swaps needed is half the max imbalance (since one swap fixes two brackets)
        return (-maxBalance + 1) / 2;
    }
};

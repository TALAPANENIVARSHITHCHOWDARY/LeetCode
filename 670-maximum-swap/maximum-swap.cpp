class Solution {
public:
    int maximumSwap(int num) {
        // Convert the number to a string to access individual digits
        string numStr = to_string(num);
        
        // Create an array to store the last occurrence of each digit
        int last[10] = {0};
        
        // Store the last occurrence of each digit in the number
        for (int i = 0; i < numStr.size(); i++) {
            last[numStr[i] - '0'] = i;
        }
        
        // Traverse the number and try to find a larger digit to swap with
        for (int i = 0; i < numStr.size(); i++) {
            // Check for a larger digit that occurs after the current digit
            for (int d = 9; d > numStr[i] - '0'; d--) {
                if (last[d] > i) {
                    // Swap the digits
                    swap(numStr[i], numStr[last[d]]);
                    // Return the result as an integer
                    return stoi(numStr);
                }
            }
        }
        
        // If no swap is possible, return the original number
        return num;
    }
};

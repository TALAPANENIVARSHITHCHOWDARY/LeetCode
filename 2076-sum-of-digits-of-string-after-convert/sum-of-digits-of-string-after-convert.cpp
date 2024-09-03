class Solution {
public:
    int getLucky(string s, int k) {
        string numStr = "";
        
        // Convert each character to its corresponding numeric value
        for (char c : s) {
            int num = c - 'a' + 1;
            numStr += to_string(num);
        }
        
        // Function to sum the digits of a number string
        auto sumDigits = [](string numStr) {
            int sum = 0;
            for (char c : numStr) {
                sum += c - '0';
            }
            return sum;
        };
        
        // Perform the sum of digits operation k times
        int result = sumDigits(numStr);
        for (int i = 1; i < k; i++) {
            result = sumDigits(to_string(result));
        }
        
        return result;
    }
};

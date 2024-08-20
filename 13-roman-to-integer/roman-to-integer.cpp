#include <unordered_map>
#include <string>

class Solution {
public:
    int romanToInt(std::string s) {
        // Step 1: Create a map of Roman numerals to integer values
        std::unordered_map<char, int> romanMap = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };

        int result = 0;  // To store the final integer value
        int n = s.length();

        // Step 2: Traverse the string from left to right
        for (int i = 0; i < n; i++) {
            // If the current character is less than the next character, subtract it
            if (i < n - 1 && romanMap[s[i]] < romanMap[s[i + 1]]) {
                result -= romanMap[s[i]];
            } else {
                // Otherwise, add it to the result
                result += romanMap[s[i]];
            }
        }

        // Step 3: Return the result
        return result;
    }
};

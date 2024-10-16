#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string result = "";
        
        // Create a vector of pairs (count, char)
        vector<pair<int, char>> chars = {{a, 'a'}, {b, 'b'}, {c, 'c'}};
        
        while (true) {
            // Sort the vector to make sure the character with the highest count comes first
            sort(chars.rbegin(), chars.rend());
            
            bool added = false;
            
            // Try to add the most frequent character
            for (int i = 0; i < 3; ++i) {
                // If there are no occurrences left of this character, skip it
                if (chars[i].first == 0) {
                    continue;
                }
                
                int n = result.size();
                
                // Check if the last two characters are the same as the one we're about to add
                if (n >= 2 && result[n - 1] == chars[i].second && result[n - 2] == chars[i].second) {
                    // If so, skip this character for now
                    continue;
                }
                
                // Add the character to the result
                result += chars[i].second;
                // Decrease the count of the character
                chars[i].first--;
                // Mark that we added a character
                added = true;
                break;
            }
            
            // If no character was added, break the loop (no valid characters left to add)
            if (!added) {
                break;
            }
        }
        
        return result;
    }
};

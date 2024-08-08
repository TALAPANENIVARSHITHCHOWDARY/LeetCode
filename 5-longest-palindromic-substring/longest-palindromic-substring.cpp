#include <vector>
#include <string>
#include <array>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n == 0) return "";
        
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        array<int, 2> ans = {0, 0};

        // Every single character is a palindrome
        for (int i = 0; i < n; ++i) {
            dp[i][i] = true;
        }

        // Check for substrings of length 2
        for (int i = 0; i < n - 1; ++i) {
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = true;
                ans = {i, i + 1};
            }
        }

        // Check for substrings longer than 2 characters
        for (int diff = 2; diff < n; ++diff) {
            for (int i = 0; i < n - diff; ++i) {
                int j = i + diff;
                if (s[i] == s[j] && dp[i + 1][j - 1]) {
                    dp[i][j] = true;
                    ans = {i, j};
                }
            }
        }

        // Extract the longest palindromic substring
        int start = ans[0];
        int end = ans[1];
        return s.substr(start, end - start + 1);
    }
};

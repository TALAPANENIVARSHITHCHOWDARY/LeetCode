class Solution {
public:
    int func(int i, int j, string s, string t, vector<vector<int>>& dp) {
        // Base cases
        if (j < 0) return 1;  // All characters in t are matched
        if (i < 0) return 0;  // s is exhausted but t isn't fully matched

        if (dp[i][j] != -1) return dp[i][j];

        int res = 0;
        if (s[i] == t[j]) {
            // If characters match, we have two options:
            // 1. Use the current character of s in the match (move both i and j).
            // 2. Skip the current character of s (move only i).
            res = func(i-1, j-1, s, t, dp) + func(i-1, j, s, t, dp);
        } else {
            // If characters don't match, just skip the current character of s.
            res = func(i-1, j, s, t, dp);
        }

        dp[i][j] = res;
        return res;
    }

    int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return func(m-1, n-1, s, t, dp);
    }
};

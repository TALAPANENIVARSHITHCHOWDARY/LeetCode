class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.size();
        // DP array to store the minimum extra characters for substrings from index 0 to i
        vector<int> dp(n + 1, n);
        dp[0] = 0;  // Base case: no extra characters if no substring is selected

        // Set of dictionary words for faster lookups
        unordered_set<string> dict(dictionary.begin(), dictionary.end());

        // Fill the DP array
        for (int i = 1; i <= n; ++i) {
            // Assume we add the current character as an extra character
            dp[i] = dp[i - 1] + 1;

            // Check if any substring ending at i is in the dictionary
            for (int len = 1; len <= i; ++len) {
                string sub = s.substr(i - len, len);
                if (dict.count(sub)) {
                    dp[i] = min(dp[i], dp[i - len]);
                }
            }
        }

        return dp[n];
    }
};

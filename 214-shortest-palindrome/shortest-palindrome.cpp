class Solution {
public:
    string shortestPalindrome(string s) {
        // Step 1: Create the reversed version of the string s
        string rev_s = s;
        reverse(rev_s.begin(), rev_s.end());
        
        // Step 2: Concatenate s, a special character, and the reversed string
        string temp = s + "#" + rev_s;
        
        // Step 3: Compute the LPS (Longest Prefix Suffix) array for temp
        int n = temp.size();
        vector<int> lps(n, 0);
        
        // KMP algorithm to fill LPS array
        for (int i = 1; i < n; i++) {
            int j = lps[i - 1];
            while (j > 0 && temp[i] != temp[j]) {
                j = lps[j - 1];
            }
            if (temp[i] == temp[j]) {
                j++;
            }
            lps[i] = j;
        }
        
        // Step 4: Use the last value of LPS to determine the longest palindromic prefix
        int longest_palindromic_prefix_len = lps[n - 1];
        
        // Step 5: Add the reversed part of the remaining suffix to the front
        string suffix_to_add = s.substr(longest_palindromic_prefix_len);
        reverse(suffix_to_add.begin(), suffix_to_add.end());
        
        return suffix_to_add + s;
    }
};

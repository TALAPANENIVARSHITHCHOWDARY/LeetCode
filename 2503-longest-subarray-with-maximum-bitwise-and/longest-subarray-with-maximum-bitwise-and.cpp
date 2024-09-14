class Solution {
public:
    int longestSubarray(vector<int>& nums) {
    int n = nums.size();
    int max_val = *max_element(nums.begin(), nums.end()); // Find the maximum value
    int max_len = 0, current_len = 0;

    // Traverse the array to find the longest subarray of max_val
    for (int i = 0; i < n; ++i) {
        if (nums[i] == max_val) {
            current_len++;
            max_len = max(max_len, current_len);
        } else {
            current_len = 0; // Reset the length counter when the value changes
        }
    }

    return max_len;
}
};
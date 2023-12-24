class Solution {
public:
    int getCommon(const vector<int>& nums1, const vector<int>& nums2) {
        unordered_set<int> nums2Set(nums2.begin(), nums2.end());
        int minCommon = -1;
        for (int num1 : nums1) {
            if (nums2Set.count(num1) > 0) {
                if (minCommon == -1 || num1 < minCommon) {
                    minCommon = num1;
                }
            }
        }
        return minCommon;
    }
};

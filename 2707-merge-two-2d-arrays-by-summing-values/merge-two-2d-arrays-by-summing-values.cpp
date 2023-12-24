class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        vector<vector<int>> result;
        int i = 0, j = 0;
        while (i < nums1.size() || j < nums2.size()) {
            if (i < nums1.size() && (j == nums2.size() || nums1[i][0] < nums2[j][0])) {
                result.push_back(nums1[i]);
                ++i;
            } else if (j < nums2.size() && (i == nums1.size() || nums1[i][0] > nums2[j][0])) {
                result.push_back(nums2[j]);
                ++j;
            } else {
                result.push_back({nums1[i][0], nums1[i][1] + nums2[j][1]});
                ++i;
                ++j;
            }
        }

        return result;
    }
};

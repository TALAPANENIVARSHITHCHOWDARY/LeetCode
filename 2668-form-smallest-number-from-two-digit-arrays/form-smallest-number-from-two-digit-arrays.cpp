class Solution {
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        for(int i=0;i<nums1.size();i++){
            for(int j=0;j<nums2.size();j++){
                if(nums1[i]==nums2[j])
                return nums1[i];
            }
        }
        int a = *min_element(nums1.begin(), nums1.end());
        int b = *min_element(nums2.begin(), nums2.end());

     
        if (a == b) {
            return a;
        } else {
            return min(10 * a + b, 10 * b + a);
        }
    }
};

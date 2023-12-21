class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int minval=nums[0];
        for(int i=1;i<nums.size();i++){
            if(abs(minval)>abs(nums[i]))
        {
            minval=nums[i];
        }
        else if(abs(minval)==abs(nums[i]))
        {
            minval=max(minval,nums[i]);
        }
        }
        return minval;
    }
};
class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int ones=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==1) ones++;
        }
        if(ones==0||ones==n) return 0;
        vector<int> arr(nums.begin(),nums.end());
        arr.insert(arr.end(),nums.begin(),nums.end());
        int mini=INT_MAX;
        int cur=0;
        for(int i=0;i<ones;i++)
{
    if(arr[i]==0) cur++;

}
mini=min(mini,cur);
for(int i=ones;i<arr.size();i++){
    if(arr[i]==0) cur++;
    if(arr[i-ones]==0) cur--;
    mini=min(mini,cur);
}
return mini;
    }
};
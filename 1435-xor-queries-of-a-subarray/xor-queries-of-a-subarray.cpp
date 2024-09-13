class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> ans;
        for(auto query:queries){
            int temp=0;
            for(int i=query[0];i<=query[1];i++)
{
    temp^=arr[i];
}
ans.push_back(temp);        
}
return ans;
    }
};
class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        int n=arr.size();
        if(n<k) return "";
        
        map<string,int> mpp;
        for(int i=0;i<n;i++){
            mpp[arr[i]]+=1;
        }
        vector<int> ans;
        int cnt=0;
        for(int i=0;i<n;i++){
            if(mpp[arr[i]]==1){
                cnt++;
                if(cnt==k) return arr[i];
            }
        }
        return "";
    }
};
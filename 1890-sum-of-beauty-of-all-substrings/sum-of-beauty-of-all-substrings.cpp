class Solution {
public:
    int beautySum(string s) {
        int n=s.length();
        int tot=0;
        for(int i=0;i<n;i++){
            vector<int> arr(26,0);
            for(int j=i;j<n;j++){
                arr[s[j]-'a']++;
                int maxi=0,mini=INT_MAX;
                for(int temp:arr){
                    if(temp>0){
                        maxi=max(temp,maxi);
                        mini=min(temp,mini);
                    }
                }
                tot+=(maxi-mini);
            }
        }
        return tot;
    }
};
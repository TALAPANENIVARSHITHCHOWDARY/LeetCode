class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        vector<int> arr(26,-1);
        for(char c:allowed){
            arr[c-'a']=1;
        }
        int cnt=words.size();
        for(string ch:words){
            for(char c:ch){
                if(arr[c-'a']!=1){
                    cnt--;
                    break;
                }
                
            }

        }
        return cnt;
    }
};
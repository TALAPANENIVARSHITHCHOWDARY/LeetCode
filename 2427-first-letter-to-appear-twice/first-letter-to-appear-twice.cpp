class Solution {
public:
    char repeatedCharacter(string s) {
        int min=s.size();
        for(int i=0;i<s.size();i++){
            for(int j=i+1;j<s.size();j++){
                if(s[i]==s[j]){
                    if(min>j){
                min=j;
                    }
                break;
                }
            }
        }
        return s[min];
    }
};
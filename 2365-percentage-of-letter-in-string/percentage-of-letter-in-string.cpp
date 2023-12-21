class Solution {
public:
    int percentageLetter(string s, char letter) {
        double count=0,n=s.size();
        for(char c:s)
        {
            if(c==letter)
            count++;
        }
    double m=(count/n);
    return m*100;
    }
};
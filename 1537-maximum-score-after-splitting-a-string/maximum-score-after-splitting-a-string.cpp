class Solution {
public:
    int maxScore(string s) {
        int maxScore = 0;
        int countOnesRight = 0;
        for (char c : s) {
            if (c == '1') {
                countOnesRight++;
            }
        }
        int countZerosLeft = 0;
        for (int i = 0; i < s.size() - 1; i++) {
            if (s[i] == '0') {
                countZerosLeft++;
            } else {
                countOnesRight--;
            }
            int currentScore = countZerosLeft + countOnesRight;
            if (currentScore > maxScore) {
                maxScore = currentScore;
            }
        }
        return maxScore;
    }
};

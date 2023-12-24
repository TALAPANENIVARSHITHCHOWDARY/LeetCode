class Solution {
public:
    int maxDivScore(vector<int>& nums, vector<int>& divisors) {
        unordered_map<int, int> scoreMap;
        for (int divisor : divisors) {
            int score = 0;
            for (int num : nums) {
                if (num % divisor == 0) {
                    score++;
                }
            }
            scoreMap[divisor] = score;
        }
        int maxScore = 0;
        int result = INT_MAX;
        for (const auto& entry : scoreMap) {
            if (entry.second > maxScore || (entry.second == maxScore && entry.first < result)) {
                maxScore = entry.second;
                result = entry.first;
            }
        }
        return result;
    }
};

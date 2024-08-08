#include <vector>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return false;
        
        vector<bool> dp(n, false);
        dp[0] = true; // Starting position is always reachable
        
        for (int i = 0; i < n; ++i) {
            if (dp[i]) {
                for (int j = 1; j <= nums[i] && i + j < n; ++j) {
                    dp[i + j] = true;
                }
            }
        }
        
        return dp[n - 1];
    }
};

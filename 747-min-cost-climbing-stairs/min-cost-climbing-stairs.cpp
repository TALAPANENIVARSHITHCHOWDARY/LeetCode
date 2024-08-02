class Solution {
public:
    int func(int i, vector<int> &dp, vector<int> &cost) {
        if (i == 0) return cost[i];
        if (i == 1) return cost[i];
        if (dp[i] != -1) return dp[i];
int two=INT_MAX;
        int one = cost[i] + func(i - 1, dp, cost);
        if(i>1)
     two = cost[i] + func(i - 2, dp, cost);

        return dp[i] = min(one, two);
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n, -1);

        // The result is the minimum of reaching the top from the last or second last step.
        return min(func(n - 1, dp, cost), func(n - 2, dp, cost));
    }
};

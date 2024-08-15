class Solution {
public:
    // -------------- recursion function ----------//
    int min_cost(vector<int>& dp, vector<int>& cost, int n) {
        if (n == 0)
            return cost[0];
        if (n == 1)
            return cost[1];

        if (dp[n] != -1) {
            return dp[n];
        }

        dp[n] =
            cost[n] + min(min_cost(dp, cost, n - 1), min_cost(dp, cost, n - 2));
        return dp[n];
    }

    int minCostClimbingStairs(vector<int>& cost) {
        cost.push_back(0); // catch for this question

        // ------------- tabulation ------------//
        vector<int> dpp(cost.size() + 1, -1);

        dpp[0] = cost[0];
        dpp[1] = cost[1];

        for (int i = 2; i < dpp.size() - 1; i++) {
            dpp[i] = cost[i] + min(dpp[i - 1], dpp[i - 2]);
        }

        return dpp[cost.size() - 1];

        // --------------- memoisation -------------- ///
        vector<int> dp(cost.size() + 1, -1);
        return min_cost(dp, cost, cost.size() - 1);
    }
};
class Solution {
public:
    // sexy backtracking + dp ka question
    int n;

    int solve(int index, int target, vector<int>& nums,
              vector<vector<int>>& dp) {
        // base case
        if (target == 0) {
            return 1;
        }
        if (index >= n || target < 0) {
            return 0;
        }

        // memoisation
        if (dp[index][target] != -1) {
            return dp[index][target];
        }

        // // backtracking , take/not_take
        // int take = solve(0,target-nums[index],nums,dp);
        // int not_take = solve(index+1,target,nums,dp);
        // // storing in dp
        // return dp[index][target]=take+not_take;

        //--------- can also be done through one loop ----//
        int result = 0;
        for (int i = index; i < n; i++) {
            int take = solve(0, target - nums[i], nums, dp);
            result += take;
        }
        return dp[index][target] = result;
    }

    int combinationSum4(vector<int>& nums, int target) {
        n = nums.size();
        int index = 0;

        vector<vector<int>> dp(201, vector<int>(1001, -1));

        return solve(index, target, nums, dp);
    }
};
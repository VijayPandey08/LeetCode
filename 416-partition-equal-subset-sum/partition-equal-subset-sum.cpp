class Solution {
public:
    bool solve(vector<int>& nums, int target, int index) {
        if (target == 0) {
            return true;
        }
        if (index >= nums.size() || target < 0) {
            return false;
        }

        bool take = solve(nums, target - nums[index], index + 1);
        bool not_take = solve(nums, target, index + 1);
        return take | not_take;
    }
    bool solvememo(vector<int>& nums, int target, int index,vector<vector<int>> &dp) {
        if (target == 0) {
            return true;
        }
        if (index >= nums.size() || target < 0) {
            return false;
        }
        if(dp[index][target]!=-1){
            return dp[index][target];
        }

        bool take = solvememo(nums, target - nums[index], index + 1,dp);
        bool not_take = solvememo(nums, target, index + 1,dp);
        dp[index][target] =(take | not_take);

        return dp[index][target];
    }

    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0ll);
        if (sum & 1)
            return false;
        int target = sum >> 1;

        int index = 0;
        int n=nums.size();
        vector<vector<int>> dp(n+5,vector<int>(target+1,-1));

        return solvememo(nums, target, index,dp);
    }
};
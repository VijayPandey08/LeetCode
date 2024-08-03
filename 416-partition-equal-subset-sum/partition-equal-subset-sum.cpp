class Solution {
public:

    int dp[201][100000];
    bool solve(vector<int>& nums, int target, int index) {
        if (target == 0) {
            return true;
        }
        if (index >= nums.size() || target < 0) {
            return false;
        }
        if(dp[index][target] != -1) return dp[index][target];
        bool take = solve(nums, target - nums[index], index + 1);
        bool not_take = solve(nums, target, index + 1);
        return dp[index][target] =take | not_take;
    }
    
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0ll);
        if (sum & 1)
            return false;
        int target = sum >> 1;

        int index = 0;
        int n=nums.size();
        memset(dp,-1,sizeof(dp));
        return solve(nums, target, index);
    }
};
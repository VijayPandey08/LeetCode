class Solution {
public:
    int solve_dp(vector<int>& nums, int curr, int prev,vector<vector<int>> &dp) {
        if (curr >= nums.size()) {
            return 0;
        }
        if(dp[curr][prev+1]!=-1){
          return dp[curr][prev+1];
        }
        int include = 0;
        int exclude = 0;
        if (prev == -1 || nums[curr] > nums[prev]) {
            include = 1 + solve_dp(nums, curr + 1, curr,dp);
        }

        exclude = 0 + solve_dp(nums, curr + 1, prev,dp);

        return dp[curr][prev+1] = max(include, exclude);
    }
    int lengthOfLIS(vector<int>& nums) {
        // jayant ka tareeka jisme ek trail vector bana lete h.. same as
        // tabulation vector<int> trail(nums.size(),0); trail[0] = 1; int ans =
        // 1; for(int i = 1;i<nums.size();i++){
        //     int maxi = 0;
        //     for(int j = 0;j<i;j++){
        //         if(nums[i]>nums[j]){
        //             maxi = max(maxi,trail[j]);
        //         }
        //     }
        //     trail[i] = maxi+1;
        //     ans = max(ans,trail[i]);
        // }
        // return ans;

        // recurssion:
        int prev = -1;
        int curr = 0;
        int n=nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return solve_dp(nums, curr, prev,dp);
    }
};
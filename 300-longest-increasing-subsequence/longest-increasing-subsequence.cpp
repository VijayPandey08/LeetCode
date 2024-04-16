class Solution {
public:
    // int solve_dp(vector<int>& nums, int curr, int prev,
    //              vector<vector<int>>& dp) {
    //     if (curr >= nums.size()) {
    //         return 0;
    //     }
    //     if (dp[curr][prev + 1] != -1) {
    //         return dp[curr][prev + 1];
    //     }
    //     int include = 0;
    //     int exclude = 0;
    //     if (prev == -1 || nums[curr] > nums[prev]) {
            
    //         include = 1 + solve_dp(nums, curr + 1, curr, dp);
    //     }

    //     exclude = 0 + solve_dp(nums, curr + 1, prev, dp);

    //     return dp[curr][prev + 1] = max(include, exclude);
    // }

    int solve_tabulation(vector<int>& nums, int curr, int prev) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        for (int curr_index = n - 1; curr_index >= 0; curr_index--) {
            for (int prev_index = curr_index; prev_index >= -1; prev_index--) {
                int include = 0;
                int exclude = 0;
                if (prev_index == -1 || nums[curr_index] > nums[prev_index]) {
                    include = 1 + dp[curr_index + 1][curr_index+1];
                }

                exclude =  dp[curr_index + 1][prev_index+1];

                 dp[curr_index][prev_index + 1] = max(include, exclude);
            }
        }
        // for(auto i:dp){
        //     for(auto j:i){
        //         cout<<j<<"  ";
        //     }
        //     cout<<endl;
        // }
        return dp[0][0];
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
        int n = nums.size();
        // vector<vector<int>> dp(n, vector<int>(n, -1));
        // return solve_dp(nums, curr, prev,dp);
        // tabulation
        return solve_tabulation(nums, curr, prev);
    }
};
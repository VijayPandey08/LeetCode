class Solution {
public:
int dp[2505][2505];
    int solve(vector<int>& nums, int prev, int curr) {
        if (curr >= nums.size()) {
            return 0;
        }
        // int ans = 0;

        if(dp[prev+1][curr]!=-1){
            return dp[prev+1][curr];
        }

        int include = 0;
        int exclude = 0;

        if (prev == -1 || nums[curr] > nums[prev]) {
            include = 1 + solve(nums, curr, curr + 1);
        }
        exclude = 0 + solve(nums, prev, curr + 1);

        return   dp[prev+1][curr]= max(include, exclude);
    }

    int lengthOfLIS(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        int prev = -1;
        int curr = 0;

        return solve(nums, prev, curr);

        // ------------------- most optimized Binary search approach
        // -----------//
        vector<int> dp;
        dp.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > dp.back()) {
                dp.push_back(nums[i]);
            } else {
                int idx =
                    lower_bound(dp.begin(), dp.end(), nums[i]) - dp.begin();
                dp[idx] = nums[i];
            }
        }
        // lower_bound --->   >= target
        // upper_bound --->   > target
        // for(auto i:dp){
        //     cout<<i<<" ";
        // }
        return dp.size();
    }
};
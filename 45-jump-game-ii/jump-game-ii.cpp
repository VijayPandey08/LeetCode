class Solution {
public:
    // unordered_map<int,int> m;
    int dp[10005];
    int solve(vector<int>& nums, int index) {
        int n = nums.size();
        if (index == n - 1) {
            return 0;
        }
        if (index >= n) {
            return INT_MAX;
        }
        if(dp[index]!= -1) return dp[index];
        int mini = INT_MAX;
        for (int i = 1; i <= nums[index]; i++) {
            mini = min(mini, solve(nums, index+i));
        }
        if (mini != INT_MAX) return dp[index] = (1+mini);
        return dp[index] = (mini);
    }

    int jump(vector<int>& nums) {

        int index = 0;
        memset(dp,-1,sizeof(dp));
        return solve(nums, index);

        //--------------- tabulation-----------------//
        int n = nums.size();
        vector<int> dpp(nums.size(), INT_MAX);
        dpp[n - 1] = 0;

        for (int i = n - 2; i >= 0; i--) {
            int mini = INT_MAX;
            for (int j = 1; j <= nums[i] && i + j < n; j++) {
                mini = min(mini, dpp[i + j]);
            }
            if (mini != INT_MAX) {

                dpp[i] = 1 + mini;
            }
        }
        for (auto i : dpp) {
            cout << i << " ";
        }

        return dpp[0];
    }
};
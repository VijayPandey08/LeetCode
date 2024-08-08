class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        for (int i = 1; i < nums.size(); i++) {
            int maxi = 0;
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    maxi = max(maxi, dp[j]);
                }
            }
            dp[i] += maxi;
        }
        return *max_element(dp.begin(),dp.end());
    }
};
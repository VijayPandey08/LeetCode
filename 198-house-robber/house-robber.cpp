class Solution {
public:
    int rob(vector<int>& nums) {

// ----------------- tabulation ---------------------- //
        vector<int> dp(nums.size(), -1);
        dp[0] = nums[0];
        if (nums.size() == 1) return nums[0];
        dp[1] = max(nums[0], nums[1]);

        for (int i = 2; i < nums.size(); i++) {
            dp[i] = max(dp[i - 1], (dp[i - 2] + nums[i]));
        }

//   --------------- space optimization ----------------//        

        int prev_2 = nums[0];
        if (nums.size() == 1) return nums[0];
        int prev_1 = max(nums[0], nums[1]);

        for (int i = 2; i < nums.size(); i++) {
            int curr = max(prev_1, (prev_2 + nums[i]));
            prev_2 = prev_1;
            prev_1 = curr;
        }

// -------------- returning ans -----------------//
        // return dp[nums.size() - 1];   ----- via tabulation
        return prev_1;   // ------- via space optimization
    }
};
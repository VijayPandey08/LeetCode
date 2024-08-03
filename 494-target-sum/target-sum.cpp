class Solution {
public:
    int solve(vector<int>& nums, int index, int temp, vector<vector<int>>& dp) {
        if (temp == 0 && index >= nums.size()) {
            return 1;
        }
        if (temp < 0 || index >= nums.size()) {
            return 0;
        }

        if (dp[index][temp] != -1) {
            return dp[index][temp];
        }

        int a = solve(nums, index + 1, temp - nums[index],dp);
        int b = solve(nums, index + 1, temp,dp);
        return dp[index][temp] = a + b;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        

        int index = 0;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        vector<vector<int>> dp(25, vector<int>(1005, -1));

        // basically kuch positive value(x) + kuch negative values(y) mila ke
        // target milega x + (-y) = target ,  yeh sala negative humne kia h x +
        // y = sum , yeh original jo nums ka sum hota bina koi fer badal

        int temp = (sum + target) / 2; // master stroke by jayant maurya
        // positive assign krne ke lie kitni values h num ke pss yeh nikal lo

        // int temp = ( sum - target)/2;
        // negative sign vali kitni values hongi yeh find krlo

        if((sum+target)&1) return 0;

        return solve(nums, index, temp, dp);
    }
};
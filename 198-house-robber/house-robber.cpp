class Solution {
public:
int solve_dp(vector<int>& nums, int index, vector<int> &dp){
    if(index>=nums.size()){
        return 0;
    }

    if(dp[index]!=-1){
        return dp[index];
    }
    int include = nums[index] + solve_dp(nums,index+2,dp);
    int exclude = solve_dp(nums,index+1,dp);
    int ans = max(include,exclude);

    return dp[index] = ans;
}
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size()+1,-1);
         return solve_dp(nums,0,dp);
    }
};
class Solution {
public:
int n;

int solve(int index, int target, vector<int>&nums, vector<vector<int>>& dp){
    if(target==0){
        return 1;
    }
    if(index>=n || target<0){
        return 0;
    }
    if(dp[index][target]!=-1){
        return dp[index][target];
    }

    int take = solve(0,target-nums[index],nums,dp);
    int not_take = solve(index+1,target,nums,dp);

    return dp[index][target]=take+not_take;
}
    int combinationSum4(vector<int>& nums, int target) {
        n = nums.size();
        int index =0;

vector<vector<int>> dp(201,vector<int>(1001,-1));

        return solve(index,target,nums,dp);
        
    }
};
class Solution {
public:

int dp[25][5000];
int solve(vector<int> &nums, int target, int index){
    if(index==nums.size()){
        return ((target==0)?1:0);
    }

    if(dp[index][target + 2000]!=-1){
             return dp[index][target+2000];
    }

    int a = solve(nums,target-nums[index],index+1);
    int b = solve(nums,target+nums[index],index+1);

    return dp[index][target+2000]=  a+b;
    
}

    int findTargetSumWays(vector<int>& nums, int target) {

        memset(dp,-1,sizeof(dp));
        int index=0;
        return solve(nums,target,index);
    }
};
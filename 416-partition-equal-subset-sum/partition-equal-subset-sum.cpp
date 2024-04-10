class Solution {
public:

bool solve(vector<int>& nums,int index, int target, vector<vector<int>> &dp){
    if(index>=nums.size()){
        if(target==0) return true;
        return false;
    } 
    if(target<0) return false;
    if(target==0) return true;

    if(dp[index][target]!=-1){
        return dp[index][target];
    }

    bool include = solve(nums,index+1,target-nums[index],dp);
    bool exclude = solve(nums,index+1,target,dp);

    return dp[index][target]=(include | exclude);

}
    bool canPartition(vector<int>& nums) {
       int n = nums.size();
       int sum = accumulate(nums.begin(),nums.end(),0ll);
       if(sum&1) return false;
       int target = sum /2;
        vector<vector<int>> dp(nums.size()+1,vector<int>(target+1,-1));
       cout<<target<<endl;
       return solve(nums,0,target,dp);


    }
};
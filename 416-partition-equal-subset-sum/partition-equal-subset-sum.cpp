class Solution {
public:

// bool solve(vector<int>& nums,int index, int target, vector<vector<int>> &dp){
// // recursion

//     if(index>=nums.size()){
//         if(target==0) return true;
//         return false;
//     } 
//     if(target<0) return false;
//     if(target==0) return true;

//     if(dp[index][target]!=-1){
//         return dp[index][target];
//     }

//     bool include = solve(nums,index+1,target-nums[index],dp);
//     bool exclude = solve(nums,index+1,target,dp);

//     return dp[index][target]=(include | exclude);

// }
    bool canPartition(vector<int>& nums) {
       int n = nums.size();
       int sum = accumulate(nums.begin(),nums.end(),0ll);
       if(sum&1) return false;
       int target = sum /2;
        vector<vector<bool>> dp(nums.size()+1,vector<bool>(target+1,false));
    //    cout<<target<<endl;
    //    return solve(nums,0,target,dp);
    for(int i=0; i<dp.size(); i++){
        dp[i][0]=true;
    }
    for(int i=1; i<dp.size(); i++){
        for(int j=1; j<target+1; j++){
               if(j>=nums[i-1]){
                dp[i][j]=dp[i-1][j] | dp[i-1][j-nums[i-1]];
               }
               else{
                 dp[i][j] = dp[i-1][j];
               }
        }
    }
    return dp[nums.size()][target];




    }
};
class Solution {
public:
    int dp[201][100000];
    bool solve(vector<int>& nums, int target, int index) {
        if (target == 0) {
            return true;
        }
        if (index >= nums.size() || target < 0) {
            return false;
        }
        if(dp[index][target] != -1) return dp[index][target];
        bool take = solve(nums, target - nums[index], index + 1);
        bool not_take = solve(nums, target, index + 1);
        return dp[index][target] =take | not_take;
    }
    
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0ll);
        if (sum & 1)
            return false;
        int target = sum >> 1;
        int n = nums.size();
        int dpp[n+1][target+1];
        // int curr[target+1];
        // int prev[target+1]={0};
        vector<int> curr(target+1,0);
        vector<int> prev(target+1,0);
        prev[0]= 1;

        for(int i = 1;i<n+1;i++){
            for(int j = 0;j<target+1;j++){
                curr[j] = prev[j];
                if(j-nums[i-1]>=0) curr[j] |= prev[j-nums[i-1]];
            }
            prev = curr;
            for(int j = 0 ;j<target+1;j++){
                curr[j] = 0;
            }
        }
        return prev[target];


        

        // for(int i=0; i<n+1; i++){
        //     for(int j=0; j<target+1; j++){
        //         if(i==0 && j==0){
        //             dpp[i][j] =1;
        //         }
        //         else if(i==0){
        //               dpp[i][j] = 0;
        //         }
        //         else if(j==0){
        //             dpp[i][j] =1;

        //         }
        //         else{
        //                 dpp[i][j] = dpp[i-1][j];   // not take
        //                 if(j-nums[i-1] >=0) dpp[i][j] |=  dpp[i-1][j-nums[i-1]]; //take
        //         }
        //     }
        // }

        // return dpp[n][target];
/*
T F F F F
T
T
T


*/


        // int index = 0;
        // int n=nums.size();
        // memset(dp,-1,sizeof(dp));
        // return solve(nums, target, index);
    }
};
class Solution {
public:
    int ans;
    int solve(vector<int>& nums, int i,int j, int sum,vector<vector<int>> &dp){
        if(i>=j){
            return 0;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int a,b,c;
        a=b=c=0;
        if(nums[i]+nums[i+1]==sum){
            a=1+solve(nums,i+2,j,sum,dp);
        }
                if(nums[j]+nums[j-1]==sum){
            b=1+solve(nums,i,j-2,sum,dp);
        }
        if(nums[i]+nums[j]==sum){
            c=1+solve(nums,i+1,j-1,sum,dp);
        }

        
        return dp[i][j]= max(a, max(b,c));
    }
    int maxOperations(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp1(n+1,vector<int>(n+1,-1));
        vector<vector<int>> dp2(n+1,vector<int>(n+1,-1));
        vector<vector<int>> dp3(n+1,vector<int>(n+1,-1));
        int i=0;
        int j=nums.size()-1;
        int a=solve(nums,i,j,nums[0]+nums[1],dp1);
        int b=solve(nums,i,j,nums[j]+nums[j-1],dp2);
        int c=solve(nums,i,j,nums[0]+nums[j],dp3);

        return max({a,b,c});

    }
};
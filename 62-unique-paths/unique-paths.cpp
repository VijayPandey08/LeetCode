class Solution {
public:
// int result;
    int solve(int i, int j,int m, int n, vector<vector<int>> &dp){
         if(i<0 || i>=m || j<0 || j>=n){
            return 0;
         }
         if(i==m-1 && j==n-1){
            return 1;
         }
         if(dp[i][j]!=0){
            return dp[i][j];
         }
         int right = solve(i+1,j,m,n,dp);
         int down = solve(i,j+1,m,n,dp);

         return dp[i][j] = right + down;

    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,0));


        // result=0;
         return solve(0,0,m,n,dp);
        // return result;
    }
};
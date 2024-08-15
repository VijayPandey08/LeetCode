class Solution {
public:

int dp[205][205];

int solve(vector<vector<int>>& grid, int n, int m, int i, int j){
   if(i==n-1 && j==m-1){
    return grid[i][j];
   }
   if(i>=n || j>=m){
    return 1e6;
   }

   if(dp[i][j]!=-1){
    return dp[i][j];
   }

   int down = grid[i][j]  + solve(grid,n,m,i+1,j);
   int right = grid[i][j]  + solve(grid,n,m,i,j+1);
   return dp[i][j] = min(down,right);
}

    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int i=0;
        int j=0;
memset(dp,-1,sizeof(dp));


        return solve(grid,n,m,i,j);
    }
};
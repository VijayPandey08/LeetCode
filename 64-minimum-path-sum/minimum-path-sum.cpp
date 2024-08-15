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
        
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(i==0 && j==0){
                    
                }
                else if(i==0){
                      grid[i][j] += grid[i][j-1]; 
                }
                else if(j==0){
                      grid[i][j] += grid[i-1][j];
                }
                else{
                    grid[i][j] += min(grid[i-1][j],grid[i][j-1]);
                }
            }
        }

        return grid[n-1][m-1];
        












        // --------------- memoisation ------------//

        int i=0;
        int j=0;
memset(dp,-1,sizeof(dp));


        return solve(grid,n,m,i,j);

    }
};
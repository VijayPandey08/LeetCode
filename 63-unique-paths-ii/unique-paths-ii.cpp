class Solution {
public:
    int dp[101][101];

    int solve(int m, int n, int i, int j,vector<vector<int>>& grid) {
        if (i > m || j > n) {
            return 0;
        }

        if(grid[i][j]==1){
            return 0;
        }
        if (i == m && j == n) {
            return 1;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int ans = solve(m, n, i + 1, j,grid) + solve(m, n, i, j + 1,grid);
        return dp[i][j] = ans;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        memset(dp, -1, sizeof(dp));

        return solve(m - 1, n - 1, 0, 0,grid);
    }
};
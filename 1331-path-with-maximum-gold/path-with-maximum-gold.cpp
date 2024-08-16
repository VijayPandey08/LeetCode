class Solution {
public:
    int solve(vector<vector<int>>& grid, int n, int m, int i, int j) {
        if (i < 0 || j < 0 || i >= n || j >= m) {
            return 0;
        }

        if (grid[i][j] == 0) {
            return 0;
        }
        int val = grid[i][j];
        grid[i][j] = 0;
        int up = grid[i][j] + solve(grid, n, m, i - 1, j);
        int down = grid[i][j] + solve(grid, n, m, i + 1, j);
        int right = grid[i][j] + solve(grid, n, m, i, j + 1);
        int left = grid[i][j] + solve(grid, n, m, i, j - 1);
        grid[i][j] = val;

        return max({up, down, right, left}) + val;
    }

    int getMaximumGold(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int i = 0;
        int j = 0;
        int maxi = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] != 0) {
                    int temp = solve(grid, n, m, i, j);
                    maxi = max(maxi, temp);
                }
            }
        }

        return maxi;
    }
};
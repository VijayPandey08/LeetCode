class Solution {
public:
    vector<vector<int>> direction = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    int islandPerimeter(vector<vector<int>>& grid) {
        // dfs
        int ans = 0;
        int n = grid.size();
        int m = grid[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0)
                    continue;
                else {
                    if (i +1 >= n || grid[i + 1][j] == 0) {
                        ans++;
                    }
                    if (i - 1 < 0 || grid[i - 1][j] == 0) {
                        ans++;
                    }
                    if (j + 1 >= m || grid[i][j+1] == 0) {
                        ans++;
                    }
                    if (j - 1 < 0 || grid[i][j - 1] == 0) {
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};
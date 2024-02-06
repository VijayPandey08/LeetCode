class Solution
{
    public:
    int m, n;
    int result=0;
    int obstacles;
    vector<vector <int>> directions = {{1,0},{-1,0},{0,1},{0,-1}};

    void solve(vector<vector < int>> &grid, int count, int x, int y)
    {

        if (x < 0 || y < 0 || x >= m || y >= n || grid[x][y] == -1)
        {
            return;
        }
        if (grid[x][y] == 2)
        {
            if (count == obstacles)
            {
                result++;
            }
                return;
        }
         grid[x][y] = -1;
        
        for (auto i: directions)
        {
            int new_x = x + i[0];
            int new_y = y + i[1];
            solve(grid, count + 1, new_x, new_y);
        }
       	
           grid[x][y] = 0;
    }
    int uniquePathsIII(vector<vector < int>> &grid)
    {
        m = grid.size();
        n = grid[0].size();
        obstacles = 0;
        int x = 0;
        int y = 0;
        int count = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 0)
                {
                    obstacles++;
                }
                if (grid[i][j] == 1)
                {
                    x = i;
                    y = j;
                }
            }
        }
        obstacles++;
        solve(grid, count, x, y);
        return result;
    }
};
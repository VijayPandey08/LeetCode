class Solution {
public:
    int m, n;
    vector<vector<int>> directions{{0, 1}, {1, 0},  {-1, 0}, {0, -1},
                                   {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
    bool isSafe(int x_, int y_) {
        return (x_ >= 0 && x_ < n && y_ >= 0 && y_ < m);
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        if (m == 0 || n == 0 || grid[0][0] != 0)
            return -1;
        queue<pair<int, int>> q;
        q.push({0, 0});
        grid[0][0] = 1;

        int level = 1;

        while (!q.empty()) {
            int N = q.size();
            while (N--) {
                auto curr = q.front();
                q.pop();
                int x = curr.first;
                int y = curr.second;

                if (x == n - 1 && y == m - 1)
                    return level;

                for (auto dir : directions) {
                    int x_ = x + dir[0];
                    int y_ = y + dir[1];

                    if (isSafe(x_, y_) && grid[x_][y_] == 0) {
                        q.push({x_, y_});
                        grid[x_][y_] = 1;
                    }
                }
            }
            level++;
        }

        return -1;
    }
};
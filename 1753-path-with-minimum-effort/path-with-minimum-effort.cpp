class Solution {
public:
    int n, m;
    typedef pair<int, pair<int, int>> P;
    vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    bool isSafe(int x_, int y_) {
        return (x_ >= 0 && y_ >= 0 && x_ < n && y_ < m);
    }

    int minimumEffortPath(vector<vector<int>>& heights) {
        n = heights.size();
        m = heights[0].size();

        priority_queue<P, vector<P>, greater<P>> pq;
        vector<vector<int>> result(n, vector<int>(m, INT_MAX));
        result[0][0] = 0;
        pq.push({0, {0, 0}});

        while (!pq.empty()) {
            int diff = pq.top().first;
            pair<int, int> node = pq.top().second;
            int node_x = node.first;
            int node_y = node.second;
            pq.pop();

            // if (node_x == n - 1 && node_y == m - 1) {
            //     return diff;
            // }

            for (auto dir : directions) {
                int x_ = node_x + dir[0];
                int y_ = node_y + dir[1];
                if (isSafe(x_, y_)) {
                    int abs_diff = abs(heights[node_x][node_y] - heights[x_][y_]);
                    int max_diff = max(diff, abs_diff);
                    if (result[x_] [y_] > max_diff) {
                        result[x_] [y_] = max_diff;
                        pq.push({max_diff, {x_, y_}});
                    }
                }
            }
        }

        return result[n - 1][m - 1];
        // return 0;
    }
};